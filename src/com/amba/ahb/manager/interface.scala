package com.amba

import chisel3._

class AHBManagerIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val aWidth = addrWidth
  val dWidth = dataWidth

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
  val aWidth = addrWidth
  val dWidth = dataWidth

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
    require(intf.aWidth == addrWidth,
      s"Address width mismatch: intf.aWidth=${intf.aWidth}, addrWidth=$addrWidth")
    require(intf.dWidth == dataWidth,
      s"Data width mismatch: intf.dWidth=${intf.dWidth}, dataWidth=$dataWidth")

    intf.hrBus.ready := this.M_AHB_HREADY
    intf.hrBus.resp  := this.M_AHB_HRESP
    intf.hrBus.rdata := this.M_AHB_HRDATA

    this.M_AHB_HADDR     := intf.hwBus.addr
    this.M_AHB_HTRANS    := intf.hwBus.trans
    this.M_AHB_HWRITE    := intf.hwBus.write
    this.M_AHB_HSIZE     := intf.hwBus.size
    this.M_AHB_HBURST    := intf.hwBus.burst
    this.M_AHB_HPROT     := intf.hwBus.prot
    this.M_AHB_HWDATA    := intf.hwBus.wdata
    this.M_AHB_HMASTLOCK := intf.hwBus.mastlock
  }
}
