package dsp.lut

import datatype.fp._

import chisel3._

class DiodeCore extends Module {
  val io = IO(new FPSISO)
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

