package dsp.mod

import dsp.dds._
import utils._
import chisel3._

class ASKIO[T <: Data](gen: T) extends Bundle {
  val data = Input(Bool())
  val out  = Output(gen)
}

class ASK[T <: Data](
  gen: T,
  mag: Double,
  carrierFreq: Int,
  phaseDelta: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"ask_m${(mag * 1000).toInt}_cf$carrierFreq"
  val io                   = IO(new ASKIO(gen)).suggestName("ASK")
  val cw                   = Module(new CWDDS(gen, mag, carrierFreq, 0.0, phaseDelta, lutWidth, clkFreq))
  val zero                 = gen.fromDouble(0.0)

  io.out := Mux(io.data, cw.io.out, zero)
}
