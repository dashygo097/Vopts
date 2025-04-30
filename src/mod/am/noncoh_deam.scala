package mod.am

import datatype.fp._
import dsp.lut.Abs
import dsp.filter.FIRCore

import chisel3._

class EDDeAMCore(baseFreqLimit: Int) extends Module {
  val io = IO(new FPSISO)
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), 64))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
