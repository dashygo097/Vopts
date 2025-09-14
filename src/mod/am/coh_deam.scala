package mod.am

import dsp.filter._
import dds.trig._

import utils._
import chisel3._

class AnalogSyncDetectorIO extends Bundle {
  val in = Input(new FP)
  val carrier = Input(new FP)
  val out = Output(new FP)
}

class SDDeAM(carrierFreq: Int, baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  override def desiredName = s"deam_sd_cf${carrierFreq}_fl${baseFreqLimit}_o${filterOrder}"
  val io = IO(new SISO(new FP)).suggestName("DeAM_SD")
  val carrier_dds = Module(new CWDDS(1.0, carrierFreq, 0.0))
  val fir = Module(new FIRFilter("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := RegNext(io.in * carrier_dds.io.out)
  io.out := fir.io.out
}

class ASDDeAM(baseFreqLimit: Int, filterOrder: Int = 64) extends Module {
  override def desiredName = s"deam_asd_fl${baseFreqLimit}_o${filterOrder}"
  val io = IO(new AnalogSyncDetectorIO)
  val fir = Module(new FIRFilter("lp", Seq(baseFreqLimit), filterOrder))

  fir.io.in := RegNext(io.carrier * io.in)
  io.out := fir.io.out
}
