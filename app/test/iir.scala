package app.test
import app.VerilogEmitter

import dsp.filter.IIRCore

object IIR extends App {
  VerilogEmitter.parse(new IIRCore("lp", Seq(100000), 64), "iir.sv")
}
