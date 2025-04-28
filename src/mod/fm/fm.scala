package mod.fm
import utils._

import data.fp.FP
import dds.trig.{BaseTrigCore, TrigCore}

import scala.math._

import chisel3._
import chisel3.util._

class FMIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class FMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new FMIO)
  val trig = Module(new BaseTrigCore(carrierFreq))

  val deviationFactor = (pow(2.0, phaseWidth) / sampleFreq * deltaFreq).toInt
  val deviation = ((io.in.value * deviationFactor.S) >> bp)(phaseWidth - 1, 0).asUInt

  trig.io.mag := (new FP).fromDouble(1.0)
  trig.io.phaseDelta := DataWrapper(deviation) // Convert combitional signal to sequential signal 

  io.out := trig.io.out
}

object FM extends Config {
  var _carrierFreq: Int = defaultCarrierFreq
  var _deltaFreq: Int = defaultFMDeltaFreq

  def apply(in: FP): FP = {
    val fm = Module(new FMCore(_carrierFreq, _deltaFreq))
    fm.io.in := in
    fm.io.out
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
