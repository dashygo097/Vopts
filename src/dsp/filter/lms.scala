package dsp.filter

import utils._
import sys.process._
import chisel3._

class LMSCoreIO extends Bundle {
  val x = Input(new FP)
  val x_valid = Input(Bool())
  val y = Output(new FP)
  val d = Input(new FP)
  val e = Output(new FP)
  val e_valid = Input(Bool())
}

class LMSCore(order: Int, cutoff: Seq[Double], lr: Double = 0.001) extends Module with Config {
  override def desiredName = s"lms_o${order}_${cutoff.mkString("_")}"
  val pyPath = "src/dsp/filter/fir.py"
  val command = Seq("python3",  pyPath, "bandpass", sampleFreq.toString, order.toString, cutoff(0).toString, cutoff(1).toString)

  val result = command.!!.trim
  val taps = result.split(",").map(_.toDouble).toIndexedSeq

  val io = IO(new LMSCoreIO).suggestName("LMS")
  val coeffs = RegInit(VecInit(taps.map(FP(_))))
  val xHistory = RegInit(VecInit(Seq.fill(order)(FP(0.0))))
  val mu = FP(lr)

  io.y := coeffs.zip(xHistory).map { case (c, x) => c * x }.reduce(_ + _)
  io.e := io.d - io.y
  when(io.x_valid) {
    xHistory(0) := io.x
    for (i <- 1 until order) {
      xHistory(i) := xHistory(i - 1)
    }
  }

  when(io.e_valid) {
    for (i <- 0 until order) {
      coeffs(i) := coeffs(i) + mu * io.e * xHistory(i)
    }
  }
}
