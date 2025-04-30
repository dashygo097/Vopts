package mod.fsk

import datatype.fp.FP
import dds.trig.MultiCWCore

import chisel3._

class FSKIO extends Bundle {
  val in = Input(Bool())
  val out = Output(new FP)
}

class FSKCore(carrierFreq_0: Int, carrierFreq_1: Int) extends Module {
  val io = IO(new FSKIO)
  val cw_source = Module(new MultiCWCore(Seq(1.0, 1.0), Seq(carrierFreq_0, carrierFreq_1), Seq(0.0, 0.0)))

  io.out := Mux(io.in, cw_source.io(1).out, cw_source.io(0).out)
}
