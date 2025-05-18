package app
import app.VerilogEmitter

import com.fmc.{FMCSlaveRAMCore, FMCMuxedSlaveRAMCore}
import chisel3._

object FMCSlaveSRAM extends App {
  VerilogEmitter.parse(new FMCSlaveRAMCore(UInt(8.W), 4), "fmc_sram_slave.sv")
}

object FMCMuxedSlaveSRAM extends App {
  VerilogEmitter.parse(new FMCMuxedSlaveRAMCore(UInt(8.W), 4), "fmc_muxed_sram_slave.sv")
}
