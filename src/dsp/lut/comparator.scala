package dsp.lut

import datatype.fp.FP

import chisel3._

class ComparatorIO extends Bundle {
  val io = Input(new FP)
  val out = Output(Bool())
}

class ComparatorCore(threshold: Double) extends Module {
  val io = IO(new ComparatorIO)
  val thresholdValue = FP(threshold)
  io.out := io.io < thresholdValue
}
