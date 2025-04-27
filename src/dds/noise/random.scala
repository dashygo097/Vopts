package dds.noise

import chisel3._
import chisel3.util.random._

class RandomUIntIO(noiseWidth: Int) extends Bundle {
  val out = Output(UInt(noiseWidth.W))
}

class RandomSIntIO(noiseWidth: Int) extends Bundle {
  val out = Output(SInt(noiseWidth.W))
}

class RandomUIntCore(noiseWidth: Int) extends Module {
  val io = IO(new RandomUIntIO(noiseWidth))
  io.out := LFSR(noiseWidth)
}

class RandomSIntCore(noiseWidth: Int) extends Module {
  val io = IO(new RandomSIntIO(noiseWidth))
  io.out := LFSR(noiseWidth).asSInt
}
