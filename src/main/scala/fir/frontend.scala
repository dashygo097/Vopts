package fir

import java.io.{BufferedWriter, File, FileWriter}
import scala.sys.process._

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

object FIR extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new FIRCore("lp", Seq(20000), 16),
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/fir.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}
