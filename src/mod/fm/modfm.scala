package mod.fm

import utils.{Float, Config, DataWrapper}
import dds.sine.SineCore

import scala.math.pow

import chisel3._

class ModFMIO extends Bundle {
  val mod = Input(new Float)
  val in = Input(new Float)
  val out = Output(new Float)
}

class ModFMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new ModFMIO)
  val sine = Module(new SineCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  sine.io.mag := (new Float).fromDouble(1.0)
  sine.io.freqRatio := io.mod
  sine.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := sine.io.out
}

object ModFMCore extends Config {
  var _carrierFreq = defaultCarrierFreq
  var _deltaFreq = defaultFMDeltaFreq

  def apply(in: Float, ctrl: UInt): Float = {
    val modfm = Module(new ModFMCore(_carrierFreq, _deltaFreq))
    modfm.io.in := in
    modfm.io.mod := ctrl
    modfm.io.out
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


