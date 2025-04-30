package mod.psk

import datatype.fp.FP
import dds.trig.BaseTrigCore

import chisel3._

class BPSKIO extends Bundle {
  val data = Input(Bool())
  val out = Output(new FP)
}

class BPSKCore(carrierFreq: Int) extends Module {
  val io = IO(new BPSKIO)
  val trig = Module(new BaseTrigCore(carrierFreq))
  val zero = FP(0.0)

  io.out := Mux(io.data, trig.io.out, zero - trig.io.out)
}

