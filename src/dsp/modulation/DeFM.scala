package vopts.dsp.mod

import vopts.dsp.filter._
import vopts.math._
import vopts.utils._
import chisel3._

class DeFM[T <: Data](
  gen: T,
  carrierFreq: Int,
  deltaFreq: Double,
  clkFreq: Int,
  filterOrder: Int = 64
)(implicit analog: Analog[T], ord: PartialOrdered[T])
    extends Module {
  override def desiredName = s"defm_o${filterOrder}_cf${carrierFreq}_df$deltaFreq"
  val io                   = IO(new SISO(gen)).suggestName("DeFM")
  val bps                  = Module(
    new FIRFilter(
      gen,
      "bp",
      Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2),
      filterOrder,
      clkFreq
    )
  )
  val din                  = Wire(gen)
  val din_abs              = Wire(gen)
  val lps                  = Module(new FIRFilter(gen, "lp", Seq(carrierFreq.toDouble / 20), filterOrder, clkFreq))
  bps.io.in := io.in
  din       := RegNext(Derivator(bps.io.out))
  din_abs   := Abs(din)
  lps.io.in := RegNext(din_abs)
  io.out    := lps.io.out
}
