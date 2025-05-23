package mod.am

import utils._
import datatype.fp._
import func.common.Abs
import dsp.filter.FIRCore

import chisel3._

class EDDeAMCore(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  val io = IO(new SISO(new FP))
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
