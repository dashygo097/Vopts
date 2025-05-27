package com.fmc

import mem.sram.AsyncRAMCore
import scala.math.max

import utils._
import chisel3._
import chisel3.experimental._

class FMCMuxedSlaveInterfaceIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val data = Analog(max(gen.getWidth, addrWidth).W)

  val ale = Input(Bool())
  val we_n = Input(Bool())
  val oe_n = Input(Bool())
  val cs_n = Input(Bool())

  val clk = Input(Clock())
}

class FMCMuxedSlaveRAMCore[T <: Data](gen: T, addrWidth: Int) extends Module {
  val io = IO(new FMCMuxedSlaveInterfaceIO(gen, addrWidth))
  
  val sram = Module(new AsyncRAMCore(gen, addrWidth))
  val width = gen.getWidth
  
  val biDirBuffer = Module(new BidirectionalBuffer(width))
  
  attach(io.data, biDirBuffer.io.dataIO)
  
  val wr_en = !io.cs_n && !io.we_n
  val rd_en = !io.cs_n && !io.oe_n
  
  biDirBuffer.io.oe := rd_en
  
  val addrLatchRising = io.ale && !RegNext(io.ale)
  val latchAddr = RegInit(0.U(addrWidth.W))
  
  when (addrLatchRising) {
    latchAddr := biDirBuffer.io.dataIn(addrWidth - 1, 0)
  }
  
  sram.io.addr := latchAddr
  sram.io.dataIn := biDirBuffer.io.dataIn.asTypeOf(gen)
  sram.io.en.we := wr_en
  sram.io.en.re := rd_en
  sram.io.en.wr_clk := io.clk
  sram.io.en.rd_clk := io.clk
  
  biDirBuffer.io.dataOut := sram.io.dataOut.asUInt
  
  dontTouch(latchAddr)
  dontTouch(wr_en)
  dontTouch(rd_en)
}
