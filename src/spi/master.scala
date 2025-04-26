package spi

import utils.Config

import chisel3._
import chisel3.util._


class SPIMasterInterfaceIO extends Bundle {
  val sck = Output(Bool())  
  val mosi = Output(Bool()) 
  val miso = Input(Bool())  
  val ss = Output(Bool())
}

class SPIMasterDataIO(sDataWidth: Int) extends Bundle {
  val txData = Input(UInt(sDataWidth.W)) 
  val rxData = Output(UInt(sDataWidth.W))
  val start = Input(Bool()) 
  val done = Output(Bool())
}


class SPIMasterReceiver(dataWidth: Int, clockDiv: Int) extends Module {
  val io = IO(new Bundle {
    // SPI Interface (Master perspective)
    val sclk = Output(Bool())   // 主机提供时钟
    val mosi = Input(Bool())    // 主机接收数据（实际是 Slave 的 MISO）
    val cs   = Output(Bool())   // 主机控制片选（低电平有效）

    // Control Interface
    val start = Input(Bool())   // 启动接收
    val busy  = Output(Bool())  // 正在接收
    val data  = Output(UInt(dataWidth.W))  // 接收到的数据
    val valid = Output(Bool())  // 数据有效标志
  })

  val sIdle :: sActive :: sDone :: Nil = Enum(3)
  val state = RegInit(sIdle)

  val clkCounter = RegInit(0.U(log2Ceil(clockDiv).W))
  val spiClk = RegInit(false.B)
  val shiftReg = RegInit(0.U(dataWidth.W))
  val bitCount = RegInit(0.U(log2Ceil(dataWidth).W))

  // Defaults
  io.sclk := spiClk
  io.cs := true.B  // 默认不选中 Slave
  io.busy := state =/= sIdle
  io.data := shiftReg
  io.valid := false.B

  // Clock generation
  clkCounter := clkCounter + 1.U
  when(clkCounter === (clockDiv/2 - 1).U) {
    spiClk := !spiClk
    clkCounter := 0.U
  }

  // FSM
  switch(state) {
    is(sIdle) {
      when(io.start) {
        state := sActive
        io.cs := false.B  // 选中 Slave
        shiftReg := 0.U
        bitCount := 0.U
      }
    }

    is(sActive) {
      // 在时钟上升沿采样数据（Mode 0）
      when(spiClk && clkCounter === (clockDiv/2 - 1).U) {
        shiftReg := (shiftReg << 1) | io.mosi
        bitCount := bitCount + 1.U

        when(bitCount === (dataWidth - 1).U) {
          state := sDone
        }
      }
    }

    is(sDone) {
      io.valid := true.B  // 数据有效
      when(!io.start) {
        state := sIdle
        io.cs := true.B  // 释放 Slave
      }
    }
  }
}
