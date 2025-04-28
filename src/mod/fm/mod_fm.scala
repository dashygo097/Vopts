package mod.fm
import utils._

import datatype.fp.FP
import dds.trig.TrigCore

import scala.math.pow

import chisel3._

class ModFMIO extends Bundle {
  val mod = Input(new FP)
  val in = Input(new FP)
  val out = Output(new FP)
}

class ModFMCore(mag: Double, carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new ModFMIO)
  val sine = Module(new TrigCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  sine.io.mag := (new FP).fromDouble(mag)
  sine.io.freqRatio := io.mod
  sine.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := sine.io.out
}

object ModFMCore extends Config {
  var _mag = 1.0
  var _carrierFreq = defaultCarrierFreq
  var _deltaFreq = defaultFMDeltaFreq

  def apply(in: FP, ctrl: UInt): FP = {
    val modfm = Module(new ModFMCore(_mag, _carrierFreq, _deltaFreq))
    modfm.io.in := in
    modfm.io.mod := ctrl
    modfm.io.out
  }

  def withMag(mag: Double): Unit = {
    _mag = mag
  }

  def withCarrierFreq(carrierFreq: Int): Unit = {
   _carrierFreq = carrierFreq
  }

  def withDeltaFreq(deltaFreq: Int): Unit = {
    _deltaFreq = deltaFreq
  }

  def withConfig(mag: Double, carrierFreq: Int, deltaFreq: Int): Unit = {
    this.withMag(mag)
    this.withCarrierFreq(carrierFreq)
    this.withDeltaFreq(deltaFreq)
  }
}


