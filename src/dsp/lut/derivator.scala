package dsp.lut

import datatype.fp.FP

import chisel3._
import chisel3.util._

class DerivatorIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class DerivatorCore extends Module {
  val io = IO(new DerivatorIO)
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
