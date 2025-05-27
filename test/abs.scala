package test

import func.common.AbsCore

import utils._
import app.VerilogEmitter

object Abs extends App {
  VerilogEmitter.parse(new AbsCore(new FP(12, 11)), "abs.sv")
}
