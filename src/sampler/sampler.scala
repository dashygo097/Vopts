package sampler 
import global.{Float, Config, FloatConverterCore}

import math.pow

import chisel3._
import chisel3.util._

class UpSamplerIO(inDataWidth: Int) extends Bundle {
  val in = Input(new Float(inDataWidth, inDataWidth - 1))
  val out = Output(new Float) 
}

class ScaledUpSamplerIO(inDataWidth: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new Float(inDataWidth, inDataWidth - 1))
  val out = Output(new Float)
}

class DownSamplerIO(outDataWidth: Int) extends Bundle with Config {
  val in = Input(new Float)
  val out = Output(new Float(outDataWidth, outDataWidth - 1))
}

class ScaledDownSamplerIO(outDataWidth: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new Float)
  val out = Output(new Float(outDataWidth, outDataWidth - 1))
}

class UpSamplerCore(inDataWidth: Int) extends Module with Config {
  val io = IO(new UpSamplerIO(inDataWidth))
  val converter = Module(new FloatConverterCore(inDataWidth, inDataWidth - 1, dataWidth, bp))
  converter.io.in := io.in
  io.out := converter.io.out
}

class ScaledUpSamplerCore(inDataWidth: Int, ctrlWidth: Int) extends Module with Config {
  val io = IO(new ScaledUpSamplerIO(inDataWidth, ctrlWidth))
  val converter = Module(new FloatConverterCore(inDataWidth, inDataWidth - 1, dataWidth, bp))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out
}

class DownSamplerCore(outDataWidth:Int) extends Module with Config {
  val io = IO(new DownSamplerIO(outDataWidth))
  val converter = Module(new FloatConverterCore(dataWidth, dataWidth - 1, outDataWidth, outDataWidth - 1))
  converter.io.in := io.in
  io.out := converter.io.out
}

class ScaledDownSamplerCore(outDataWidth: Int, ctrlWidth: Int) extends Module with Config {
  val io = IO(new ScaledDownSamplerIO(outDataWidth, ctrlWidth))
  val converter = Module(new FloatConverterCore(dataWidth, bp, outDataWidth, outDataWidth - 1))
  converter.io.in := io.in * (io.ctrl + 1.U)
  io.out := converter.io.out 
}
