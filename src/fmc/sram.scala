package fmc

import mem.SRAMCoreIO

import chisel3._

class FMCSRAMCoreIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val sram = new SRAMCoreIO(addrWidth, dataWidth)
  val fmc = new FMCInterfaceCoreIO
}

class FMCSRAMCore(addrWidth: Int , dataWidth: Int) extends Module {
  val io = IO(new FMCSRAMCoreIO(addrWidth, dataWidth))
}
