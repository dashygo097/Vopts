package com.axi

import chisel3._
import chisel3.util._

class AXILiteSlaveIF(dataWidth: Int, addrWidth: Int) extends Bundle {
  val writeAddr   = Flipped(Decoupled(new AXILiteAddress(addrWidth)))

  val writeData   = Flipped(Decoupled(new AXILiteWriteData(dataWidth)))

  val writeResp   = Decoupled(UInt(2.W))
  
  val readAddr    = Flipped(Decoupled(new AXILiteAddress(addrWidth)))

  val readData    = Decoupled(new AXILiteReadData(dataWidth))
  
  override def clone = { new AXILiteSlaveIF(dataWidth, addrWidth).asInstanceOf[this.type] }
}

object AXILiteSlaveIF {
  def apply(dataWidth: Int, addrWidth: Int): AXILiteSlaveIF = {
    val axi = new AXILiteSlaveIF(dataWidth, addrWidth)
    axi
  }
}


class AXILiteExternalIF(dataWidth: Int, addrWidth: Int) extends Bundle {
  val AWADDR  = Input(UInt(addrWidth.W))
  val AWPROT  = Input(UInt(3.W))
  val AWVALID = Input(Bool())
  val AWREADY = Output(Bool())

  val WDATA   = Input(UInt(dataWidth.W))
  val WSTRB   = Input(UInt((dataWidth / 8).W))
  val WVALID  = Input(Bool())
  val WREADY  = Output(Bool())

  val BRESP   = Output(UInt(2.W))
  val BVALID  = Output(Bool())
  val BREADY  = Input(Bool())

  val ARADDR  = Input(UInt(addrWidth.W))
  val ARPROT  = Input(UInt(3.W))
  val ARVALID = Input(Bool())
  val ARREADY = Output(Bool())

  val RDATA   = Output(UInt(dataWidth.W))
  val RRESP   = Output(UInt(2.W))
  val RVALID  = Output(Bool())
  val RREADY  = Input(Bool())

  def connect(inst: AXILiteSlaveIF): Unit = {
    inst.writeAddr.bits.addr := this.AWADDR
    inst.writeAddr.bits.prot := this.AWPROT
    inst.writeAddr.valid := this.AWVALID
    this.AWREADY := inst.writeAddr.ready

    inst.writeData.bits.data := this.WDATA
    inst.writeData.bits.strb := this.WSTRB
    inst.writeData.valid := this.WVALID
    this.WREADY := inst.writeData.ready

    this.BRESP := inst.writeResp.bits
    this.BVALID := inst.writeResp.valid
    inst.writeResp.ready := this.BREADY

    inst.readAddr.bits.addr := this.ARADDR
    inst.readAddr.bits.prot := this.ARPROT
    inst.readAddr.valid := this.ARVALID
    this.ARREADY := inst.readAddr.ready

    this.RDATA := inst.readData.bits.data
    this.RRESP := inst.readData.bits.resp
    this.RVALID := inst.readData.valid
    inst.readData.ready := this.RREADY
  }
}
