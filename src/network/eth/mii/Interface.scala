package vopts.net.eth

import chisel3._

class MIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en  = Output(Bool())
  val txd    = Output(UInt(4.W))

  val rx_clk = Output(Clock())
  val rx_dv  = Output(Bool())
  val rxd    = Input(UInt(4.W))

  val col = Input(Bool())
  val crs = Input(Bool())
}
