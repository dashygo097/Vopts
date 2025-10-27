package dsp.resample

import utils._
import chisel3._
import chisel3.util._

class Decimator[T <: Data](gen: T, factor: Int) extends Module {
  override def desiredName = s"decimator_${gen.toString.toLowerCase()}_f$factor"
  require(factor > 0, "Decimation factor must be greater than 0")
  val io                   = IO(new SISO(gen)).suggestName("DECIMATOR")
  val count                = RegInit(0.U(log2Ceil(factor).W))
  val out_next             = RegInit(0.U.asTypeOf(gen))

  count := Mux(count === (factor - 1).U, 0.U, count + 1.U)
  when(count === 0.U) {
    out_next := io.in
  }

  io.out := out_next
}

object Decimator {
  def apply[T <: Data](in: T, factor: Int): T = {
    val decimator = Module(new Decimator(in, factor))
    decimator.io.in := in
    decimator.io.out
  }
}
