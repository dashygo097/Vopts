package func.common

import datatype.fp.FP

import chisel3._

class ComparatorIO extends Bundle {
  val in = Input(new FP)
  val out = Output(Bool())
}

class ComparatorCore(threshold: Double) extends Module {
  val io = IO(new ComparatorIO)
  val thresholdValue = Wire(FP(threshold))
  io.out := io.in > thresholdValue
}
