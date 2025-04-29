package com.uart

import chisel3._

object UartState {
  val IDLE = 0.U
  val START = 1.U
  val DATA = 2.U
  val STOP = 3.U
}
