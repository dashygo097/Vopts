package dsp.resample

import data.fp.FP

import chisel3._

class InterpolatorIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
  val in_valid = Input(Bool())
  val out_valid = Output(Bool())
}

