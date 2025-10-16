package com.uart

import com.axi._
import chisel3._
import chisel3.util._

class AXILiteMasterByteLevelUartCmd(addrWidth: Int, dataWidth: Int, baudRate: Int, clkFreq: Int) extends Module {
  override def desiredName: String = 
    s"axilite_master_uart_cmd_${addrWidth}x${dataWidth}_b${baudRate}_f${clkFreq}"

  // AXI Lite Master Interface
  val ext_axi = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi = Wire(new AXILiteMasterIO(addrWidth, dataWidth))

  val txd = IO(Output(Bool())).suggestName("TX")
  val rxd = IO(Input(Bool())).suggestName("RX")
  val cmd_valid = IO(Output(Bool())).suggestName("CMD_VALID")
  val cmd_type = IO(Output(UartCmdType())).suggestName("CMD_TYPE")
  val uart_cmd = Module(new ByteLevelUartCmdProcessor(baudRate, clkFreq))

  // Signals
  val axi_awaddr      = RegInit(0.U(addrWidth.W))
  val axi_awvalid     = RegInit(false.B)
  val axi_wdata      = RegInit(0.U(dataWidth.W))
  val axi_wvalid     = RegInit(false.B)
  val axi_bready     = RegInit(false.B)
  val axi_araddr     = RegInit(0.U(addrWidth.W))
  val axi_arvalid    = RegInit(false.B)
  val axi_rready     = RegInit(false.B)

  // I/O Connections
  axi.aw.bits.addr := axi_awaddr
  axi.aw.bits.prot := 0.U
  axi.aw.valid     := axi_awvalid
  axi.w.bits.data  := axi_wdata
  axi.w.bits.strb  := Fill(dataWidth / 8, 1.U)
  axi.w.valid      := axi_wvalid
  axi.b.ready     := axi_bready
  axi.ar.bits.addr := axi_araddr
  axi.ar.bits.prot := 0.U
  axi.ar.valid     := axi_arvalid
  axi.r.ready     := axi_rready

  txd := uart_cmd.io.txd
  uart_cmd.io.rxd := rxd

  cmd_valid := uart_cmd.io.cmd_valid
  cmd_type := uart_cmd.io.cmd_type

  // Command Processing
  when(uart_cmd.io.cmd_valid) {
    when(uart_cmd.io.cmd_type === UartCmdType.WRITE) {
      axi_awaddr := uart_cmd.io.cmd_addr
      axi_wdata := uart_cmd.io.cmd_wdata
      axi_awvalid := true.B
      axi_wvalid := true.B
    } .elsewhen(uart_cmd.io.cmd_type === UartCmdType.READ) {
      axi_araddr := uart_cmd.io.cmd_addr
      axi_arvalid := true.B
    }
  }

  // Write Address Channel
  when(axi.aw.ready && axi_awvalid) {
    axi_awvalid := false.B
  }

  // Write Data Channel
  when(axi.w.ready && axi_wvalid) {
    axi_wvalid := false.B
    axi_bready := true.B
  }

  // Write Response Channel
  when (axi_bready && axi.b.valid) {
    axi_bready := false.B
  }

  // Read Address Channel
  when (axi.ar.ready && axi_arvalid) {
    axi_arvalid := false.B
    axi_rready := true.B
  }

  // Read Data Channel
  when (axi_rready && axi.r.valid) {
    axi_rready := false.B
    uart_cmd.io.resp_valid := true.B
    uart_cmd.io.resp_rdata := axi.r.bits.data
  } .otherwise {
    uart_cmd.io.resp_valid := false.B
    uart_cmd.io.resp_rdata := 0.U
  }

  ext_axi.connect(axi)
}
