package com.uart
import com.axi._
import chisel3._
import chisel3.util._

object MasterByteLevelUartState extends ChiselEnum {
  val sIdle = Value(0.U)
  val sWriteAddr = Value(1.U)
  val sWriteData = Value(2.U)
  val sWriteResp = Value(3.U)
  val sReadAddr = Value(4.U)
  val sReadData = Value(5.U)
}

class AXILiteMasterByteLevelUartCmd(addrWidth: Int, dataWidth: Int, baudRate: Int, clkFreq: Int)
    extends Module {
  override def desiredName: String =
    s"axilite_master_uart_cmd_${addrWidth}x${dataWidth}_b${baudRate}_f$clkFreq"
  
  // AXI Lite Master Interface
  val ext_axi = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi     = Wire(new AXILiteMasterIO(addrWidth, dataWidth))
  val txd       = IO(Output(Bool())).suggestName("TX")
  val rxd       = IO(Input(Bool())).suggestName("RX")
  val cmd_valid = IO(Output(Bool())).suggestName("CMD_VALID")
  val cmd_type  = IO(Output(UartCmdType())).suggestName("CMD_TYPE")
  
  val uart_cmd  = Module(new ByteLevelUartCmdProcessor(baudRate, clkFreq))
  
  // State machine for AXI transactions
  val state = RegInit(MasterByteLevelUartState.sIdle)
  
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
  cmd_valid := uart_cmd.io.cmd_valid
  cmd_type  := uart_cmd.io.cmd_type
  
  // Default values for response
  uart_cmd.io.resp_valid := false.B
  uart_cmd.io.resp_rdata := 0.U
  
  // State Machine
  switch(state) {
    is(MasterByteLevelUartState.sIdle) {
      when(uart_cmd.io.cmd_valid) {
        when(uart_cmd.io.cmd_type === UartCmdType.WRITE) {
          axi_awaddr  := uart_cmd.io.cmd_addr
          axi_wdata   := uart_cmd.io.cmd_wdata
          axi_awvalid := true.B
          axi_wvalid  := true.B
          aw_done     := false.B
          w_done      := false.B
          state       := MasterByteLevelUartState.sWriteAddr
        }.elsewhen(uart_cmd.io.cmd_type === UartCmdType.READ) {
          axi_araddr  := uart_cmd.io.cmd_addr
          axi_arvalid := true.B
          state       := MasterByteLevelUartState.sReadAddr
        }
      }
    }
    
    is(MasterByteLevelUartState.sWriteAddr) {
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
        state      := MasterByteLevelUartState.sWriteResp
      }
    }
    
    is(MasterByteLevelUartState.sWriteResp) {
      when(axi.b.valid && axi_bready) {
        axi_bready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := 0.U
        state                  := MasterByteLevelUartState.sIdle
      }
    }
    
    is(MasterByteLevelUartState.sReadAddr) {
      when(axi.ar.ready && axi_arvalid) {
        axi_arvalid := false.B
        axi_rready  := true.B
        state       := MasterByteLevelUartState.sReadData
      }
    }
    
    is(MasterByteLevelUartState.sReadData) {
      when(axi.r.valid && axi_rready) {
        axi_rready             := false.B
        uart_cmd.io.resp_valid := true.B
        uart_cmd.io.resp_rdata := axi.r.bits.data
        state                  := MasterByteLevelUartState.sIdle
      }
    }
  }
  
  ext_axi.connect(axi)
}
