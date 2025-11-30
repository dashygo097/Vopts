package dsp.mod

import dsp.dds._
import dsp.filter._
import math._
import utils._
import chisel3._

class AnalogSyncDetectorIO[T <: Data](gen: T) extends Bundle {
  val in      = Input(gen)
  val carrier = Input(gen)
  val out     = Output(gen)
}

class SDDeAM[T <: Data](
  gen: T,
  carrierFreq: Int,
  baseFreqLimit: Double,
  phaseWidth: Int,
  lutWidth: Int,
  clkFreq: Int,
  filterOrder: Int = 64
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"deam_sd_cf${carrierFreq}_fl${baseFreqLimit}_o$filterOrder"
  val io                   = IO(new SISO(gen)).suggestName("DeAM_SD")
  val carrier_dds          = Module(new CWDDS(gen, 1.0, carrierFreq, 0.0, phaseWidth, lutWidth, clkFreq))
  val fir                  = Module(new FIRFilter(gen, "lp", Seq(baseFreqLimit), filterOrder, clkFreq))

  fir.io.in := RegNext(io.in * carrier_dds.io.out)
  io.out    := fir.io.out
}

class ASDDeAM[T <: Data](gen: T)(baseFreqLimit: Double, clkFreq: Int, filterOrder: Int = 64)(implicit
  analog: Analog[T]
) extends Module {
  override def desiredName = s"deam_asd_fl${baseFreqLimit}_o$filterOrder"
  val io                   = IO(new AnalogSyncDetectorIO(gen))
  val fir                  = Module(new FIRFilter(gen, "lp", Seq(baseFreqLimit), filterOrder, clkFreq))

  fir.io.in := RegNext(io.carrier * io.in)
  io.out    := fir.io.out
}

class EDDeAM[T <: Data](gen: T, baseFreqLimit: Int, clkFreq: Int, filterOrder: Int = 64)(implicit
  analog: Analog[T],
  ord: PartialOrdered[T]
) extends Module {
  override def desiredName = s"deam_ed_fl${baseFreqLimit}_o$filterOrder"
  val io                   = IO(new SISO(gen)).suggestName("DeAM_ED")
  val fir                  = Module(new FIRFilter(gen, "lp", Seq(baseFreqLimit), filterOrder, clkFreq))

  fir.io.in := Abs(io.in)
  io.out    := fir.io.out
}
