package dsp.filter

import utils._
import chisel3._

class LMSCoreIO extends Bundle {
  val x = Input(new FP)
  val x_valid = Input(Bool())
  val y = Output(new FP)
  val d = Input(new FP)
  val e = Output(new FP)
  val e_valid = Input(Bool())
}

class LMSCore(order: Int, lr: Double = 0.01) extends Module {
  val io = IO(new LMSCoreIO)
  val coeffs = RegInit(VecInit(Seq.fill(order)(FP(0.0))))
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
