package app.test
import app.VerilogEmitter

import mod.ask.ASKCore

object ASK extends App {
  VerilogEmitter.parse(new ASKCore(1.0, 1000000), "ask.sv")
}

