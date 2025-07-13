package test

import app.VerilogEmitter
import mem.fifo.{SyncFIFOCore, AsyncFIFOCore}

import chisel3._

object SyncFIFO extends App {
  VerilogEmitter.parse(new SyncFIFOCore(UInt(8.W), 16), "fifo.sv")
  VerilogEmitter.parse(new AsyncFIFOCore(UInt(8.W), 16), "async_fifo.sv")
}

