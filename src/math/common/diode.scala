package math

import utils._
import chisel3._

class DiodeCore[T <: Data](gen: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  override def desiredName = s"diode_${gen.toString.toLowerCase()}"
  val io = IO(new SISO(gen)).suggestName("DIODE")
  val zero = gen.zero()

  io.out := Mux(io.in > zero, io.in, zero)
}

object DiodeCore {
  def apply[T <: Data](in: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]): T = {
    val diode = Module(new DiodeCore(in))
    diode.io.in := in
    diode.io.out
  }
}

