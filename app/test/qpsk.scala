package app.test
import app.VerilogEmitter

import mod.psk._

object QPSK extends App {
  VerilogEmitter.parse(new QPSKCore(1000000), "qpsk.sv")
}

