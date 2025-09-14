package math

import utils._
import chisel3._

class Derivator[T <: Data](gen: T)(implicit ev: Arithmetic[T]) extends Module {
  override def desiredName = s"derivator_${gen.toString().toLowerCase()}"
  val io = IO(new SISO(gen)).suggestName("DERIVATOR")
  val prev = RegInit(Zero(gen))

  prev := io.in
  io.out := io.in - prev
}

object Derivator {
  def apply[T <: Data](in: T)(implicit ev: Arithmetic[T]): T = {
    val module = Module(new Derivator(in))
    module.io.in := in
    module.io.out
  }
}
