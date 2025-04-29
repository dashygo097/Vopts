package dsp.lut

import datatype.fp.FP

import chisel3._

class AbsIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class AbsCore extends Module {
  val io = IO(new AbsIO)
  val zero = Wire(new FP)
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
