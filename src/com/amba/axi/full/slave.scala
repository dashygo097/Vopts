package com.amba

import chisel3._
import chisel3.util._

class AXIFullSlaveIO(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aWidth = addrWidth
  val dWidth = dataWidth
  val iWidth = idWidth
  val uWidth = userWidth

  val aw = Flipped(Decoupled(new AXIFullAddrIO(addrWidth, idWidth, userWidth)))
  val w  = Flipped(Decoupled(new AXIFullWriteIO(dataWidth, idWidth, userWidth)))
  val b  = Decoupled(new AXIFullWriteRespIO(idWidth, userWidth))
  val ar = Flipped(Decoupled(new AXIFullAddrIO(addrWidth, idWidth, userWidth)))
  val r  = Decoupled(new AXIFullReadIO(dataWidth, idWidth, userWidth))

  override def clone =
    new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth).asInstanceOf[this.type]

}

object AXIFullSlaveIO {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXIFullSlaveIO =
    new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)
}

class AXIFullSlaveExternalIO(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Bundle {
  val AWADDR   = Input(UInt(addrWidth.W))
  val AWPROT   = Input(UInt(3.W))
  val AWVALID  = Input(Bool())
  val AWREADY  = Output(Bool())
  val AWID     = Input(UInt(idWidth.W))
  val AWLEN    = Input(UInt(8.W))
  val AWSIZE   = Input(UInt(3.W))
  val AWBURST  = Input(UInt(2.W))
  val AWLOCK   = Input(Bool())
  val AWCACHE  = Input(UInt(4.W))
  val AWQOS    = Input(UInt(4.W))
  val AWREGION = Input(UInt(4.W))
  val AWUSER   = Input(UInt(userWidth.W))

  val WDATA  = Input(UInt(dataWidth.W))
  val WSTRB  = Input(UInt((dataWidth / 8).W))
  val WVALID = Input(Bool())
  val WREADY = Output(Bool())
  val WLAST  = Input(Bool())
  val WID    = Input(UInt(idWidth.W))
  val WUSER  = Input(UInt(userWidth.W))

  val BREADY = Input(Bool())
  val BRESP  = Output(UInt(2.W))
  val BVALID = Output(Bool())
  val BID    = Output(UInt(idWidth.W))
  val BUSER  = Output(UInt(userWidth.W))

  val ARADDR   = Input(UInt(addrWidth.W))
  val ARPROT   = Input(UInt(3.W))
  val ARVALID  = Input(Bool())
  val ARREADY  = Output(Bool())
  val ARID     = Input(UInt(idWidth.W))
  val ARLEN    = Input(UInt(8.W))
  val ARSIZE   = Input(UInt(3.W))
  val ARBURST  = Input(UInt(2.W))
  val ARLOCK   = Input(Bool())
  val ARCACHE  = Input(UInt(4.W))
  val ARQOS    = Input(UInt(4.W))
  val ARREGION = Input(UInt(4.W))
  val ARUSER   = Input(UInt(userWidth.W))

  val RREADY = Input(Bool())
  val RDATA  = Output(UInt(dataWidth.W))
  val RRESP  = Output(UInt(2.W))
  val RVALID = Output(Bool())
  val RLAST  = Output(Bool())
  val RID    = Output(UInt(idWidth.W))
  val RUSER  = Output(UInt(userWidth.W))

  def connect(intf: AXIFullSlaveIO): Unit = {
    require(intf.aWidth == addrWidth, "Address width must match")
    require(intf.dWidth == dataWidth, "Data width must match")
    require(intf.iWidth == idWidth, "ID width must match")
    require(intf.uWidth == userWidth, "User width must match")

    intf.aw.bits.addr   := this.AWADDR
    intf.aw.bits.prot   := this.AWPROT
    intf.aw.valid       := this.AWVALID
    this.AWREADY        := intf.aw.ready
    intf.aw.bits.id     := this.AWID
    intf.aw.bits.len    := this.AWLEN
    intf.aw.bits.size   := this.AWSIZE
    intf.aw.bits.burst  := this.AWBURST
    intf.aw.bits.lock   := this.AWLOCK
    intf.aw.bits.cache  := this.AWCACHE
    intf.aw.bits.qos    := this.AWQOS
    intf.aw.bits.region := this.AWREGION
    intf.aw.bits.user   := this.AWUSER

    intf.w.bits.data := this.WDATA
    intf.w.bits.strb := this.WSTRB
    intf.w.valid     := this.WVALID
    this.WREADY      := intf.w.ready
    intf.w.bits.last := this.WLAST
    intf.w.bits.id   := this.WID
    intf.w.bits.user := this.WUSER

    this.BRESP   := intf.b.bits.resp
    this.BID     := intf.b.bits.id
    this.BUSER   := intf.b.bits.user
    this.BVALID  := intf.b.valid
    intf.b.ready := this.BREADY

    intf.ar.bits.addr   := this.ARADDR
    intf.ar.bits.prot   := this.ARPROT
    intf.ar.valid       := this.ARVALID
    this.ARREADY        := intf.ar.ready
    intf.ar.bits.id     := this.ARID
    intf.ar.bits.len    := this.ARLEN
    intf.ar.bits.size   := this.ARSIZE
    intf.ar.bits.burst  := this.ARBURST
    intf.ar.bits.lock   := this.ARLOCK
    intf.ar.bits.cache  := this.ARCACHE
    intf.ar.bits.qos    := this.ARQOS
    intf.ar.bits.region := this.ARREGION
    intf.ar.bits.user   := this.ARUSER

    this.RDATA   := intf.r.bits.data
    this.RRESP   := intf.r.bits.resp
    this.RLAST   := intf.r.bits.last
    this.RID     := intf.r.bits.id
    this.RUSER   := intf.r.bits.user
    this.RVALID  := intf.r.valid
    intf.r.ready := this.RREADY
  }
}
