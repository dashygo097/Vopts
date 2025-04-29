package com.uart
import utils._

import chisel3._
import chisel3.util._

// The serialized Uart interface
class SerialUartTXIO extends Bundle {
  val txd = Output(Bool())
  val channel = Flipped(Decoupled(Bool()))
  val tick = Output(Bool())
  val busy = Output(Bool())
}

class SerialUartRXIO extends Bundle {
  val rxd = Input(Bool())
  val channel = Decoupled(Bool()) 
  val tick = Output(Bool())
  val error = Output(Bool())
}

class SerialUartTXCore(baudRate: Int) extends Module with Config {
  val io = IO(new SerialUartTXIO)
  val baudTickDivider = clkFreq / baudRate

  val state = RegInit(UartState.IDLE)

  val data = Reg(UInt(8.W))
  val bitCounter = RegInit(0.U(3.W))
  val shiftBuffer = Reg(UInt(8.W))
  val shiftCounter = RegInit(0.U(3.W))
  val loading = RegInit(true.B)

  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))
  tickCounter := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  io.tick := tickCounter === (baudTickDivider - 1).U

  io.busy := state =/= UartState.IDLE || shiftCounter =/= 0.U
  io.txd := true.B
  io.channel.ready := (shiftCounter === 0.U)

  switch(state) {
    is(UartState.IDLE) {
      when(shiftCounter === 0.U && io.channel.valid) {
        shiftBuffer := Cat(io.channel.bits, shiftBuffer(7,1))
        shiftCounter := shiftCounter + 1.U
      } .elsewhen(shiftCounter === 8.U) {
        data := shiftBuffer
        shiftCounter := 0.U
        state := UartState.START
      }
    }

    is(UartState.START) {
      io.txd := false.B
      when(io.tick) {
        state := UartState.DATA
        bitCounter := 0.U
      }
    }

    is(UartState.DATA) {
      io.txd := data(0)
      when(io.tick) {
        data := data >> 1
        when(bitCounter === 7.U) {
          state := UartState.STOP
        } .otherwise {
          bitCounter := bitCounter + 1.U
        }
      }
    }

    is(UartState.STOP) {
      io.txd := true.B
      when(io.tick) {
        state := UartState.IDLE
      }
    }
  }

  when(io.channel.valid && shiftCounter < 8.U && state === UartState.IDLE) {
    shiftBuffer := Cat(io.channel.bits, shiftBuffer(7,1))
    shiftCounter := shiftCounter + 1.U
  }
}

class SerialUartRXCore(baudRate: Int) extends Module with Config {
  val io = IO(new SerialUartRXIO)
  val baudTickDivider = clkFreq / baudRate

  val state = RegInit(UartState.IDLE)

  val data = Reg(UInt(8.W))
  val bitCounter = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  val shiftBuffer = Reg(UInt(8.W))
  val shiftCounter = RegInit(0.U(3.W))

  tickCounter := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  io.tick := tickCounter === (baudTickDivider - 1).U

  io.channel.valid := false.B
  io.channel.bits := false.B
  io.error := false.B

  val rxd = RegNext(RegNext(io.rxd))

  switch(state) {
    is(UartState.IDLE) {
      when(!rxd) {
        state := UartState.START
      }
    }

    is(UartState.START) {
      when(io.tick) {
        state := UartState.DATA
        bitCounter := 0.U
      }
    }

    is(UartState.DATA) {
      when(io.tick) {
        data := Cat(rxd, data(7,1))
        when(bitCounter === 7.U) {
          state := UartState.STOP
        } .otherwise {
          bitCounter := bitCounter + 1.U
        }
      }
    }

    is(UartState.STOP) {
      when(io.tick) {
        io.error := !rxd
        state := UartState.IDLE
        shiftBuffer := data
        shiftCounter := 8.U
      }
    }
  }

  when(shiftCounter > 0.U) {
    io.channel.valid := true.B
    io.channel.bits := shiftBuffer(0)
    when(io.channel.ready) {
      shiftBuffer := shiftBuffer >> 1
      shiftCounter := shiftCounter - 1.U
    }
  }
}

class SerialUartCore(baudRate: Int) extends Module with Config {
  val io = IO(new Bundle {
    val tx = new SerialUartTXIO
    val rx = new SerialUartRXIO
  })

  val tx = Module(new SerialUartTXCore(baudRate))
  val rx = Module(new SerialUartRXCore(baudRate))

  tx.io <> io.tx
  rx.io <> io.rx
}
