package dsp.lut

import datatype.fp.FP

import chisel3._

class DiodeIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class DiodeCore extends Module {
  val io = IO(new DiodeIO)
  val zero = FP(0.0)

  io.out := Mux(io.out > zero, io.in, zero)
}

object DiodeCore {
  def apply(in: FP): FP = {
    val diode = Module(new DiodeCore)
    diode.io.in := in
    diode.io.out
  }
}

