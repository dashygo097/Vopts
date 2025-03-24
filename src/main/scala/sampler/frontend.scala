package sampler

import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage


object UpSampler extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new UpSamplerCore,
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/upsampler.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}

object DownSampler extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new DownSamplerCore(16),
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/downsampler.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}
