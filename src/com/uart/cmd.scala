package com.uart
import chisel3._
import chisel3.util._

class UartCmdProcessorIO extends Bundle {
  val txd        = Output(Bool())
  val rxd        = Input(Bool())
  val cmd_valid  = Output(Bool())
  val cmd_type   = Output(UartCmdType())
  val cmd_addr   = Output(UInt(32.W))
  val cmd_wdata  = Output(UInt(32.W))
  val resp_valid = Input(Bool())
  val resp_rdata = Input(UInt(32.W))
  val resp_ready = Output(Bool())
}

class UartCmdProcessor(clkFreq: Int, baudRate: Int, endianness: String) extends Module {
  override def desiredName: String =
    s"uart_level_b${baudRate}_f${clkFreq}_$endianness"

  val io = IO(new UartCmdProcessorIO).suggestName("UART_CMD")

  val uart_tx = Module(new UartTx(baudRate, clkFreq))
  val uart_rx = Module(new UartRx(baudRate, clkFreq))

  def assembleWord32FromBytes(b0: UInt, b1: UInt, b2: UInt, b3: UInt): UInt =
    if (isLittleEndian) {
      // Little-endian: LSB first (b0 is LSB)
      Cat(b3, b2, b1, b0)
    } else {
      // Big-endian: MSB first (b0 is MSB)
      Cat(b0, b1, b2, b3)
    }

  def disassembleWord32(word: UInt): Vec[UInt] = {
    val bytes = Wire(Vec(4, UInt(8.W)))
    if (isLittleEndian) {
      // Little-endian: LSB first
      bytes(0) := word(7, 0)
      bytes(1) := word(15, 8)
      bytes(2) := word(23, 16)
      bytes(3) := word(31, 24)
    } else {
      // Big-endian: MSB first
      bytes(0) := word(31, 24)
      bytes(1) := word(23, 16)
      bytes(2) := word(15, 8)
      bytes(3) := word(7, 0)
    }
    bytes
  }

  io.txd                   := uart_tx.io.txd
  uart_tx.io.channel.valid := false.B
  uart_tx.io.channel.bits  := 0.U
  uart_rx.io.rxd           := io.rxd
  uart_rx.io.channel.ready := true.B

  require(endianness == "big" || endianness == "little", s"endianness must be 'big' or 'little', got '$endianness'")

  val isLittleEndian = endianness == "little"

  val rx_state    = RegInit(0.U(2.W))
  val rx_byte_cnt = RegInit(0.U(4.W))
  val rx_buffer   = Reg(Vec(9, UInt(8.W)))

  val cmd_valid_reg = RegInit(false.B)
  val cmd_type_reg  = Reg(UartCmdType())
  val cmd_addr_reg  = RegInit(0.U(32.W))
  val cmd_wdata_reg = RegInit(0.U(32.W))

  io.cmd_valid := cmd_valid_reg
  io.cmd_type  := cmd_type_reg
  io.cmd_addr  := cmd_addr_reg
  io.cmd_wdata := cmd_wdata_reg

  when(cmd_valid_reg) {
    cmd_valid_reg := false.B
  }

  switch(rx_state) {
    is(0.U) { // IDLE
      when(uart_rx.io.channel.valid && !uart_rx.io.error) {
        rx_buffer(0) := uart_rx.io.channel.bits
        rx_byte_cnt  := 1.U
        rx_state     := 1.U
      }
    }
    is(1.U) { // RECEIVING
      when(uart_rx.io.channel.valid && !uart_rx.io.error) {
        rx_buffer(rx_byte_cnt) := uart_rx.io.channel.bits

        val next_byte_cnt = rx_byte_cnt + 1.U
        rx_byte_cnt := next_byte_cnt

        when(next_byte_cnt === 9.U) {
          cmd_valid_reg := true.B
          cmd_type_reg  := MuxLookup(rx_buffer(0), UartCmdType.WRITE)(
            Seq(
              0.U -> UartCmdType.WRITE,
              1.U -> UartCmdType.READ,
              2.U -> UartCmdType.MOVE
            )
          )

          cmd_addr_reg := assembleWord32FromBytes(
            rx_buffer(1),
            rx_buffer(2),
            rx_buffer(3),
            rx_buffer(4)
          )

          cmd_wdata_reg := assembleWord32FromBytes(
            rx_buffer(5),
            rx_buffer(6),
            rx_buffer(7),
            uart_rx.io.channel.bits
          )

          rx_state    := 0.U
          rx_byte_cnt := 0.U
        }
      }
    }
  }

  val tx_state       = RegInit(0.U(2.W))
  val tx_byte_cnt    = RegInit(0.U(3.W))
  val tx_buffer      = Reg(Vec(5, UInt(8.W)))
  val tx_total_bytes = RegInit(0.U(4.W))

  io.resp_ready            := false.B
  uart_tx.io.channel.valid := false.B
  uart_tx.io.channel.bits  := 0.U
  switch(tx_state) {
    is(0.U) { // IDLE
      when(io.resp_valid) {
        tx_buffer(0) := 0.U // Status byte

        val resp_bytes = disassembleWord32(io.resp_rdata)
        tx_buffer(1) := resp_bytes(0)
        tx_buffer(2) := resp_bytes(1)
        tx_buffer(3) := resp_bytes(2)
        tx_buffer(4) := resp_bytes(3)

        tx_total_bytes := 5.U
        tx_byte_cnt    := 0.U
        tx_state       := 1.U
        io.resp_ready  := true.B
      }
    }
    is(1.U) { // SENDING
      uart_tx.io.channel.valid := true.B
      uart_tx.io.channel.bits  := tx_buffer(tx_byte_cnt)
      when(uart_tx.io.channel.ready) {
        when(tx_byte_cnt === (tx_total_bytes - 1.U)) {
          tx_state    := 0.U
          tx_byte_cnt := 0.U
        }.otherwise {
          tx_byte_cnt := tx_byte_cnt + 1.U
        }
      }
    }
  }
}
