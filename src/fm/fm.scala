package fm
import global.{Float, Config}

import scala.math._

import chisel3._
import chisel3.util._

class FMIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class DeFMIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class FMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new FMIO)
  val trig = Module(new dds.TrigCore(carrierFreq))

  trig.io.mag := (new Float).fromDouble(1.0)
  trig.io.phase_delta := ((deltaFreq.U * io.in.value) / pow(2, bp).toInt.S)(phaseWidth - 1, 0)

  io.out := trig.io.out
}

class DeFMCore(carrierFreq: Int, deltaFreq: Int) extends Module with Config {
  val io = IO(new DeFMIO)
  val bps = Module(new fir.FIRCore("bp", Seq(carrierFreq - deltaFreq * 2, carrierFreq + deltaFreq * 2), 64))
  val din = Wire(new Float)
  val din_abs = Wire(new Float)
  val lps = Module(new fir.FIRCore("lp", Seq(carrierFreq / 20), 64))
  bps.io.in := io.in
  din := DerivatorCore(bps.io.out)
  din_abs := AbsCore(din)
  lps.io.in := din_abs
  io.out := lps.io.out
}
