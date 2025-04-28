package dsp.resample

import data.fp.FP

import chisel3._
import chisel3.util._

class DecimatorIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
  val in_valid = Input(Bool())
  val out_valid = Output(Bool())
}

class DecimatorCore(factor: Int) extends Module {
  val io = IO(new DecimatorIO)
  val count = RegInit(0.U(log2Ceil(factor).W))

  count := Mux(io.in_valid, Mux(count === (factor - 1).U, 0.U, count + 1.U), count)

  io.out_valid := io.in_valid && (count === 0.U)
  io.out := io.in
}

object Decimator {
  
  var _factor: Int = 1

  def apply(in: FP, in_valid: Bool): (FP, Bool) = {
    val decimator = Module(new DecimatorCore(_factor))
    decimator.io.in := in
    decimator.io.in_valid := in_valid
    (decimator.io.out, decimator.io.out_valid)
  }

  def withFactor(factor: Int): Unit = {
    _factor = factor
  }

  def withConfig(factor: Int): Unit = {
    this.withFactor(factor)
  }
}
