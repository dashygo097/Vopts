package test

import app.VerilogEmitter
import mem.fifo.SyncQueueCore

import utils._

object Queue extends App {
  VerilogEmitter.parse(new SyncQueueCore(new FP, 4), "queue.sv")
}

