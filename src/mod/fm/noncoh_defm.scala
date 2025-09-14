package mod.fm

import dsp.filter._
import math._
import utils._
import chisel3._

class DeFM(carrierFreq: Int, deltaFreq: Int, filterOrder: Int = 64) extends Module with Config {
  override def desiredName = s"defm_o${filterOrder}_cf${carrierFreq}_df${deltaFreq}"
  val io = IO(new SISO(new FP)).suggestName("DeFM")
  val bps = Module(new FIRFilter("bp", Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2), filterOrder))
  val din = Wire(new FP)
  val din_abs = Wire(new FP)
  val lps = Module(new FIRFilter("lp", Seq(carrierFreq.toDouble / 20), filterOrder))
  bps.io.in := io.in
  din := RegNext(Derivator(bps.io.out))
  din_abs := Abs(din)
  lps.io.in := RegNext(din_abs)
  io.out := lps.io.out
}

object DeFM extends Config {
  var _carrierFreq = defaultCarrierFreq
  var _deltaFreq = defaultFMDeltaFreq
  var _filterOrder = 64

  def apply(in: FP): FP = {
    val defm = Module(new DeFM(_carrierFreq, _deltaFreq, _filterOrder))
    defm.io.in := in
    defm.io.out
  }

  def withCarrierFreq(carrierFreq: Int): Unit = {
    _carrierFreq = carrierFreq
  }

  def withDeltaFreq(deltaFreq: Int): Unit = {
    _deltaFreq = deltaFreq
  }

  def withFilterOrder(filterOrder: Int): Unit = {
    _filterOrder = filterOrder
  }

  def withConfig(carrierFreq: Int, deltaFreq: Int): Unit = {
    this.withCarrierFreq(carrierFreq)
    this.withDeltaFreq(deltaFreq)
    this.withFilterOrder(_filterOrder)
  }
}


