package mod.am

import utils._
import datatype.fp._
import dsp.filter.FIRCore
import dds.trig.CWCore

import chisel3._

class AnalogSyncDetectorIO extends Bundle {
  val in = Input(new FP)
  val carrier = Input(new FP)
  val out = Output(new FP)
}

class SDDeAMCore(carrierFreq: Int, baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  val io = IO(new SISO(new FP))
  val carrier_dds = Module(new CWCore(1.0, carrierFreq, 0.0))
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := DataWrapper(io.in * carrier_dds.io.out)
  io.out := fir.io.out
}

class ASDDeAMCore(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  val io = IO(new AnalogSyncDetectorIO)
  val fir = Module(new FIRCore("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := DataWrapper(io.carrier * io.in)
  io.out := fir.io.out
}
