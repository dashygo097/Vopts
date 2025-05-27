package func.common

import utils._
import chisel3._

class LimiterCore(threshold: Double) extends Module {
  val io = IO(new SISO(new FP))
  val thresholdValue = Wire(FP(threshold))
  val zero = Wire(FP(0.0))
  io.out := Mux(io.in > thresholdValue, thresholdValue, Mux(io.in < zero - thresholdValue, zero - thresholdValue, io.in))
} 
