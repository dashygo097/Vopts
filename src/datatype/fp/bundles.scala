package datatype.fp

import chisel3._

class FPSO extends Bundle {
  val out = Output(new FP)
}

class FPMO(outs: Int) extends Bundle {
  val out = Output(Vec(outs, new FP))
}

class FPSISO extends Bundle {
  val in = Input(new FP)
  val out = Output(new FP)
}

class FPSIMO(outs: Int) extends Bundle {
  val in = Input(new FP)
  val out = Output(Vec(outs, new FP))
}

class FPMISO(ins: Int) extends Bundle {
  val in = Input(Vec(ins, new FP))
  val out = Output(new FP)
}

class FPMIMO(ins: Int, outs: Int) extends Bundle {
  val in = Input(Vec(ins, new FP))
  val out = Output(Vec(outs, new FP))
}
