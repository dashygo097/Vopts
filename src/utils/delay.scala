package utils

import chisel3._
import chisel3.util._

object Delay {
  def apply[T <: Data](signal: T, n: Int): T = {
    require(n >= 0, "Delay must be non-negative")
    val delayedSignal = RegInit(signal.cloneType)
    when(RegNext(true.B)) {
      delayedSignal := signal
    }
    delayedSignal
  }

  def apply(waitClks: Int): Unit = {
    require(waitClks >= 0, "Delay must be non-negative")
    val counter = RegInit(0.U(log2Ceil(waitClks + 1).W))
    when(counter < waitClks.U) {
      counter := counter + 1.U
    }
  }
}
