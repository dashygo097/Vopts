package peripheral

import utils._
import chisel3._
import chisel3.util._

class MCP4921IO extends Bundle {
  val en = Input(Bool())
  val buf = Input(Bool())
  val gain_n = Input(Bool())
  val shdn_n = Input(Bool())

  val cs_n = Output(Bool())
  val sdi = Output(Bool())
  val ldac_n = Output(Bool())
  val dataIn = Input(new FP(12, 11))

  val sclk = Input(Clock())
}

object MCP4921State {
  val IDLE = 0.U(2.W)
  val TRANSMIT = 1.U(2.W)
  val COMPLETE = 2.U(2.W)
}

class MCP4921Core extends Module {
  val io = IO(new MCP4921IO)
  
  withClock(io.sclk) {
    val state = RegInit(MCP4921State.IDLE)
    val bitCounter = RegInit(0.U(5.W))
    val transmitReg = RegInit(0.U(16.W))
    
    val cs_n_reg = RegInit(true.B)
    val sdi_reg = RegInit(false.B)
    val ldac_n_reg = RegInit(true.B)
    
    switch(state) {
      is(MCP4921State.IDLE) {
        when(io.en) {
          transmitReg := Cat(
            0.U(1.W),
            io.buf,
            io.gain_n,
            io.shdn_n,
            io.dataIn.value.asUInt
          )
          bitCounter := 0.U
          state := MCP4921State.TRANSMIT
          cs_n_reg := false.B
          ldac_n_reg := true.B
        }
      }
      
      is(MCP4921State.TRANSMIT) {
        when(bitCounter < 16.U) {
          sdi_reg := transmitReg(15.U - bitCounter(3, 0))
          bitCounter := bitCounter + 1.U
        }.otherwise {
          state := MCP4921State.COMPLETE
          cs_n_reg := true.B
        }
      }
      
      is(MCP4921State.COMPLETE) {
        ldac_n_reg := false.B
        state := MCP4921State.IDLE
      }
    }
    
    when(!io.en) {
      state := MCP4921State.IDLE
      cs_n_reg := true.B
      sdi_reg := false.B
      ldac_n_reg := true.B
      bitCounter := 0.U
    }
    
    io.cs_n := cs_n_reg
    io.sdi := sdi_reg
    io.ldac_n := ldac_n_reg
  }
}
