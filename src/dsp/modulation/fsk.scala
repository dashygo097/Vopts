package dsp.mod 

import dsp.dds._
import utils._
import chisel3._

class FSKIO[T <: Data](gen: T) extends Bundle {
  val data = Input(Bool())
  val out  = Output(gen)
}

class FSK[T <: Data](
  gen: T,
  carrierFreq_0: Int,
  carrierFreq_1: Int,
  phaseDelta: Int,
  lutWidth: Int,
  clkFreq: Int
)(implicit analog: Analog[T])
    extends Module {
  override def desiredName = s"fsk_cf0${carrierFreq_0}_cf1$carrierFreq_1"
  val io                   = IO(new FSKIO(gen)).suggestName("FSK")
  val cw_source            = Module(
    new MultiCWDDS(
      gen,
      Seq(1.0, 1.0),
      Seq(carrierFreq_0, carrierFreq_1),
      Seq(0.0, 0.0),
      phaseDelta,
      lutWidth,
      clkFreq
    )
  )

  io.out := Mux(io.data, cw_source.io.out(1), cw_source.io.out(0))
}
