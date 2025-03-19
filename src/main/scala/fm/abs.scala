package fm
import global.Float

import chisel3._
import chisel3.util._

class AbsIO extends Bundle {
  val in = Input(new Float)
  val sign = Input(Bool())
  val out = Output(new Float)
}

class Abs extends Module {
  val io = IO(new AbsIO)
  val zero = Wire(new Float)
  val out = Mux(io.sign, zero - io.in, io.in)
  zero := zero.fromDouble(0.0)
  io.out := out
}
