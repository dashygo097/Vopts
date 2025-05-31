package app

import app.VerilogEmitter
import com.fsmc.FSMCSlaveRAMCore
import chisel3._

object FSMCSlaveRAM extends App {
  VerilogEmitter.parse(new FSMCSlaveRAMCore(UInt(8.W), 4), "fsmc_ram_slave.sv")
}

