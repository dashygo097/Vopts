package test

import app.VerilogEmitter
import mem.fifo.SyncFIFOCore

import chisel3._

object SyncFIFO extends App {
  VerilogEmitter.parse(new SyncFIFOCore(UInt(8.W), 16), "fifo.sv")
}
