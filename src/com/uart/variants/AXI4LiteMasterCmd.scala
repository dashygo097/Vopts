package com.uart

import com.amba._
import utils._
import chisel3._

class AXILiteMasterUartCmd(addrWidth: Int, dataWidth: Int, clkFreq: Int, baudRate: Int, endianness: String) extends AXILiteMaster(addrWidth, dataWidth) {
  override def desiredName: String =
    s"axilite_master_uart_cmd_${addrWidth}x${dataWidth}_b${baudRate}_f$clkFreq"

  // AXI Lite Master Interface
  val txd       = IO(Output(Bool())).suggestName("TX")
  val rxd       = IO(Input(Bool())).suggestName("RX")
  val cmd_valid = IO(Output(Bool())).suggestName("CMD_VALID")
  val cmd_type  = IO(Output(UartCmdType())).suggestName("CMD_TYPE")

  val uart_cmd = Module(new UartCmdProcessor(clkFreq, baudRate, endianness))

  // Tracking registers for handshake completion
  val aw_done = RegInit(false.B)
  val w_done  = RegInit(false.B)

  // UART Connections
  txd             := uart_cmd.io.txd
  uart_cmd.io.rxd := rxd
  cmd_valid       := uart_cmd.io.cmd_valid
  cmd_type        := uart_cmd.io.cmd_type

  // Default values for response
  uart_cmd.io.resp_valid := false.B
  uart_cmd.io.resp_rdata := 0.U

  // State Machine
  override protected def onIDLE(): Unit =
    when(uart_cmd.io.cmd_valid) {
      when(uart_cmd.io.cmd_type === UartCmdType.WRITE) {
        axi_awaddr  := uart_cmd.io.cmd_addr
        axi_wdata   := uart_cmd.io.cmd_wdata
        axi_awvalid := true.B
        axi_wvalid  := true.B
        aw_done     := false.B
        w_done      := false.B
        state       := WRITE_ADDR
      }.elsewhen(uart_cmd.io.cmd_type === UartCmdType.READ) {
        axi_araddr  := uart_cmd.io.cmd_addr
        axi_arvalid := true.B
        state       := READ_ADDR
      }
    }

  override protected def onWriteAddr(): Unit = {
    axi_awvalid := false.B
    aw_done     := true.B
    state       := WRITE_DATA
  }

  override protected def onWriteData(): Unit = {
    axi_wvalid := false.B
    w_done     := true.B

    axi_bready := true.B
    state      := WRITE_RESP
  }

  override protected def onWriteResp(): Unit = {
    axi_bready             := false.B
    uart_cmd.io.resp_valid := true.B
    uart_cmd.io.resp_rdata := 0.U
    state                  := IDLE
  }

  override protected def onReadAddr(): Unit = {
    axi_arvalid := false.B
    axi_rready  := true.B
    state       := READ_DATA
  }

  override protected def onReadData(): Unit = {
    axi_rready             := false.B
    uart_cmd.io.resp_valid := true.B
    uart_cmd.io.resp_rdata := axi.r.bits.data
    state                  := IDLE
  }

  setup()
}

object TestAXILiteMasterUartCmd extends App {
  VerilogEmitter.parse(
    new AXILiteMasterUartCmd(32, 32, 100000000, 115200, "big"),
    "axilite_master_uart_cmd.sv",
    info = true
  )
}
