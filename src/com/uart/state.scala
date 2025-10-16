package com.uart

import chisel3._

object UartState extends ChiselEnum {
  val IDLE  = Value(0.U(2.W))
  val START = Value(1.U(2.W))
  val DATA  = Value(2.U(2.W))
  val STOP  = Value(3.U(2.W))
}
