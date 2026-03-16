package vopts.math

import vopts.utils._
import chisel3._

class Diode[T <: Data](gen: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]) extends Module {
  override def desiredName = s"diode_${gen.toString.toLowerCase()}"
  val io                   = IO(new SISO(gen)).suggestName("DIODE")

  io.out := Mux(io.in > gen.zero, io.in, gen.zero)
}

object Diode {
  def apply[T <: Data](in: T)(implicit ord: PartialOrdered[T], ev: Arithmetic[T]): T = {
    val diode = Module(new Diode(in))
    diode.io.in := in
    diode.io.out
  }
}
