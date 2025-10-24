package com.uart

import com.axi._
import utils._
import chisel3._
import chisel3.util._

object MasterUartState extends ChiselEnum {
  val IDLE      = Value(0.U(4.W))

  val WRITE_ADDR = Value(1.U(4.W))
  val WRITE_DATA = Value(2.U(4.W))
  val WRITE_RESP = Value(3.U(4.W))

  val READ_ADDR  = Value(4.U(4.W))
  val READ_DATA  = Value(5.U(4.W))
}

class AXILiteMasterUartCmd(addrWidth: Int, dataWidth: Int, clkFreq: Int, option: UartCmdOption)
    extends Module {
  override def desiredName: String =
    s"axilite_master_uart_cmd_${addrWidth}x${dataWidth}_b${option.baudRate}_f${clkFreq}"

  // AXI Lite Master Interface
  val ext_axi   = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi       = Wire(new AXILiteMasterIO(addrWidth, dataWidth))
  val txd       = IO(Output(Bool())).suggestName("TX")
  val rxd       = IO(Input(Bool())).suggestName("RX")
  val cmd_valid = IO(Output(Bool())).suggestName("CMD_VALID")
  val cmd_type  = IO(Output(UartCmdType())).suggestName("CMD_TYPE")

  val uart_cmd = Module(new UartCmdProcessor(clkFreq, option))

  // State machine for AXI transactions
  val state = RegInit(MasterUartState.IDLE)

  // Registers for AXI signals
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_awvalid = RegInit(false.B)
  val axi_wdata   = RegInit(0.U(dataWidth.W))
  val axi_wvalid  = RegInit(false.B)
  val axi_bready  = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_arvalid = RegInit(false.B)
  val axi_rready  = RegInit(false.B)

  // Tracking registers for handshake completion
  val aw_done = RegInit(false.B)
  val w_done  = RegInit(false.B)

  // AXI Interface Connections
  axi.aw.bits.addr := axi_awaddr
  axi.aw.bits.prot := 0.U
  axi.aw.valid     := axi_awvalid
  axi.w.bits.data  := axi_wdata
  axi.w.bits.strb  := Fill(dataWidth / 8, 1.U)
  axi.w.valid      := axi_wvalid
  axi.b.ready      := axi_bready
  axi.ar.bits.addr := axi_araddr
  axi.ar.bits.prot := 0.U
  axi.ar.valid     := axi_arvalid
  axi.r.ready      := axi_rready

  // UART Connections
  txd             := uart_cmd.io.txd
  uart_cmd.io.rxd := rxd
  cmd_valid       := uart_cmd.io.cmd_valid
  cmd_type        := uart_cmd.io.cmd_type

  // Default values for response
  uart_cmd.io.resp_valid := false.B
  uart_cmd.io.resp_rdata := 0.U

  // State Machine
  switch(state) {
    is(MasterUartState.IDLE) {
      when(uart_cmd.io.cmd_valid) {
        when(uart_cmd.io.cmd_type === UartCmdType.WRITE) {
          axi_awaddr  := uart_cmd.io.cmd_addr
          axi_wdata   := uart_cmd.io.cmd_wdata
          axi_awvalid := true.B
          axi_wvalid  := true.B
          aw_done     := false.B
          w_done      := false.B
          state       := MasterUartState.WRITE_ADDR
        }.elsewhen(uart_cmd.io.cmd_type === UartCmdType.READ) {
          axi_araddr  := uart_cmd.io.cmd_addr
          axi_arvalid := true.B
          state       := MasterUartState.READ_ADDR
        }
      }
    }

    is(MasterUartState.WRITE_ADDR) {
      when(axi.aw.ready && axi_awvalid) {
        axi_awvalid := false.B
        aw_done     := true.B
      }
      when(axi.w.ready && axi_wvalid) {
        axi_wvalid := false.B
        w_done     := true.B
      }

      when(aw_done && w_done) {
        axi_bready := true.B
        state      := MasterUartState.WRITE_RESP
      }
    }

    is(MasterUartState.WRITE_RESP) {
      when(axi.b.valid && axi_bready) {
        axi_bready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := 0.U
        state                  := MasterUartState.IDLE
      }
    }

    is(MasterUartState.READ_ADDR) {
      when(axi.ar.ready && axi_arvalid) {
        axi_arvalid := false.B
        axi_rready  := true.B
        state       := MasterUartState.READ_DATA
      }
    }

    is(MasterUartState.READ_DATA) {
      when(axi.r.valid && axi_rready) {
        axi_rready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := axi.r.bits.data
        state                  := MasterUartState.IDLE
      }
    }
  }

  ext_axi.connect(axi)
}

object TestAXILiteMasterUartCmd extends App {
  VerilogEmitter.parse(new AXILiteMasterUartCmd(32, 32, 100000000, UartCmdOption(115200)), "axi_lite_master_uart_cmd.sv", info=true)
}
