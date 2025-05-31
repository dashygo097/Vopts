package test

import func.resample.{DecimatorCore, LinearInterpolatorCore}
import app.VerilogEmitter

import utils._

object Decimator extends App {
  VerilogEmitter.parse(new DecimatorCore(new FP, 4), "decimator.sv")
}

object LinearInterpolator extends App {
  VerilogEmitter.parse(new LinearInterpolatorCore(new FP, 4), "linear_interpolator.sv")
}
