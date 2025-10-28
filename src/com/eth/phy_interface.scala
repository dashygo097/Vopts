package com.eth

import chisel3._

object PHYInterfaceType extends Enumeration {
  val MII = Value(0)
  val RMII = Value(1)
  val RGMII = Value(2)
}

class MIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en = Output(Bool())
  val txd = Output(UInt(4.W))

  val rx_clk = Output(Clock())
  val rx_dv = Output(Bool())
  val rxd = Input(UInt(4.W))

  val col = Input(Bool())
  val crs = Input(Bool())
}

class RMIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en = Output(Bool())
  val txd = Output(UInt(2.W))

  val rx_clk = Output(Clock())
  val rx_dv = Output(Bool())
  val rxd = Input(UInt(2.W))

  val crs_dv = Input(Bool())
}

class RGMIIInterface extends Bundle {
  val tx_clk = Output(Clock())
  val tx_en = Output(Bool())
  val txd = Output(UInt(4.W))
  val tx_er = Output(Bool())

  val rx_clk = Output(Clock())
  val rx_dv = Output(Bool())
  val rxd = Input(UInt(4.W))
  val rx_er = Input(Bool())
}

class PHYInterface(phyType: PHYInterfaceType.Value) extends Bundle {
  val mdio = new MDIOInterface
  val rst_n = Output(Bool())
  val irq = Input(Bool())
  
  val mii = if (phyType == PHYInterfaceType.MII) Some(new MIIInterface) else None
  val rmii = if (phyType == PHYInterfaceType.RMII) Some(new RMIIInterface) else None
  val rgmii = if (phyType == PHYInterfaceType.RGMII) Some(new RGMIIInterface) else None
}
