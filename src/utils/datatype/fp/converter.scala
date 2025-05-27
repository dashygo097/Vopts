package utils 

import scala.math.pow

import chisel3._

class FPConverterIO(in_dw: Int, in_bp: Int, out_dw: Int, out_bp: Int) extends Bundle {
  val in = Input(new FP(in_dw, in_bp))
  val out = Output(new FP(out_dw, out_bp))
}

class FPConverterCore(in_dw: Int, in_bp: Int, out_dw: Int, out_bp: Int) extends Module {
  val io = IO(new FPConverterIO(in_dw, in_bp, out_dw, out_bp))
  val shiftAmt = out_bp - in_bp
  val shifted = if (shiftAmt > 0) {
    io.in * pow(2, shiftAmt)
  } else if (shiftAmt < 0) {
    io.in * (1 / pow(2, -shiftAmt))
  } else {
    io.in
  }

  io.out := shifted.value.asSInt.pad(in_dw).asSInt.asTypeOf(new FP(out_dw, out_bp))
}
