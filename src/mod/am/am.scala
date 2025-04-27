package mod.am

import utils.{Float, Config}
import dds.trig.BaseTrigCore

import chisel3._
import chisel3.util._

class AMIO extends Bundle {
  val in = Input(new Float)
  val out =  Output(new Float)
}

class AMCore(carrierFreq: Int) extends Module with Config {
  val io = IO(new AMIO)
  val trig = Module(new BaseTrigCore(carrierFreq))

  trig.io.mag := io.in
  trig.io.phaseDelta := 0.U

  io.out := trig.io.out
}

object AM extends Config {
  var _carrierFreq: Int = defaultCarrierFreq

  def apply(in: Float): Float = {
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
