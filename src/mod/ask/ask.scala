package mod.ask
import utils._

import dds.trig.CWCore
import datatype.fp.FP

import chisel3._

class ASKIO extends Bundle {
  val in = Input(Bool())
  val out = Output(new FP)
}

class ASKCore(mag: Double, carrierFreq: Int) extends Module with Config {
  val io = IO(new ASKIO)
  val cw = Module(new CWCore(mag, carrierFreq, 0.0))
  val zero = FP(0.0)

  io.out := Mux(io.in, cw.io.out, zero)
}
