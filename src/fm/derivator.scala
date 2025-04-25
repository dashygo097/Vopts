package fm
import utils.Float

import chisel3._
import chisel3.util._

class DerivatorIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class DerivatorCore extends Module {
  val io = IO(new DerivatorIO)
  val prev = Reg(new Float)

  prev := io.in
  io.out := io.in - prev
}

object DerivatorCore {
  def apply(in: Float): Float = {
    val module = Module(new DerivatorCore)
    module.io.in := in
    module.io.out
  }
}
