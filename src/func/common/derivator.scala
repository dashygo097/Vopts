package func.common 

import utils._
import utils.ArithmeticSyntax._
import chisel3._

class DerivatorCore[T <: Data](gen: T)(implicit ev: Arithmetic[T]) extends Module {
  val io = IO(new SISO(gen))
  val prev = RegInit(Zero(gen))

  prev := io.in
  io.out := io.in - prev
}

object Derivator {
  def apply[T <: Data](in: T)(implicit ev: Arithmetic[T]): T = {
    val module = Module(new DerivatorCore(in))
    module.io.in := in
    module.io.out
  }
}
