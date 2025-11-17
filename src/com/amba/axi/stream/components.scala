package com.amba

import chisel3._

class AXIStreamIO(dataWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val strb = UInt((dataWidth / 8).W)
  val keep = UInt((dataWidth / 8).W)
  val last = Bool()
  val id  = UInt(idWidth.W)
  val dest = UInt(idWidth.W)
  val user = UInt(userWidth.W)

  override def clone = new AXIStreamIO(dataWidth, idWidth, userWidth).asInstanceOf[this.type]
}
