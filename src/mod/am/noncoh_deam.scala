package mod.am

import math.Abs
import dsp.filter.FIRCore
import utils._
import chisel3._

class EDDeAMCore(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  override def desiredName = s"deam_ed_fl${baseFreqLimit}_o${filterOrder}"
  val io = IO(new SISO(new FP)).suggestName("DeAM_ED")
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
