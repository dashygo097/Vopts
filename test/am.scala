package test

import app.VerilogEmitter
import mod.am.AMCore

object AM extends App {
  VerilogEmitter.parse(new AMCore(1000000), "am.sv")
}
