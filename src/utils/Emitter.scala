package vopts.utils

import java.io.{ BufferedWriter, File, FileWriter }
import _root_.circt.stage.ChiselStage
import scala.sys.process._

object DesignEmitter {

  sealed trait EmitTarget
  case object SystemVerilog extends EmitTarget
  case object FIRRTL        extends EmitTarget
  case object MLIR          extends EmitTarget

  def emit(
    gen: => chisel3.Module,
    filename: String,
    target: EmitTarget = SystemVerilog,
    info: Boolean = true,
    lowering: Boolean = false,
    options: Seq[String] = Seq()
  ): Unit =
    target match {
      case SystemVerilog => emitSystemVerilog(gen, filename, info, lowering, options)
      case FIRRTL        => emitFIRRTL(gen, filename, info)
      case MLIR          => emitMLIR(gen, filename, info, lowering, options)
    }

  private def emitSystemVerilog(
    gen: => chisel3.Module,
    filename: String,
    info: Boolean,
    lowering: Boolean,
    options: Seq[String]
  ): Unit = {
    val firtoolOpts = if (lowering) {
      options ++
        Seq("--lowering-options=disallowLocalVariables,disallowPackedArrays")
    } else {
      options
    }

    val code = ChiselStage.emitSystemVerilog(
      gen = gen,
      firtoolOpts = Array(
        "-disable-all-randomization",
        "-strip-debug-info",
        "--disable-layers=Verification",
        "--disable-layers=Verification.Assert",
        "--disable-layers=Verification.Assume",
        "--disable-layers=Verification.Cover",
      ) ++ firtoolOpts
    )

    writeToFile(s"$filename.sv", code, "`timescale 1ns / 1ps\n", info)
  }

  private def emitFIRRTL(
    gen: => chisel3.Module,
    filename: String,
    info: Boolean
  ): Unit = {
    val firrtl = ChiselStage.emitCHIRRTL(gen)

    writeToFile(s"$filename.fir", firrtl, "", info)

    if (info) {
      println(s"[INFO] FIRRTL will be converted to MLIR by CMake/firtool")
      println(s"[INFO] For manual conversion, run:")
      println(s"[INFO]   firtool build/$filename.fir -ir-fir -o build/$filename.mlir")
    }
  }

  private def emitMLIR(
    gen: => chisel3.Module,
    filename: String,
    info: Boolean,
    lowering: Boolean,
    options: Seq[String]
  ): Unit = {
    val firrtl     = ChiselStage.emitCHIRRTL(gen)
    val firrtlFile = s"build/$filename.fir"
    val mlirFile   = s"build/$filename.mlir"

    val buildDir = new File("build")
    if (!buildDir.exists()) buildDir.mkdirs()

    val fw = new BufferedWriter(new FileWriter(new File(firrtlFile)))
    fw.write(firrtl)
    fw.close()

    val firtoolPath =
      try
        "which firtool".!!.trim
      catch {
        case _: Exception =>
          if (info) {
            println("[ERROR] firtool not found in PATH")
            println("[INFO] Falling back to FIRRTL output")
            println("[INFO] Install CIRCT or set PATH to include firtool")
          }
          return
      }

    if (info) println(s"[INFO] Using firtool: $firtoolPath")

    val firtoolOpts = if (lowering) {
      options ++ Seq("--lowering-options=disallowLocalVariables,disallowPackedArrays")
    } else {
      options
    }

    val irTarget = if (lowering) "-ir-hw" else "-ir-fir"

    val firtoolCmd = Seq(
      "firtool",
      firrtlFile,
      irTarget,
      "-o",
      mlirFile
    ) ++ firtoolOpts

    try {
      val result = firtoolCmd.!!

      if (info) {
        println(s"[INFO] MLIR emitted to build/$filename.mlir")

        val mlirContent = scala.io.Source.fromFile(mlirFile).mkString
        val numLines    = mlirContent.split("\n").length
        val preview     = mlirContent.split("\n").take(20).mkString("\n")

        println(s"[INFO] Total lines: $numLines")
        println("[INFO] MLIR code preview:")
        println(preview)
        println("...")
      }

    } catch {
      case e: Exception =>
        if (info) {
          println(s"[ERROR] firtool conversion failed: ${e.getMessage}")
          println(s"[INFO] FIRRTL file kept at: $firrtlFile")
        }
    }
  }

  private def writeToFile(
    filename: String,
    content: String,
    header: String,
    info: Boolean
  ): Unit = {
    val buildDir = new File("build")
    if (!buildDir.exists()) buildDir.mkdirs()

    val file = new File(s"build/$filename")
    val bw   = new BufferedWriter(new FileWriter(file))
    if (header.nonEmpty) bw.write(header)
    bw.write(content)
    bw.close()

    if (info) {
      val numLines = content.split("\n").length
      val preview  = content.split("\n").take(20).mkString("\n")

      println(s"[INFO] Output emitted to build/$filename")
      println(s"[INFO] Total lines: $numLines")
      println("[INFO] Preview:")
      println(preview)
      println("...")
    }
  }
}

object VerilogEmitter {
  def parse(
    gen: => chisel3.Module,
    filename: String,
    info: Boolean = true,
    lowering: Boolean = false,
    options: Seq[String] = Seq()
  ): Unit =
    DesignEmitter.emit(
      gen = gen,
      filename = filename.stripSuffix(".sv"),
      target = DesignEmitter.SystemVerilog,
      info = info,
      lowering = lowering,
      options = options
    )
}
