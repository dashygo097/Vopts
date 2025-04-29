package app.test
import app.VerilogEmitter

import datatype.fp.FP
import dsp.filter.FIRCore

import chisel3._

class FIR extends Module {
  val io = IO(new Bundle {
    val in = Input(new FP)
    val out = Output(new FP)
  })
  val fir = Module(new FIRCore("lp", Seq(100000), 64))
  fir.io.in := io.in
  io.out := fir.io.out
}

object FIR extends App {
  VerilogEmitter.parse(new FIR, "fir.sv")
}
