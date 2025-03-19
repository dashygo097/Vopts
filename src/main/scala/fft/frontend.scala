package fft

import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

object FFT extends App with Config {
  val code = ChiselStage.emitSystemVerilog(
    gen = new MDCCore,
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/fft${n}.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") 
  bw.write(code)
  bw.close()

  println(code)
}
