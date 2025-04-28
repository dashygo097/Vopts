package dsp.resample

import utils.Float

import chisel3._

class InterpolatorIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
  val in_valid = Input(Bool())
  val out_valid = Output(Bool())
}

