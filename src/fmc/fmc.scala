package fmc

import chisel3._

class FMCInterfaceCoreIO extends Bundle {
  val clk = Input(Bool())
  val we = Input(Bool())
  val ne = Input(Bool())
  val oe = Input(Bool())
  val adv = Input(Bool())
  val nwait = Output(Bool())
}
