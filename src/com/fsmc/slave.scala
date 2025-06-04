package com.fsmc

import mem.sram.SyncRAMCore

import utils._
import chisel3._
import chisel3.util._
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

  mem.io.en.re := false.B
  mem.io.en.we := false.B
  mem.io.addr := 0.U(addrWidth.W)
  mem.io.dataIn := 0.U.asTypeOf(gen)

  bi_buffer.io.oe := false.B
  bi_buffer.io.dataOut := 0.U(gen.getWidth.W)

  switch(cnt) {
    is(sFSMC.IDLE) {
      mem.io.en.re := false.B
      mem.io.en.we := false.B
      mem.io.addr := 0.U(addrWidth.W)
      mem.io.dataIn := 0.U.asTypeOf(gen)

      bi_buffer.io.oe := false.B
      bi_buffer.io.dataOut := 0.U(gen.getWidth.W)
      
      when(!io.ne) {
        addrNext := io.addr
        when(!io.noe) {
          cnt := sFSMC.READ
        }.elsewhen(io.noe) {
          cnt := sFSMC.WRITE
        }
      }
    }
    
    is(sFSMC.READ) {
      mem.io.en.re := true.B
      mem.io.en.we := false.B
      mem.io.addr := addrNext
      mem.io.dataIn := 0.U.asTypeOf(gen)
      
      bi_buffer.io.oe := true.B
      bi_buffer.io.dataOut := mem.io.dataOut.asUInt
      
      when(io.ne || io.noe) {
        cnt := sFSMC.IDLE
      }.otherwise {
        addrNext := io.addr
      }
    }
    
    is(sFSMC.WRITE) {
      bi_buffer.io.oe := false.B 
      bi_buffer.io.dataOut := 0.U(gen.getWidth.W)
      
      when(!io.ne && io.noe) {
        when(!io.nwe) {
          mem.io.en.re := false.B
          mem.io.en.we := true.B
          mem.io.addr := addrNext
          mem.io.dataIn := bi_buffer.io.dataIn.asTypeOf(gen)
        }.otherwise {
          mem.io.en.re := false.B
          mem.io.en.we := false.B
          mem.io.addr := addrNext
          mem.io.dataIn := 0.U.asTypeOf(gen)
          addrNext := io.addr
        }
      }.otherwise {
        mem.io.en.re := false.B
        mem.io.en.we := false.B
        mem.io.addr := 0.U(addrWidth.W)
        mem.io.dataIn := 0.U.asTypeOf(gen)
        cnt := sFSMC.IDLE
      }
      
      when(io.ne) {
        cnt := sFSMC.IDLE
      }
    }
  }
}
