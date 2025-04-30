package app.test

import app.VerilogEmitter
import mod.am.{EvlpDetectorCore, SyncDetectorCore}

object EvlpDetector extends App {
  VerilogEmitter.parse(new EvlpDetectorCore(10000), "evlp_detector.sv")
}

object SyncDetector extends App {
  VerilogEmitter.parse(new SyncDetectorCore(1000000, 10000), "sync_detector.sv")
}

