package app

import java.io.{BufferedWriter, File, FileWriter}

import _root_.circt.stage.ChiselStage

object VerilogEmitter {
  def parse(gen: => chisel3.Module, filename: String): Unit = {
    val code = ChiselStage.emitSystemVerilog(
      gen = gen,
      firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
    )

    val buildDir = new File("build")
    if (!buildDir.exists()) buildDir.mkdirs()

    val file = new File(s"build/$filename")
    val bw = new BufferedWriter(new FileWriter(file))
    bw.write("`timescale 1ns / 1ps\n")
    bw.write(code)
    bw.close()

    println(s"Verilog emitted to $file")
  }
}
