package mod.am

import dds.trig._
import utils._
import chisel3._

class AM(carrierFreq: Int) extends Module {
  override def desiredName = s"am_cf${carrierFreq}"
  val io = IO(new SISO(new FP)).suggestName("AM")
  val trig = Module(new LiteTrigDDS(carrierFreq))

  trig.io.mag := io.in
  trig.io.phaseDelta := 0.U

  io.out := trig.io.out
}

object AM extends Config {
  var _carrierFreq: Int = defaultCarrierFreq

  def apply(in: FP): FP = {
    val amCore = Module(new AM(_carrierFreq))
    amCore.io.in := in
    amCore.io.out
  }

  def withCarrierFreq(carrierFreq: Int): Unit = {
    _carrierFreq = carrierFreq
  }

  def withConfig(carrierFreq: Int): Unit = {
    this.withCarrierFreq(carrierFreq)
  }
}
