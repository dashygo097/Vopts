package dsp.lut

import datatype.fp._

import chisel3._

class DerivatorCore extends Module {
  val io = IO(new FPSISO)
  val prev = Reg(new FP)

  prev := io.in
  io.out := io.in - prev
}

object Derivator {
  def apply(in: FP): FP = {
    val module = Module(new DerivatorCore)
    module.io.in := in
    module.io.out
  }
}
