package com.axi

import chisel3._
import chisel3.util._

class AXIFullSlaveIO(dataWidth: Int, addrWidth: Int) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aw = Flipped(Decoupled(new AXIFullAddrIO(addrWidth)))
  val w  = Flipped(Decoupled(new AXIFullWriteIO(dataWidth)))
  val b  = Decoupled(new AXIFullWriteRespIO())
  val ar = Flipped(Decoupled(new AXIFullAddrIO(addrWidth)))
  val r  = Decoupled(new AXIFullReadIO(dataWidth))

  override def clone = { new AXIFullSlaveIO(addrWidth, dataWidth).asInstanceOf[this.type] }

}

object AXIFullSlaveIO {
  def apply(dataWidth: Int, addrWidth: Int): AXIFullSlaveIO = new AXIFullSlaveIO(dataWidth, addrWidth)
}

class AXIFullSlaveExternalIO(dataWidth: Int, addrWidth: Int) extends Bundle {
  val AWADDR   = Input(UInt(addrWidth.W))
  val AWPROT   = Input(UInt(3.W))
  val AWVALID  = Input(Bool())
  val AWREADY  = Output(Bool())
  val AWID     = Input(UInt(4.W))
  val AWLEN    = Input(UInt(8.W))
  val AWSIZE   = Input(UInt(3.W))
  val AWBURST  = Input(UInt(2.W))
  val AWLOCK   = Input(Bool())
  val AWCACHE  = Input(UInt(4.W))
  val AWQOS    = Input(UInt(4.W))
  val AWREGION = Input(UInt(4.W))
  val AWUSER   = Input(UInt(1.W))

  val WDATA  = Input(UInt(dataWidth.W))
  val WSTRB  = Input(UInt((dataWidth / 8).W))
  val WVALID = Input(Bool())
  val WREADY = Output(Bool())
  val WLAST  = Input(Bool())
  val WID    = Input(UInt(4.W))
  val WUSER  = Input(UInt(1.W))

  val BREADY = Input(Bool())
  val BRESP  = Output(UInt(2.W))
  val BVALID = Output(Bool())
  val BID    = Output(UInt(4.W))
  val BUSER  = Output(UInt(1.W))

  val ARADDR   = Input(UInt(addrWidth.W))
  val ARPROT   = Input(UInt(3.W))
  val ARVALID  = Input(Bool())
  val ARREADY  = Output(Bool())
  val ARID     = Input(UInt(4.W))
  val ARLEN    = Input(UInt(8.W))
  val ARSIZE   = Input(UInt(3.W))
  val ARBURST  = Input(UInt(2.W))
  val ARLOCK   = Input(Bool())
  val ARCACHE  = Input(UInt(4.W))
  val ARQOS    = Input(UInt(4.W))
  val ARREGION = Input(UInt(4.W))
  val ARUSER   = Input(UInt(1.W))

  val RREADY = Input(Bool())
  val RDATA  = Output(UInt(dataWidth.W))
  val RRESP  = Output(UInt(2.W))
  val RVALID = Output(Bool())
  val RLAST  = Output(Bool())
  val RID    = Output(UInt(4.W))
  val RUSER  = Output(UInt(1.W))

  def connect(intf: AXIFullSlaveIO): Unit = {
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
    intf.b.valid := this.BVALID
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
