package com.uart
import chisel3._
import chisel3.util._

object UartState extends ChiselEnum {
  val IDLE, START, DATA, STOP = Value
}

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
  override def desiredName: String = s"uart_tx_byte_level_b${baudRate}_f$clkFreq"
  val io                           = IO(new ByteLevelUartTXIO).suggestName("UART_TX")
  val baudTickDivider              = clkFreq / baudRate

  val state       = RegInit(UartState.IDLE)
  val data        = Reg(UInt(8.W))
  val bitCounter  = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  // Tick generation
  val tick = tickCounter === (baudTickDivider - 1).U
  tickCounter := Mux(tick, 0.U, tickCounter + 1.U)

  // Default outputs
  io.busy          := state =/= UartState.IDLE
  io.txd           := true.B // Default idle high
  io.channel.ready := false.B

  switch(state) {
    is(UartState.IDLE) {
      io.channel.ready := true.B
      when(io.channel.valid) {
        state       := UartState.START
        data        := io.channel.bits
        tickCounter := 0.U
      }
    }
    is(UartState.START) {
      io.txd := false.B // Start bit is LOW
      when(tick) {
        state      := UartState.DATA
        bitCounter := 0.U
      }
    }
    is(UartState.DATA) {
      io.txd := data(0) // Send LSB first
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
      io.txd := true.B // Stop bit is HIGH
      when(tick) {
        state := UartState.IDLE
      }
    }
  }
}

class ByteLevelUartRX(baudRate: Int, clkFreq: Int) extends Module {
  override def desiredName: String = s"uart_rx_byte_level_b${baudRate}_f$clkFreq"
  val io                           = IO(new ByteLevelUartRXIO).suggestName("UART_RX")
  val baudTickDivider              = clkFreq / baudRate

  val state       = RegInit(UartState.IDLE)
  val data        = Reg(UInt(8.W))
  val bitCounter  = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  // Tick generation
  val tick = tickCounter === (baudTickDivider - 1).U
  tickCounter := Mux(tick, 0.U, tickCounter + 1.U)

  // Double-register rxd to avoid metastability
  val rxd = RegNext(RegNext(io.rxd))

  // Default outputs
  io.channel.valid := false.B
  io.channel.bits  := 0.U
  io.error         := false.B

  switch(state) {
    is(UartState.IDLE) {
      when(!rxd) { // Detect start bit (HIGH to LOW transition)
        state       := UartState.START
        tickCounter := (baudTickDivider / 2).U
      }
    }
    is(UartState.START) {
      when(tick) {
        when(!rxd) { // Verify start bit is still LOW
          state      := UartState.DATA
          bitCounter := 0.U
        }.otherwise {
          state := UartState.IDLE
        }
      }
    }
    is(UartState.DATA) {
      when(tick) {
        data := Cat(rxd, data(7, 1)) // Shift in from MSB, receive LSB first
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
        io.channel.bits  := data
        io.error         := !rxd // Error if stop bit is not HIGH
        state            := UartState.IDLE
      }
    }
  }
}

class ByteLevelUart(baudRate: Int, clkFreq: Int) extends Module {
  override def desiredName: String = s"uart_byte_level_b${baudRate}_f$clkFreq"
  val io                           = IO(new Bundle {
    val tx = new ByteLevelUartTXIO
    val rx = new ByteLevelUartRXIO
  }).suggestName("UART")

  val tx = Module(new ByteLevelUartTX(baudRate, clkFreq))
  val rx = Module(new ByteLevelUartRX(baudRate, clkFreq))

  tx.io <> io.tx
  rx.io <> io.rx
}
