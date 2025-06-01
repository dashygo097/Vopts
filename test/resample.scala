package test

import func.resample.DecimatorCore
import app.VerilogEmitter

import utils._

object Decimator extends App {
  VerilogEmitter.parse(new DecimatorCore(new FP, 4), "decimator.sv")
}

