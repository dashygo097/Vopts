package com.amba

import chisel3._
import chisel3.util._

class AXIStreamMasterIO(dataWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val dWidth = dataWidth
  val iWidth = idWidth
  val uWidth = userWidth

  val t = Decoupled(new AXIStreamIO(dataWidth, idWidth, userWidth))

  override def clone = new AXIStreamMasterIO(dataWidth, idWidth, userWidth).asInstanceOf[this.type]
}

class AXIStreamMasterExternalIO(dataWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val dWidth = dataWidth
  val iWidth = idWidth
  val uWidth = userWidth

  val TDATA = Output(UInt(dataWidth.W))
  val TKEEP = Output(UInt((dataWidth / 8).W))
  val TSTRB = Output(UInt((dataWidth / 8).W))
  val TLAST = Output(Bool())
  val TID   = Output(UInt(idWidth.W))
  val TDEST = Output(UInt(idWidth.W))
  val TUSER = Output(UInt(userWidth.W))
  val TVALID = Output(Bool())
  val TREADY = Input(Bool())

  def connect(intf: AXIStreamMasterIO): Unit = {
    require(intf.dWidth == dataWidth && intf.iWidth == idWidth && intf.uWidth == userWidth,
      s"Data width, ID width, and user width must match: $dataWidth, $idWidth, $userWidth")

    this.TDATA := intf.t.bits.data
    this.TKEEP := intf.t.bits.keep
    this.TSTRB := intf.t.bits.strb
    this.TLAST := intf.t.bits.last
    this.TID   := intf.t.bits.id
    this.TDEST := intf.t.bits.dest
    this.TUSER := intf.t.bits.user
    this.TVALID := intf.t.valid
    intf.t.ready := this.TREADY
  }
} 
