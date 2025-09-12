package mod.ask

import dds.trig.CWCore

import utils._
import chisel3._

class ASKIO extends Bundle {
  val data = Input(Bool())
  val out = Output(new FP)
}

class ASKCore(mag: Double, carrierFreq: Int) extends Module with Config {
  override def desiredName = s"ask_m${(mag * 1000).toInt}_cf${carrierFreq}"
  val io = IO(new ASKIO).suggestName("ASK")
  val cw = Module(new CWCore(mag, carrierFreq, 0.0))
  val zero = FP(0.0)

  io.out := Mux(io.data, cw.io.out, zero)
}
