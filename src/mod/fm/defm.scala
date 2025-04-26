package mod.fm
import utils.{Float, Config}
import filter.fir.FIRCore
import dsp.lut.{Derivator, Abs}

import scala.math._

import chisel3._
import chisel3.util._

class DeFMIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class DeFMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new DeFMIO)
  val bps = Module(new FIRCore("bp", Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2), 64))
  val din = Wire(new Float)
  val din_abs = Wire(new Float)
  val lps = Module(new FIRCore("lp", Seq(carrierFreq / 20), 64))
  bps.io.in := io.in
  din := Derivator(bps.io.out)
  din_abs := Abs(din)
  lps.io.in := din_abs
  io.out := lps.io.out
}
