package func.resample

import chisel3._

class InterpolatorIO[T <: Data](gen: T) extends Bundle {
  val in = Input(gen)
  val out = Output(gen)
  val in_valid = Input(Bool())
  val out_valid = Output(Bool())
}

class Interpolator[T <: Data](gen: T, factor: Int) extends Module {
  val io = IO(new InterpolatorIO(gen))
}
