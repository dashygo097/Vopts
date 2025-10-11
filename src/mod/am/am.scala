package mod.am

import dds.trig._
import utils._
import chisel3._

class AM[T <: Data](gen: T)(carrierFreq: Long, phaseDelta: Int, lutWidth: Int, clkFreq: Long)(
  implicit analog: Analog[T]
) extends Module {
  override def desiredName = s"am_cf$carrierFreq"
  val io                   = IO(new SISO(gen)).suggestName("AM")
  val trig                 = Module(new LiteTrigDDS(gen)(carrierFreq, phaseDelta, lutWidth, clkFreq))

  trig.io.mag        := io.in
  trig.io.phaseDelta := 0.U

  io.out := trig.io.out
}
