package dsp.fft

import utils._
import chisel3._

class ButterflyIO(dw: Int, bp: Int) extends Bundle {
  val in1  = Input(new FPComplex(dw, bp))
  val in2  = Input(new FPComplex(dw, bp))
  val wn   = Input(new FPComplex(dw, bp))
  val out1 = Output(new FPComplex(dw, bp))
  val out2 = Output(new FPComplex(dw, bp))
}

class Butterfly(dw: Int, bp: Int) extends Module {
  override def desiredName = s"butterfly"
  val io                   = IO(new ButterflyIO(dw, bp))
  io.out1 := io.in1 + io.in2
  io.out2 := (io.in1 - io.in2) * io.wn
}

object Butterfly {
  def apply(in1: FPComplex, in2: FPComplex, wn: FPComplex): (FPComplex, FPComplex) = {
    in1.requireCompatible(in2)
    in1.requireCompatible(wn)

    val m = Module(new Butterfly(in1.dw(), in1.bp()))
    m.io.in1 := in1
    m.io.in2 := in2
    m.io.wn  := wn
    (m.io.out1, m.io.out2)
  }
}
