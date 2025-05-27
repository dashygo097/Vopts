package mod.fsk

import dds.trig.MultiCWCore

import utils._
import chisel3._

class FSKIO extends Bundle {
  val data = Input(Bool())
  val out = Output(new FP)
}

class FSKCore(carrierFreq_0: Int, carrierFreq_1: Int) extends Module {
  val io = IO(new FSKIO)
  val cw_source = Module(new MultiCWCore(Seq(1.0, 1.0), Seq(carrierFreq_0, carrierFreq_1), Seq(0.0, 0.0)))

  io.out := Mux(io.data, cw_source.io.out(1), cw_source.io.out(0))
}
