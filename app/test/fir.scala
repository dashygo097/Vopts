package app.test
import app.VerilogEmitter

import dsp.filter.FIRCore

object FIR extends App {
  VerilogEmitter.parse(new FIRCore("lp", Seq(100000), 64), "fir.sv")
}
