package vopts.dsp.mod

import vopts.dsp.dds._
import vopts.utils._
import chisel3._

class AM[T <: Data](gen: T, carrierFreq: Int, phaseDelta: Int, lutWidth: Int, clkFreq: Int)(implicit
  analog: Analog[T]
) extends Module {
  override def desiredName = s"am_cf$carrierFreq"
  val io                   = IO(new SISO(gen)).suggestName("AM")
  val trig                 = Module(new LiteTrigDDS(gen, carrierFreq, phaseDelta, lutWidth, clkFreq))

  trig.io.mag        := io.in
  trig.io.phaseDelta := 0.U

  io.out := trig.io.out
}
