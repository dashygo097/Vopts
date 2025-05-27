package test

import func.common.ComparatorCore
import app.VerilogEmitter

import utils._
import chisel3._

class Comparator extends Module {
  val io = IO(new Bundle {
    val in = Input(new FP(12, 11))
    val out = Output(Bool())
  })
  val comparator = Module(new ComparatorCore(new FP(12, 11), 0.5))
  comparator.io.in := io.in
  io.out := comparator.io.out
}

object Comparator extends App {
  VerilogEmitter.parse(new Comparator, "comparator.sv")
}
