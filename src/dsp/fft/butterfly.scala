package dsp.fft
import utils._

import data.fp.FPComplex

import chisel3._
import chisel3.util._

class ButterflyIO extends Bundle {
  val in1 = Input(new FPComplex)
  val in2 = Input(new FPComplex)
  val wn = Input(new FPComplex)
  val out1 = Output(new FPComplex)
  val out2 = Output(new FPComplex)
}

class Butterfly extends Module {
  val io = IO(new ButterflyIO)
  io.out1 := io.in1 + io.in2
  io.out2 := (io.in1 - io.in2) * io.wn
}

object Butterfly {
  def apply(in1: FPComplex, in2: FPComplex, wn: FPComplex): (FPComplex, FPComplex) = {
    val m = Module(new Butterfly)
    m.io.in1 := in1
    m.io.in2 := in2
    m.io.wn := wn
    (m.io.out1, m.io.out2)
  }
}

