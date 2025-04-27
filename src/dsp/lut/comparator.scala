package dsp.lut

import utils.Float

import chisel3._

class ComparatorIO extends Bundle {
  val io = Input(new Float)
  val out = Output(Bool())
}

class ComparatorCore(threshold: Double) extends Module {
  val io = IO(new ComparatorIO)
  val thresholdFloat = Float(threshold)
  io.out := io.io < thresholdFloat
}
