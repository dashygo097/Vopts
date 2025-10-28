package net.eth

import chisel3._
import chisel3.util._

object RGMIIEthernetRXState extends ChiselEnum {
  val IDLE     = Value(0.U(2.W))
  val PREAMBLE = Value(1.U(2.W))
  val DATA     = Value(2.U(2.W))
}

class RGMIIEthernetRX extends Module {
  override def desiredName: String = "eth_rgmii_rx"

  val io = IO(new Bundle {
    val rgmii = new Bundle {
      val rx_clk = Input(Clock())
      val rx_dv  = Input(Bool())
      val rxd    = Input(UInt(4.W))
      val rx_er  = Input(Bool())
    }
    val frame = Decoupled(new Bundle {
      val data  = UInt(8.W)
      val last  = Bool()
      val error = Bool()
    })
  })

  // State machine
  val state = RegInit(RGMIIEthernetRXState.IDLE)

  // Nibble assembly (false = waiting for lower, true = have lower, waiting for upper)
  val nibblePhase = RegInit(false.B)
  val lowerNibble = RegInit(0.U(4.W))

  // Assembled byte
  val assembledByte = Wire(UInt(8.W))
  assembledByte := Cat(io.rgmii.rxd, lowerNibble)

  // Output registers
  val dataValidReg = RegInit(false.B)
  val dataReg      = RegInit(0.U(8.W))
  val lastReg      = RegInit(false.B)
  val errorReg     = RegInit(false.B)

  io.frame.valid      := dataValidReg
  io.frame.bits.data  := dataReg
  io.frame.bits.last  := lastReg
  io.frame.bits.error := errorReg

  // Preamble detection
  val preambleCount = RegInit(0.U(4.W))

  // CRC validation (simplified - not checking CRC for now)
  val crcModule = Module(new CRC32)
  crcModule.io.data  := assembledByte
  crcModule.io.valid := state === RGMIIEthernetRXState.DATA && nibblePhase && io.rgmii.rx_dv
  crcModule.io.reset := state === RGMIIEthernetRXState.IDLE

  // Frame byte counter
  val byteCount = RegInit(0.U(16.W))

  // Default: clear valid when data is accepted
  when(io.frame.fire) {
    dataValidReg := false.B
  }

  switch(state) {
    is(RGMIIEthernetRXState.IDLE) {
      nibblePhase   := false.B
      preambleCount := 0.U
      lastReg       := false.B
      byteCount     := 0.U

      when(io.rgmii.rx_dv && io.rgmii.rxd === 0x5.U) {
        state       := RGMIIEthernetRXState.PREAMBLE
        lowerNibble := io.rgmii.rxd
        nibblePhase := true.B
      }
    }

    is(RGMIIEthernetRXState.PREAMBLE) {
      when(!io.rgmii.rx_dv) {
        state := RGMIIEthernetRXState.IDLE

      }.elsewhen(!nibblePhase) {
        lowerNibble := io.rgmii.rxd
        nibblePhase := true.B

      }.otherwise {
        when(assembledByte === 0x55.U) {
          nibblePhase   := false.B
          preambleCount := preambleCount + 1.U

          when(preambleCount > 8.U) {
            state := RGMIIEthernetRXState.IDLE
          }

        }.elsewhen(assembledByte === 0xd5.U && preambleCount >= 6.U) {
          state       := RGMIIEthernetRXState.DATA
          nibblePhase := false.B
          byteCount   := 0.U

        }.otherwise {
          state := RGMIIEthernetRXState.IDLE
        }
      }
    }

    is(RGMIIEthernetRXState.DATA) {
      when(!io.rgmii.rx_dv) {
        when(byteCount > 0.U) {
          when(!dataValidReg) {
            dataValidReg := true.B
            dataReg      := assembledByte
            lastReg      := true.B
            errorReg     := io.rgmii.rx_er
          }
        }
        state := RGMIIEthernetRXState.IDLE

      }.elsewhen(!nibblePhase) {
        lowerNibble := io.rgmii.rxd
        nibblePhase := true.B

      }.otherwise {
        when(!dataValidReg) {
          dataReg      := assembledByte
          dataValidReg := true.B
          lastReg      := false.B
          errorReg     := io.rgmii.rx_er
          byteCount    := byteCount + 1.U
        }
        nibblePhase := false.B
      }
    }
  }
}
