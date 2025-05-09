package utils

import chisel3._

class SO[T <: Data](gen: T) extends Bundle {
  val out = Output(gen)
}

class MO[T <: Data](gen: T, outs: Int) extends Bundle {
  val out = Output(Vec(outs, gen))
}

class SISO[T <: Data](gen: T) extends Bundle {
  val in = Input(gen)
  val out = Output(gen)
}

class SIMO[T <: Data](gen: T, outs: Int) extends Bundle {
  val in = Input(gen)
  val out = Output(Vec(outs, gen))
}

class MISO[T <: Data](gen: T, ins: Int) extends Bundle {
  val in = Input(Vec(ins, gen))
  val out = Output(gen)
}

class MIMO[T <: Data](gen: T, ins: Int, outs: Int) extends Bundle {
  val in = Input(Vec(ins, gen))
  val out = Output(Vec(outs, gen))
}

