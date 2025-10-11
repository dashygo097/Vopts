package io.uart

import com.axi._
import chisel3._
import chisel3.util._

class AXIFullMasterUART(
  addrWidth: Int = 32,
  dataWidth: Int = 32,
  idWidth: Int = 4,
  userWidth: Int = 0,
  clkFreq: Int = 100000000,
  baudRate: Int = 115200
) extends Module {
  override def desiredName: String =
    s"axifull_master_uart_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  val axi  = IO(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))
  val uart = IO(new Bundle {
    val tx  = Output(Bool())
    val rx  = Input(Bool())
    val cts = Input(Bool())
    val rts = Output(Bool())
  })

  val ctrl = IO(new Bundle {
    val start         = Input(Bool())
    val tx_data       = Input(UInt(8.W))
    val tx_valid      = Input(Bool())
    val tx_ready      = Output(Bool())
    val rx_data       = Output(UInt(8.W))
    val rx_valid      = Output(Bool())
    val rx_ready      = Input(Bool())
    val status        = Output(UInt(8.W))
    val config        = Input(UInt(32.W))
    val mem_base_addr = Input(UInt(addrWidth.W))
    val mem_length    = Input(UInt(addrWidth.W))
  })

  val clockDivider = (clkFreq / baudRate).toInt
  val divWidth     = log2Ceil(clockDivider)

  val sIdle :: sWriteAddr :: sWriteData :: sWriteResp :: sReadAddr :: sReadData :: sReadResp :: Nil =
    Enum(7)
  val state                                                                                         = RegInit(sIdle)

  val uIdle :: uStart :: uData :: uParity :: uStop :: Nil = Enum(5)
  val uartState                                           = RegInit(uIdle)

  val txShiftReg  = RegInit(0x7f.U(10.W))
  val rxShiftReg  = RegInit(0.U(10.W))
  val txBitCount  = RegInit(0.U(4.W))
  val rxBitCount  = RegInit(0.U(4.W))
  val baudCounter = RegInit(0.U(divWidth.W))
  val baudTick    = baudCounter === (clockDivider - 1).U

  val awaddr   = RegInit(0.U(addrWidth.W))
  val araddr   = RegInit(0.U(addrWidth.W))
  val wdata    = RegInit(0.U(dataWidth.W))
  val wstrb    = RegInit(0.U((dataWidth / 8).W))
  val txBuffer = RegInit(0.U(8.W))
  val rxBuffer = RegInit(0.U(8.W))
  val txFull   = RegInit(false.B)
  val rxEmpty  = RegInit(true.B)
  val txFifo   = Module(new Queue(UInt(8.W), 16))
  val rxFifo   = Module(new Queue(UInt(8.W), 16))

  val memAddr          = RegInit(0.U(addrWidth.W))
  val memLength        = RegInit(0.U(addrWidth.W))
  val bytesTransferred = RegInit(0.U(addrWidth.W))

  uart.rts      := false.B
  ctrl.tx_ready := !txFull
  ctrl.rx_data  := rxFifo.io.deq.bits
  ctrl.rx_valid := rxFifo.io.deq.valid
  ctrl.status   := Cat(
    0.U(6.W),
    rxEmpty,
    txFull
  )

  baudCounter := Mux(baudTick, 0.U, baudCounter + 1.U)

  switch(uartState) {
    is(uIdle) {
      when(txFifo.io.deq.valid && baudTick) {
        uartState           := uStart
        txShiftReg          := Cat(1.B, txFifo.io.deq.bits, 0.B)
        txBitCount          := 0.U
        txFifo.io.deq.ready := true.B
      }
    }
    is(uStart) {
      when(baudTick) {
        uartState  := uData
        txBitCount := txBitCount + 1.U
      }
    }
    is(uData) {
      when(baudTick) {
        txBitCount := txBitCount + 1.U
        when(txBitCount === 8.U) {
          uartState := uStop
        }
      }
    }
    is(uStop) {
      when(baudTick) {
        uartState := uIdle
      }
    }
  }

  uart.tx := txShiftReg(0)
  when(baudTick && uartState =/= uIdle) {
    txShiftReg := txShiftReg >> 1
  }

  val rxSync   = RegNext(RegNext(uart.rx))
  val rxSample = baudTick && baudCounter === (clockDivider / 2).U

  switch(state) {
    is(sIdle) {
      when(ctrl.start && bytesTransferred < memLength) {
        state  := sWriteAddr
        awaddr := memAddr + bytesTransferred
      }
    }
    is(sWriteAddr) {
      when(axi.aw.ready) {
        state := sWriteData
      }
    }
    is(sWriteData) {
      when(axi.w.ready) {
        state := sWriteResp
      }
    }
    is(sWriteResp) {
      when(axi.b.valid) {
        bytesTransferred := bytesTransferred + (dataWidth / 8).U
        when(bytesTransferred + (dataWidth / 8).U >= memLength) {
          state := sIdle
        }.otherwise {
          state := sWriteAddr
        }
      }
    }
  }

  axi.aw.valid       := state === sWriteAddr
  axi.aw.bits.addr   := awaddr
  axi.aw.bits.prot   := 0.U
  axi.aw.bits.id     := 0.U
  axi.aw.bits.user   := 0.U
  axi.aw.bits.len    := 0.U                     
  axi.aw.bits.size   := log2Ceil(dataWidth / 8).U 
  axi.aw.bits.burst  := 1.U                  
  axi.aw.bits.lock   := 0.U
  axi.aw.bits.cache  := 0.U
  axi.aw.bits.qos    := 0.U
  axi.aw.bits.region := 0.U

  axi.w.valid     := state === sWriteData
  axi.w.bits.data := Cat(Fill(dataWidth - 8, 0.U), txFifo.io.deq.bits)
  axi.w.bits.strb := 1.U((dataWidth / 8).W)
  axi.w.bits.last := true.B
  axi.w.bits.user := 0.U

  axi.b.ready := state === sWriteResp

  axi.ar.valid := false.B 
  axi.ar.bits  := DontCare

  axi.r.ready := false.B

  txFifo.io.enq.bits  := ctrl.tx_data
  txFifo.io.enq.valid := ctrl.tx_valid && !txFull
  txFull              := !txFifo.io.enq.ready

  rxFifo.io.deq.ready := ctrl.rx_ready

  when(ctrl.start) {
    memAddr          := ctrl.mem_base_addr
    memLength        := ctrl.mem_length
    bytesTransferred := 0.U
  }

  val debug = IO(new Bundle {
    val state      = Output(UInt(3.W))
    val uart_state = Output(UInt(3.W))
    val bytes_sent = Output(UInt(32.W))
  })

  debug.state      := state
  debug.uart_state := uartState
  debug.bytes_sent := bytesTransferred
}
