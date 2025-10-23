package mod.fm

import dds.trig._

import scala.math._
import utils._
import chisel3._

class FM[T <: Data](gen: T, 
  mag: Double,
  carrierFreq: Int,
  deltaFreq: Int,
  phaseWidth: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"fm_m${(mag * 1000).toInt}_cf${carrierFreq}_df$deltaFreq"
  val io                   = IO(new SISO(gen)).suggestName("FM")
  val trig                 = Module(new LiteTrigDDS(gen, carrierFreq, phaseWidth, lutWidth, clkFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / clkFreq * deltaFreq).toInt
  val deviation       = (io.in * gen.fromInt(deviationFactor)).apply(phaseWidth - 1, 0).asUInt

  trig.io.mag        := gen.fromDouble(mag)
  trig.io.phaseDelta := deviation

  io.out := trig.io.out

}
