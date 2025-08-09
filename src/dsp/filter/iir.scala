package dsp.filter

import scala.sys.process._
import utils._
import chisel3._


/*
 *package dsp.filter

import scala.sys.process._
import utils._
import chisel3._

class FIRCore(filterType: String, cutoff: Seq[Double], numTaps: Int) extends Module with Config{
  val pyPath = "src/dsp/filter/fir.py"
  val command = filterType match {
    case "bp" | "bandpass" => Seq("python3",  pyPath, "bandpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString, cutoff(1).toString)
    case "lp" | "lowpass" => Seq("python3", pyPath ,"lowpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString)
    case "hp" | "highpass"=> Seq("python3", pyPath, "highpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString)
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

  val stage2Sums = Pipeline.buildBinaryTree(stage1Products)(_ + _)

  io.out := stage2Sums
}
 
 *
 *
 *
 */

class IIRCore(filterType: String, cutoff: Seq[Double], order: Int) extends Module with Config {
  val pyPath = "src/dsp/filter/iir.py"
  val command = filterType match {
    case "bp" | "bandpass" => Seq("python3", pyPath, "bandpass", sampleFreq.toString, order.toString, cutoff(0).toString, cutoff(1).toString)
    case "bs" | "bandstop" => Seq("python3", pyPath, "bandstop", sampleFreq.toString, order.toString, cutoff(0).toString, cutoff(1).toString)
    case "lp" | "lowpass" => Seq("python3", pyPath, "lowpass", sampleFreq.toString, order.toString, cutoff(0).toString)
    case "hp" | "highpass" => Seq("python3", pyPath, "highpass", sampleFreq.toString, order.toString, cutoff(0).toString)
    case _ => throw new IllegalArgumentException("Invalid filter type")
  }

  val result = command.!!.trim
  val lines = result.split("\n")
  val bCoeffs = lines(0).stripPrefix("b=").split(",").map(_.toDouble).toIndexedSeq
  val aCoeffs = lines(1).stripPrefix("a=").split(",").map(_.toDouble).toIndexedSeq

  val io = IO(new SISO(new FP)).suggestName("IIR")

  val b = VecInit(bCoeffs.map(FP(_)))
  val a = VecInit(aCoeffs.map(FP(_)))

  val xRegs = RegInit(VecInit(Seq.fill(b.length)( FP(0.0) )))
  val yRegs = RegInit(VecInit(Seq.fill(a.length)( FP(0.0) )))

  xRegs(0) := io.in
  yRegs(0) := io.out
  for (i <- 1 until b.length) {
    xRegs(i) := xRegs(i - 1)
  }
  for (i <- 1 until a.length) {
    yRegs(i) := yRegs(i - 1)
  }

  val stage1FFProducts = VecInit.tabulate(b.length) {
    i => RegNext(xRegs(i) * b(i))
  }
  val stage1FBProducts = VecInit.tabulate(a.length) {
    i => RegNext(yRegs(i) * a(i))
  }

  val stage2FFSums = Pipeline.buildBinaryTree(stage1FFProducts)(_ + _)
  val stage2FBSums = Pipeline.buildBinaryTree(stage1FBProducts)(_ + _)

  io.out := stage2FFSums - stage2FBSums
}
