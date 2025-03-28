import dds.CWCore
import fft.MDCCore

import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

object CW extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new CWCore(1.0, 1000, 90.0),
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/dds_cw.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}

object FFT extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new MDCCore(512),
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/dds_cw.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}
