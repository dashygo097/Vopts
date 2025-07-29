package mod.am

import math.common.Abs
import dsp.filter.FIRCore
import utils._
import chisel3._

class EDDeAMCore(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  val io = IO(new SISO(new FP))
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
