package com.axi

import chisel3._

class AXIFullAddrIO(addrWidth: Int) extends Bundle {
  val addr  = UInt(addrWidth.W)
  val prot  = UInt(3.W)
  val id    = UInt(4.W) 
  val len   = UInt(8.W)
  val size  = UInt(3.W)
  val burst = UInt(2.W)

  override def clone = { new AXIFullAddrIO(addrWidth).asInstanceOf[this.type] }
}

class AXIFullWriteIO(dataWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val strb = UInt((dataWidth / 8).W)
  val last = Bool()
  val id   = UInt(4.W)

  override def clone = { new AXIFullWriteIO(dataWidth).asInstanceOf[this.type] }
}

class AXIFullWriteRespIO extends Bundle {
  val resp = UInt(2.W)
  val id   = UInt(4.W)

  override def clone = { new AXIFullWriteRespIO().asInstanceOf[this.type] }
}

class AXIFullReadIO(dataWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val resp = UInt(2.W)
  val last = Bool()
  val id   = UInt(4.W)

  override def clone = { new AXIFullReadIO(dataWidth).asInstanceOf[this.type] }
}


