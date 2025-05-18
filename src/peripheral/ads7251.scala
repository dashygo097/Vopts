package peripheral

import utils._
import datatype.fp._
import mem.fifo.AsyncFIFOCore

import chisel3._
import chisel3.util._

class ADS7251IO extends Bundle {
  val cs_n = Output(Bool())
  val sdoa = Input(Bool())
  val sdob = Input(Bool())
  val dataA = Output(new FP(12, 11))
  val dataB = Output(new FP(12, 11))

  val sclk = Input(Clock())
}

class ADS7251Core extends Module with Config {
  val io = IO(new ADS7251IO)

  withClock(io.sclk) {
    val csCounter = RegInit(0.U(4.W))

    io.cs_n := Mux(csCounter === 13.U, true.B, false.B)
    csCounter := Mux(csCounter === 13.U, 0.U, csCounter + 1.U)
  }

  val fifoA = Module(new AsyncFIFOCore(new FP(12, 11), 16))
  val fifoB = Module(new AsyncFIFOCore(new FP(12, 11), 16))

  withClock(io.sclk) {
    val shiftRegA = RegInit(0.U(12.W))
    val bitCounterA = RegInit(0.U(4.W))
    val shiftRegB = RegInit(0.U(12.W))
    val bitCounterB = RegInit(0.U(4.W))

    bitCounterA := Mux(bitCounterA === 12.U, 0.U, bitCounterA + 1.U)
    bitCounterB := Mux(bitCounterB === 12.U, 0.U, bitCounterB + 1.U)

    shiftRegA := Mux(!io.cs_n, Cat(shiftRegA(10, 0), io.sdoa), shiftRegA)
    shiftRegB := Mux(!io.cs_n, Cat(shiftRegB(10, 0), io.sdob), shiftRegB)

    fifoA.io.wdata := shiftRegA.asTypeOf(new FP(12, 11))
    fifoA.io.wr := bitCounterA === 12.U
    fifoB.io.wdata := shiftRegB.asTypeOf(new FP(12, 11))
    fifoB.io.wr := bitCounterB === 12.U

    fifoA.io.wr := bitCounterA === 12.U
    fifoB.io.rd := bitCounterB === 12.U
    fifoA.io.wclk := io.sclk
    fifoB.io.wclk := io.sclk
  }

  fifoA.io.rclk := clock
  fifoB.io.rclk := clock
  fifoA.io.rd := true.B
  fifoB.io.rd := true.B


  io.dataA := fifoA.io.rdata
  io.dataB := fifoB.io.rdata
}
