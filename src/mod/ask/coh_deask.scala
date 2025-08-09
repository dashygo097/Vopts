package mod.ask

import dsp.filter.FIRCore
import math.{ComparatorCore, Abs}

import utils._
import chisel3._

class EnvelopDetectorIO extends Bundle {
  val in = Input(new FP)
  val data = Output(Bool())
}

class EDDeASKCore(baseFreqLimit: Int, threshold: Double, filterOrder : Int = 64) extends Module {
  val io = IO(new EnvelopDetectorIO).suggestName("DeASK_ED")
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))
  val comparator = Module(new ComparatorCore(new FP, threshold))

  fir.io.in := RegNext(Abs(io.in))
  comparator.io.in := RegNext(fir.io.out)
  io.data := comparator.io.out
}

