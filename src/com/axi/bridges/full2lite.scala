package com.axi

import chisel3._

class AXIFull2LiteBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Module {
  override def desiredName: String =
    s"axi_full2lite_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val full = IO(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val lite = IO(new AXILiteMasterIO(addrWidth, dataWidth)).suggestName("M_AXI")

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
  unsupportedWriteBurst := full.aw.valid && full.aw.bits.burst =/= 1.U
  unsupportedWriteLen   := full.aw.valid && full.aw.bits.len =/= 0.U
  unsupportedWriteID    := full.aw.valid && full.aw.bits.id =/= 0.U
  unsupportedWriteUser  := full.aw.valid && full.aw.bits.user =/= 0.U
  unsupportedWrite      := unsupportedWriteBurst || unsupportedWriteLen || unsupportedWriteID || unsupportedWriteUser

  unsupportedReadBurst := full.ar.valid && full.ar.bits.burst =/= 1.U
  unsupportedReadLen   := full.ar.valid && full.ar.bits.len =/= 0.U
  unsupportedReadID    := full.ar.valid && full.ar.bits.id =/= 0.U
  unsupportedReadUser  := full.ar.valid && full.ar.bits.user =/= 0.U
  unsupportedRead      := unsupportedReadBurst || unsupportedReadLen || unsupportedReadID || unsupportedReadUser

  // Write Address Channel
  lite.aw.bits.addr := full.aw.bits.addr
  lite.aw.bits.prot := full.aw.bits.prot
  lite.aw.valid     := full.aw.valid && !unsupportedWrite
  full.aw.ready     := lite.aw.ready && !unsupportedWrite

  // Write Data Channel
  lite.w.bits.data := full.w.bits.data
  lite.w.bits.strb := full.w.bits.strb
  lite.w.valid     := full.w.valid && !unsupportedWrite
  full.w.ready     := lite.w.ready && !unsupportedWrite

  // Write Response Channel
  full.b.bits.resp := Mux(unsupportedWrite, 3.U, lite.b.bits.resp) // DECERR if unsupported
  full.b.bits.id   := 0.U
  full.b.bits.user := 0.U
  full.b.valid     := lite.b.valid || (full.aw.valid && full.w.valid && unsupportedWrite)
  lite.b.ready     := full.b.ready && !unsupportedWrite

  // Read Address Channel
  lite.ar.bits.addr := full.ar.bits.addr
  lite.ar.bits.prot := full.ar.bits.prot
  lite.ar.valid     := full.ar.valid && !unsupportedRead
  full.ar.ready     := lite.ar.ready && !unsupportedRead

  // Read Data Channel
  full.r.bits.data := Mux(unsupportedRead, 0.U, lite.r.bits.data)
  full.r.bits.resp := Mux(unsupportedRead, 3.U, lite.r.bits.resp) // DECERR if unsupported
  full.r.bits.last := true.B
  full.r.bits.id   := 0.U
  full.r.bits.user := 0.U
  full.r.valid     := lite.r.valid || (full.ar.valid && unsupportedRead)
  lite.r.ready     := full.r.ready && !unsupportedRead
}

object AXIFull2LiteBridge {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXIFull2LiteBridge =
    new AXIFull2LiteBridge(addrWidth, dataWidth, idWidth, userWidth)
}
