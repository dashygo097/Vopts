package sampler 
import global.Float

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
}

class DownSamplerCore extends Module with Config {
  val io = IO(new DownSamplerIO)
}
