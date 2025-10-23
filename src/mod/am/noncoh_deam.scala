package mod.am

import math._
import dsp.filter._
import utils._
import chisel3._

class EDDeAM[T <: Data](gen: T, baseFreqLimit: Int, clkFreq: Int, filterOrder: Int = 64)(implicit
  analog: Analog[T],
  ord: PartialOrdered[T]
) extends Module {
  override def desiredName = s"deam_ed_fl${baseFreqLimit}_o$filterOrder"
  val io                   = IO(new SISO(gen)).suggestName("DeAM_ED")
  val fir                  = Module(new FIRFilter(gen, "lp", Seq(baseFreqLimit), filterOrder, clkFreq))

  fir.io.in := Abs(io.in)
  io.out    := fir.io.out
}
