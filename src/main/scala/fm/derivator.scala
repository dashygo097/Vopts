package fm
import global.Float

import chisel3._
import chisel3.util._

class DerivatorIO extends Bundle {
  val in = Input(new Float)
  val out = Output(new Float)
}

class Derivator extends Module {
  val io = IO(new DerivatorIO)
  val prev = Reg(new Float)

  prev := io.in
  io.out := io.in - prev
}

object Derivator {
  def apply(in: Float): Float = {
    val module = Module(new Derivator)
    module.io.in := in
    module.io.out
  }
}
