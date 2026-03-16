package vopts.dsp.fft

import vopts.utils._
import chisel3._

class CommutatorIO(dw: Int, bp: Int) extends Bundle {
  val in1  = Input(new FPComplex(dw, bp))
  val in2  = Input(new FPComplex(dw, bp))
  val sel  = Input(Bool())
  val out1 = Output(new FPComplex(dw, bp))
  val out2 = Output(new FPComplex(dw, bp))
}

class Commutator(dw: Int, bp: Int) extends Module {
  override def desiredName = s"commutator"
  val io                   = IO(new CommutatorIO(dw, bp))
  io.out1 := Mux(io.sel, io.in2, io.in1)
  io.out2 := Mux(io.sel, io.in1, io.in2)
}

object Commutator {
  def apply(in1: FPComplex, in2: FPComplex, sel: Bool): (FPComplex, FPComplex) = {
    in1.requireCompatible(in2)

    val commutator = Module(new Commutator(in1.dw, in1.bp))
    commutator.io.in1 := in1
    commutator.io.in2 := in2
    commutator.io.sel := sel
    (commutator.io.out1, commutator.io.out2)
  }
}
