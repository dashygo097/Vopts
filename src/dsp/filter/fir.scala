package dsp.filter

import scala.sys.process._
import utils._
import chisel3._

class FIRFilter[T <: Data](gen: T, 
  filterType: String,
  cutoff: Seq[Double],
  order: Int,
  clkFreq: Int,
  groupSize: Int = 2
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"fir_${filterType}_o${order}_g${groupSize}_${cutoff.mkString("_")}"
  val pyPath               = "src/dsp/filter/fir.py"
  val command              = filterType match {
    case "bp" | "bandpass" =>
      Seq(
        "python3",
        pyPath,
        "bandpass",
        clkFreq.toString,
        order.toString,
        cutoff(0).toString,
        cutoff(1).toString
      )
    case "lp" | "lowpass"  =>
      Seq("python3", pyPath, "lowpass", clkFreq.toString, order.toString, cutoff(0).toString)
    case "hp" | "highpass" =>
      Seq("python3", pyPath, "highpass", clkFreq.toString, order.toString, cutoff(0).toString)
    case _                 => throw new IllegalArgumentException("Invalid filter type")
  }

  val result = command.!!.trim
  val taps   = result.split(",").map(_.toDouble).toIndexedSeq

  val io     = IO(new SISO(gen)).suggestName("FIR")
  val regs   = RegInit(VecInit(Seq.fill(taps.length)(gen.fromDouble(0.0))))
  val coeffs = VecInit(taps.map(c => gen.fromDouble(c)))

  regs(0)   := io.in
  for (i <- 1 until taps.length)
    regs(i) := regs(i - 1)

  val stage1Products = VecInit.tabulate(taps.length) { i =>
    RegNext(regs(i) * coeffs(i))
  }

  val stage2Sums = Pipeline.buildTree(stage1Products, groupSize)(_ + _)

  io.out := stage2Sums
}
