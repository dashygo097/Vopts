package com.amba

import chisel3._
import chisel3.util._

class AXIStreamSlaveIO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Bundle {
  val dWidth = dataWidth
  val iWidth = idWidth
  val deWidth = destWidth
  val uWidth = userWidth

  val t = Flipped(Decoupled(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth)))

  override def clone = new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth).asInstanceOf[this.type]
}

class AXIStreamSlaveExternalIO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Bundle {
  val dWidth = dataWidth
  val iWidth = idWidth
  val deWidth = destWidth
  val uWidth = userWidth

  val TDATA = Input(UInt(dataWidth.W))
  val TKEEP = Input(UInt((dataWidth / 8).W))
  val TSTRB = Input(UInt((dataWidth / 8).W))
  val TLAST = Input(Bool())
  val TID   = Input(UInt(idWidth.W))
  val TDEST = Input(UInt(idWidth.W))
  val TUSER = Input(UInt(userWidth.W))
  val TVALID = Input(Bool())
  val TREADY = Output(Bool())

  def connect(intf: AXIStreamSlaveIO): Unit = {
    require(intf.dWidth == this.dWidth, "Data width mismatch")
    require(intf.iWidth == this.iWidth, "ID width mismatch")
    require(intf.deWidth == this.deWidth, "Dest width mismatch")
    require(intf.uWidth == this.uWidth, "User width mismatch")

    intf.t.bits.data := TDATA
    intf.t.bits.strb := TSTRB
    intf.t.bits.keep := TKEEP
    intf.t.bits.last := TLAST
    intf.t.bits.id   := TID
    intf.t.bits.dest := TDEST
    intf.t.bits.user := TUSER
    intf.t.valid    := TVALID
    TREADY         := intf.t.ready
  }
} 
