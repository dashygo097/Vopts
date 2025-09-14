package com.axi

import chisel3._
import chisel3.util._

class AXIFullMasterIO(dataWidth: Int, addrWidth: Int) extends Bundle {
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")
  val aw = Decoupled(new AXIFullAddrIO(addrWidth))
  val w  = Decoupled(new AXIFullWriteIO(dataWidth))
  val b  = Flipped(Decoupled(new AXIFullWriteRespIO()))
  val ar = Decoupled(new AXIFullAddrIO(addrWidth))
  val r  = Flipped(Decoupled(new AXIFullReadIO(dataWidth)))

  override def clone = { new AXIFullMasterIO(addrWidth, dataWidth).asInstanceOf[this.type] }
}

object AXIFullMasterIO {
  def apply(dataWidth: Int, addrWidth: Int): AXIFullMasterIO = new AXIFullMasterIO(dataWidth, addrWidth)
}


