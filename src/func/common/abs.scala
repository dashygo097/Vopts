package func.common

import utils._
import datatype.fp._

import chisel3._

class AbsCore extends Module {
  val io = IO(new SISO(new FP))
  val zero = Wire(FP(0.0))
  zero := (new FP).fromDouble(0.0)
  io.out := Mux(io.in > zero, io.in, zero - io.in)
}

object Abs {
  def apply(in: FP): FP = {
    val abs = Module(new AbsCore)
    abs.io.in := in
    abs.io.out
  }
}
