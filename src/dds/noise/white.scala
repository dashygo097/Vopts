package dds.noise
import utils._

import datatype.fp._

import chisel3._

class WhiteNoiseCore extends Module with Config {
  val io = IO(new FPSO)
  val rand_sint = Module(new RandomSIntCore(dataWidth))

  io.out := rand_sint.io.out.asTypeOf(new FP)
}

object WhiteNoise {
  def apply(): FP = {
    val noise_source = Module(new WhiteNoiseCore)
    noise_source.io.out
  }
}
