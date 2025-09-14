package mod.ask

import dsp.filter._
import math._

import utils._
import chisel3._

class EnvelopDetectorIO extends Bundle {
  val in = Input(new FP)
  val data = Output(Bool())
}

class EDDeASK(baseFreqLimit: Int, threshold: Double, filterOrder : Int = 64) extends Module {
  override def desiredName = s"deask_ed_fl${baseFreqLimit}_o${filterOrder}_thres${(threshold * 1000).toInt}"
  val io = IO(new EnvelopDetectorIO).suggestName("DeASK_ED")
  val fir = Module(new FIRFilter("lp", Seq(baseFreqLimit), filterOrder))
  val comparator = Module(new Comparator(new FP, threshold))

  fir.io.in := RegNext(Abs(io.in))
  comparator.io.in := RegNext(fir.io.out)
  io.data := comparator.io.out
}

