package com.uart

import chisel3._
import chisel3.util._

class ByteLevelUartTXIO extends Bundle {
  val txd     = Output(Bool())
  val channel = Flipped(Decoupled(UInt(8.W)))
  val busy    = Output(Bool())
}

class ByteLevelUartRXIO extends Bundle {
  val rxd     = Input(Bool())
  val channel = Decoupled(UInt(8.W))
  val error   = Output(Bool())
}

class ByteLevelUartTX(baudRate: Int, clkFreq: Int) extends Module {
  val io              = IO(new ByteLevelUartTXIO).suggestName("UART_TX")
  val baudTickDivider = clkFreq / baudRate

  val state = RegInit(UartState.IDLE)

  val data        = Reg(UInt(8.W))
  val tick        = RegInit(false.B)
  val bitCounter  = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  tickCounter      := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  tick             := Mux(tickCounter === (baudTickDivider - 1).U, true.B, false.B)
  io.busy          := state =/= UartState.IDLE
  io.txd           := true.B
  io.channel.ready := state === UartState.IDLE

  switch(state) {
    is(UartState.IDLE) {
      when(io.channel.valid) {
        state := UartState.START
        data  := io.channel.bits
      }
    }

    is(UartState.START) {
      io.txd := false.B
      when(tick) {
        state      := UartState.DATA
        bitCounter := 0.U
      }
    }

    is(UartState.DATA) {
      io.txd := data(0)
      when(tick) {
        when(bitCounter === 7.U) {
          state := UartState.STOP
        }.otherwise {
          bitCounter := bitCounter + 1.U
          data       := data >> 1
        }
      }
    }

    is(UartState.STOP) {
      io.txd := true.B
      when(tick) {
        state := UartState.IDLE
      }
    }
  }
}

class ByteLevelUartRX(baudRate: Int, clkFreq: Int) extends Module {
  val io              = IO(new ByteLevelUartRXIO).suggestName("UART_RX")
  val baudTickDivider = clkFreq / baudRate

  val state = RegInit(UartState.IDLE)

  val data        = Reg(UInt(8.W))
  val tick        = RegInit(false.B)
  val bitCounter  = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  tickCounter      := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  tick             := Mux(tickCounter === (baudTickDivider - 1).U, true.B, false.B)
  io.channel.valid := false.B
  io.channel.bits  := data
  io.error         := false.B

  val rxd = RegNext(RegNext(io.rxd))

  switch(state) {
    is(UartState.IDLE) {
      when(!rxd) {
        state := UartState.START
      }
    }

    is(UartState.START) {
      when(tick) {
        state      := UartState.DATA
        bitCounter := 0.U
      }
    }

    is(UartState.DATA) {
      when(tick) {
        data := Cat(rxd, data(7, 1))
        when(bitCounter === 7.U) {
          state := UartState.STOP
        }.otherwise {
          bitCounter := bitCounter + 1.U
        }
      }
    }

    is(UartState.STOP) {
      when(tick) {
        io.channel.valid := true.B
        io.error         := !rxd
        state            := UartState.IDLE
      }
    }
  }
}

class ByteLevelUart(baudRate: Int, clkFreq: Int) extends Module {
  val io = IO(new Bundle {
    val tx = new ByteLevelUartTXIO
    val rx = new ByteLevelUartRXIO
  }).suggestName("UART")

  val tx = Module(new ByteLevelUartTX(baudRate, clkFreq))
  val rx = Module(new ByteLevelUartRX(baudRate, clkFreq))

  tx.io <> io.tx
  rx.io <> io.rx
}
