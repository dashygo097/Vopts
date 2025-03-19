package fm

import java.io.{BufferedWriter, File, FileWriter}

import chisel3._
import chisel3.util._

import _root_.circt.stage.ChiselStage

object FM extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new FMCore,
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/fm.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}

object DeFM extends App {
  val code = ChiselStage.emitSystemVerilog(
    gen = new DeFMCore,
    firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  )

  val buildDir = new File("build")
  if (!buildDir.exists()) buildDir.mkdir()
  
  val file = new File(s"build/fm_de.sv")
  val bw = new BufferedWriter(new FileWriter(file))
  bw.write("`timescale 1ns / 1ps\n") // by default, 1ns/1ps
  bw.write(code)
  bw.close()

  println(code)
}
