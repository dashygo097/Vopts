package com.uart

import com.amba._
import utils._
import chisel3._
import chisel3.util._

object MasterUartCmdState extends ChiselEnum {
  val IDLE = Value(0.U(4.W))

  // WRITE states
  val WRITE_ADDR = Value(1.U(4.W))
  val WRITE_DATA = Value(2.U(4.W))
  val WRITE_RESP = Value(3.U(4.W))

  // READ states
  val READ_ADDR = Value(4.U(4.W))
  val READ_DATA = Value(5.U(4.W))

  // MOVE states (ALL CAPS)
  val MOVE_READ_ADDR  = Value(6.U(4.W))
  val MOVE_READ_DATA  = Value(7.U(4.W))
  val MOVE_WRITE_ADDR = Value(8.U(4.W))
  val MOVE_WRITE_RESP = Value(9.U(4.W))
}

class AXILiteMasterUartCmd(addrWidth: Int, dataWidth: Int, clkFreq: Int, baudRate: Int, endianness: String) extends Module {
  override def desiredName: String =
    s"axilite_master_uart_cmd_${addrWidth}x${dataWidth}_b${baudRate}_f$clkFreq"

  // AXI Lite Master Interface
  val ext_axi   = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi       = Wire(new AXILiteMasterIO(addrWidth, dataWidth))
  val txd       = IO(Output(Bool())).suggestName("TX")
  val rxd       = IO(Input(Bool())).suggestName("RX")
  val cmd_valid = IO(Output(Bool())).suggestName("CMD_VALID")
  val cmd_type  = IO(Output(UartCmdType())).suggestName("CMD_TYPE")

  val uart_cmd = Module(new UartCmdProcessor(clkFreq, baudRate, endianness))

  // State machine for AXI transactions
  val state = RegInit(MasterUartCmdState.IDLE)

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

  // MOVE helpers
  val move_src_addr = RegInit(0.U(addrWidth.W))
  val move_dst_addr = RegInit(0.U(addrWidth.W))
  val move_data_buf = RegInit(0.U(dataWidth.W))

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
    is(MasterUartCmdState.IDLE) {
      when(uart_cmd.io.cmd_valid) {
        when(uart_cmd.io.cmd_type === UartCmdType.WRITE) {
          axi_awaddr  := uart_cmd.io.cmd_addr
          axi_wdata   := uart_cmd.io.cmd_wdata
          axi_awvalid := true.B
          axi_wvalid  := true.B
          aw_done     := false.B
          w_done      := false.B
          state       := MasterUartCmdState.WRITE_ADDR
        }.elsewhen(uart_cmd.io.cmd_type === UartCmdType.READ) {
          axi_araddr  := uart_cmd.io.cmd_addr
          axi_arvalid := true.B
          state       := MasterUartCmdState.READ_ADDR
        }.elsewhen(uart_cmd.io.cmd_type === UartCmdType.MOVE) {
          move_src_addr := uart_cmd.io.cmd_addr
          move_dst_addr := uart_cmd.io.cmd_wdata
          axi_araddr    := uart_cmd.io.cmd_addr
          axi_arvalid   := true.B
          state         := MasterUartCmdState.MOVE_READ_ADDR
        }
      }
    }

    is(MasterUartCmdState.WRITE_ADDR) {
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
        state      := MasterUartCmdState.WRITE_RESP
      }
    }

    is(MasterUartCmdState.WRITE_RESP) {
      when(axi.b.valid && axi_bready) {
        axi_bready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := 0.U
        state                  := MasterUartCmdState.IDLE
      }
    }

    is(MasterUartCmdState.READ_ADDR) {
      when(axi.ar.ready && axi_arvalid) {
        axi_arvalid := false.B
        axi_rready  := true.B
        state       := MasterUartCmdState.READ_DATA
      }
    }

    is(MasterUartCmdState.READ_DATA) {
      when(axi.r.valid && axi_rready) {
        axi_rready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := axi.r.bits.data
        state                  := MasterUartCmdState.IDLE
      }
    }

    // MOVE: READ phase
    is(MasterUartCmdState.MOVE_READ_ADDR) {
      when(axi.ar.ready && axi_arvalid) {
        axi_arvalid := false.B
        axi_rready  := true.B
        state       := MasterUartCmdState.MOVE_READ_DATA
      }
    }

    is(MasterUartCmdState.MOVE_READ_DATA) {
      when(axi.r.valid && axi_rready) {
        axi_rready    := false.B
        move_data_buf := axi.r.bits.data
        axi_awaddr    := move_dst_addr
        axi_wdata     := axi.r.bits.data
        axi_awvalid   := true.B
        axi_wvalid    := true.B
        aw_done       := false.B
        w_done        := false.B
        state         := MasterUartCmdState.MOVE_WRITE_ADDR
      }
    }

    // MOVE: WRITE phase
    is(MasterUartCmdState.MOVE_WRITE_ADDR) {
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
        state      := MasterUartCmdState.MOVE_WRITE_RESP
      }
    }

    is(MasterUartCmdState.MOVE_WRITE_RESP) {
      when(axi.b.valid && axi_bready) {
        axi_bready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := move_data_buf // return moved data; change to 0.U for ACK only
        state                  := MasterUartCmdState.IDLE
      }
    }
  }

  ext_axi.connect(axi)
}

object TestAXILiteMasterUartCmd extends App {
  VerilogEmitter.parse(
    new AXILiteMasterUartCmd(32, 32, 100000000, 115200, "big"),
    "axilite_master_uart_cmd.sv",
    info = true
  )
}
