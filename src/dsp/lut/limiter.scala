package dsp.lut

import datatype.fp.FP

import chisel3._

class LimiterIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class LimiterCore(threshold: Double) extends Module {
  val io = IO(new LimiterIO)
  val thresholdValue = FP(threshold)
  val zero = FP(0.0)
  io.out := Mux(io.in > thresholdValue, thresholdValue, Mux(io.in < zero - thresholdValue, zero - thresholdValue, io.in))
} 
