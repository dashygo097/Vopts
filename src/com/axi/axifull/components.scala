package com.axi

import chisel3._

class AXIFullAddrIO(addrWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val addr   = UInt(addrWidth.W)
  val prot   = UInt(3.W)
  val id     = UInt(idWidth.W)
  val len    = UInt(8.W)
  val size   = UInt(3.W)
  val burst  = UInt(2.W)
  val lock   = Bool()
  val cache  = UInt(4.W)
  val qos    = UInt(4.W)
  val region = UInt(4.W)
  val user   = UInt(userWidth.W)

  override def clone = new AXIFullAddrIO(addrWidth, idWidth, userWidth).asInstanceOf[this.type]
}

class AXIFullWriteIO(dataWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val strb = UInt((dataWidth / 8).W)
  val last = Bool()
  val id   = UInt(idWidth.W)
  val user = UInt(userWidth.W)

  override def clone = new AXIFullWriteIO(dataWidth, idWidth, userWidth).asInstanceOf[this.type]
}

class AXIFullWriteRespIO(idWidth: Int, userWidth: Int) extends Bundle {
  val resp = UInt(2.W)
  val id   = UInt(idWidth.W)
  val user = UInt(userWidth.W)

  override def clone = new AXIFullWriteRespIO(idWidth, userWidth).asInstanceOf[this.type]
}

class AXIFullReadIO(dataWidth: Int, idWidth: Int, userWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val resp = UInt(2.W)
  val last = Bool()
  val id   = UInt(idWidth.W)
  val user = UInt(userWidth.W)

  override def clone = new AXIFullReadIO(dataWidth, idWidth, userWidth).asInstanceOf[this.type]
}
