package fm
import global.Float

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

class FMCore extends Module with Config {
  val io = IO(new FMIO)
  val trig = Module(new dds.TrigCore(carrierFreq))

  trig.io.mag := (new Float).fromDouble(1.0)
  trig.io.phase_delta := ((deltaFreq.U * io.in.value) / pow(2, bp).toInt.S)(phaseWidth - 1, 0)

  io.out := trig.io.out
}

class DeFMCore extends Module with Config {
  val io = IO(new DeFMIO)
  val din = Wire(new Float)
  val din_abs = Wire(new Float)
  val lps = Module(new fir.FIRCore("lp", Seq(carrierFreq / 10), 64))
  din := Derivator(io.in)
  din_abs := Abs(din)
  lps.io.in := din_abs
  io.out := lps.io.out
}
