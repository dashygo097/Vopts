package test
import app.VerilogEmitter

import datatype.fp.FP
import mem.sram.{SyncSRAMCore, AsyncSRAMCore}

object SRAM extends App {
  VerilogEmitter.parse(new SyncSRAMCore(new FP, 4), "sram.sv")
}

object AsyncSRAM extends App {
  VerilogEmitter.parse(new AsyncSRAMCore(new FP, 4), "async_sram.sv")
}
