package func.common

import utils._
import chisel3._

class AbsCore[T <: Data](gen: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  val io = IO(new SISO(gen))
  val zero = gen.zero()
  io.out := Mux(io.in > zero, io.in, zero - io.in)
}

object Abs {
  def apply[T <: Data](in: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]): T = {
    val abs = Module(new AbsCore(in))
    abs.io.in := in
    abs.io.out
  }
}
