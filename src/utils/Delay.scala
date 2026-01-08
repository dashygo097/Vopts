package vopts.utils

import chisel3._
import chisel3.util._

object Delay {
  def apply(waitClks: Int): Unit = {
    require(waitClks >= 0, "Delay must be non-negative")
    val counter = RegInit(0.U(log2Ceil(waitClks + 1).W))
    when(counter < waitClks.U) {
      counter := counter + 1.U
    }
  }
}
