package test

import app.VerilogEmitter
import peripheral.SegmentCore

object Segment extends App {
  VerilogEmitter.parse(new SegmentCore, "segment.sv")
}


