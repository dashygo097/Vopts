package com.amba

import utils._
import chisel3._

class AXIFull2LiteBridgeNoBurst(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Module {
  override def desiredName: String =
    s"axifull2lite_no_burst_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val ext_slave = IO(new AXIFullSlaveExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val slave     = Wire(AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth))

  val ext_master = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val master     = Wire(AXILiteMasterIO(addrWidth, dataWidth))

  // Unsupported feature detection registers
  val unsupportedWrite      = WireDefault(false.B)
  val unsupportedWriteBurst = WireDefault(false.B)
  val unsupportedWriteLen   = WireDefault(false.B)
  val unsupportedWriteID    = WireDefault(false.B)
  val unsupportedWriteUser  = WireDefault(false.B)

  val unsupportedRead      = WireDefault(false.B)
  val unsupportedReadBurst = WireDefault(false.B)
  val unsupportedReadLen   = WireDefault(false.B)
  val unsupportedReadID    = WireDefault(false.B)
  val unsupportedReadUser  = WireDefault(false.B)

  // Check for unsupported features
  unsupportedWriteBurst := slave.aw.valid && slave.aw.bits.burst =/= AXIBurstType.INCR
  unsupportedWriteLen   := slave.aw.valid && slave.aw.bits.len =/= 0.U
  unsupportedWriteID    := slave.aw.valid && slave.aw.bits.id =/= 0.U
  unsupportedWriteUser  := slave.aw.valid && slave.aw.bits.user =/= 0.U
  unsupportedWrite      := unsupportedWriteBurst || unsupportedWriteLen || unsupportedWriteID || unsupportedWriteUser

  unsupportedReadBurst := slave.ar.valid && slave.ar.bits.burst =/= AXIBurstType.INCR
  unsupportedReadLen   := slave.ar.valid && slave.ar.bits.len =/= 0.U
  unsupportedReadID    := slave.ar.valid && slave.ar.bits.id =/= 0.U
  unsupportedReadUser  := slave.ar.valid && slave.ar.bits.user =/= 0.U
  unsupportedRead      := unsupportedReadBurst || unsupportedReadLen || unsupportedReadID || unsupportedReadUser

  // Write Address Channel
  master.aw.bits.addr := slave.aw.bits.addr
  master.aw.bits.prot := slave.aw.bits.prot
  master.aw.valid     := slave.aw.valid && !unsupportedWrite
  slave.aw.ready      := master.aw.ready && !unsupportedWrite

  // Write Data Channel
  master.w.bits.data := slave.w.bits.data
  master.w.bits.strb := slave.w.bits.strb
  master.w.valid     := slave.w.valid && !unsupportedWrite
  slave.w.ready      := master.w.ready && !unsupportedWrite

  // Write Response Channel
  slave.b.bits.resp := Mux(unsupportedWrite, 3.U, master.b.bits.resp) // DECERR if unsupported
  slave.b.bits.id   := 0.U
  slave.b.bits.user := 0.U
  slave.b.valid     := master.b.valid || (slave.aw.valid && slave.w.valid && unsupportedWrite)
  master.b.ready    := slave.b.ready && !unsupportedWrite

  // Read Address Channel
  master.ar.bits.addr := slave.ar.bits.addr
  master.ar.bits.prot := slave.ar.bits.prot
  master.ar.valid     := slave.ar.valid && !unsupportedRead
  slave.ar.ready      := master.ar.ready && !unsupportedRead

  // Read Data Channel
  slave.r.bits.data := Mux(unsupportedRead, 0.U, master.r.bits.data)
  slave.r.bits.resp := Mux(unsupportedRead, 3.U, master.r.bits.resp) // DECERR if unsupported
  slave.r.bits.last := true.B
  slave.r.bits.id   := 0.U
  slave.r.bits.user := 0.U
  slave.r.valid     := master.r.valid || (slave.ar.valid && unsupportedRead)
  master.r.ready    := slave.r.ready && !unsupportedRead

  ext_slave.connect(slave)
  ext_master.connect(master)

  def connect(intf: AXIFullMasterExternalIO): Unit = intf <> ext_slave
  def connect(intf: AXILiteSlaveExternalIO): Unit  = intf <> ext_master
}

object AXIFull2LiteBridgeNoBurst {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    userWidth: Int = 0
  ): AXIFull2LiteBridgeNoBurst =
    Module(new AXIFull2LiteBridgeNoBurst(addrWidth, dataWidth, idWidth, userWidth))
}

object TestAXIFull2LiteBridgeNoBurst extends App {
  VerilogEmitter.parse(
    new AXIFull2LiteBridgeNoBurst(32, 32, 4, 1),
    "axifull2lite_bridge_no_burst.sv",
    info = true
  )
}
