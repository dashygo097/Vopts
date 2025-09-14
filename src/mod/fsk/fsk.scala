package mod.fsk

import dds.trig._

import utils._
import chisel3._

class FSKIO extends Bundle {
  val data = Input(Bool())
  val out = Output(new FP)
}

class FSK(carrierFreq_0: Int, carrierFreq_1: Int) extends Module {
  override def desiredName = s"fsk_cf0${carrierFreq_0}_cf1${carrierFreq_1}"
  val io = IO(new FSKIO).suggestName("FSK")
  val cw_source = Module(new MultiCWDDS(Seq(1.0, 1.0), Seq(carrierFreq_0, carrierFreq_1), Seq(0.0, 0.0)))

  io.out := Mux(io.data, cw_source.io.out(1), cw_source.io.out(0))
}
