package mod.am

import math._
import dsp.filter._
import utils._
import chisel3._

class EDDeAM(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  override def desiredName = s"deam_ed_fl${baseFreqLimit}_o${filterOrder}"
  val io = IO(new SISO(new FP)).suggestName("DeAM_ED")
  val fir = Module(new FIRFilter("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := Abs(io.in)
  io.out := fir.io.out
}
