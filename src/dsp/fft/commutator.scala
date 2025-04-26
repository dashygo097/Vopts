package dsp.fft
import utils.Complex

import chisel3._

class CommutatorIO extends Bundle {
  val in1 = Input(new Complex)
  val in2 = Input(new Complex)
  val sel = Input(Bool())
  val out1 = Output(new Complex)
  val out2 = Output(new Complex)
}

class Commutator extends Module {
  val io = IO(new CommutatorIO)
  io.out1 := Mux(io.sel, io.in2, io.in1)
  io.out2 := Mux(io.sel, io.in1, io.in2)
}

object Commutator {
  def apply(in1: Complex, in2: Complex, sel: Bool): (Complex, Complex) = {
    val commutator = Module(new Commutator)
    commutator.io.in1 := in1
    commutator.io.in2 := in2
    commutator.io.sel := sel
    (commutator.io.out1 , commutator.io.out2)
  }
}
