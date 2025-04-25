package app

import utils._
import fm.{FMCore, DeFMCore}
import sampler.{UpSamplerCore, ScaledDownSamplerCore}

import chisel3._

class TxCoreIO extends Bundle {
  val ctrl = Input(UInt(4.W))
  val in = Input(new Float(12, 11))
  val out = Output(new Float(14, 13))
}

class TxCore extends Module {
  val io = IO(new TxCoreIO)

  val upsampler = Module(new UpSamplerCore(12))
  val fm = Module(new FMCore(1000000, 10000))
  val downsampler = Module(new ScaledDownSamplerCore(14, 4))

  upsampler.io.in := io.in
  fm.io.in := upsampler.io.out
  downsampler.io.ctrl := io.ctrl
  downsampler.io.in := fm.io.out * 0.25
  io.out := downsampler.io.out
}

object TX_2019G extends App {
  VerilogEmitter.parse(new TxCore, "2019g_tx.sv")
}
