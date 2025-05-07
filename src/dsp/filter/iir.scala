package dsp.filter
import utils._

import datatype.fp._

import scala.sys.process._

import chisel3._

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

  val io = IO(new SISO(new FP))

  val b = VecInit(bCoeffs.map(FP(_)))
  val a = VecInit(aCoeffs.map(FP(_)))

  val xRegs = RegInit(VecInit(Seq.fill(b.length)( FP(0.0) )))
  val yRegs = RegInit(VecInit(Seq.fill(a.length)( FP(0.0) )))

  xRegs := io.in +: xRegs.init
  yRegs := io.out +: yRegs.init

  val feedforward = (xRegs zip b).map { case (x, coeff) => x * coeff }.reduce(_ + _)

  val feedback = (yRegs.tail zip a.tail).map { case (y, coeff) => y * coeff }.reduce(_ + _)

  io.out := feedforward - feedback
}
