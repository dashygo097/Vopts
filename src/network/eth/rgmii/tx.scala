package net.eth

import chisel3._
import chisel3.util._

object RGMIIEthernetTXState extends ChiselEnum {
  val IDLE = Value(0.U(3.W))
  val PREAMBLE = Value(1.U(3.W))
  val DATA = Value(2.U(3.W))
  val CRC = Value(3.U(3.W))
  val IFG = Value(4.U(3.W))
}

class RGMIIEthernetTX extends Module with EthernetFrameParams {
  val io = IO(new Bundle {
    val rgmii = new Bundle {
      val tx_clk = Output(Clock())
      val tx_en = Output(Bool())
      val txd = Output(UInt(4.W))
      val tx_er = Output(Bool())
    }
    val frame = Flipped(Decoupled(new Bundle {
      val data = UInt(8.W)
      val last = Bool()
      val error = Bool()
    }))
    val clk125m = Input(Clock()) // 125 MHz for gigabit
  })

  // State machine
  val state = RegInit(RGMIIEthernetTXState.IDLE)

  // Counters and registers
  val byteCounter = RegInit(0.U(16.W))
  val ifgCounter = RegInit(0.U(4.W))
  val preambleCounter = RegInit(0.U(3.W))
  
  // DDR output registers (RGMII uses both clock edges)
  val txdReg = RegInit(0.U(4.W))
  val txEnReg = RegInit(false.B)
  val txErReg = RegInit(false.B)
  
  // Data buffering
  val dataBuffer = RegInit(0.U(8.W))
  val dataValid = RegInit(false.B)
  val clockPhase = RegInit(false.B)
  
  // CRC-32 calculation
  val crcModule = Module(new CRC32)
  crcModule.io.data := dataBuffer
  crcModule.io.valid := state === RGMIIEthernetTXState.DATA && dataValid
  crcModule.io.reset := state === RGMIIEthernetTXState.IDLE
  
  val crcValue = RegInit(0.U(32.W))

  // Default outputs
  io.frame.ready := false.B
  io.rgmii.tx_clk := io.clk125m
  io.rgmii.tx_en := txEnReg
  io.rgmii.txd := txdReg
  io.rgmii.tx_er := txErReg

  // Clock phase toggle for DDR
  clockPhase := ~clockPhase

  switch(state) {
    is(RGMIIEthernetTXState.IDLE) {
      txEnReg := false.B
      txdReg := 0.U
      txErReg := false.B
      
      when(io.frame.valid) {
        state := RGMIIEthernetTXState.PREAMBLE
        preambleCounter := 0.U
      }
    }

    is(RGMIIEthernetTXState.PREAMBLE) {
      txEnReg := true.B
      txErReg := false.B
      
      // Send preamble and SFD
      when(preambleCounter < 7.U) {
        when(clockPhase) {
          txdReg := 0x5.U // Lower nibble of 0x55
        }.otherwise {
          txdReg := 0x5.U // Upper nibble of 0x55
        }
      }.otherwise { // SFD byte (0xD5)
        when(clockPhase) {
          txdReg := 0x5.U
        }.otherwise {
          txdReg := 0xD.U
        }
      }
      
      when(clockPhase) {
        preambleCounter := preambleCounter + 1.U
        when(preambleCounter === 7.U) {
          state := RGMIIEthernetTXState.DATA
          byteCounter := 0.U
        }
      }
    }

    is(RGMIIEthernetTXState.DATA) {
      txEnReg := true.B
      
      when(clockPhase) {
        // Lower nibble
        txdReg := dataBuffer(3, 0)
      }.otherwise {
        // Upper nibble
        txdReg := dataBuffer(7, 4)
        
        // Ready for next byte
        io.frame.ready := true.B
        
        when(io.frame.valid) {
          dataBuffer := io.frame.bits.data
          dataValid := true.B
          txErReg := io.frame.bits.error
          byteCounter := byteCounter + 1.U
          
          when(io.frame.bits.last) {
            crcValue := crcModule.io.crc
            state := RGMIIEthernetTXState.CRC
            byteCounter := 0.U
          }
        }.otherwise {
          dataValid := false.B
        }
      }
    }

    is(RGMIIEthernetTXState.CRC) {
      txEnReg := true.B
      txErReg := false.B
      
      // Send CRC-32 in reverse bit order (LSB first)
      val crcByte = Wire(UInt(8.W))
      crcByte := MuxLookup(byteCounter, 0.U)(Seq(
        0.U -> crcValue(7, 0),
        1.U -> crcValue(15, 8),
        2.U -> crcValue(23, 16),
        3.U -> crcValue(31, 24)
      ))
      
      when(clockPhase) {
        txdReg := crcByte(3, 0)
      }.otherwise {
        txdReg := crcByte(7, 4)
        byteCounter := byteCounter + 1.U
        
        when(byteCounter === 3.U) {
          state := RGMIIEthernetTXState.IFG
          ifgCounter := 0.U
        }
      }
    }

    is(RGMIIEthernetTXState.IFG) {
      txEnReg := false.B
      txdReg := 0.U
      txErReg := false.B
      
      when(clockPhase) {
        ifgCounter := ifgCounter + 1.U
        when(ifgCounter === 11.U) {
          state := RGMIIEthernetTXState.IDLE
        }
      }
    }
  }
}

