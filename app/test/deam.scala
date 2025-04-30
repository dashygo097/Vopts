package app.test

import app.VerilogEmitter
import mod.am.{SDDeAMCore, EDDeAMCore}

object EDDeAM extends App {
  VerilogEmitter.parse(new EDDeAMCore(10000), "evlp_detector.sv")
}

object SDDeAM extends App {
  VerilogEmitter.parse(new SDDeAMCore(1000000, 10000), "sync_detector.sv")
}

