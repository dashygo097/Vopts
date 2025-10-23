package mod.ask

import dsp.filter._
import math._

import utils._
import chisel3._

class EnvelopDetectorIO[T <: Data](gen: T) extends Bundle {
  val in   = Input(gen)
  val data = Output(Bool())
}

class EDDeASK[T <: Data](gen: T, 
  baseFreqLimit: Double,
  threshold: Double,
  clkFreq: Int,
  filterOrder: Int = 64
)(implicit analog: Analog[T], ord: PartialOrdered[T])
    extends Module {
  override def desiredName =
    s"deask_ed_fl${baseFreqLimit}_o${filterOrder}_thres${(threshold * 1000).toInt}"
  val io                   = IO(new EnvelopDetectorIO(gen)).suggestName("DeASK_ED")
  val fir                  = Module(new FIRFilter(gen, "lp", Seq(baseFreqLimit), filterOrder, clkFreq))
  val comparator           = Module(new Comparator(gen, threshold))

  fir.io.in        := RegNext(Abs(io.in))
  comparator.io.in := RegNext(fir.io.out)
  io.data          := comparator.io.out
}
