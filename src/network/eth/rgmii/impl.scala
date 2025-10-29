package net.eth

import utils._
import chisel3._
import chisel3.util._

class RGMIIEthernet extends Module {
  override def desiredName: String =
    s"eth_rgmii"
  val io                           = IO(new Bundle {
    val rgmii   = new RGMIIInterface
    val tx      = Flipped(Decoupled(new EthernetFrameIO))
    val rx      = Decoupled(new EthernetFrameIO)
    val clk125m = Input(Clock())
  })

  val tx = Module(new RGMIIEthernetTx)
  val rx = Module(new RGMIIEthernetRx)

  tx.io.clk125m   := io.clk125m
  tx.io.frame <> io.tx
  io.rgmii.tx_clk := tx.io.rgmii.tx_clk
  io.rgmii.tx_en  := tx.io.rgmii.tx_en
  io.rgmii.txd    := tx.io.rgmii.txd
  io.rgmii.tx_er  := tx.io.rgmii.tx_er

  rx.io.rgmii.rx_clk := io.rgmii.rx_clk
  rx.io.rgmii.rx_dv  := io.rgmii.rx_dv
  rx.io.rgmii.rxd    := io.rgmii.rxd
  rx.io.rgmii.rx_er  := io.rgmii.rx_er
  io.rx <> rx.io.frame
}

object TestRGMIIEthernet extends App {
  VerilogEmitter.parse(new RGMIIEthernet, "eth_rgmii.sv")
}
