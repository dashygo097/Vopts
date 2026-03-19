package vopts.com.amba

import vopts.utils._
import chisel3._
import chisel3.util._

class AXILiteArbiter(
  addrWidth: Int,
  dataWidth: Int,
  numMasters: Int,
  fifoDepth: Int = 4
) extends Module {
  override def desiredName: String =
    s"axilite_arbiter_${numMasters}_${addrWidth}x${dataWidth}_d$fifoDepth"

  require(numMasters > 0, "Number of masters must be at least 1")
  require(fifoDepth > 0, "FIFO depth must be at least 1")

  val slaves_ext =
    IO(Vec(numMasters, new AXILiteSlaveExtIO(addrWidth, dataWidth))).suggestName("S_AXI")
  val slaves     = Wire(Vec(numMasters, AXILiteSlaveIO(addrWidth, dataWidth)))

  val master_ext = IO(new AXILiteMasterExtIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  dontTouch(slaves_ext)
  dontTouch(master_ext)

  val masterWidth = log2Ceil(numMasters.max(2))

  class AWEntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val master_id = UInt(masterWidth.W)
  }

  val aw_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AWEntry, fifoDepth)).io))

  class WEntry extends Bundle {
    val data      = UInt(dataWidth.W)
    val strb      = UInt((dataWidth / 8).W)
    val master_id = UInt(masterWidth.W)
  }

  val w_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new WEntry, fifoDepth)).io))

  class AREntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val master_id = UInt(masterWidth.W)
  }

  val ar_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AREntry, fifoDepth)).io))

  for (i <- 0 until numMasters) {
    aw_fifos(i).enq.valid          := slaves(i).aw.valid
    aw_fifos(i).enq.bits.addr      := slaves(i).aw.bits.addr
    aw_fifos(i).enq.bits.prot      := slaves(i).aw.bits.prot
    aw_fifos(i).enq.bits.master_id := i.U
    slaves(i).aw.ready             := aw_fifos(i).enq.ready

    w_fifos(i).enq.valid          := slaves(i).w.valid
    w_fifos(i).enq.bits.data      := slaves(i).w.bits.data
    w_fifos(i).enq.bits.strb      := slaves(i).w.bits.strb
    w_fifos(i).enq.bits.master_id := i.U
    slaves(i).w.ready             := w_fifos(i).enq.ready

    ar_fifos(i).enq.valid          := slaves(i).ar.valid
    ar_fifos(i).enq.bits.addr      := slaves(i).ar.bits.addr
    ar_fifos(i).enq.bits.prot      := slaves(i).ar.bits.prot
    ar_fifos(i).enq.bits.master_id := i.U
    slaves(i).ar.ready             := ar_fifos(i).enq.ready
  }

  def nextMaster(current: UInt): UInt =
    if (numMasters == 1) {
      0.U
    } else {
      val next = Wire(UInt(masterWidth.W))
      next := 0.U
      for (i <- 0 until numMasters)
        when(current === i.U) {
          next := ((i + 1) % numMasters).U
        }
      next
    }

  def roundRobinGrant(start: UInt, valids: Seq[Bool]): (UInt, Bool) = {
    val grant = Wire(UInt(masterWidth.W))
    val found = Wire(Bool())
    grant := 0.U
    found := false.B
    for (startVal <- 0 until numMasters)
      when(start === startVal.U) {
        grant := 0.U
        found := false.B
        for (offset <- (numMasters - 1) to 0 by -1) {
          val idx = (startVal + offset) % numMasters
          when(valids(idx)) {
            grant := idx.U
            found := true.B
          }
        }
      }
    (grant, found)
  }

  val selected_master_w = RegInit(0.U(masterWidth.W))
  val w_active          = RegInit(false.B)
  val aw_done           = RegInit(false.B)
  val w_done            = RegInit(false.B)

  val aw_fifo_valids = VecInit(aw_fifos.map(_.deq.valid))
  val w_fifo_valids  = VecInit(w_fifos.map(_.deq.valid))

  val w_both_valid                   = Seq.tabulate(numMasters)(i => aw_fifo_valids(i) && w_fifo_valids(i))
  val (aw_grant_val, aw_grant_found) = roundRobinGrant(selected_master_w, w_both_valid)

  val aw_grant = Wire(UInt(masterWidth.W))
  when(!w_active) {
    aw_grant := aw_grant_val
  }.otherwise {
    aw_grant := selected_master_w
  }

  when(!w_active && aw_grant_found) {
    w_active          := true.B
    selected_master_w := aw_grant
    aw_done           := false.B
    w_done            := false.B
  }

  when(w_active) {
    when(!aw_done && aw_fifos(selected_master_w).deq.valid && master.aw.ready) {
      aw_done := true.B
    }

    when(!w_done && w_fifos(selected_master_w).deq.valid && master.w.ready) {
      w_done := true.B
    }

    when(aw_done && w_done && master.b.valid && slaves(selected_master_w).b.ready) {
      w_active          := false.B
      selected_master_w := nextMaster(selected_master_w)
    }
  }

  master.aw.valid     := w_active && !aw_done && aw_fifos(selected_master_w).deq.valid
  master.aw.bits.addr := aw_fifos(selected_master_w).deq.bits.addr
  master.aw.bits.prot := aw_fifos(selected_master_w).deq.bits.prot

  for (i <- 0 until numMasters)
    aw_fifos(i).deq.ready := w_active && !aw_done &&
      (selected_master_w === i.U) &&
      master.aw.ready

  master.w.valid     := w_active && !w_done && w_fifos(selected_master_w).deq.valid
  master.w.bits.data := w_fifos(selected_master_w).deq.bits.data
  master.w.bits.strb := w_fifos(selected_master_w).deq.bits.strb

  for (i <- 0 until numMasters)
    w_fifos(i).deq.ready := w_active && !w_done &&
      (selected_master_w === i.U) &&
      master.w.ready

  val b_route_fifo   = Module(new Queue(UInt(masterWidth.W), fifoDepth * numMasters))
  val b_need_enqueue = RegInit(false.B)

  when(
    w_active && !aw_done && aw_fifos(selected_master_w).deq.valid && master.aw.ready &&
      !w_done && w_fifos(selected_master_w).deq.valid && master.w.ready
  ) {
    b_need_enqueue := true.B
  }.elsewhen(w_active && aw_done && !w_done && w_fifos(selected_master_w).deq.valid && master.w.ready) {
    b_need_enqueue := true.B
  }.elsewhen(w_active && !aw_done && aw_fifos(selected_master_w).deq.valid && master.aw.ready && w_done) {
    b_need_enqueue := true.B
  }.elsewhen(b_route_fifo.io.enq.fire) {
    b_need_enqueue := false.B
  }

  b_route_fifo.io.enq.valid := b_need_enqueue
  b_route_fifo.io.enq.bits  := selected_master_w

  b_route_fifo.io.deq.ready := master.b.valid &&
    slaves(b_route_fifo.io.deq.bits).b.ready

  for (i <- 0 until numMasters) {
    slaves(i).b.valid := master.b.valid &&
      b_route_fifo.io.deq.valid &&
      (b_route_fifo.io.deq.bits === i.U)
    slaves(i).b.bits  := master.b.bits
  }

  master.b.ready := b_route_fifo.io.deq.valid &&
    slaves(b_route_fifo.io.deq.bits).b.ready

  val selected_master_ar = RegInit(0.U(masterWidth.W))
  val ar_locked          = RegInit(false.B)

  val ar_fifo_valids = VecInit(ar_fifos.map(_.deq.valid))

  val ar_valids_seq                  = Seq.tabulate(numMasters)(i => ar_fifo_valids(i))
  val (ar_grant_val, ar_grant_found) = roundRobinGrant(selected_master_ar, ar_valids_seq)

  val ar_grant = Wire(UInt(masterWidth.W))
  when(!ar_locked) {
    ar_grant := ar_grant_val
  }.otherwise {
    ar_grant := selected_master_ar
  }

  val ar_request_valid = Mux(!ar_locked, ar_grant_found, ar_fifo_valids(selected_master_ar))

  when(!ar_locked && ar_grant_found && master.ar.ready) {
    ar_locked          := true.B
    selected_master_ar := ar_grant
  }.elsewhen(ar_locked && master.r.valid && slaves(selected_master_ar).r.ready) {
    ar_locked          := false.B
    selected_master_ar := nextMaster(selected_master_ar)
  }

  master.ar.valid     := Mux(!ar_locked, ar_grant_found && ar_fifo_valids(ar_grant_val), ar_fifo_valids(selected_master_ar))
  master.ar.bits.addr := Mux(!ar_locked, ar_fifos(ar_grant_val).deq.bits.addr, ar_fifos(selected_master_ar).deq.bits.addr)
  master.ar.bits.prot := Mux(!ar_locked, ar_fifos(ar_grant_val).deq.bits.prot, ar_fifos(selected_master_ar).deq.bits.prot)

  for (i <- 0 until numMasters)
    ar_fifos(i).deq.ready := Mux(!ar_locked, (ar_grant_val === i.U) && ar_grant_found && master.ar.ready, (selected_master_ar === i.U) && master.ar.ready)

  val r_route_fifo = Module(new Queue(UInt(masterWidth.W), fifoDepth * numMasters))

  val ar_fire = Wire(Bool())
  ar_fire := false.B
  for (i <- 0 until numMasters)
    when(ar_fifos(i).deq.ready && ar_fifos(i).deq.valid) {
      ar_fire := true.B
    }

  val ar_fire_id = Wire(UInt(masterWidth.W))
  ar_fire_id := 0.U
  for (i <- 0 until numMasters)
    when(ar_fifos(i).deq.ready && ar_fifos(i).deq.valid) {
      ar_fire_id := ar_fifos(i).deq.bits.master_id
    }

  r_route_fifo.io.enq.valid := ar_fire
  r_route_fifo.io.enq.bits  := ar_fire_id

  r_route_fifo.io.deq.ready := master.r.valid &&
    slaves(r_route_fifo.io.deq.bits).r.ready

  for (i <- 0 until numMasters) {
    slaves(i).r.valid := master.r.valid &&
      r_route_fifo.io.deq.valid &&
      (r_route_fifo.io.deq.bits === i.U)
    slaves(i).r.bits  := master.r.bits
  }

  master.r.ready := r_route_fifo.io.deq.valid &&
    slaves(r_route_fifo.io.deq.bits).r.ready

  master_ext.connect(master)
  for (i <- 0 until numMasters)
    slaves_ext(i).connect(slaves(i))
}

object AXILiteArbiter {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    numMasters: Int,
    fifoDepth: Int = 4
  ): AXILiteArbiter =
    Module(new AXILiteArbiter(addrWidth, dataWidth, numMasters, fifoDepth))
}

object TestAXILiteArbiter extends App {
  VerilogEmitter.parse(
    new AXILiteArbiter(
      addrWidth = 32,
      dataWidth = 32,
      numMasters = 4,
      fifoDepth = 4
    ),
    "axilite_arbiter.sv",
    info = true
  )
}
