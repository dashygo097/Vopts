package fir
import global.{Float, Config}

import scala.sys.process._

import chisel3._
import chisel3.util._


class FIRIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class FIRCore(filterType: String, cutoff: Seq[Double], numTaps: Int) extends Module with Config{
  val pyPath = "src/main/scala/fir/fir.py"
  val command = filterType match {
    case "bp" => Seq("python3",  pyPath, "bandpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString, cutoff(1).toString)
    case "lp"  => Seq("python3", pyPath ,"lowpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString)
    case "hp" => Seq("python3", pyPath, "highpass", sampleFreq.toString, numTaps.toString, cutoff(0).toString)
    case _ => throw new IllegalArgumentException("Invalid filter type")
  }
  val result = command.!!.trim
  val taps = result.split(",").map(_.toDouble).toIndexedSeq

  val io = IO(new FIRIO)
  val regs = RegInit(VecInit(Seq.fill(taps.length)( Float(0.0))))
  val coeffs = VecInit(taps.map( c => Float(c) ))

  regs := io.in +: regs.init

  io.out := (regs zip coeffs).map { case (r, c) => r * c }.reduce(_ + _)

}

