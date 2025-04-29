package app.test
import app.VerilogEmitter

import datatype.fp.FP
import dsp.filter.IIRCore

import chisel3._

class IIR extends Module {
  val io = IO(new Bundle {
    val in = Input(new FP)
    val out = Output(new FP)
  })
  val iir = Module(new IIRCore("lp", Seq(100000), 64))
  iir.io.in := io.in
  io.out := iir.io.out
}

object IIR extends App {
  VerilogEmitter.parse(new IIR, "iir.sv")
}
