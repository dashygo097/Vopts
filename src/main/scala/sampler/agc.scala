package sampler
import global.Float

import chisel3._
import chisel3.util._

class AGCIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class AGCCore extends Module with Config {
  val io = IO(new AGCIO)
}
