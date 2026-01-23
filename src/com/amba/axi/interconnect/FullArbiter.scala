package vopts.com.amba

import vopts.utils._
import chisel3._
import chisel3.util._

class AXIFullArbiter(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  numMasters: Int,
  fifoDepth: Int = 4,
  userWidth: Int = 0
) extends Module {

  override def desiredName: String =
    s"axifull_arbiter${numMasters}_${addrWidth}x${dataWidth}_id${idWidth}_d$fifoDepth"

  require(numMasters > 0, "Number of masters must be at least 1")
  require(fifoDepth > 0, "FIFO depth must be at least 1")
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slaves_ext = IO(Vec(numMasters, new AXIFullSlaveExtIO(addrWidth, dataWidth, idWidth, userWidth))).suggestName("S_AXI")
  val slaves     = Wire(Vec(numMasters, AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)))

  val master_ext = IO(new AXIFullMasterExtIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("M_AXI")
  val master     = Wire(AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  dontTouch(slaves_ext)
  dontTouch(master_ext)

  // AW channel FIFOs
  class AWEntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val id        = UInt(idWidth.W)
    val len       = UInt(8.W)
    val size      = UInt(3.W)
    val burst     = UInt(2.W)
    val lock      = Bool()
    val cache     = UInt(4.W)
    val qos       = UInt(4.W)
    val region    = UInt(4.W)
    val user      = UInt(userWidth.W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val aw_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AWEntry, fifoDepth)).io))

  // W channel FIFOs
  class WEntry extends Bundle {
    val data      = UInt(dataWidth.W)
    val strb      = UInt((dataWidth / 8).W)
    val last      = Bool()
    val id        = UInt(idWidth.W)
    val user      = UInt(userWidth.W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val w_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new WEntry, fifoDepth)).io))

  // AR channel FIFOs
  class AREntry extends Bundle {
    val addr      = UInt(addrWidth.W)
    val prot      = UInt(3.W)
    val id        = UInt(idWidth.W)
    val len       = UInt(8.W)
    val size      = UInt(3.W)
    val burst     = UInt(2.W)
    val lock      = Bool()
    val cache     = UInt(4.W)
    val qos       = UInt(4.W)
    val region    = UInt(4.W)
    val user      = UInt(userWidth.W)
    val master_id = UInt(log2Ceil(numMasters).W)
  }

  val ar_fifos = VecInit(Seq.fill(numMasters)(Module(new Queue(new AREntry, fifoDepth)).io))

  // Connect slaves to FIFOs
  for (i <- 0 until numMasters) {
    // AW channel
    aw_fifos(i).enq.valid          := slaves(i).aw.valid
    aw_fifos(i).enq.bits.addr      := slaves(i).aw.bits.addr
    aw_fifos(i).enq.bits.prot      := slaves(i).aw.bits.prot
    aw_fifos(i).enq.bits.id        := slaves(i).aw.bits.id
    aw_fifos(i).enq.bits.len       := slaves(i).aw.bits.len
    aw_fifos(i).enq.bits.size      := slaves(i).aw.bits.size
    aw_fifos(i).enq.bits.burst     := slaves(i).aw.bits.burst
    aw_fifos(i).enq.bits.lock      := slaves(i).aw.bits.lock
    aw_fifos(i).enq.bits.cache     := slaves(i).aw.bits.cache
    aw_fifos(i).enq.bits.qos       := slaves(i).aw.bits.qos
    aw_fifos(i).enq.bits.region    := slaves(i).aw.bits.region
    aw_fifos(i).enq.bits.user      := slaves(i).aw.bits.user
    aw_fifos(i).enq.bits.master_id := i.U
    slaves(i).aw.ready             := aw_fifos(i).enq.ready

    // W channel
    w_fifos(i).enq.valid          := slaves(i).w.valid
    w_fifos(i).enq.bits.data      := slaves(i).w.bits.data
    w_fifos(i).enq.bits.strb      := slaves(i).w.bits.strb
    w_fifos(i).enq.bits.last      := slaves(i).w.bits.last
    w_fifos(i).enq.bits.id        := slaves(i).w.bits.id
    w_fifos(i).enq.bits.user      := slaves(i).w.bits.user
    w_fifos(i).enq.bits.master_id := i.U
    slaves(i).w.ready             := w_fifos(i).enq.ready

    // AR channel
    ar_fifos(i).enq.valid          := slaves(i).ar.valid
    ar_fifos(i).enq.bits.addr      := slaves(i).ar.bits.addr
    ar_fifos(i).enq.bits.prot      := slaves(i).ar.bits.prot
    ar_fifos(i).enq.bits.id        := slaves(i).ar.bits.id
    ar_fifos(i).enq.bits.len       := slaves(i).ar.bits.len
    ar_fifos(i).enq.bits.size      := slaves(i).ar.bits.size
    ar_fifos(i).enq.bits.burst     := slaves(i).ar.bits.burst
    ar_fifos(i).enq.bits.lock      := slaves(i).ar.bits.lock
    ar_fifos(i).enq.bits.cache     := slaves(i).ar.bits.cache
    ar_fifos(i).enq.bits.qos       := slaves(i).ar.bits.qos
    ar_fifos(i).enq.bits.region    := slaves(i).ar.bits.region
    ar_fifos(i).enq.bits.user      := slaves(i).ar.bits.user
    ar_fifos(i).enq.bits.master_id := i.U
    slaves(i).ar.ready             := ar_fifos(i).enq.ready
  }

  // Write Path Arbitration
  val selected_master_w = RegInit(0.U(log2Ceil(numMasters).W))
  val w_active          = RegInit(false.B)
  val aw_done           = RegInit(false.B)
  val w_burst_count     = RegInit(0.U(9.W))
  val w_burst_len       = RegInit(0.U(8.W))

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
    w_burst_count     := 0.U
    w_burst_len       := 0.U
  }

  when(w_active) {
    when(!aw_done && aw_fifos(selected_master_w).deq.valid && master.aw.ready) {
      aw_done     := true.B
      w_burst_len := aw_fifos(selected_master_w).deq.bits.len
    }

    when(w_fifos(selected_master_w).deq.valid && master.w.ready) {
      w_burst_count := w_burst_count + 1.U
    }

    when(aw_done && w_burst_count === (w_burst_len + 1.U) && master.b.valid && slaves(selected_master_w).b.ready) {
      w_active          := false.B
      selected_master_w := (selected_master_w + 1.U) % numMasters.U
    }
  }

  // AW channel from FIFO to master
  master.aw.valid       := w_active && !aw_done && aw_fifos(selected_master_w).deq.valid
  master.aw.bits.addr   := aw_fifos(selected_master_w).deq.bits.addr
  master.aw.bits.prot   := aw_fifos(selected_master_w).deq.bits.prot
  master.aw.bits.id     := aw_fifos(selected_master_w).deq.bits.id
  master.aw.bits.len    := aw_fifos(selected_master_w).deq.bits.len
  master.aw.bits.size   := aw_fifos(selected_master_w).deq.bits.size
  master.aw.bits.burst  := aw_fifos(selected_master_w).deq.bits.burst
  master.aw.bits.lock   := aw_fifos(selected_master_w).deq.bits.lock
  master.aw.bits.cache  := aw_fifos(selected_master_w).deq.bits.cache
  master.aw.bits.qos    := aw_fifos(selected_master_w).deq.bits.qos
  master.aw.bits.region := aw_fifos(selected_master_w).deq.bits.region
  master.aw.bits.user   := aw_fifos(selected_master_w).deq.bits.user

  for (i <- 0 until numMasters)
    aw_fifos(i).deq.ready := w_active && !aw_done &&
      (selected_master_w === i.U) &&
      master.aw.ready

  // W channel from FIFO to master
  master.w.valid     := w_active && aw_done && w_fifos(selected_master_w).deq.valid
  master.w.bits.data := w_fifos(selected_master_w).deq.bits.data
  master.w.bits.strb := w_fifos(selected_master_w).deq.bits.strb
  master.w.bits.last := w_fifos(selected_master_w).deq.bits.last
  master.w.bits.id   := w_fifos(selected_master_w).deq.bits.id
  master.w.bits.user := w_fifos(selected_master_w).deq.bits.user

  for (i <- 0 until numMasters)
    w_fifos(i).deq.ready := w_active && aw_done &&
      (selected_master_w === i.U) &&
      master.w.ready

  // B channel response routing
  val b_route_fifo = Module(new Queue(UInt(log2Ceil(numMasters).W), fifoDepth * numMasters))

  b_route_fifo.io.enq.valid := w_active && !aw_done &&
    aw_fifos(selected_master_w).deq.valid && master.aw.ready
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
  val r_burst_count      = RegInit(0.U(9.W))
  val r_burst_len        = RegInit(0.U(8.W))

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
    r_burst_count      := 0.U
    r_burst_len        := ar_fifos(ar_grant).deq.bits.len
  }.elsewhen(ar_locked && master.r.valid && slaves(selected_master_ar).r.ready) {
    r_burst_count := r_burst_count + 1.U
    when(r_burst_count === r_burst_len && master.r.bits.last) {
      ar_locked          := false.B
      selected_master_ar := (selected_master_ar + 1.U) % numMasters.U
    }
  }

  // AR channel from FIFO to master
  master.ar.valid       := ar_fifo_valids(ar_grant)
  master.ar.bits.addr   := ar_fifos(ar_grant).deq.bits.addr
  master.ar.bits.prot   := ar_fifos(ar_grant).deq.bits.prot
  master.ar.bits.id     := ar_fifos(ar_grant).deq.bits.id
  master.ar.bits.len    := ar_fifos(ar_grant).deq.bits.len
  master.ar.bits.size   := ar_fifos(ar_grant).deq.bits.size
  master.ar.bits.burst  := ar_fifos(ar_grant).deq.bits.burst
  master.ar.bits.lock   := ar_fifos(ar_grant).deq.bits.lock
  master.ar.bits.cache  := ar_fifos(ar_grant).deq.bits.cache
  master.ar.bits.qos    := ar_fifos(ar_grant).deq.bits.qos
  master.ar.bits.region := ar_fifos(ar_grant).deq.bits.region
  master.ar.bits.user   := ar_fifos(ar_grant).deq.bits.user

  for (i <- 0 until numMasters)
    ar_fifos(i).deq.ready := (ar_grant === i.U) && master.ar.ready

  // R channel response routing
  val r_route_fifo = Module(new Queue(UInt(log2Ceil(numMasters).W), fifoDepth * numMasters))

  r_route_fifo.io.enq.valid := ar_fifo_valids(ar_grant) && master.ar.ready
  r_route_fifo.io.enq.bits  := ar_fifos(ar_grant).deq.bits.master_id

  r_route_fifo.io.deq.ready := master.r.valid &&
    slaves(r_route_fifo.io.deq.bits).r.ready &&
    master.r.bits.last

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

object AXIFullArbiter {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    numMasters: Int,
    fifoDepth: Int = 4,
    userWidth: Int = 0
  ): AXIFullArbiter =
    Module(new AXIFullArbiter(addrWidth, dataWidth, numMasters, fifoDepth, userWidth))
}

object TestAXIFullArbiter extends App {
  VerilogEmitter.parse(
    new AXIFullArbiter(
      addrWidth = 32,
      dataWidth = 32,
      idWidth = 4,
      numMasters = 4,
      fifoDepth = 4,
      userWidth = 0
    ),
    "axifull_arbiter.sv",
    info = true
  )
}
