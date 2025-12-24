package com.amba

import utils._
import chisel3._
import chisel3.util._

class AXILite2FullBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Module {
  override def desiredName: String =
    s"axilite2full_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave_ext = IO(new AXILiteSlaveExtIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val slave     = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  val master_ext = IO(new AXIFullMasterExtIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("M_AXI")
  val master     =
    Wire(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  // Write Address Channel
  master.aw.bits.addr   := slave.aw.bits.addr
  master.aw.bits.prot   := slave.aw.bits.prot
  master.aw.bits.id     := 0.U
  master.aw.bits.len    := 0.U // Single transfer
  master.aw.bits.size   := log2Ceil(dataWidth / 8).U
  master.aw.bits.burst  := 1.U // INCR burst type
  master.aw.bits.lock   := false.B
  master.aw.bits.cache  := 0.U
  master.aw.bits.qos    := 0.U
  master.aw.bits.region := 0.U
  master.aw.bits.user   := 0.U
  master.aw.valid       := slave.aw.valid
  slave.aw.ready        := master.aw.ready

  // Write Data Channel
  master.w.bits.data := slave.w.bits.data
  master.w.bits.strb := slave.w.bits.strb
  master.w.bits.last := true.B // Always last for single transfer
  master.w.bits.id   := 0.U
  master.w.bits.user := 0.U
  master.w.valid     := slave.w.valid
  slave.w.ready      := master.w.ready

  // Write Response Channel
  slave.b.bits.resp := master.b.bits.resp
  slave.b.valid     := master.b.valid
  master.b.ready    := slave.b.ready

  // Read Address Channel
  master.ar.bits.addr   := slave.ar.bits.addr
  master.ar.bits.prot   := slave.ar.bits.prot
  master.ar.bits.id     := 0.U
  master.ar.bits.len    := 0.U // Single transfer
  master.ar.bits.size   := log2Ceil(dataWidth / 8).U
  master.ar.bits.burst  := 1.U // INCR burst type
  master.ar.bits.lock   := false.B
  master.ar.bits.cache  := 0.U
  master.ar.bits.qos    := 0.U
  master.ar.bits.region := 0.U
  master.ar.bits.user   := 0.U
  master.ar.valid       := slave.ar.valid
  slave.ar.ready        := master.ar.ready

  // Read Data Channel
  slave.r.bits.data := master.r.bits.data
  slave.r.bits.resp := master.r.bits.resp
  slave.r.valid     := master.r.valid
  master.r.ready    := slave.r.ready

  slave_ext.connect(slave)
  master_ext.connect(master)
}

object AXILite2FullBridge {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    userWidth: Int = 0
  ): AXILite2FullBridge =
    Module(new AXILite2FullBridge(addrWidth, dataWidth, idWidth, userWidth))
}

object TestAXILite2FullBridge extends App {
  VerilogEmitter.parse(
    new AXILite2FullBridge(32, 32, 4, 1),
    "axilite2full_bridge.sv",
    info = true
  )
}
