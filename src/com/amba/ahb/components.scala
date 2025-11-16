package com.ahb

import chisel3._

class AHBHRBusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val hrdata = Input(UInt(dataWidth.W))
  val hready = Input(Bool())
  val hresp  = Input(Bool())
}

class AHBHWBusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val haddr     = Output(UInt(addrWidth.W))
  val hwdata    = Output(UInt(dataWidth.W))
  val hwrite    = Output(Bool())
  val hsize     = Output(UInt(3.W))
  val hburst    = Output(UInt(3.W))
  val hprot     = Output(UInt(4.W))
  val htrans    = Output(UInt(2.W))
  val hmastlock = Output(Bool())
}

object AHBHRBusIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBHRBusIO = new AHBHRBusIO(addrWidth, dataWidth)
}

object AHBHWBusIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBHWBusIO = new AHBHWBusIO(addrWidth, dataWidth)
}
