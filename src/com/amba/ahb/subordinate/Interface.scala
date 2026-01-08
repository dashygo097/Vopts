package vopts.com.amba

import chisel3._

class AHBSubordinateIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val aWidth = addrWidth
  val dWidth = dataWidth

  val sel   = Input(Bool())
  val hrBus = Flipped(AHBHRBusIO(addrWidth, dataWidth))
  val hwBus = Flipped(AHBHWBusIO(addrWidth, dataWidth))

  override def clone =
    new AHBSubordinateIO(addrWidth, dataWidth).asInstanceOf[this.type]
}

object AHBSubordinateIO {
  def apply(addrWidth: Int, dataWidth: Int): AHBSubordinateIO =
    new AHBSubordinateIO(addrWidth, dataWidth)
}

class AHBSubordinateExtIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val aWidth = addrWidth
  val dWidth = dataWidth

  val S_AHB_HREADYOUT = Output(Bool())
  val S_AHB_HRESP     = Output(Bool())
  val S_AHB_HRDATA    = Output(UInt(dataWidth.W))

  val S_AHB_HSEL      = Input(Bool())
  val S_AHB_HADDR     = Input(UInt(addrWidth.W))
  val S_AHB_HTRANS    = Input(UInt(2.W))
  val S_AHB_HWRITE    = Input(Bool())
  val S_AHB_HSIZE     = Input(UInt(3.W))
  val S_AHB_HBURST    = Input(UInt(3.W))
  val S_AHB_HPROT     = Input(UInt(4.W))
  val S_AHB_HWDATA    = Input(UInt(dataWidth.W))
  val S_AHB_HMASTLOCK = Input(Bool())

  def connect(intf: AHBSubordinateIO): Unit = {
    require(intf.aWidth == addrWidth, s"Address width mismatch: intf.aWidth=${intf.aWidth}, addrWidth=$addrWidth")
    require(intf.dWidth == dataWidth, s"Data width mismatch: intf.dWidth=${intf.dWidth}, dataWidth=$dataWidth")

    this.S_AHB_HREADYOUT := intf.hrBus.ready
    this.S_AHB_HRESP     := intf.hrBus.resp
    this.S_AHB_HRDATA    := intf.hrBus.rdata

    intf.sel            := this.S_AHB_HSEL
    intf.hwBus.addr     := this.S_AHB_HADDR
    intf.hwBus.trans    := this.S_AHB_HTRANS
    intf.hwBus.write    := this.S_AHB_HWRITE
    intf.hwBus.size     := this.S_AHB_HSIZE
    intf.hwBus.burst    := this.S_AHB_HBURST
    intf.hwBus.prot     := this.S_AHB_HPROT
    intf.hwBus.wdata    := this.S_AHB_HWDATA
    intf.hwBus.mastlock := this.S_AHB_HMASTLOCK
  }
}
