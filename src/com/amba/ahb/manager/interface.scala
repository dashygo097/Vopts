package com.ahb

import chisel3._

class AHBManagerIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val hrBus = AHBHRBusIO(addrWidth, dataWidth)
  val hwBus = AHBHWBusIO(addrWidth, dataWidth)

  override def clone =
    new AHBManagerIO(addrWidth, dataWidth).asInstanceOf[this.type]
}

object AHBManagerIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBManagerIO =
    new AHBManagerIO(addrWidth, dataWidth)
}

class AHBManagerExternalIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val M_AHB_HREADY = Input(Bool())
  val M_AHB_HRESP  = Input(Bool())
  val M_AHB_HRDATA = Input(UInt(dataWidth.W))

  val M_AHB_HADDR     = Output(UInt(addrWidth.W))
  val M_AHB_HTRANS    = Output(UInt(2.W))
  val M_AHB_HWRITE    = Output(Bool())
  val M_AHB_HSIZE     = Output(UInt(3.W))
  val M_AHB_HBURST    = Output(UInt(3.W))
  val M_AHB_HPROT     = Output(UInt(4.W))
  val M_AHB_HWDATA    = Output(UInt(dataWidth.W))
  val M_AHB_HMASTLOCK = Output(Bool())

  def connect(intf: AHBManagerIO): Unit = {
    intf.hrBus.hready := M_AHB_HREADY
    intf.hrBus.hresp  := M_AHB_HRESP
    intf.hrBus.hrdata := M_AHB_HRDATA

    M_AHB_HADDR     := intf.hwBus.haddr
    M_AHB_HTRANS    := intf.hwBus.htrans
    M_AHB_HWRITE    := intf.hwBus.hwrite
    M_AHB_HSIZE     := intf.hwBus.hsize
    M_AHB_HBURST    := intf.hwBus.hburst
    M_AHB_HPROT     := intf.hwBus.hprot
    M_AHB_HWDATA    := intf.hwBus.hwdata
    M_AHB_HMASTLOCK := intf.hwBus.hmastlock
  }
}
