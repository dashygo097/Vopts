package com.axi

import chisel3._
import chisel3.util._

class AXIFullMasterIO(dataWidth: Int, addrWidth: Int) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aw = Decoupled(new AXIFullAddrIO(addrWidth))
  val w  = Decoupled(new AXIFullWriteIO(dataWidth))
  val b  = Flipped(Decoupled(new AXIFullWriteRespIO()))
  val ar = Decoupled(new AXIFullAddrIO(addrWidth))
  val r  = Flipped(Decoupled(new AXIFullReadIO(dataWidth)))

  override def clone = { new AXIFullMasterIO(addrWidth, dataWidth).asInstanceOf[this.type] }
}

object AXIFullMasterIO {
  def apply(dataWidth: Int, addrWidth: Int): AXIFullMasterIO = new AXIFullMasterIO(dataWidth, addrWidth)
}

class AXIFullMasterExternalIO(dataWidth: Int, addrWidth: Int) extends Bundle {
  val AWADDR   = Output(UInt(addrWidth.W))
  val AWPROT   = Output(UInt(3.W))
  val AWVALID  = Output(Bool())
  val AWREADY  = Input(Bool())
  val AWID     = Output(UInt(4.W))
  val AWLEN    = Output(UInt(8.W))
  val AWSIZE   = Output(UInt(3.W))
  val AWBURST  = Output(UInt(2.W))
  val AWLOCK   = Output(Bool())
  val AWCACHE  = Output(UInt(4.W))
  val AWQOS    = Output(UInt(4.W))
  val AWREGION = Output(UInt(4.W))
  val AWUSER   = Output(UInt(1.W))

  val WDATA  = Output(UInt(dataWidth.W))
  val WSTRB  = Output(UInt((dataWidth / 8).W))
  val WVALID = Output(Bool())
  val WREADY = Input(Bool())
  val WLAST  = Output(Bool())
  val WID    = Output(UInt(4.W))
  val WUSER  = Output(UInt(1.W))

  val BREADY = Output(Bool())
  val BRESP  = Input(UInt(2.W))
  val BVALID = Input(Bool())
  val BID    = Input(UInt(4.W))
  val BUSER  = Input(UInt(1.W))

  val ARADDR   = Output(UInt(addrWidth.W))
  val ARPROT   = Output(UInt(3.W))
  val ARVALID  = Output(Bool())
  val ARREADY  = Input(Bool())
  val ARID     = Output(UInt(4.W))
  val ARLEN    = Output(UInt(8.W))
  val ARSIZE   = Output(UInt(3.W))
  val ARBURST  = Output(UInt(2.W))
  val ARLOCK   = Output(Bool())
  val ARCACHE  = Output(UInt(4.W))
  val ARQOS    = Output(UInt(4.W))
  val ARREGION = Output(UInt(4.W))
  val ARUSER   = Output(UInt(1.W))

  val RREADY = Output(Bool())
  val RDATA  = Input(UInt(dataWidth.W))
  val RRESP  = Input(UInt(2.W))
  val RVALID = Input(Bool())
  val RLAST  = Input(Bool())
  val RID    = Input(UInt(4.W))
  val RUSER  = Input(UInt(1.W))

  def connect(intf: AXIFullMasterIO): Unit = {
    this.AWADDR   := intf.aw.bits.addr
    this.AWPROT   := intf.aw.bits.prot
    this.AWVALID  := intf.aw.valid
    intf.aw.ready := this.AWREADY
    this.AWID     := intf.aw.bits.id
    this.AWLEN    := intf.aw.bits.len
    this.AWSIZE   := intf.aw.bits.size
    this.AWBURST  := intf.aw.bits.burst
    this.AWLOCK   := intf.aw.bits.lock
    this.AWCACHE  := intf.aw.bits.cache
    this.AWQOS    := intf.aw.bits.qos
    this.AWREGION := intf.aw.bits.region
    this.AWUSER   := intf.aw.bits.user

    this.WDATA   := intf.w.bits.data
    this.WSTRB   := intf.w.bits.strb
    this.WVALID  := intf.w.valid
    intf.w.ready := this.WREADY
    this.WLAST   := intf.w.bits.last
    this.WID     := intf.w.bits.id
    this.WUSER   := intf.w.bits.user

    intf.b.bits.resp := this.BRESP
    intf.b.bits.id   := this.BID
    intf.b.bits.user := this.BUSER
    intf.b.valid     := this.BVALID
    this.BREADY      := intf.b.ready

    this.ARADDR   := intf.ar.bits.addr
    this.ARPROT   := intf.ar.bits.prot
    this.ARVALID  := intf.ar.valid
    intf.ar.ready := this.ARREADY
    this.ARID     := intf.ar.bits.id
    this.ARLEN    := intf.ar.bits.len
    this.ARSIZE   := intf.ar.bits.size
    this.ARBURST  := intf.ar.bits.burst
    this.ARLOCK   := intf.ar.bits.lock
    this.ARCACHE  := intf.ar.bits.cache
    this.ARQOS    := intf.ar.bits.qos
    this.ARREGION := intf.ar.bits.region
    this.ARUSER   := intf.ar.bits.user

    intf.r.bits.data := this.RDATA
    intf.r.bits.resp := this.RRESP
    intf.r.bits.last := this.RLAST
    intf.r.bits.id   := this.RID
    intf.r.bits.user := this.RUSER
    intf.r.valid     := this.RVALID
    this.RREADY      := intf.r.ready
  }
}


