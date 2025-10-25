package com.uart

import chisel3._

case class UartCmdOption(
  baudRate: Int = 115200,
  read: Boolean = true,
  write: Boolean = true,
  move: Boolean = true
)

object UartCmdType extends ChiselEnum {
  val WRITE = Value(0.U(2.W))
  val READ  = Value(1.U(2.W))
  val MOVE  = Value(2.U(2.W))
}
