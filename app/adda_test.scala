package app
import sampler.{UpSamplerCore, ScaledDownSamplerCore}
import utils.Float

import chisel3._

class ADDACoreIO extends Bundle{
  val ctrl = Input(UInt(4.W))
  val in = Input(new Float(12, 11))
  val out = Output(new Float(14, 13))
}

class ADDACore extends Module {
  val io = IO(new ADDACoreIO)

  val upSampler = Module(new UpSamplerCore(12))
  val downSampler = Module(new ScaledDownSamplerCore(14, 4))

  upSampler.io.in := io.in
  downSampler.io.in := upSampler.io.out
  downSampler.io.ctrl := io.ctrl
  io.out := downSampler.io.out

}

object ADDATest extends App {
  VerilogEmitter.parse(new ADDACore, "adda_test.sv")
}

