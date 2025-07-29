package mod.ask

import dsp.filter.FIRCore
import math.common.{ComparatorCore, Abs}

import utils._
import chisel3._

class EnvelopDetectorIO extends Bundle {
  val in = Input(new FP)
  val data = Output(Bool())
}

class EDDeASKCore(baseFreqLimit: Int, threshold: Double, filterOrder : Int = 64) extends Module {
  val io = IO(new EnvelopDetectorIO)
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))
  val comparator = Module(new ComparatorCore(new FP, threshold))

  fir.io.in := DataWrapper(Abs(io.in))
  comparator.io.in := DataWrapper(fir.io.out)
  io.data := comparator.io.out
}

