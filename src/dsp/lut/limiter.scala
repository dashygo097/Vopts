package dsp.lut
import utils.Float

import chisel3._
import chisel3.util._

class LimiterIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class Limiter(threshold: Double) extends Module {
  val io = IO(new LimiterIO)
  val thresholdFloat = Float(threshold)
  val zero = Float(0.0)
  io.out := Mux(io.in > thresholdFloat, thresholdFloat, Mux(io.in < zero - thresholdFloat, zero - thresholdFloat, io.in))
} 
