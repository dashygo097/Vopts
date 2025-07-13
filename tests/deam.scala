package test

import app.VerilogEmitter
import mod.am.{SDDeAMCore, EDDeAMCore}

object EDDeAM extends App {
  VerilogEmitter.parse(new EDDeAMCore(10000, 256), "evlp_detector.sv")
  VerilogEmitter.parse(new SDDeAMCore(1000000, 10000, 256), "sync_detector.sv")
}

