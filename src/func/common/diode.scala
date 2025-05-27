package func.common

import utils._
import chisel3._

class DiodeCore extends Module {
  val io = IO(new SISO(new FP))
  val zero = Wire(FP(0.0))

  io.out := Mux(io.out > zero, io.in, zero)
}

object DiodeCore {
  def apply(in: FP): FP = {
    val diode = Module(new DiodeCore)
    diode.io.in := in
    diode.io.out
  }
}

