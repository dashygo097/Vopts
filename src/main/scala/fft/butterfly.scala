package fft
import global.Complex

import chisel3._
import chisel3.util._

class ButterflyIO extends Bundle {
  val in1 = Input(new Complex)
  val in2 = Input(new Complex)
  val wn = Input(new Complex)
  val out1 = Output(new Complex)
  val out2 = Output(new Complex)
}

class Butterfly extends Module {
  val io = IO(new ButterflyIO)
  io.out1 := io.in1 + io.in2
  io.out2 := (io.in1 - io.in2) * io.wn
}

object Butterfly {
  def apply(in1: Complex, in2: Complex, wn: Complex): (Complex, Complex) = {
    val m = Module(new Butterfly)
    m.io.in1 := in1
    m.io.in2 := in2
    m.io.wn := wn
    (m.io.out1, m.io.out2)
  }
}

