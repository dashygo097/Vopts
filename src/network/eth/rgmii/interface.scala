package net.eth

import chisel3._

class RGMIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en  = Output(Bool())
  val txd    = Output(UInt(4.W))
  val tx_er  = Output(Bool())

  val rx_clk = Input(Clock())
  val rx_dv  = Input(Bool())
  val rxd    = Input(UInt(4.W))
  val rx_er  = Input(Bool())
}
