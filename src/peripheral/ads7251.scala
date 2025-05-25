package peripheral

import datatype.fp._
import mem.fifo.AsyncFIFOCore

import chisel3._
import chisel3.util._

// ADS7251 is a dual-channel 12-bit ADC with SPI interface
class ADS7251IO extends Bundle {
  val cs_n = Output(Bool())
  val sdoa = Input(Bool())
  val sdob = Input(Bool())
  val dataA = Output(new FP(12, 11))
  val dataB = Output(new FP(12, 11))

  val sclk = Input(Clock())
}

class ADS7251Core extends Module {
  val io = IO(new ADS7251IO)

  val fifoA = Module(new AsyncFIFOCore(new FP(12, 11), 16))
  val fifoB = Module(new AsyncFIFOCore(new FP(12, 11), 16))

  withClock(io.sclk) {
    val csCounter = RegInit(0.U(5.W))

    io.cs_n := csCounter >= 14.U
    csCounter := Mux(csCounter === 15.U, 0.U, csCounter + 1.U)

    val shiftRegA = RegInit(0.U(14.W))
    val shiftRegB = RegInit(0.U(14.W))

    when(!io.cs_n && csCounter >= 2.U && csCounter < 14.U) {
      shiftRegA := Cat(shiftRegA(12, 0), io.sdoa)
      shiftRegB := Cat(shiftRegB(12, 0), io.sdob)
    }

    val dataA_12bit = shiftRegA(11, 0)
    val dataB_12bit = shiftRegB(11, 0)

    shiftRegA := Mux(!io.cs_n, Cat(shiftRegA(10, 0), io.sdoa), shiftRegA)
    shiftRegB := Mux(!io.cs_n, Cat(shiftRegB(10, 0), io.sdob), shiftRegB)

    fifoA.io.wclk := io.sclk
    fifoB.io.wclk := io.sclk

    fifoA.io.wdata := dataA_12bit.asTypeOf(new FP(12, 11))
    fifoB.io.wdata := dataB_12bit.asTypeOf(new FP(12, 11))

    fifoA.io.wr := (csCounter === 13.U) && !fifoA.io.full  
    fifoB.io.wr := (csCounter === 13.U) && !fifoB.io.full  

    fifoA.io.rd := csCounter === 13.U
    fifoB.io.rd := csCounter === 13.U
  }

  fifoA.io.rclk := clock
  fifoB.io.rclk := clock

  io.dataA := fifoA.io.rdata
  io.dataB := fifoB.io.rdata
}
