package com.axi

import utils._
import chisel3._

class AXIFull2LiteBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Module {
  override def desiredName: String =
    s"axi_full2lite_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave  = IO(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val master = IO(new AXILiteMasterIO(addrWidth, dataWidth)).suggestName("M_AXI")

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
  unsupportedWriteBurst := slave.aw.valid && slave.aw.bits.burst =/= 1.U
  unsupportedWriteLen   := slave.aw.valid && slave.aw.bits.len =/= 0.U
  unsupportedWriteID    := slave.aw.valid && slave.aw.bits.id =/= 0.U
  unsupportedWriteUser  := slave.aw.valid && slave.aw.bits.user =/= 0.U
  unsupportedWrite      := unsupportedWriteBurst || unsupportedWriteLen || unsupportedWriteID || unsupportedWriteUser

  unsupportedReadBurst := slave.ar.valid && slave.ar.bits.burst =/= 1.U
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

  def connect(intf: AXIFullMasterExternalIO): Unit = {
    slave.aw.bits.addr   := intf.AWADDR
    slave.aw.bits.prot   := intf.AWPROT
    slave.aw.bits.len    := intf.AWLEN
    slave.aw.bits.size   := intf.AWSIZE
    slave.aw.bits.burst  := intf.AWBURST
    slave.aw.bits.lock   := intf.AWLOCK
    slave.aw.bits.cache  := intf.AWCACHE
    slave.aw.bits.qos    := intf.AWQOS
    slave.aw.bits.region := intf.AWREGION
    slave.aw.bits.id     := intf.AWID
    slave.aw.bits.user   := intf.AWUSER
    slave.aw.valid       := intf.AWVALID
    intf.AWREADY         := slave.aw.ready
    slave.w.bits.data    := intf.WDATA
    slave.w.bits.strb    := intf.WSTRB
    slave.w.bits.last    := intf.WLAST
    slave.w.bits.id      := intf.WID
    slave.w.bits.user    := intf.WUSER
    slave.w.valid        := intf.WVALID
    intf.WREADY          := slave.w.ready
    intf.BRESP           := slave.b.bits.resp
    intf.BID             := slave.b.bits.id
    intf.BUSER           := slave.b.bits.user
    intf.BVALID          := slave.b.valid
    slave.b.ready        := intf.BREADY
    slave.ar.bits.addr   := intf.ARADDR
    slave.ar.bits.prot   := intf.ARPROT
    slave.ar.bits.len    := intf.ARLEN
    slave.ar.bits.size   := intf.ARSIZE
    slave.ar.bits.burst  := intf.ARBURST
    slave.ar.bits.lock   := intf.ARLOCK
    slave.ar.bits.cache  := intf.ARCACHE
    slave.ar.bits.qos    := intf.ARQOS
    slave.ar.bits.region := intf.ARREGION
    slave.ar.bits.id     := intf.ARID
    slave.ar.bits.user   := intf.ARUSER
    slave.ar.valid       := intf.ARVALID
    intf.ARREADY         := slave.ar.ready
    intf.RDATA           := slave.r.bits.data
    intf.RRESP           := slave.r.bits.resp
    intf.RLAST           := slave.r.bits.last
    intf.RID             := slave.r.bits.id
    intf.RUSER           := slave.r.bits.user
    intf.RVALID          := slave.r.valid
    slave.r.ready        := intf.RREADY
  }

  def connect(intf: AXIFullMasterIO): Unit =
    slave <> intf

  def connect(intf: AXILiteSlaveExternalIO): Unit = {
    intf.AWADDR        := master.aw.bits.addr
    intf.AWPROT        := master.aw.bits.prot
    intf.AWVALID       := master.aw.valid
    master.aw.ready    := intf.AWREADY
    intf.WDATA         := master.w.bits.data
    intf.WSTRB         := master.w.bits.strb
    intf.WVALID        := master.w.valid
    master.w.ready     := intf.WREADY
    master.b.bits.resp := intf.BRESP
    intf.BVALID        := master.b.valid
    master.b.ready     := intf.BREADY
    intf.ARADDR        := master.ar.bits.addr
    intf.ARPROT        := master.ar.bits.prot
    intf.ARVALID       := master.ar.valid
    master.ar.ready    := intf.ARREADY
    master.r.bits.data := intf.RDATA
    master.r.bits.resp := intf.RRESP
    intf.RVALID        := master.r.valid
    master.r.ready     := intf.RREADY
  }

  def connect(intf: AXILiteMasterIO): Unit =
    master <> intf
}

object AXIFull2LiteBridge {
  def apply(
    addrWidth: Int,
    dataWidth: Int,
    idWidth: Int,
    userWidth: Int = 0
  ): AXIFull2LiteBridge =
    Module(new AXIFull2LiteBridge(addrWidth, dataWidth, idWidth, userWidth))
}


object TestAXIFull2LiteBridge extends App {
  VerilogEmitter.parse(new AXIFull2LiteBridge(32, 32, 4, 1), "axi_full_to_lite_bridge.sv", info=true)
}

