package mod.fm

import dsp.filter.FIRCore
import math.{Derivator, Abs}

import utils._
import chisel3._

class DeFMCore(carrierFreq: Int, deltaFreq: Int, filterOrder: Int = 64) extends Module with Config {
  val io = IO(new SISO(new FP)).suggestName("DeFM")
  val bps = Module(new FIRCore("bp", Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2), filterOrder))
  val din = Wire(new FP)
  val din_abs = Wire(new FP)
  val lps = Module(new FIRCore("lp", Seq(carrierFreq.toDouble / 20), filterOrder))
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
    val defm = Module(new DeFMCore(_carrierFreq, _deltaFreq, _filterOrder))
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


