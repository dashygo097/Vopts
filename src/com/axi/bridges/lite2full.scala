package com.axi

import chisel3._
import chisel3.util._

class AXILite2FullBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Module {
  override def desiredName: String =
    s"axi_lite2full_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val slave  = IO(new AXILiteSlaveIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val master =
    IO(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("M_AXI")

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

  def connect(intf: AXILiteMasterExternalIO): Unit = {
    intf.AWADDR       := slave.aw.bits.addr
    intf.AWPROT       := slave.aw.bits.prot
    intf.AWVALID      := slave.aw.valid
    slave.aw.ready    := intf.AWREADY
    intf.WDATA        := slave.w.bits.data
    intf.WSTRB        := slave.w.bits.strb
    intf.WVALID       := slave.w.valid
    slave.w.ready     := intf.WREADY
    slave.b.bits.resp := intf.BRESP
    intf.BVALID       := slave.b.valid
    slave.b.ready     := intf.BREADY
    intf.ARADDR       := slave.ar.bits.addr
    intf.ARPROT       := slave.ar.bits.prot
    intf.ARVALID      := slave.ar.valid
    slave.ar.ready    := intf.ARREADY
    intf.RDATA        := slave.r.bits.data
    intf.RRESP        := slave.r.bits.resp
    intf.RVALID       := slave.r.valid
    slave.r.ready     := intf.RREADY
  }

  def connect(intf: AXILiteMasterIO): Unit =
    slave <> intf

  def connect(intf: AXIFullSlaveExternalIO): Unit = {
    intf.AWADDR        := master.aw.bits.addr
    intf.AWPROT        := master.aw.bits.prot
    intf.AWLEN         := master.aw.bits.len
    intf.AWSIZE        := master.aw.bits.size
    intf.AWBURST       := master.aw.bits.burst
    intf.AWLOCK        := master.aw.bits.lock
    intf.AWCACHE       := master.aw.bits.cache
    intf.AWQOS         := master.aw.bits.qos
    intf.AWREGION      := master.aw.bits.region
    intf.AWID          := master.aw.bits.id
    intf.AWUSER        := master.aw.bits.user
    intf.AWVALID       := master.aw.valid
    master.aw.ready    := intf.AWREADY
    intf.WDATA         := master.w.bits.data
    intf.WSTRB         := master.w.bits.strb
    intf.WLAST         := master.w.bits.last
    intf.WID           := master.w.bits.id
    intf.WUSER         := master.w.bits.user
    intf.WVALID        := master.w.valid
    master.w.ready     := intf.WREADY
    master.b.bits.resp := intf.BRESP
    master.b.bits.id   := intf.BID
    master.b.bits.user := intf.BUSER
    master.b.valid     := intf.BVALID
    intf.BREADY        := master.b.ready
    intf.ARADDR        := master.ar.bits.addr
    intf.ARPROT        := master.ar.bits.prot
    intf.ARLEN         := master.ar.bits.len
    intf.ARSIZE        := master.ar.bits.size
    intf.ARBURST       := master.ar.bits.burst
    intf.ARLOCK        := master.ar.bits.lock
    intf.ARCACHE       := master.ar.bits.cache
    intf.ARQOS         := master.ar.bits.qos
    intf.ARREGION      := master.ar.bits.region
    intf.ARID          := master.ar.bits.id
    intf.ARUSER        := master.ar.bits.user
    intf.ARVALID       := master.ar.valid
    master.ar.ready    := intf.ARREADY
    master.r.bits.data := intf.RDATA
    master.r.bits.resp := intf.RRESP
    master.r.bits.last := intf.RLAST
    master.r.bits.id   := intf.RID
    master.r.bits.user := intf.RUSER
    master.r.valid     := intf.RVALID
    intf.RREADY        := master.r.ready
  }

  def connect(intf: AXIFullSlaveIO): Unit =
    master <> intf
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
