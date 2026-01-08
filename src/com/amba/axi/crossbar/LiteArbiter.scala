package vopts.com.amba

import vopts.utils._
import chisel3._
import chisel3.util._

class AXILiteArbiter(
  addrWidth: Int,
  dataWidth: Int,
  numMasters: Int
) extends Module {
  override def desiredName: String =
    s"axilite_arbiter${numMasters}_${addrWidth}x$dataWidth"

  require(numMasters > 0, "Number of masters must be at least 1")

  val slaves_ext =
    IO(Vec(numMasters, new AXILiteSlaveExtIO(addrWidth, dataWidth))).suggestName("S_AXI")
  val slaves     = Wire(Vec(numMasters, AXILiteSlaveIO(addrWidth, dataWidth)))

  val master_ext = IO(new AXILiteMasterExtIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  // Arbitration state
  val selected_master_aw = RegInit(0.U(log2Ceil(numMasters).W))
  val selected_master_ar = RegInit(0.U(log2Ceil(numMasters).W))
  val aw_locked          = RegInit(false.B)
  val ar_locked          = RegInit(false.B)

  // Store the address for routing responses back
  val aw_addr_store = RegInit(0.U(addrWidth.W))
  val ar_addr_store = RegInit(0.U(addrWidth.W))

  // Round-robin arbiter for write address channel
  val aw_grant = Wire(UInt(log2Ceil(numMasters).W))
  val aw_reqs  = VecInit(slaves.map(_.aw.valid))

  when(!aw_locked) {
    aw_grant := PriorityMux(
      (0 until numMasters).map { i =>
        val idx = (selected_master_aw + i.U) % numMasters.U
        (aw_reqs(idx), idx)
      }
    )
  }.otherwise {
    aw_grant := selected_master_aw
  }

  // Round-robin arbiter for read address channel
  val ar_grant = Wire(UInt(log2Ceil(numMasters).W))
  val ar_reqs  = VecInit(slaves.map(_.ar.valid))

  when(!ar_locked) {
    ar_grant := PriorityMux(
      (0 until numMasters).map { i =>
        val idx = (selected_master_ar + i.U) % numMasters.U
        (ar_reqs(idx), idx)
      }
    )
  }.otherwise {
    ar_grant := selected_master_ar
  }

  // Write transaction locking logic
  when(!aw_locked && slaves(aw_grant).aw.valid && master.aw.ready) {
    aw_locked          := true.B
    selected_master_aw := aw_grant
    aw_addr_store      := slaves(aw_grant).aw.bits.addr
  }.elsewhen(aw_locked && master.b.valid && slaves(selected_master_aw).b.ready) {
    aw_locked          := false.B
    selected_master_aw := (selected_master_aw + 1.U) % numMasters.U
  }

  // Read transaction locking logic
  when(!ar_locked && slaves(ar_grant).ar.valid && master.ar.ready) {
    ar_locked          := true.B
    selected_master_ar := ar_grant
    ar_addr_store      := slaves(ar_grant).ar.bits.addr
  }.elsewhen(ar_locked && master.r.valid && slaves(selected_master_ar).r.ready) {
    ar_locked          := false.B
    selected_master_ar := (selected_master_ar + 1.U) % numMasters.U
  }

  // AW
  master.aw.valid := Mux(aw_locked, slaves(selected_master_aw).aw.valid, slaves(aw_grant).aw.valid)
  master.aw.bits  := Mux(aw_locked, slaves(selected_master_aw).aw.bits, slaves(aw_grant).aw.bits)

  for (i <- 0 until numMasters)
    slaves(i).aw.ready := Mux(
      aw_locked && (selected_master_aw === i.U),
      master.aw.ready,
      Mux(!aw_locked && (aw_grant === i.U), master.aw.ready, false.B)
    )

  // W
  master.w.valid := Mux(aw_locked, slaves(selected_master_aw).w.valid, false.B)
  master.w.bits  := Mux(aw_locked, slaves(selected_master_aw).w.bits, 0.U.asTypeOf(master.w.bits))

  for (i <- 0 until numMasters)
    slaves(i).w.ready := Mux(
      aw_locked && (selected_master_aw === i.U),
      master.w.ready,
      false.B
    )

  // B
  for (i <- 0 until numMasters) {
    slaves(i).b.valid := Mux(
      aw_locked && (selected_master_aw === i.U),
      master.b.valid,
      false.B
    )
    slaves(i).b.bits  := master.b.bits
  }

  master.b.ready := Mux(aw_locked, slaves(selected_master_aw).b.ready, false.B)

  // AR
  master.ar.valid := Mux(ar_locked, slaves(selected_master_ar).ar.valid, slaves(ar_grant).ar.valid)
  master.ar.bits  := Mux(ar_locked, slaves(selected_master_ar).ar.bits, slaves(ar_grant).ar.bits)

  for (i <- 0 until numMasters)
    slaves(i).ar.ready := Mux(
      ar_locked && (selected_master_ar === i.U),
      master.ar.ready,
      Mux(!ar_locked && (ar_grant === i.U), master.ar.ready, false.B)
    )

  // R
  for (i <- 0 until numMasters) {
    slaves(i).r.valid := Mux(
      ar_locked && (selected_master_ar === i.U),
      master.r.valid,
      false.B
    )
    slaves(i).r.bits  := master.r.bits
  }

  master.r.ready := Mux(ar_locked, slaves(selected_master_ar).r.ready, false.B)

  // Connect external interfaces
  master_ext.connect(master)
  for (i <- 0 until numMasters)
    slaves_ext(i).connect(slaves(i))
}

object AXILiteArbiter {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    numMasters: Int
  ): AXILiteArbiter =
    Module(new AXILiteArbiter(addrWidth, dataWidth, numMasters))
}

object TestAXILiteArbiter extends App {
  VerilogEmitter.parse(
    new AXILiteArbiter(
      addrWidth = 32,
      dataWidth = 32,
      numMasters = 4
    ),
    "axilite_arbiter.sv",
    info = true
  )
}
