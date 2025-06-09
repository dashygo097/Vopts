package peripheral

import mem.fifo.AsyncFIFOCore

import utils._
import chisel3._
import chisel3.util._

// ADC122S625 is a dual-channel 12-bit ADC with SPI interface
class ADC122S625IO extends Bundle {
  val sclk = Input(Clock())
  val sdo = Input(Bool())
  val cs_n = Input(Bool())

  val gateIn = Input(Bool())
  val gateOut = Input(Bool())
  val dataA = Output(new FP(12, 11))
  val dataB = Output(new FP(12, 11))

  val fullA = Output(Bool())
  val fullB = Output(Bool())
  val emptyA = Output(Bool())
  val emptyB = Output(Bool())
}

class ADC122S625Core(bufferSize: Int) extends Module {
  val io = IO(new ADC122S625IO)

  val fifoA = Module(new AsyncFIFOCore(new FP(12, 11), bufferSize))
  val fifoB = Module(new AsyncFIFOCore(new FP(12, 11), bufferSize))

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

    fifoA.io.wclk := io.sclk
    fifoB.io.wclk := io.sclk

    fifoA.io.wdata := shiftRegA.asTypeOf(new FP(12, 11))
    fifoB.io.wdata := shiftRegB.asTypeOf(new FP(12, 11))

    when(io.gateIn && io.gateOut) {
      fifoA.io.wr := bitCounterA === 11.U
      fifoB.io.wr := bitCounterB === 11.U
      fifoA.io.rd := bitCounterA === 11.U
      fifoB.io.rd := bitCounterB === 11.U
    } .elsewhen(io.gateIn && !io.gateOut) {
      fifoA.io.wr := bitCounterA === 11.U
      fifoB.io.wr := bitCounterB === 11.U
      fifoA.io.rd := false.B
      fifoB.io.rd := false.B
    } .elsewhen(!io.gateIn && io.gateOut) {
      fifoA.io.wr := false.B
      fifoB.io.wr := false.B
      fifoA.io.rd := true.B
      fifoB.io.rd := true.B
    } .otherwise {
      fifoA.io.wr := false.B
      fifoB.io.wr := false.B
      fifoA.io.rd := false.B
      fifoB.io.rd := false.B
    }
  }

  fifoA.io.rclk := clock
  fifoB.io.rclk := clock

  io.fullA := fifoA.io.full
  io.fullB := fifoB.io.full
  io.emptyA := fifoA.io.empty
  io.emptyB := fifoB.io.empty

  io.dataA := fifoA.io.rdata
  io.dataB := fifoB.io.rdata
}
