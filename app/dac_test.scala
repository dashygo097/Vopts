package app

import dds.sine.CWCore
import sampler.ScaledDownSamplerCore
import utils.Float

import chisel3._

class DACoreIO extends Bundle {
  val ctrl = Input(UInt(4.W))
  val out = Output(new Float(14, 13))
}

class DACore extends Module {
  val io = IO(new DACoreIO)
  val dds = Module(new CWCore(0.5, 50000, 0))
  val sampler = Module(new ScaledDownSamplerCore(14, 13, 4))
  sampler.io.ctrl := io.ctrl
  sampler.io.in := dds.io.out
  io.out := sampler.io.out
}

object DATest extends App {
  VerilogEmitter.parse(new DACore, "dac_cw.sv")
}

