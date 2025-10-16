package com.uart

import chisel3._
import chisel3.util._

object UartCmdState extends ChiselEnum {
  val IDLE      = Value(0.U(1.W))
  val START     = Value(1.U(1.W))
}

object UartCmdType extends ChiselEnum {
  val WRITE = Value(0.U(1.W))  
  val READ  = Value(1.U(1.W))
}

class ByteLevelUartCmdProcessorIO extends Bundle {
  val uart_tx = new ByteLevelUartTXIO
  val uart_rx = new ByteLevelUartRXIO
  
  val cmd_valid    = Output(Bool())
  val cmd_type     = Output(UartCmdType())
  val cmd_addr     = Output(UInt(32.W))
  val cmd_wdata    = Output(UInt(32.W))
  
  val resp_valid   = Input(Bool())
  val resp_rdata   = Input(UInt(32.W))
  val resp_ready   = Output(Bool())
  
  val send_cmd     = Input(Bool())
  val send_type    = Input(UartCmdType())
  val send_addr    = Input(UInt(32.W))
  val send_wdata   = Input(UInt(32.W))
  val send_ready   = Output(Bool())
}

class ByteLevelUartCmdProcessor(baudRate: Int, clkFreq: Int) extends Module {
  val io = IO(new ByteLevelUartCmdProcessorIO).suggestName("UART_CMD")
  
  val uart_tx = Module(new ByteLevelUartTX(baudRate, clkFreq))
  val uart_rx = Module(new ByteLevelUartRX(baudRate, clkFreq))
  
  io.uart_tx <> uart_tx.io
  io.uart_rx <> uart_rx.io
  
  val rx_state = RegInit(0.U(2.W))
  val rx_byte_cnt = RegInit(0.U(4.W))
  val rx_buffer = Reg(Vec(9, UInt(8.W)))
  
  io.cmd_valid := false.B
  io.cmd_type := UartCmdType.WRITE
  io.cmd_addr := 0.U
  io.cmd_wdata := 0.U
  
  uart_rx.io.channel.ready := true.B
  
  switch(rx_state) {
    is(0.U) {
      when(uart_rx.io.channel.valid && !uart_rx.io.error) {
        rx_buffer(0) := uart_rx.io.channel.bits
        rx_byte_cnt := 1.U
        rx_state := 1.U
      }
    }
    is(1.U) {
      when(uart_rx.io.channel.valid && !uart_rx.io.error) {
        rx_buffer(rx_byte_cnt) := uart_rx.io.channel.bits
        when(rx_byte_cnt === 8.U) {
          io.cmd_valid := true.B
          io.cmd_type := Mux(rx_buffer(0) === 0.U, UartCmdType.WRITE, UartCmdType.READ)
          io.cmd_addr := Cat(rx_buffer(4), rx_buffer(3), rx_buffer(2), rx_buffer(1))
          io.cmd_wdata := Cat(rx_buffer(8), rx_buffer(7), rx_buffer(6), rx_buffer(5))
          rx_state := 0.U
          rx_byte_cnt := 0.U
        }.otherwise {
          rx_byte_cnt := rx_byte_cnt + 1.U
        }
      }
    }
  }
  
  val tx_state = RegInit(0.U(2.W))
  val tx_byte_cnt = RegInit(0.U(4.W))
  val tx_buffer = Reg(Vec(9, UInt(8.W)))
  val tx_total_bytes = RegInit(0.U(4.W))
  
  io.send_ready := tx_state === 0.U
  io.resp_ready := false.B
  
  switch(tx_state) {
    is(0.U) {
      when(io.send_cmd) {
        tx_buffer(0) := Mux(io.send_type === UartCmdType.WRITE, 0.U, 1.U)
        tx_buffer(1) := io.send_addr(7, 0)
        tx_buffer(2) := io.send_addr(15, 8)
        tx_buffer(3) := io.send_addr(23, 16)
        tx_buffer(4) := io.send_addr(31, 24)
        tx_buffer(5) := io.send_wdata(7, 0)
        tx_buffer(6) := io.send_wdata(15, 8)
        tx_buffer(7) := io.send_wdata(23, 16)
        tx_buffer(8) := io.send_wdata(31, 24)
        tx_total_bytes := 9.U
        tx_byte_cnt := 0.U
        tx_state := 1.U
      }.elsewhen(io.resp_valid) {
        tx_buffer(0) := 0.U
        tx_buffer(1) := io.resp_rdata(7, 0)
        tx_buffer(2) := io.resp_rdata(15, 8)
        tx_buffer(3) := io.resp_rdata(23, 16)
        tx_buffer(4) := io.resp_rdata(31, 24)
        tx_total_bytes := 5.U
        tx_byte_cnt := 0.U
        tx_state := 1.U
        io.resp_ready := true.B
      }
    }
    is(1.U) {
      uart_tx.io.channel.valid := true.B
      uart_tx.io.channel.bits := tx_buffer(tx_byte_cnt)
      
      when(uart_tx.io.channel.ready) {
        when(tx_byte_cnt === (tx_total_bytes - 1.U)) {
          tx_state := 0.U
          tx_byte_cnt := 0.U
        }.otherwise {
          tx_byte_cnt := tx_byte_cnt + 1.U
        }
      }
    }
  }
  
  when(tx_state === 0.U) {
    uart_tx.io.channel.valid := false.B
    uart_tx.io.channel.bits := 0.U
  }
}

