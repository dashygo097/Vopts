package test

import app.VerilogEmitter
import mem.sram.{SyncRAMCore, AsyncRAMCore}

import utils._

object RAM extends App {
  VerilogEmitter.parse(new SyncRAMCore(new FP, 5), "ram.sv")
}

object AsyncRAM extends App {
  VerilogEmitter.parse(new AsyncRAMCore(new FP, 5), "async_ram.sv")
}
