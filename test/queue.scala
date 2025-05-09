package test
import app.VerilogEmitter

import datatype.fp.FP
import com.fifo.QueueCore

object Queue extends App {
  VerilogEmitter.parse(new QueueCore(new FP, 4), "queue.sv")
}

