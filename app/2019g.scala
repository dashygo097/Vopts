package app
import utils._

import datatype.fp._
import mod.fm.{FMCore, ModFMCore}

import chisel3._

class TxCoreIO extends Bundle {
  val ctrl = Input(UInt(4.W))
  val in = Input(new FP(12, 11))
  val out = Output(new FP(14, 13))
}

class TxCoreIO_Advanced extends Bundle {
  val ctrl = Input(UInt(4.W))
  val mod = Input(new FP(12, 11))
  val in = Input(new FP(12, 11))
  val out = Output(new FP(14, 13))
}

class TxCore extends Module {
  val io = IO(new TxCoreIO)

  val fm = Module(new FMCore(1.0, 15500000, 10000))
  val downsampler = Module(new ScaledDownSamplerCore(14, 13, 4))

  fm.io.in := DataWrapper(UpSample(io.in))
  downsampler.io.ctrl := io.ctrl
  downsampler.io.in := DataWrapper(fm.io.out * 0.25)
  io.out := downsampler.io.out
}

class TxCore_Advanced extends Module {
  val io = IO(new TxCoreIO_Advanced)

  val upsampler_mod = Module(new UpSamplerCore(12, 11))
  val fm = Module(new ModFMCore(1.0, 15500000, 10000))
  val downsampler = Module(new ScaledDownSamplerCore(14, 13, 4))

  upsampler_mod.io.in := io.mod
  fm.io.in := DataWrapper(UpSample(io.in))
  fm.io.mod := DataWrapper(upsampler_mod.io.out)
  downsampler.io.ctrl := io.ctrl
  downsampler.io.in := DataWrapper(fm.io.out * 0.25)
  io.out := downsampler.io.out
}

object TX_2019G extends App {
  VerilogEmitter.parse(new TxCore, "2019g_tx.sv")
}

object TX_2019G_Advanced extends App {
  VerilogEmitter.parse(new TxCore_Advanced, "2019g_tx_advanced.sv")
}
