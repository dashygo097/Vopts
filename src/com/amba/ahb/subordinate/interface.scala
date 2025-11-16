package com.ahb

import chisel3._

class AHBSubordinateIO(addrWidth: Int, dataWidth: Int, selSize: Int) extends Bundle {
  val sel = Input(UInt(selSize.W))
  val hrBus = Flipped(AHBHRBusIO(addrWidth, dataWidth))
  val hwBus = Flipped(AHBHWBusIO(addrWidth, dataWidth))

  override def clone =
    new AHBSubordinateIO(addrWidth, dataWidth, selSize).asInstanceOf[this.type]
}

object AHBSubordinateIO {
  def apply(addrWidth: Int, dataWidth: Int, selSize: Int): AHBSubordinateIO =
    new AHBSubordinateIO(addrWidth, dataWidth, selSize)
}

class AHBSubordinateExternalIO(addrWidth: Int, dataWidth: Int, selSize: Int) extends Bundle {
  val S_AHB_HREADYOUT = Output(Bool())
  val S_AHB_HRESP = Output(Bool())
  val S_AHB_HRDATA = Output(UInt(dataWidth.W))

  val S_AHB_HSEL = Input(UInt(selSize.W))
  val S_AHB_HADDR = Input(UInt(addrWidth.W))
  val S_AHB_HTRANS = Input(UInt(2.W))
  val S_AHB_HWRITE = Input(Bool())
  val S_AHB_HSIZE = Input(UInt(3.W))
  val S_AHB_HBURST = Input(UInt(3.W))
  val S_AHB_HPROT = Input(UInt(4.W))
  val S_AHB_HWDATA = Input(UInt(dataWidth.W))
  val S_AHB_HMASTLOCK = Input(Bool())

  def connect(intf: AHBSubordinateIO): Unit = {
    S_AHB_HREADYOUT := intf.hrBus.hready
    S_AHB_HRESP := intf.hrBus.hresp
    S_AHB_HRDATA := intf.hrBus.hrdata

    intf.sel := S_AHB_HSEL
    intf.hwBus.haddr := S_AHB_HADDR
    intf.hwBus.htrans := S_AHB_HTRANS
    intf.hwBus.hwrite := S_AHB_HWRITE
    intf.hwBus.hsize := S_AHB_HSIZE
    intf.hwBus.hburst := S_AHB_HBURST
    intf.hwBus.hprot := S_AHB_HPROT
    intf.hwBus.hwdata := S_AHB_HWDATA
    intf.hwBus.hmastlock := S_AHB_HMASTLOCK
  }
}
