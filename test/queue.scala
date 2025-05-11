package test
import app.VerilogEmitter

import datatype.fp.FP
import mem.fifo.SyncQueueCore

object Queue extends App {
  VerilogEmitter.parse(new SyncQueueCore(new FP, 4), "queue.sv")
}

