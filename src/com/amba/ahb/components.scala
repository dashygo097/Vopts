package com.amba

import chisel3._

class AHBHRBusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val rdata = Input(UInt(dataWidth.W))
  val ready = Input(Bool())
  val resp  = Input(Bool())

  override def clone =
    new AHBHRBusIO(addrWidth, dataWidth).asInstanceOf[this.type]
}

class AHBHWBusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr     = Output(UInt(addrWidth.W))
  val wdata    = Output(UInt(dataWidth.W))
  val write    = Output(Bool())
  val size     = Output(UInt(3.W))
  val burst    = Output(UInt(3.W))
  val prot     = Output(UInt(4.W))
  val trans    = Output(UInt(2.W))
  val mastlock = Output(Bool())

  override def clone =
    new AHBHWBusIO(addrWidth, dataWidth).asInstanceOf[this.type]
}

object AHBHRBusIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBHRBusIO = new AHBHRBusIO(addrWidth, dataWidth)
}

object AHBHWBusIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBHWBusIO = new AHBHWBusIO(addrWidth, dataWidth)
}
