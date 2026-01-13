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
    s"axilite_arbiter${numMasters}_${addrWidth}x${dataWidth}_d$fifoDepth"

  require(numMasters > 0, "Number of masters must be at least 1")
  require(fifoDepth > 0, "FIFO depth must be at least 1")

  val slaves_ext =
    IO(Vec(numMasters, new AXILiteSlaveExtIO(addrWidth, dataWidth))).suggestName("S_AXI")
  val slaves     = Wire(Vec(numMasters, AXILiteSlaveIO(addrWidth, dataWidth)))

  val master_ext = IO(new AXILiteMasterExtIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  dontTouch(slaves_ext)
  dontTouch(master_ext)

  // AW channel FIFOs
  class AWEntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val aw_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AWEntry, fifoDepth)).io))

  // W channel FIFOs
  class WEntry extends Bundle {
    val data      = UInt(dataWidth.W)
    val strb      = UInt((dataWidth / 8).W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val w_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new WEntry, fifoDepth)).io))

  // AR channel FIFOs
  class AREntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val ar_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AREntry, fifoDepth)).io))

  // Connect slaves to FIFOs
  for (i <- 0 until numMasters) {
    // AW channel
    aw_fifos(i).enq.valid          := slaves(i).aw.valid
    aw_fifos(i).enq.bits.addr      := slaves(i).aw.bits.addr
    aw_fifos(i).enq.bits.prot      := slaves(i).aw.bits.prot
    aw_fifos(i).enq.bits.master_id := i.U
    slaves(i).aw.ready             := aw_fifos(i).enq.ready

    // W channel
    w_fifos(i).enq.valid          := slaves(i).w.valid
    w_fifos(i).enq.bits.data      := slaves(i).w.bits.data
    w_fifos(i).enq.bits.strb      := slaves(i).w.bits.strb
    w_fifos(i).enq.bits.master_id := i.U
    slaves(i).w.ready             := w_fifos(i).enq.ready

    // AR channel
    ar_fifos(i).enq.valid          := slaves(i).ar.valid
    ar_fifos(i).enq.bits.addr      := slaves(i).ar.bits.addr
    ar_fifos(i).enq.bits.prot      := slaves(i).ar.bits.prot
    ar_fifos(i).enq.bits.master_id := i.U
    slaves(i).ar.ready             := ar_fifos(i).enq.ready
  }

  // Write Path Arbitration
  val selected_master_w = RegInit(0.U(log2Ceil(numMasters).W))
  val w_active          = RegInit(false.B)
  val aw_done           = RegInit(false.B)
  val w_done            = RegInit(false.B)

  val aw_fifo_valids = VecInit(aw_fifos.map(_.deq.valid))
  val w_fifo_valids  = VecInit(w_fifos.map(_.deq.valid))

  // Round-robin arbiter for write
  val aw_grant = Wire(UInt(log2Ceil(numMasters).W))

  when(!w_active) {
    aw_grant := PriorityMux(
      (0 until numMasters).map { i =>
        val idx = (selected_master_w + i.U) % numMasters.U
        (aw_fifo_valids(idx) || w_fifo_valids(idx), idx)
      }
    )
  }.otherwise {
    aw_grant := selected_master_w
  }

  // Write transaction control
  when(!w_active && (aw_fifo_valids.asUInt.orR || w_fifo_valids.asUInt.orR)) {
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
      selected_master_w := (selected_master_w + 1.U) % numMasters.U
    }
  }

  // AW channel from FIFO to master
  master.aw.valid     := w_active && !aw_done && aw_fifos(selected_master_w).deq.valid
  master.aw.bits.addr := aw_fifos(selected_master_w).deq.bits.addr
  master.aw.bits.prot := aw_fifos(selected_master_w).deq.bits.prot

  for (i <- 0 until numMasters)
    aw_fifos(i).deq.ready := w_active && !aw_done &&
      (selected_master_w === i.U) &&
      master.aw.ready

  // W channel from FIFO to master
  master.w.valid     := w_active && !w_done && w_fifos(selected_master_w).deq.valid
  master.w.bits.data := w_fifos(selected_master_w).deq.bits.data
  master.w.bits.strb := w_fifos(selected_master_w).deq.bits.strb

  for (i <- 0 until numMasters)
    w_fifos(i).deq.ready := w_active && !w_done &&
      (selected_master_w === i.U) &&
      master.w.ready

  // B channel response routing
  val b_route_fifo   = Module(new Queue(UInt(log2Ceil(numMasters).W), fifoDepth * numMasters))
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

  // Read Path Arbitration
  val selected_master_ar = RegInit(0.U(log2Ceil(numMasters).W))
  val ar_locked          = RegInit(false.B)

  val ar_fifo_valids = VecInit(ar_fifos.map(_.deq.valid))

  val ar_grant = Wire(UInt(log2Ceil(numMasters).W))

  when(!ar_locked) {
    ar_grant := PriorityMux(
      (0 until numMasters).map { i =>
        val idx = (selected_master_ar + i.U) % numMasters.U
        (ar_fifo_valids(idx), idx)
      }
    )
  }.otherwise {
    ar_grant := selected_master_ar
  }

  when(!ar_locked && ar_fifo_valids(ar_grant) && master.ar.ready) {
    ar_locked          := true.B
    selected_master_ar := ar_grant
  }.elsewhen(ar_locked && master.r.valid && slaves(selected_master_ar).r.ready) {
    ar_locked          := false.B
    selected_master_ar := (selected_master_ar + 1.U) % numMasters.U
  }

  // AR channel from FIFO to master
  master.ar.valid     := ar_fifo_valids(ar_grant)
  master.ar.bits.addr := ar_fifos(ar_grant).deq.bits.addr
  master.ar.bits.prot := ar_fifos(ar_grant).deq.bits.prot

  for (i <- 0 until numMasters)
    ar_fifos(i).deq.ready := (ar_grant === i.U) && master.ar.ready

  // R channel response routing
  val r_route_fifo = Module(new Queue(UInt(log2Ceil(numMasters).W), fifoDepth * numMasters))

  r_route_fifo.io.enq.valid := ar_fifo_valids(ar_grant) && master.ar.ready
  r_route_fifo.io.enq.bits  := ar_fifos(ar_grant).deq.bits.master_id

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

  // Connect external interfaces
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
