package test
import app.VerilogEmitter

import datatype.fp.FP
import mem.sram.{SyncRAMCore, AsyncRAMCore}

object RAM extends App {
  VerilogEmitter.parse(new SyncRAMCore(new FP, 5), "ram.sv")
}

object AsyncRAM extends App {
  VerilogEmitter.parse(new AsyncRAMCore(new FP, 5), "async_ram.sv")
}
