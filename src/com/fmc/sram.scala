package com.fmc

import mem.SRAMIO

import chisel3._

class FMCSRAMIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val sram = new SRAMIO(addrWidth, dataWidth)
  val fmc = new FMCInterfaceIO
}

class FMCSRAMCore(addrWidth: Int , dataWidth: Int) extends Module {
  val io = IO(new FMCSRAMIO(addrWidth, dataWidth))
}
