package net.eth

import chisel3._

class MDIOInterface extends Bundle {
  val mdc     = Output(Bool())
  val mdio_o  = Output(Bool())
  val mdio_i  = Input(Bool())
  val mdio_oe = Output(Bool())
}
