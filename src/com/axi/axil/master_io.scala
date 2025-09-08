package com.axi

import chisel3._
import chisel3.util._

class AXILiteMasterIF(dataWidth: Int, addrWidth: Int) extends Bundle {  
  val writeAddr   = Decoupled(new AXILiteAddress(addrWidth))

  val writeData   = Decoupled(new AXILiteWriteData(dataWidth))

  val writeResp   = Flipped(Decoupled(UInt(2.W)))
  
  val readAddr    = Decoupled(new AXILiteAddress(addrWidth))

  val readData    = Flipped(Decoupled(new AXILiteReadData(dataWidth)))

  override def clone = { new AXILiteMasterIF(dataWidth, addrWidth).asInstanceOf[this.type] }
}

object AXILiteMasterIF {
 def apply(dataWidth: Int, addrWidth: Int): AXILiteMasterIF = {
   val axi = new AXILiteMasterIF(dataWidth, addrWidth)
   axi
 }
}

class AXILiteMasterExternalIF(dataWidth: Int, addrWidth: Int) extends Bundle {
  val AWADDR  = Output(UInt(addrWidth.W))
  val AWPROT  = Output(UInt(3.W))
  val AWVALID = Output(Bool())
  val AWREADY = Input(Bool())

  val WDATA   = Output(UInt(dataWidth.W))
  val WSTRB   = Output(UInt((dataWidth / 8).W))
  val WVALID  = Output(Bool())
  val WREADY  = Input(Bool())

  val BRESP   = Input(UInt(2.W))
  val BVALID  = Input(Bool())
  val BREADY  = Output(Bool())

  val ARADDR  = Output(UInt(addrWidth.W))
  val ARPROT  = Output(UInt(3.W))
  val ARVALID = Output(Bool())
  val ARREADY = Input(Bool())

  val RDATA   = Input(UInt(dataWidth.W))
  val RRESP   = Input(UInt(2.W))
  val RVALID  = Input(Bool())
  val RREADY  = Output(Bool())

  def connect(intf: AXILiteMasterIF): Unit = {
    this.AWADDR  := intf.writeAddr.bits.addr
    this.AWPROT  := intf.writeAddr.bits.prot
    this.AWVALID := intf.writeAddr.valid
    intf.writeAddr.ready := this.AWREADY

    this.WDATA   := intf.writeData.bits.data
    this.WSTRB   := intf.writeData.bits.strb
    this.WVALID  := intf.writeData.valid
    intf.writeData.ready := this.WREADY

    intf.writeResp.bits  := this.BRESP
    intf.writeResp.valid := this.BVALID
    this.BREADY := intf.writeResp.ready

    this.ARADDR  := intf.readAddr.bits.addr
    this.ARPROT  := intf.readAddr.bits.prot
    this.ARVALID := intf.readAddr.valid
    intf.readAddr.ready := this.ARREADY

    intf.readData.bits.data := this.RDATA
    intf.readData.bits.resp := this.RRESP
    intf.readData.valid     := this.RVALID
    this.RREADY := intf.readData.ready
  }
}
