package fm
import global.Float

import scala.math._

import chisel3._
import chisel3.util._

class FMCoreIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class DeFMCoreIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class FMCore extends Module with Config {
  val io = IO(new FMCoreIO)
  val trig = Module(new dds.TrigCore(carrierFreq))

  trig.io.mag := (new Float).fromDouble(1.0)
  trig.io.phase_delta := ((deltaFreq.U * io.in.value) / pow(2, bp).toInt.S)(phaseWidth - 1, 0)

  io.out := trig.io.out
}


class DeFMCore extends Module with Config {
  val io = IO(new DeFMCoreIO)
}
