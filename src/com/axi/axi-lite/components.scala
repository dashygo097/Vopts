package com.axi

import chisel3._

class AXILiteAddrIO(addrWidth: Int) extends Bundle {
  val addr = UInt(addrWidth.W)
  val prot = UInt(3.W)
  override def clone = { new AXILiteAddrIO(addrWidth).asInstanceOf[this.type] }
}

class AXILiteWriteIO(dataWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val strb = UInt((dataWidth / 8).W)
  override def clone = { new AXILiteWriteIO(dataWidth).asInstanceOf[this.type] }
}

class AXILiteWriteRespIO extends Bundle {
  val resp = UInt(2.W)
  override def clone = { new AXILiteWriteRespIO().asInstanceOf[this.type] }
}

class AXILiteReadIO(dataWidth: Int) extends Bundle {
  val data = UInt(dataWidth.W)
  val resp = UInt(2.W)
  override def clone = { new AXILiteReadIO(dataWidth).asInstanceOf[this.type] }
}
