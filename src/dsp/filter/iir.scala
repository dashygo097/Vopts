package dsp.filter

import scala.sys.process._
import utils._
import chisel3._

class IIRFilter[T <: Data](gen: T)(
  filterType: String,
  cutoff: Seq[Double],
  order: Int,
  clkFreq: Int,
  groupSize: Int = 2
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName: String =
    s"IIRCore_${filterType}_o${order}_g${groupSize}_${cutoff.mkString("_")}"
  val pyPath                       = "src/dsp/filter/iir.py"
  val command                      = filterType match {
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
    case "bs" | "bandstop" =>
      Seq(
        "python3",
        pyPath,
        "bandstop",
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

  val result  = command.!!.trim
  val lines   = result.split("\n")
  val bCoeffs = lines(0).stripPrefix("b=").split(",").map(_.toDouble).toIndexedSeq
  val aCoeffs = lines(1).stripPrefix("a=").split(",").map(_.toDouble).toIndexedSeq

  val io = IO(new SISO(gen)).suggestName("IIR")

  val b = VecInit(bCoeffs.map(gen.fromDouble(_)))
  val a = VecInit(aCoeffs.map(gen.fromDouble(_)))

  val xRegs = RegInit(VecInit(Seq.fill(b.length)(gen.fromDouble(0.0))))
  val yRegs = RegInit(VecInit(Seq.fill(a.length)(gen.fromDouble(0.0))))

  xRegs(0)   := io.in
  yRegs(0)   := io.out
  for (i <- 1 until b.length)
    xRegs(i) := xRegs(i - 1)
  for (i <- 1 until a.length)
    yRegs(i) := yRegs(i - 1)

  val stage1FFProducts = VecInit.tabulate(b.length) { i =>
    RegNext(xRegs(i) * b(i))
  }
  val stage1FBProducts = VecInit.tabulate(a.length) { i =>
    RegNext(yRegs(i) * a(i))
  }

  val stage2FFSums = Pipeline.buildTree(stage1FFProducts, groupSize)(_ + _)
  val stage2FBSums = Pipeline.buildTree(stage1FBProducts, groupSize)(_ + _)

  io.out := stage2FFSums - stage2FBSums
}
