package test

import func.resample.{DecimatorCore, AutoLinearInterpolatorCore}
import app.VerilogEmitter

import utils._

object Decimator extends App {
  VerilogEmitter.parse(new DecimatorCore(new FP, 4), "decimator.sv")
}

object Interpolator extends App {
  VerilogEmitter.parse(new AutoLinearInterpolatorCore(new FP), "interpolator.sv")
}
