package com.amba

import chisel3._

object AHBTransferType extends ChiselEnum {
  val IDLE   = Value(0.U(2.W))
  val BUSY   = Value(1.U(2.W))
  val NONSEQ = Value(2.U(2.W))
  val SEQ    = Value(3.U(2.W))
}

object AHBBurstType extends ChiselEnum {
  val SINGLE = Value(0.U(3.W))
  val INCR   = Value(1.U(3.W))
  val WRAP4  = Value(2.U(3.W))
  val INCR4  = Value(3.U(3.W))
  val WRAP8  = Value(4.U(3.W))
  val INCR8  = Value(5.U(3.W))
  val WRAP16 = Value(6.U(3.W))
  val INCR16 = Value(7.U(3.W))
}
