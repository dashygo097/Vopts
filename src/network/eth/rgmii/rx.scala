package net.eth

import chisel3._
import chisel3.util._

object RGMIIEthernetRXState extends ChiselEnum {
  val IDLE = Value(0.U(2.W))
  val PREAMBLE = Value(1.U(2.W))
  val DATA = Value(2.U(2.W))
}

class RGMIIEthernetRX extends Module {
  val io = IO(new Bundle {
    val rgmii = new Bundle {
      val rx_clk = Input(Clock())
      val rx_dv = Input(Bool())
      val rxd = Input(UInt(4.W))
      val rx_er = Input(Bool())
    }
    val frame = Decoupled(new Bundle {
      val data = UInt(8.W)
      val last = Bool()
      val error = Bool()
    })
  })

  // State machine
  val state = RegInit(RGMIIEthernetRXState.IDLE)

  // DDR input capture
  val rxdLower = RegInit(0.U(4.W))
  val rxdUpper = RegInit(0.U(4.W))
  val rxDvReg = RegInit(false.B)
  val rxErReg = RegInit(false.B)
  val clockPhase = RegInit(false.B)

  // Data assembly
  val dataAssembled = Wire(UInt(8.W))
  dataAssembled := Cat(rxdUpper, rxdLower)
  
  val dataBuffer = RegInit(0.U(8.W))
  val dataValidReg = RegInit(false.B)
  val dataLastReg = RegInit(false.B)
  val dataErrorReg = RegInit(false.B)

  // CRC validation
  val crcModule = Module(new CRC32)
  crcModule.io.data := dataAssembled
  crcModule.io.valid := state === RGMIIEthernetRXState.DATA && clockPhase
  crcModule.io.reset := state === RGMIIEthernetRXState.IDLE

  val receivedCrc = RegInit(0.U(32.W))
  val crcByteCount = RegInit(0.U(2.W))

  // Counters
  val preambleCount = RegInit(0.U(4.W))
  val byteCount = RegInit(0.U(16.W))

  // Output assignment
  io.frame.bits.data := dataBuffer
  io.frame.bits.last := dataLastReg
  io.frame.bits.error := dataErrorReg
  io.frame.valid := dataValidReg

  // Clock phase tracking
  clockPhase := ~clockPhase

  // Capture inputs on both edges (simplified - actual RGMII uses DDR)
  when(clockPhase) {
    rxdLower := io.rgmii.rxd
  }.otherwise {
    rxdUpper := io.rgmii.rxd
  }
  rxDvReg := io.rgmii.rx_dv
  rxErReg := io.rgmii.rx_er

  switch(state) {
    is(RGMIIEthernetRXState.IDLE) {
      dataValidReg := false.B
      preambleCount := 0.U
      byteCount := 0.U
      
      when(rxDvReg && clockPhase) {
        when(dataAssembled === 0x55.U) {
          state := RGMIIEthernetRXState.PREAMBLE
          preambleCount := 1.U
        }
      }
    }

    is( RGMIIEthernetRXState.PREAMBLE) {
      when(!rxDvReg) {
        state := RGMIIEthernetRXState.IDLE
      }.elsewhen(clockPhase) {
        when(dataAssembled === 0xD5.U) {
          // Start of Frame Delimiter
          state := RGMIIEthernetRXState.DATA
          byteCount := 0.U
          crcByteCount := 0.U
        }.elsewhen(dataAssembled =/= 0x55.U) {
          state := RGMIIEthernetRXState.IDLE // Invalid preamble
        }.otherwise {
          preambleCount := preambleCount + 1.U
          when(preambleCount > 8.U) {
            state := RGMIIEthernetRXState.IDLE // Too long preamble
          }
        }
      }
    }

    is( RGMIIEthernetRXState.DATA) {
      when(!rxDvReg) {
        // End of frame
        dataLastReg := true.B
        dataValidReg := false.B
        
        // Check CRC
        val crcValid = crcModule.io.crc === receivedCrc
        dataErrorReg := !crcValid || rxErReg
        
        state := RGMIIEthernetRXState.IDLE
      }.elsewhen(clockPhase) {
        dataBuffer := dataAssembled
        dataValidReg := true.B
        dataLastReg := false.B
        dataErrorReg := rxErReg
        byteCount := byteCount + 1.U
        
        // Capture last 4 bytes as CRC
        when(crcByteCount < 4.U) {
          receivedCrc := Cat(dataAssembled, receivedCrc(31, 8))
          crcByteCount := crcByteCount + 1.U
        }
      }.otherwise {
        when(io.frame.ready) {
          dataValidReg := false.B
        }
      }
    }
  }
}
