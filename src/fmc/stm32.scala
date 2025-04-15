package fmc 

import chisel3._
import chisel3.util._

import chisel3.experimental.Analog

class FSMCInterfaceIO(addrWidth: Int, dataWidth: Int) extends Bundle {
}

class FMCInterfaceIO(addrWidth: Int, dataWidth: Int) extends Bundle {
}

class FSMCInterface(addrWidth: Int, dataWidth: Int) extends Module {
  val io = IO(new FSMCInterfaceIO(addrWidth, dataWidth))
}

class FMCInterface(addrWidth: Int, dataWidth: Int) extends Module {
  val io = IO(new FMCInterfaceIO(addrWidth, dataWidth))
}
