package func.common 

import utils._
import datatype.fp._

import chisel3._

class DerivatorCore extends Module {
  val io = IO(new SISO(new FP))
  val prev = RegInit(FP(0.0))

  prev := io.in
  io.out := io.in - prev
}

object Derivator {
  def apply(in: FP): FP = {
    val module = Module(new DerivatorCore)
    module.io.in := in
    module.io.out
  }
}
