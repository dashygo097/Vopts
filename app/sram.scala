package app

import mem.SRAMCore

object SRAM extends App {
  VerilogEmitter.parse(new SRAMCore(4, 16), "sram.sv")
}

