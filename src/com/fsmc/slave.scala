package com.fsmc

import mem.sram.SyncRAMCore

import utils._
import chisel3._
import chisel3.experimental._

class FSMCSlaveInterfaceIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val ne = Input(Bool())
  val noe = Input(Bool())
  val nwe = Input(Bool())

  val addr = Input(UInt(addrWidth.W))
  val data = Analog(gen.getWidth.W)
}

object sFSMC {
  val IDLE = 0.U(2.W)
  val READ = 1.U(2.W)
  val WRITE = 2.U(2.W)
  val WAIT = 3.U(2.W)
}

class FSMCSlaveRAMCore[T <: Data](gen: T, addrWidth: Int) extends Module {
  val io = IO(new FSMCSlaveInterfaceIO(gen, addrWidth))
  val size = 1 << addrWidth
  val mem = Module(new SyncRAMCore(gen, size))

  val cnt = RegInit(0.U(2.W))
  val addrNext = RegInit(0.U(addrWidth.W))
  val bi_buffer = Module(new BidirectionalBuffer(gen.getWidth))
  attach(io.data, bi_buffer.io.dataIO)

  cnt := sFSMC.IDLE
  mem.io.dataIn := 0.U.asTypeOf(gen)
  mem.io.addr := 0.U(gen.getWidth.W)
  mem.io.en.re := false.B
  mem.io.en.we := false.B
  bi_buffer.io.oe := false.B
  bi_buffer.io.dataOut := 0.U(gen.getWidth.W)

  when(cnt === sFSMC.IDLE) {
    mem.io.en.re := false.B
    mem.io.en.we := false.B
    bi_buffer.io.oe := false.B
    when(!io.ne && !io.noe) {
      cnt := sFSMC.READ
      addrNext := io.addr
    }.elsewhen(!io.ne && io.noe) {
      cnt := sFSMC.WRITE
      addrNext := io.addr
    } .otherwise {
      cnt := sFSMC.IDLE
    }
  }.elsewhen(cnt === sFSMC.READ) {
    mem.io.en.we := false.B
    mem.io.en.re := true.B
    bi_buffer.io.oe := true.B
    mem.io.addr := addrNext
    bi_buffer.io.dataOut := mem.io.dataOut.asUInt

    when(io.ne | io.noe) {
      cnt := sFSMC.IDLE
    } .otherwise {
      cnt := sFSMC.READ
    }

  }.elsewhen(cnt === sFSMC.WRITE) {
    when(!io.nwe) {
      mem.io.en.re := false.B
      mem.io.en.we := true.B
      bi_buffer.io.oe := false.B
      mem.io.addr := addrNext
      mem.io.dataIn := bi_buffer.io.dataIn.asTypeOf(gen)
    } .elsewhen(io.nwe) {
      mem.io.en.re := false.B
      mem.io.en.we := false.B
      bi_buffer.io.oe := false.B
      addrNext := io.addr
      mem.io.addr := addrNext
    } .elsewhen(!io.ne && io.noe && io.nwe) {
      /// DO NOTHING, just wait for next command
    } .elsewhen(io.ne | io.noe) {
      cnt := sFSMC.IDLE
    } .otherwise {
      cnt := sFSMC.WRITE
    }

  }.elsewhen(cnt === sFSMC.WAIT) {
    /// TODO: Implement WAIT state if needed
  }
}
