package dsp.filter

import utils._
import sys.process._
import chisel3._

class LMSFilterIO[T <: Data](gen: T) extends Bundle {
  val x       = Input(gen)
  val x_valid = Input(Bool())
  val y       = Output(gen)
  val d       = Input(gen)
  val e       = Output(gen)
  val e_valid = Input(Bool())
}

class LMSFilter[T <: Data](gen: T, 
  order: Int,
  cutoff: Seq[Double],
  clkFreq: Int,
  lr: Double = 0.001
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"lms_o${order}_${cutoff.mkString("_")}"
  val pyPath               = "src/dsp/filter/fir.py"
  val command              = Seq(
    "python3",
    pyPath,
    "bandpass",
    clkFreq.toString,
    order.toString,
    cutoff(0).toString,
    cutoff(1).toString
  )

  val result = command.!!.trim
  val taps   = result.split(",").map(_.toDouble).toIndexedSeq

  val io       = IO(new LMSFilterIO(gen)).suggestName("LMS")
  val coeffs   = RegInit(VecInit(taps.map(gen.fromDouble(_))))
  val xHistory = RegInit(VecInit(Seq.fill(order)(gen.fromDouble(0.0))))
  val mu       = gen.fromDouble(lr)

  io.y := coeffs.zip(xHistory).map { case (c, x) => c * x }.reduce(_ + _)
  io.e := io.d - io.y
  when(io.x_valid) {
    xHistory(0)   := io.x
    for (i <- 1 until order)
      xHistory(i) := xHistory(i - 1)
  }

  when(io.e_valid) {
    for (i <- 0 until order)
      coeffs(i) := coeffs(i) + mu * io.e * xHistory(i)
  }
}
