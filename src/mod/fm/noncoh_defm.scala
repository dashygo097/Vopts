package mod.fm
import utils._

import datatype.fp._
import dsp.filter.FIRCore
import dsp.lut.{Derivator, Abs}

import chisel3._

class DeFMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new FPSISO)
  val bps = Module(new FIRCore("bp", Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2), 64))
  val din = Wire(new FP)
  val din_abs = Wire(new FP)
  val lps = Module(new FIRCore("lp", Seq(carrierFreq.toDouble / 20), 64))
  bps.io.in := io.in
  din := DataWrapper(Derivator(bps.io.out))
  din_abs := Abs(din)
  lps.io.in := DataWrapper(din_abs)
  io.out := lps.io.out
}

object DeFM extends Config {
  var _carrierFreq = defaultCarrierFreq
  var _deltaFreq = defaultFMDeltaFreq

  def apply(in: FP): FP = {
    val defm = Module(new DeFMCore(_carrierFreq, _deltaFreq))
    defm.io.in := in
    defm.io.out
  }

  def withCarrierFreq(carrierFreq: Int): Unit = {
    _carrierFreq = carrierFreq
  }

  def withDeltaFreq(deltaFreq: Int): Unit = {
    _deltaFreq = deltaFreq
  }

  def withConfig(carrierFreq: Int, deltaFreq: Int): Unit = {
    this.withCarrierFreq(carrierFreq)
    this.withDeltaFreq(deltaFreq)
  }
}


