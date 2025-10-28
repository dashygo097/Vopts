package com.eth

import chisel3._
import chisel3.util._

class RGMIIRXDecoder extends Module {
  val io = IO(new Bundle {
    val rgmii_rx_clk = Input(Clock())
    val rgmii_rxd = Input(UInt(4.W))
    val rgmii_rxdv = Input(Bool())
    
    val rx_axis_tdata = Output(UInt(8.W))
    val rx_axis_tvalid = Output(Bool())
    val rx_axis_tlast = Output(Bool())
    val rx_axis_tuser = Output(Bool())
  })

  withClock(io.rgmii_rx_clk) {
    val rxd_d1 = RegNext(io.rgmii_rxd)
    val rxdv_d1 = RegNext(io.rgmii_rxdv)
    val rxdv_d2 = RegNext(rxdv_d1)
    
    val byte_ready = RegInit(false.B)
    val rx_byte = RegInit(0.U(8.W))
    val rx_valid = RegInit(false.B)
    val rx_last = RegInit(false.B)
    val rx_error = RegInit(false.B)
    
    when(rxdv_d1) {
      when(!byte_ready) {
        rx_byte := Cat(0.U(4.W), rxd_d1)
        byte_ready := true.B
        rx_valid := false.B
      }.otherwise {
        rx_byte := Cat(rxd_d1, rx_byte(3, 0))
        byte_ready := false.B
        rx_valid := true.B
      }
    }.otherwise {
      rx_valid := false.B
      byte_ready := false.B
      when(rxdv_d2) {
        rx_last := true.B
      }.otherwise {
        rx_last := false.B
      }
    }
    
    val sync_data = RegNext(RegNext(rx_byte))
    val sync_valid = RegNext(RegNext(rx_valid))
    val sync_last = RegNext(RegNext(rx_last))
    val sync_error = RegNext(RegNext(rx_error))
    
    io.rx_axis_tdata := sync_data
    io.rx_axis_tvalid := sync_valid
    io.rx_axis_tlast := sync_last
    io.rx_axis_tuser := sync_error
  }
}

class RGMIITXEncoder extends Module {
  val io = IO(new Bundle {
    val tx_axis_tdata = Input(UInt(8.W))
    val tx_axis_tvalid = Input(Bool())
    val tx_axis_tready = Output(Bool())
    val tx_axis_tlast = Input(Bool())
    
    val rgmii_tx_clk = Output(Clock())
    val rgmii_txd = Output(UInt(4.W))
    val rgmii_txen = Output(Bool())
  })

  val tx_clk_div = RegInit(false.B)
  tx_clk_div := ~tx_clk_div
  io.rgmii_tx_clk := tx_clk_div.asClock
  
  withClock(tx_clk_div.asClock) {
    val state = RegInit(0.U(1.W)) 
    val tx_byte_reg = RegInit(0.U(8.W))
    val tx_en_reg = RegInit(false.B)
    
    io.tx_axis_tready := (state === 0.U) && !tx_en_reg
    
    when(io.tx_axis_tvalid && (state === 0.U)) {
      tx_byte_reg := io.tx_axis_tdata
      tx_en_reg := true.B
      state := 0.U
    }
    
    when(tx_en_reg) {
      when(state === 0.U) {
        io.rgmii_txd := tx_byte_reg(3, 0)
        state := 1.U
      }.otherwise {
        io.rgmii_txd := tx_byte_reg(7, 4)
        state := 0.U
        when(io.tx_axis_tlast) {
          tx_en_reg := false.B
        }
      }
    }.otherwise {
      io.rgmii_txd := 0.U
    }
    
    io.rgmii_txen := tx_en_reg
  }
}
