package sampler 
import global.Float

import math.pow

import chisel3._
import chisel3.util._

class UpSamplerIO extends Bundle with Config {
  val in = Input(SInt(inDataWidth.W)) 
  val out = Output(new Float) 
}

class DownSamplerIO extends Bundle with Config {
  val in = Input(new Float)
  val out = Output(SInt(outDataWidth.W))
}

class UpSamplerCore extends Module with Config {
  val io = IO(new UpSamplerIO)
  io.out := (io.in << bp).asTypeOf(new Float)
}

class DownSamplerCore(retainBit: Int) extends Module with Config {
  // A Slicer 
  val io = IO(new DownSamplerIO)
  io.out := ((io.in.value << retainBit) >> bp).asTypeOf(SInt(outDataWidth.W))
}
