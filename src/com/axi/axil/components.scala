package com.axi

import chisel3._

class AXILiteAddress(addrWidth: Int) extends Bundle {
  val addr    = UInt(addrWidth.W)
  val prot    = UInt(3.W)

  override def clone = { new AXILiteAddress(addrWidth).asInstanceOf[this.type] }
}

class AXILiteWriteData(dataWidth: Int) extends Bundle {
  val data    = UInt(dataWidth.W)
  val strb    = UInt((dataWidth / 8).W)
  override def clone = { new AXILiteWriteData(dataWidth).asInstanceOf[this.type] }
}

class AXILiteReadData(dataWidth: Int) extends Bundle {
  val data    = UInt(dataWidth.W)
  val resp    = UInt(2.W)
  override def clone = { new AXILiteReadData(dataWidth).asInstanceOf[this.type] }
}
