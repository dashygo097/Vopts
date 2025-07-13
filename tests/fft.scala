package test

import dsp.fft.MDCCore
import app.VerilogEmitter

object FFT extends App {
  VerilogEmitter.parse(new MDCCore(256), "fft256.sv")
}
