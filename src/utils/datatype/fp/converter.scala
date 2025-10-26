package utils

import chisel3._

class FPConverterIO(in_dw: Int, in_bp: Int, out_dw: Int, out_bp: Int) extends Bundle {
  val in  = Input(new FP(in_dw, in_bp))
  val out = Output(new FP(out_dw, out_bp))
}

class FPConverter(in_dw: Int, in_bp: Int, out_dw: Int, out_bp: Int) extends Module {
  override def desiredName = s"fp_converter_${in_dw}w${in_bp}b_to_${out_dw}w${out_bp}b"
  val io                   = IO(new FPConverterIO(in_dw, in_bp, out_dw, out_bp))
  val shiftAmt             = out_bp - in_bp
  val shifted              = if (shiftAmt > 0) {
    io.in.value << shiftAmt.U
  } else if (shiftAmt < 0) {
    io.in.value >> (-shiftAmt).U
  } else {
    io.in.value
  }

  io.out := new FP(out_dw, out_bp).fromSInt(shifted)
}

object FPConverter {
  def apply(out_dw: Int, out_bp: Int)(in: FP): FP = {
    val converter = Module(new FPConverter(in.dw(), in.bp(), out_dw, out_bp))
    converter.io.in := in
    converter.io.out
  }
  def apply(in_dw: Int, in_bp: Int, out_dw: Int, out_bp: Int)(in: FP): FP = {
    val converter = Module(new FPConverter(in_dw, in_bp, out_dw, out_bp))
    converter.io.in := in
    converter.io.out
  }
}
