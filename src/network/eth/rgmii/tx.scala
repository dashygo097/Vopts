package net.eth

import chisel3._
import chisel3.util._

object RGMIIEthernetTxState extends ChiselEnum {
  val IDLE     = Value(0.U(3.W))
  val PREAMBLE = Value(1.U(3.W))
  val DATA     = Value(2.U(3.W))
  val CRC      = Value(3.U(3.W))
  val IFG      = Value(4.U(3.W))
}

class RGMIIEthernetTx extends Module with EthernetFrameParams {
  override def desiredName: String = "eth_rgmii_tx"

  val io = IO(new Bundle {
    val rgmii   = new Bundle {
      val tx_clk = Output(Clock())
      val tx_en  = Output(Bool())
      val txd    = Output(UInt(4.W))
      val tx_er  = Output(Bool())
    }
    val frame   = Flipped(Decoupled(new EthernetFrameIO))
    val clk125m = Input(Clock())
  })

  // State machine
  val state = RegInit(RGMIIEthernetTxState.IDLE)

  // Counters
  val preambleCounter = RegInit(0.U(4.W))
  val ifgCounter      = RegInit(0.U(5.W))
  val crcByteIndex    = RegInit(0.U(2.W))

  // Nibble phase: false = lower nibble, true = upper nibble
  val nibblePhase = RegInit(false.B)

  // Data buffering
  val dataReg  = RegInit(0.U(8.W))
  val lastReg  = RegInit(false.B)
  val errorReg = RegInit(false.B)

  // CRC module
  val crcModule = Module(new CRC32)
  val crcReg    = RegInit(0.U(32.W))

  crcModule.io.reset := state === RGMIIEthernetTxState.IDLE
  crcModule.io.data  := io.frame.bits.data
  crcModule.io.valid := io.frame.fire && state === RGMIIEthernetTxState.DATA

  // Output registers
  val txEnReg = RegInit(false.B)
  val txdReg  = RegInit(0.U(4.W))
  val txErReg = RegInit(false.B)

  // Connect outputs
  io.rgmii.tx_clk := io.clk125m
  io.rgmii.tx_en  := txEnReg
  io.rgmii.txd    := txdReg
  io.rgmii.tx_er  := txErReg

  // Default ready signal
  io.frame.ready := false.B

  switch(state) {
    is(RGMIIEthernetTxState.IDLE) {
      txEnReg         := false.B
      txdReg          := 0.U
      txErReg         := false.B
      nibblePhase     := false.B
      preambleCounter := 0.U

      when(io.frame.valid) {
        state := RGMIIEthernetTxState.PREAMBLE
      }
    }

    is(RGMIIEthernetTxState.PREAMBLE) {
      txEnReg := true.B
      txErReg := false.B

      when(!nibblePhase) {
        when(preambleCounter < 7.U) {
          txdReg := 0x5.U // Preamble: 0x55
        }.otherwise {
          txdReg := 0x5.U // SFD lower: 0xD5
        }
        nibblePhase := true.B

      }.otherwise {
        when(preambleCounter < 7.U) {
          txdReg := 0x5.U // Preamble: 0x55
        }.otherwise {
          txdReg := 0xd.U // SFD upper: 0xD5
        }
        nibblePhase     := false.B
        preambleCounter := preambleCounter + 1.U

        when(preambleCounter === 7.U) {
          state := RGMIIEthernetTxState.DATA
          when(io.frame.valid) {
            dataReg        := io.frame.bits.data
            lastReg        := io.frame.bits.last
            errorReg       := io.frame.bits.error
            io.frame.ready := true.B
          }
        }
      }
    }

    is(RGMIIEthernetTxState.DATA) {
      txEnReg := true.B
      txErReg := errorReg

      when(!nibblePhase) {
        txdReg      := dataReg(3, 0)
        nibblePhase := true.B

      }.otherwise {
        txdReg      := dataReg(7, 4)
        nibblePhase := false.B

        when(lastReg) {
          state        := RGMIIEthernetTxState.CRC
          crcReg       := crcModule.io.crc
          crcByteIndex := 0.U
        }.otherwise {
          io.frame.ready := true.B
          when(io.frame.valid) {
            dataReg  := io.frame.bits.data
            lastReg  := io.frame.bits.last
            errorReg := io.frame.bits.error
          }
        }
      }
    }

    is(RGMIIEthernetTxState.CRC) {
      txEnReg := true.B
      txErReg := false.B

      val crcByte = MuxLookup(crcByteIndex, 0.U)(
        Seq(
          0.U -> crcReg(7, 0),
          1.U -> crcReg(15, 8),
          2.U -> crcReg(23, 16),
          3.U -> crcReg(31, 24)
        )
      )

      when(!nibblePhase) {
        txdReg      := crcByte(3, 0)
        nibblePhase := true.B

      }.otherwise {
        txdReg       := crcByte(7, 4)
        nibblePhase  := false.B
        crcByteIndex := crcByteIndex + 1.U

        when(crcByteIndex === 3.U) {
          state      := RGMIIEthernetTxState.IFG
          ifgCounter := 0.U
        }
      }
    }

    is(RGMIIEthernetTxState.IFG) {
      txEnReg := false.B
      txdReg  := 0.U
      txErReg := false.B

      ifgCounter := ifgCounter + 1.U
      when(ifgCounter === 23.U) {
        state := RGMIIEthernetTxState.IDLE
      }
    }
  }
}
