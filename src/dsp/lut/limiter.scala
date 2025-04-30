package dsp.lut

import datatype.fp._

import chisel3._

class LimiterCore(threshold: Double) extends Module {
  val io = IO(new FPSISO)
  val thresholdValue = FP(threshold)
  val zero = FP(0.0)
  io.out := Mux(io.in > thresholdValue, thresholdValue, Mux(io.in < zero - thresholdValue, zero - thresholdValue, io.in))
} 
