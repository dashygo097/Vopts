package test 

import app.VerilogEmitter

import utils._
import chisel3._

class FPAdder extends Module {
  val io = IO(new Bundle {
    val a = Input(new FP(12, 11))
    val b = Input(new FP)
    val out = Output(new FP(12, 11))
  })
  io.out := io.a + io.b
}

object Test extends App {
  VerilogEmitter.parse(new FPAdder, "test.sv")
}
