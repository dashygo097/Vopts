import global._
import fm.FMCore
import sampler.{UpSamplerCore, ScaledDownSamplerCore}

import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

class TxCoreIO extends Bundle {
  val ctrl = Input(UInt(4.W))
  val in = Input(SInt(12.W))
  val out = Output(SInt(14.W))
}

class TxCore extends Module {
  val io = IO(new TxCoreIO)

  val upsampler = Module(new UpSamplerCore(12))
  val fm = Module(new FMCore(1000000, 10000))
  val downsampler = Module(new ScaledDownSamplerCore(14, 4))

  upsampler.io.in := io.in
  fm.io.in := upsampler.io.out
  downsampler.io.ctrl := io.ctrl
  downsampler.io.in := fm.io.out
  io.out := downsampler.io.out
}


object TX extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new TxCore,
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/2019g_tx.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}
