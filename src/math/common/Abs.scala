package vopts.math

import vopts.utils._
import chisel3._

class Abs[T <: Data](gen: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  override def desiredName: String = s"abs_${gen.toString().toLowerCase()}"
  val io                           = IO(new SISO(gen)).suggestName("ABS")

  io.out := Mux(io.in > gen.zero, io.in, gen.zero - io.in)
}

object Abs {
  def apply[T <: Data](in: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]): T = {
    val abs = Module(new Abs(in))
    abs.io.in := in
    abs.io.out
  }
}
