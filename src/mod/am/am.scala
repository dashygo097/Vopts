package mod.am
import utils._

import datatype.fp._
import dds.trig.BaseTrigCore

import chisel3._

class AMCore(carrierFreq: Int) extends Module with Config {
  /*
  AM Modulator Core

  Description:
    This module implements an Amplitude Modulation (AM) modulator.
    NOTE: Input signal should be positive
  */
  val io = IO(new SISO(new FP))
  val trig = Module(new BaseTrigCore(carrierFreq))

  trig.io.mag := io.in
  trig.io.phaseDelta := 0.U

  io.out := trig.io.out
}

object AM extends Config {
  var _carrierFreq: Int = defaultCarrierFreq

  def apply(in: FP): FP = {
    val amCore = Module(new AMCore(_carrierFreq))
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
