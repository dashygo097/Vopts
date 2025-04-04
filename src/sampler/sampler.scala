package sampler 
import global.{Float, Config}

import math.pow

import chisel3._
import chisel3.util._

class UpSamplerIO(inDataWidth: Int) extends Bundle {
  val in = Input(SInt(inDataWidth.W)) 
  val out = Output(new Float) 
}

class DownSamplerIO(outDataWidth: Int) extends Bundle with Config {
  val in = Input(new Float)
  val out = Output(SInt(outDataWidth.W))
}

class ScaledDownSamplerIO(outDataWidth: Int, ctrlWidth: Int) extends Bundle with Config {
  val ctrl = Input(UInt(ctrlWidth.W))
  val in = Input(new Float)
  val out = Output(SInt(outDataWidth.W))
}

class UpSamplerCore(inDataWidth: Int) extends Module with Config {
  val io = IO(new UpSamplerIO(inDataWidth))
  io.out := (io.in << (bp - inDataWidth)).asTypeOf(new Float)
}

class DownSamplerCore(outDataWidth:Int, retainBit: Int) extends Module with Config {
  // A Slicer 
  val io = IO(new DownSamplerIO(outDataWidth))
  io.out := ((io.in.value << retainBit) >> bp).asTypeOf(SInt(outDataWidth.W))
}

class ScaledDownSamplerCore(outDataWidth: Int, ctrlWidth: Int) extends Module with Config {
  // A Slicer 
  val io = IO(new ScaledDownSamplerIO(outDataWidth, ctrlWidth))
  io.out := ((io.in.value << io.ctrl) >> bp).asTypeOf(SInt(outDataWidth.W))
}
