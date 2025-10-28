package com.eth

import chisel3._
import chisel3.util._

object MDIOControllerState extends ChiselEnum {
  val IDLE = Value(0.U(3.W))
  val PREAMBLE = Value(1.U(3.W))
  val START = Value(2.U(3.W))
  val OP = Value(3.U(3.W))
  val PHY_ADDR = Value(4.U(3.W))
  val REG_ADDR = Value(5.U(3.W))
  val TURNAROUND = Value(6.U(3.W))
  val DATA = Value(7.U(3.W))
  val DONE = Value(8.U(3.W))
} 

class MDIOController(
  clockFreq: Int,
  mdcFreq: Int
) extends Module {
  val io = IO(new Bundle {
    val mdio = new MDIOInterface
    
    val start = Input(Bool())
    val write = Input(Bool())
    val phy_addr = Input(UInt(5.W))
    val reg_addr = Input(UInt(5.W))
    val write_data = Input(UInt(16.W))
    val read_data = Output(UInt(16.W))
    val busy = Output(Bool())
    val done = Output(Bool())
  })

  val divider = (clockFreq / mdcFreq / 2) - 1
  val mdc_counter = RegInit(0.U(log2Ceil(divider + 1).W))
  val mdc_reg = RegInit(false.B)
  
  when(mdc_counter === divider.U) {
    mdc_counter := 0.U
    mdc_reg := ~mdc_reg
  }.otherwise {
    mdc_counter := mdc_counter + 1.U
  }
  
  io.mdio.mdc := mdc_reg

  val state = RegInit(MDIOControllerState.IDLE)
  
  val bit_counter = RegInit(0.U(6.W))
  val shift_reg = RegInit(0.U(32.W))
  val is_write = RegInit(false.B)
  val read_data_reg = RegInit(0.U(16.W))
  
  io.mdio.mdio_o := shift_reg(31)
  io.mdio.mdio_oe := (state =/= MDIOControllerState.TURNAROUND) && (state =/= MDIOControllerState.DATA || is_write)
  io.read_data := read_data_reg
  io.busy := state =/= MDIOControllerState.IDLE
  io.done := state === MDIOControllerState.DONE

  val mdc_posedge = mdc_reg && (mdc_counter === 0.U)
  val mdc_negedge = !mdc_reg && (mdc_counter === 0.U)

  switch(state) {
    is(MDIOControllerState.IDLE) {
      when(io.start) {
        is_write := io.write
        val op = Mux(io.write, 1.U(2.W), 2.U(2.W)) 
        shift_reg := Cat(
          0xFFFFFFFF.U(32.W), 
          1.U(2.W),             
          op,                   
          io.phy_addr,            
          io.reg_addr,       
          Mux(io.write, 2.U(2.W), 0.U(2.W)), 
          Mux(io.write, io.write_data, 0.U(16.W))
        )(31, 0)
        bit_counter := 0.U
        state := MDIOControllerState.PREAMBLE
      }
    }

    is(MDIOControllerState.PREAMBLE) {
      when(mdc_negedge) {
        when(bit_counter === 31.U) {
          bit_counter := 0.U
          state := MDIOControllerState.START
        }.otherwise {
          shift_reg := Cat(shift_reg(30, 0), 1.U)
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.START) {
      when(mdc_negedge) {
        when(bit_counter === 1.U) {
          bit_counter := 0.U
          state := MDIOControllerState.OP
        }.otherwise {
          shift_reg := Cat(shift_reg(30, 0), 0.U)
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.OP) {
      when(mdc_negedge) {
        when(bit_counter === 1.U) {
          bit_counter := 0.U
          state := MDIOControllerState.PHY_ADDR
        }.otherwise {
          shift_reg := Cat(shift_reg(30, 0), 0.U)
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.PHY_ADDR) {
      when(mdc_negedge) {
        when(bit_counter === 4.U) {
          bit_counter := 0.U
          state := MDIOControllerState.REG_ADDR
        }.otherwise {
          shift_reg := Cat(shift_reg(30, 0), 0.U)
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.REG_ADDR) {
      when(mdc_negedge) {
        when(bit_counter === 4.U) {
          bit_counter := 0.U
          state := MDIOControllerState.TURNAROUND
        }.otherwise {
          shift_reg := Cat(shift_reg(30, 0), 0.U)
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.TURNAROUND) {
      when(mdc_posedge && !is_write) {
        shift_reg := Cat(shift_reg(30, 0), io.mdio.mdio_i)
      }
      when(mdc_negedge) {
        when(bit_counter === 1.U) {
          bit_counter := 0.U
          state := MDIOControllerState.DATA
        }.otherwise {
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.DATA) {
      when(mdc_posedge && !is_write) {
        shift_reg := Cat(shift_reg(30, 0), io.mdio.mdio_i)
      }
      when(mdc_negedge) {
        when(bit_counter === 15.U) {
          when(!is_write) {
            read_data_reg := shift_reg(15, 0)
          }
          state := MDIOControllerState.DONE
        }.otherwise {
          when(is_write) {
            shift_reg := Cat(shift_reg(30, 0), 0.U)
          }
          bit_counter := bit_counter + 1.U
        }
      }
    }

    is(MDIOControllerState.DONE) {
      state := MDIOControllerState.IDLE
    }
  }
}
