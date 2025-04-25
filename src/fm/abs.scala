package fm
import utils.Float

import chisel3._
import chisel3.util._

class AbsIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class AbsCore extends Module {
  val io = IO(new AbsIO)
  val zero = Wire(new Float)
  zero := (new Float).fromDouble(0.0)
  io.out := Mux(io.in > zero, io.in, zero - io.in)
}

object AbsCore {
  def apply(in: Float): Float = {
    val abs = Module(new AbsCore)
    abs.io.in := in
    abs.io.out
  }
}
