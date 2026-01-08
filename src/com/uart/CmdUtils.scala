package com.uart

import chisel3._

object UartCmdType extends ChiselEnum {
  val WRITE = Value(0.U(2.W))
  val READ  = Value(1.U(2.W))
}
