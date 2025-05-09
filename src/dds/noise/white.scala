package dds.noise
import utils._

import chisel3._
import chisel3.util.random._

class WhiteNoiseCore[T <: Data](gen: T) extends Module {
  val io = IO(new SO(gen))
  val lfsr = LFSR(gen.getWidth)

  io.out := lfsr.asTypeOf(gen)
}

object WhiteNoise {
  def apply[T <: Data](gen: T): T = {
    val noise_source = Module(new WhiteNoiseCore(gen))
    noise_source.io.out
  }
}
