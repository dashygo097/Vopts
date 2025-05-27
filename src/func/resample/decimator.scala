package func.resample

import chisel3._
import chisel3.util._

class DecimatorIO[T <: Data](gen: T) extends Bundle {
  val in = Input(gen)
  val out = Output(gen)
  val in_valid = Input(Bool())
  val out_valid = Output(Bool())
}

class DecimatorCore[T <: Data](gen: T, factor: Int) extends Module {
  val io = IO(new DecimatorIO(gen))
  val count = RegInit(0.U(log2Ceil(factor).W))

  count := Mux(io.in_valid, Mux(count === (factor - 1).U, 0.U, count + 1.U), count)

  io.out_valid := io.in_valid && (count === 0.U)
  io.out := io.in
}

object Decimator {
  
  var _factor: Int = 1

  def apply[T <: Data](in: T, in_valid: Bool): (T, Bool) = {
    val decimator = Module(new DecimatorCore(in, _factor))
    decimator.io.in := in
    decimator.io.in_valid := in_valid
    (decimator.io.out, decimator.io.out_valid)
  }

  def withFactor(factor: Int): Unit = {
    _factor = factor
  }

  def withConfig(factor: Int): Unit = {
    this.withFactor(factor)
  }
}
