package com.axi

import chisel3._
import chisel3.util._

class AXILiteMasterIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aWidth = addrWidth
  val dWidth = dataWidth

  val aw = Decoupled(new AXILiteAddrIO(addrWidth))
  val w  = Decoupled(new AXILiteWriteIO(dataWidth))
  val b  = Flipped(Decoupled(new AXILiteWriteRespIO))
  val ar = Decoupled(new AXILiteAddrIO(addrWidth))
  val r  = Flipped(Decoupled(new AXILiteReadIO(dataWidth)))

  override def clone = new AXILiteMasterIO(dataWidth, addrWidth).asInstanceOf[this.type]
}

object AXILiteMasterIO {
  def apply(addrWidth: Int, dataWidth: Int): AXILiteMasterIO =
    new AXILiteMasterIO(addrWidth, dataWidth)
}

class AXILiteMasterExternalIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val AWADDR  = Output(UInt(addrWidth.W))
  val AWPROT  = Output(UInt(3.W))
  val AWVALID = Output(Bool())
  val AWREADY = Input(Bool())

  val WDATA  = Output(UInt(dataWidth.W))
  val WSTRB  = Output(UInt((dataWidth / 8).W))
  val WVALID = Output(Bool())
  val WREADY = Input(Bool())

  val BRESP  = Input(UInt(2.W))
  val BVALID = Input(Bool())
  val BREADY = Output(Bool())

  val ARADDR  = Output(UInt(addrWidth.W))
  val ARPROT  = Output(UInt(3.W))
  val ARVALID = Output(Bool())
  val ARREADY = Input(Bool())

  val RDATA  = Input(UInt(dataWidth.W))
  val RRESP  = Input(UInt(2.W))
  val RVALID = Input(Bool())
  val RREADY = Output(Bool())

  def connect(intf: AXILiteMasterIO): Unit = {
    require(intf.aWidth == addrWidth, "Address width mismatch")
    require(intf.dWidth == dataWidth, "Data width mismatch")

    this.AWADDR   := intf.aw.bits.addr
    this.AWPROT   := intf.aw.bits.prot
    this.AWVALID  := intf.aw.valid
    intf.aw.ready := this.AWREADY

    this.WDATA   := intf.w.bits.data
    this.WSTRB   := intf.w.bits.strb
    this.WVALID  := intf.w.valid
    intf.w.ready := this.WREADY

    intf.b.bits  := this.BRESP
    intf.b.valid := this.BVALID
    this.BREADY  := intf.b.ready

    this.ARADDR   := intf.ar.bits.addr
    this.ARPROT   := intf.ar.bits.prot
    this.ARVALID  := intf.ar.valid
    intf.ar.ready := this.ARREADY

    intf.r.bits.data := this.RDATA
    intf.r.bits.resp := this.RRESP
    intf.r.valid     := this.RVALID
    this.RREADY      := intf.r.ready
  }
}
