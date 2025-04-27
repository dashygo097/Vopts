package dds.noise

import utils.{Float, Config}

import chisel3._
import chisel3.util.random._

class WhiteNoiseIO extends Bundle {
  val out = Output(new Float)
}

class WhiteNoiseCore extends Module with Config {
  val io = IO(new WhiteNoiseIO)
  val rand_sint = Module(new RandomSIntCore(dataWidth))

  io.out := rand_sint.io.out.asTypeOf(new Float)
}

object WhiteNoise {
  def apply(): Float = {
    val noise_source = Module(new WhiteNoiseCore)
    noise_source.io.out
  }
}
