package dds.noise
import utils._

import datatype.fp.FP

import chisel3._

class WhiteNoiseIO extends Bundle {
  val out = Output(new FP)
}

class WhiteNoiseCore extends Module with Config {
  val io = IO(new WhiteNoiseIO)
  val rand_sint = Module(new RandomSIntCore(dataWidth))

  io.out := rand_sint.io.out.asTypeOf(new FP)
}

object WhiteNoise {
  def apply(): FP = {
    val noise_source = Module(new WhiteNoiseCore)
    noise_source.io.out
  }
}
