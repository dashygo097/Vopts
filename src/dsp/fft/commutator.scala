package dsp.fft

import data.fp.FPComplex

import chisel3._

class CommutatorIO extends Bundle {
  val in1 = Input(new FPComplex)
  val in2 = Input(new FPComplex)
  val sel = Input(Bool())
  val out1 = Output(new FPComplex)
  val out2 = Output(new FPComplex)
}

class Commutator extends Module {
  val io = IO(new CommutatorIO)
  io.out1 := Mux(io.sel, io.in2, io.in1)
  io.out2 := Mux(io.sel, io.in1, io.in2)
}

object Commutator {
  def apply(in1: FPComplex, in2: FPComplex, sel: Bool): (FPComplex, FPComplex) = {
    val commutator = Module(new Commutator)
    commutator.io.in1 := in1
    commutator.io.in2 := in2
    commutator.io.sel := sel
    (commutator.io.out1 , commutator.io.out2)
  }
}
