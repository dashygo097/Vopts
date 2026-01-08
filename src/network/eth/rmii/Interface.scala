package vopts.net.eth

import chisel3._

class RMIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en  = Output(Bool())
  val txd    = Output(UInt(2.W))

  val rx_clk = Output(Clock())
  val rx_dv  = Output(Bool())
  val rxd    = Input(UInt(2.W))

  val crs_dv = Input(Bool())
}
