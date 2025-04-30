package mod.am

import datatype.fp.FP
import dsp.lut.Abs
import dsp.filter.FIRCore

import chisel3._

class DeAMIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class EvlpDetectorCore(baseFreqLimit: Int) extends Module {
  val io = IO(new DeAMIO)
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), 64))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
