package mod.am

import datatype.fp.FP

import chisel3._

class DeAMIO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}
