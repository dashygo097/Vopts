package sampler 
import utils.{Float, Config, FloatConverterCore}

import math.pow

import chisel3._
import chisel3.util._

class DownSamplerIO(outDataWidth: Int, outBp: Int) extends Bundle with Config {
  val in = Input(new Float)
  val out = Output(new Float(outDataWidth, outBp))
}

class ScaledDownSamplerIO(outDataWidth: Int, outBp: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new Float)
  val out = Output(new Float(outDataWidth, outDataWidth - 1))
}
class DownSamplerCore(outDataWidth: Int, outBp: Int) extends Module with Config {
  val io = IO(new DownSamplerIO(outDataWidth, outBp))
  val converter = Module(new FloatConverterCore(dataWidth, bp, outDataWidth, outDataWidth - 1))
  converter.io.in := io.in
  io.out := converter.io.out
}

class ScaledDownSamplerCore(outDataWidth: Int, outBp: Int, ctrlWidth: Int) extends Module with Config {
  val io = IO(new ScaledDownSamplerIO(outDataWidth, outBp, ctrlWidth))
  val converter = Module(new FloatConverterCore(dataWidth, bp, outDataWidth, outDataWidth - 1))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out 
}
