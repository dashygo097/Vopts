package mod.fm

import dds.trig.BaseTrigCore

import scala.math._
import utils._
import chisel3._

class FMCore(mag: Double, carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new SISO(new FP))
  val trig = Module(new BaseTrigCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  trig.io.mag := (new FP).fromDouble(mag)
  trig.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := trig.io.out
}

object FM extends Config {
  var _mag: Double = 1.0
  var _carrierFreq: Int = defaultCarrierFreq
  var _deltaFreq: Int = defaultFMDeltaFreq

  def apply(in: FP): FP = {
    val fm = Module(new FMCore(_mag, _carrierFreq, _deltaFreq))
    fm.io.in := in
    fm.io.out
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
