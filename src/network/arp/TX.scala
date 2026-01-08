package vopts.net.arp

import vopts.net.eth._
import chisel3._
import chisel3.util._

object ARPTxState extends ChiselEnum {
  val IDLE = Value(0.U(1.W))
  val SEND = Value(1.U(1.W))
}

class ARPTx extends Module {
  override def desiredName: String = "arp_tx"

  val io = IO(new Bundle {
    val config = Input(new Bundle {
      val myMAC = UInt(48.W)
      val myIP  = UInt(32.W)
    })

    val arpTx = Flipped(Decoupled(new ARPTxFrameIO))
    val ethTx = Decoupled(new EthernetFrameIO)
  })

  val state   = RegInit(ARPTxState.IDLE)
  val counter = RegInit(0.U(6.W))

  val operation = RegInit(0.U(16.W))
  val targetIP  = RegInit(0.U(32.W))
  val targetMAC = RegInit(0.U(48.W))

  // Build frame data
  val frameData = Wire(Vec(42, UInt(8.W)))

  val destMAC = Mux(operation === ARPOp.REPLY, targetMAC, "hFFFFFFFFFFFF".U)
  val tgtMAC  = Mux(operation === ARPOp.REPLY, targetMAC, 0.U)

  // Ethernet header
  frameData(0)  := destMAC(47, 40)
  frameData(1)  := destMAC(39, 32)
  frameData(2)  := destMAC(31, 24)
  frameData(3)  := destMAC(23, 16)
  frameData(4)  := destMAC(15, 8)
  frameData(5)  := destMAC(7, 0)
  frameData(6)  := io.config.myMAC(47, 40)
  frameData(7)  := io.config.myMAC(39, 32)
  frameData(8)  := io.config.myMAC(31, 24)
  frameData(9)  := io.config.myMAC(23, 16)
  frameData(10) := io.config.myMAC(15, 8)
  frameData(11) := io.config.myMAC(7, 0)
  frameData(12) := 0x08.U
  frameData(13) := 0x06.U

  // ARP header
  frameData(14) := 0x00.U
  frameData(15) := 0x01.U
  frameData(16) := 0x08.U
  frameData(17) := 0x00.U
  frameData(18) := 0x06.U
  frameData(19) := 0x04.U
  frameData(20) := operation(15, 8)
  frameData(21) := operation(7, 0)

  // Sender MAC
  frameData(22) := io.config.myMAC(47, 40)
  frameData(23) := io.config.myMAC(39, 32)
  frameData(24) := io.config.myMAC(31, 24)
  frameData(25) := io.config.myMAC(23, 16)
  frameData(26) := io.config.myMAC(15, 8)
  frameData(27) := io.config.myMAC(7, 0)

  // Sender IP
  frameData(28) := io.config.myIP(31, 24)
  frameData(29) := io.config.myIP(23, 16)
  frameData(30) := io.config.myIP(15, 8)
  frameData(31) := io.config.myIP(7, 0)

  // Target MAC
  frameData(32) := tgtMAC(47, 40)
  frameData(33) := tgtMAC(39, 32)
  frameData(34) := tgtMAC(31, 24)
  frameData(35) := tgtMAC(23, 16)
  frameData(36) := tgtMAC(15, 8)
  frameData(37) := tgtMAC(7, 0)

  // Target IP
  frameData(38) := targetIP(31, 24)
  frameData(39) := targetIP(23, 16)
  frameData(40) := targetIP(15, 8)
  frameData(41) := targetIP(7, 0)

  // Outputs
  io.arpTx.ready := state === ARPTxState.IDLE

  io.ethTx.valid      := state === ARPTxState.SEND
  io.ethTx.bits.data  := frameData(counter)
  io.ethTx.bits.last  := (counter === 41.U) && (state === ARPTxState.SEND)
  io.ethTx.bits.error := false.B

  // State machine
  switch(state) {
    is(ARPTxState.IDLE) {
      when(io.arpTx.fire) {
        operation := io.arpTx.bits.operation
        targetIP  := io.arpTx.bits.targetIP
        targetMAC := io.arpTx.bits.targetMAC
        counter   := 0.U
        state     := ARPTxState.SEND
      }
    }

    is(ARPTxState.SEND) {
      when(io.ethTx.fire) {
        when(counter < 41.U) {
          counter := counter + 1.U
        }.otherwise {
          // Last byte sent
          counter := 0.U
          state   := ARPTxState.IDLE
        }
      }
    }
  }
}
