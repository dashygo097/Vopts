package dsp.dds 

import utils._
import chisel3._
import chisel3.util.random._

class WhiteNoise[T <: Data](gen: T) extends Module {
  override def desiredName = s"whitenoise_${gen.toString().toLowerCase()}"
  val io                   = IO(new SO(gen))
  val lfsr                 = LFSR(gen.getWidth)

  io.out := lfsr.asTypeOf(gen)
}

object WhiteNoise {
  def apply[T <: Data](gen: T): T = {
    val noise_source = Module(new WhiteNoise(gen))
    noise_source.io.out
  }
}
