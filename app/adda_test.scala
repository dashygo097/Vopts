package app
import utils._

import chisel3._

class ADDACoreIO extends Bundle{
  val ctrl = Input(UInt(4.W))
  val in = Input(new Float(12, 11))
  val out = Output(new Float(14, 13))
}

class ADDACore extends Module {
  val io = IO(new ADDACoreIO)

  val downsampler = Module(new ScaledDownSamplerCore(14, 13, 4))

  downsampler.io.in := UpSample(io.in) 
  downsampler.io.ctrl := io.ctrl
  io.out := downsampler.io.out

}

object ADDATest extends App {
  VerilogEmitter.parse(new ADDACore, "adda_test.sv")
}

