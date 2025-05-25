package peripheral

import datatype.fp._ 
import mem.fifo.AsyncFIFOCore

import chisel3._
import chisel3.util._

// ADC122S625 is a dual-channel 12-bit ADC with SPI interface
class ADC122S625IO extends Bundle {
  val en = Input(Bool())
  val cs_n = Output(Bool())
  val sdo = Input(Bool())
  val dataA = Output(new FP(12, 11))
  val dataB = Output(new FP(12, 11))

  val sclk = Input(Clock())
}

class ADC122S625Core extends Module {
  val io = IO(new ADC122S625IO)

  val fifoA = Module(new AsyncFIFOCore(new FP(12, 11), 4))
  val fifoB = Module(new AsyncFIFOCore(new FP(12, 11), 4))

  io.cs_n := !io.en

  withClock(io.sclk) {
    val csCounter = RegInit(0.U(5.W))
    csCounter := Mux(!io.cs_n, csCounter + 1.U, 0.U)

    val onSamplingA = RegInit(false.B)
    val onSamplingB = RegInit(false.B)

    onSamplingA := Mux(csCounter >= 4.U && csCounter < 16.U, true.B, false.B)
    onSamplingB := Mux(csCounter >= 20.U && csCounter < 32.U, true.B, false.B)

    val shiftRegA = RegInit(0.U(12.W))
    val bitCounterA = RegInit(0.U(4.W))
    val shiftRegB = RegInit(0.U(12.W))
    val bitCounterB = RegInit(0.U(4.W))

    bitCounterA := Mux(onSamplingA, bitCounterA + 1.U, 0.U)
    bitCounterB := Mux(onSamplingB, bitCounterB + 1.U, 0.U)

    shiftRegA := Mux(!io.cs_n && onSamplingA, Cat(io.sdo, shiftRegA(11, 1)), shiftRegA)
    shiftRegB := Mux(!io.cs_n && onSamplingB, Cat(io.sdo, shiftRegB(11, 1)), shiftRegB)

    fifoA.io.wdata := shiftRegA.asTypeOf(new FP(12, 11))
    fifoA.io.wr := bitCounterA === 11.U
    fifoB.io.wdata := shiftRegB.asTypeOf(new FP(12, 11))
    fifoB.io.wr := bitCounterB === 11.U

    fifoA.io.wclk := io.sclk
    fifoB.io.wclk := io.sclk

    fifoA.io.rd := bitCounterA === 11.U
    fifoB.io.rd := bitCounterB === 11.U
  }

  fifoA.io.rclk := clock
  fifoB.io.rclk := clock

  io.dataA := fifoA.io.rdata
  io.dataB := fifoB.io.rdata
}
