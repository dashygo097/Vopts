package dsp.filter

import scala.sys.process._
import utils._
import chisel3._

class FIRFilter(filterType: String, cutoff: Seq[Double], order: Int, groupSize: Int = 2) extends Module with Config{
  override def desiredName = s"fir_${filterType}_o${order}_g${groupSize}_${cutoff.mkString("_")}"
  val pyPath = "src/dsp/filter/fir.py"
  val command = filterType match {
    case "bp" | "bandpass" => Seq("python3",  pyPath, "bandpass", sampleFreq.toString, order.toString, cutoff(0).toString, cutoff(1).toString)
    case "lp" | "lowpass" => Seq("python3", pyPath ,"lowpass", sampleFreq.toString, order.toString, cutoff(0).toString)
    case "hp" | "highpass"=> Seq("python3", pyPath, "highpass", sampleFreq.toString, order.toString, cutoff(0).toString)
    case _ => throw new IllegalArgumentException("Invalid filter type")
  }

  val result = command.!!.trim
  val taps = result.split(",").map(_.toDouble).toIndexedSeq

  val io = IO(new SISO(new FP)).suggestName("FIR")
  val regs = RegInit(VecInit(Seq.fill(taps.length)( FP(0.0) )))
  val coeffs = VecInit(taps.map( c => FP(c) ))

  regs(0) := io.in
  for (i <- 1 until taps.length) {
    regs(i) := regs(i - 1)
  }

  val stage1Products = VecInit.tabulate(taps.length) {
    i => RegNext(regs(i) * coeffs(i))
  }

  val stage2Sums = Pipeline.buildTree(stage1Products, groupSize)(_ + _)

  io.out := stage2Sums
}

