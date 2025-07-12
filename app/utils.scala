package app

import java.io.{BufferedWriter, File, FileWriter}

import _root_.circt.stage.ChiselStage

object VerilogEmitter {
  def parse(gen: => chisel3.Module, filename: String, info: Boolean = false): Unit = {
    val code = ChiselStage.emitSystemVerilog(
      gen = gen,
      firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
    )

    val num_lines = code.split("\n").length

    val buildDir = new File("build")
    if (!buildDir.exists()) buildDir.mkdirs()

    val file = new File(s"build/$filename")
    val bw = new BufferedWriter(new FileWriter(file))
    bw.write("`timescale 1ns / 1ps\n")
    bw.write(code)
    bw.close()

    val codePreview = code.split("\n").take(20).mkString("\n")
    if (info) {
      println(s"[INFO] Verilog emitted to $file")
      print(s"[INFO] Total lines: $num_lines\n")
      println("[INFO] Verilog code preview:")
      println(codePreview)
      println("...")
    }
  }
}
