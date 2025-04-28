package com.uart
import utils._

import chisel3._
import chisel3.util._

class UartTXIO extends Bundle {
  val txd = Output(Bool())
  val channel = Flipped(Decoupled(UInt(8.W))) 
  val tick = Output(Bool())
  val busy = Output(Bool())
}

class UartRXIO extends Bundle {
  val rxd = Input(Bool())
  val channel = Decoupled(UInt(8.W))
  val tick = Output(Bool())
  val error = Output(Bool())
}

class UartTXCore(baudRate: Int) extends Module with Config {
  val io = IO(new UartTXIO)
  val baudTickDivider = clkFreq / baudRate
  
  val sIdle :: sStart :: sData :: sStop :: Nil = Enum(4)
  val state = RegInit(sIdle)
  
  val data = Reg(UInt(8.W))
  val bitCounter = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  tickCounter := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  io.tick := Mux(tickCounter === (baudTickDivider - 1).U, true.B, false.B)
  io.busy := state =/= sIdle
  io.txd := true.B  
  io.channel.ready := state === sIdle
  
  switch (state) {
    is (sIdle) {
      when (io.channel.valid) {
        state := sStart
        data := io.channel.bits
      }
    }
    
    is (sStart) {
      io.txd := false.B
      when (io.tick) {
        state := sData
        bitCounter := 0.U
      }
    }
    
    is (sData) {
      io.txd := data(0)  
      when (io.tick) {
        when (bitCounter === 7.U) {
          state := sStop
        } .otherwise {
          bitCounter := bitCounter + 1.U
          data := data >> 1
        }
      }
    }
    
    is (sStop) {
      io.txd := true.B  
      when (io.tick) {
        state := sIdle
      }
    }
  }

}

class UartRXCore(baudRate: Int) extends Module with Config {
  val io = IO(new UartRXIO)
  val baudTickDivider = clkFreq / baudRate
  
  val sIdle :: sStart :: sData :: sStop :: Nil = Enum(4)
  val state = RegInit(sIdle)
  
  val data = Reg(UInt(8.W))
  val bitCounter = RegInit(0.U(3.W))
  val tickCounter = RegInit(0.U(log2Ceil(baudTickDivider).W))

  tickCounter := Mux(tickCounter === (baudTickDivider - 1).U, 0.U, tickCounter + 1.U)
  io.tick := Mux(tickCounter === (baudTickDivider - 1).U, true.B, false.B)
  io.channel.valid := false.B
  io.channel.bits := data
  io.error := false.B
  
  val rxd = RegNext(RegNext(io.rxd))
  
  switch (state) {
    is (sIdle) {
      when (!rxd) {  
        state := sStart
      }
    }
    
    is (sStart) {
      when (io.tick) {
        state := sData
        bitCounter := 0.U
      }
    }
    
    is (sData) {
      when (io.tick) {
        data := Cat(rxd, data(7, 1))  
        when (bitCounter === 7.U) {
          state := sStop
        } .otherwise {
          bitCounter := bitCounter + 1.U
        }
      }
    }
    
    is (sStop) {
      when (io.tick) {
        io.channel.valid := true.B
        io.error := !rxd  
        state := sIdle
      }
    }
  }
}

class UartCore(baudRate: Int) extends Module with Config {
  val io = IO(new Bundle {
    val tx = new UartTXIO
    val rx = new UartRXIO
  })
  
  val tx = Module(new UartTXCore(baudRate))
  val rx = Module(new UartRXCore(baudRate))
  
  tx.io <> io.tx
  rx.io <> io.rx
}
