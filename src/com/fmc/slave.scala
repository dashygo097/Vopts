package com.fmc

import mem.sram.AsyncRAMCore;

import chisel3._

class FMCSlaveInterfaceIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val dataIn = Input(gen)
  val dataOut = Output(gen)
  val dataOE = Output(Bool())

  val we_n = Input(Bool())
  val oe_n = Input(Bool())
  val cs_n = Input(Bool())

  val clk = Input(Clock())
}

class FMCSlaveRAMCore[T <: Data](gen: T, addrWidth: Int) extends Module {
  val io = IO(new FMCSlaveInterfaceIO(gen, addrWidth))
  val sram = Module(new AsyncRAMCore(gen, addrWidth))

  sram.io.addr := io.addr
  sram.io.dataIn := io.dataIn

  val wr_en = !(io.cs_n && io.we_n)
  val rd_en = !(io.cs_n && io.oe_n)

  sram.io.en.we := wr_en
  sram.io.en.re := rd_en

  sram.io.en.wr_clk := io.clk
  sram.io.en.rd_clk := io.clk

  io.dataOut := sram.io.dataOut
  io.dataOE := rd_en
}


