package test
import app.VerilogEmitter

import mod.fsk.FSKCore

object FSK extends App {
  VerilogEmitter.parse(new FSKCore(1000000, 2000000), "fsk.sv")
}
