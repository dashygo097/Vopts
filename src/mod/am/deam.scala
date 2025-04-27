package mod.am

import utils.{Float, Config}

import chisel3._

class DeAMIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}
