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

class DSISO[InT <: Data, OutT <: Data](inGen: InT, outGen: OutT) extends Bundle {
  val in = Input(inGen)
  val out = Output(outGen)
}

class SIMO[T <: Data](gen: T, outs: Int) extends Bundle {
  val in = Input(gen)
  val out = Output(Vec(outs, gen))
}

class DSIMO[InT <: Data, OutT <: Data](inGen: InT, outs: (OutT, Int)) extends Bundle {
  val in = Input(inGen)
  val out = Output(Vec(outs._2, outs._1))
}

class MISO[T <: Data](gen: T, ins: Int) extends Bundle {
  val in = Input(Vec(ins, gen))
  val out = Output(gen)
}

class DMISO[InT <: Data, OutT <: Data](ins: (InT, Int), outGen: OutT) extends Bundle {
  val in = Input(Vec(ins._2, ins._1))
  val out = Output(outGen)
}

class MIMO[T <: Data](gen: T, ins: Int, outs: Int) extends Bundle {
  val in = Input(Vec(ins, gen))
  val out = Output(Vec(outs, gen))
}

class DMIMO[InT <: Data, OutT <: Data](ins: (InT, Int), outs: (OutT, Int)) extends Bundle {
  val in = Input(Vec(ins._2, ins._1))
  val out = Output(Vec(outs._2, outs._1))
}

