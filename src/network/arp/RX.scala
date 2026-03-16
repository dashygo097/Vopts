package vopts.net.arp

import vopts.net.eth._
import chisel3._
import chisel3.util._

object ARPRxState extends ChiselEnum {
  val IDLE    = Value(0.U(1.W))
  val RECEIVE = Value(1.U(1.W))
}

class ARPRx extends Module {
  override def desiredName: String = "arp_rx"

  val io = IO(new Bundle {
    val config = Input(new Bundle {
      val myIP = UInt(32.W)
    })

    val ethRx = Flipped(Decoupled(new EthernetFrameIO))
    val arpRx = Decoupled(new ARPRxFrameIO)
  })

  val state   = RegInit(ARPRxState.IDLE)
  val counter = RegInit(0.U(6.W))

  // Receive buffer (42 bytes total: 14 ETH + 28 ARP)
  val rxBuffer = Reg(Vec(42, UInt(8.W)))

  // Parsed fields
  val operation = RegInit(0.U(16.W))
  val senderMAC = RegInit(0.U(48.W))
  val senderIP  = RegInit(0.U(32.W))
  val targetIP  = RegInit(0.U(32.W))
  val validPkt  = RegInit(false.B)

  io.ethRx.ready := state === ARPRxState.IDLE || state === ARPRxState.RECEIVE

  io.arpRx.valid          := validPkt
  io.arpRx.bits.operation := operation
  io.arpRx.bits.senderMAC := senderMAC
  io.arpRx.bits.senderIP  := senderIP
  io.arpRx.bits.targetIP  := targetIP

  when(io.arpRx.fire) {
    validPkt := false.B
  }

  switch(state) {
    is(ARPRxState.IDLE) {
      counter := 0.U
      when(io.ethRx.fire && !io.ethRx.bits.error) {
        rxBuffer(0) := io.ethRx.bits.data
        counter     := 1.U
        state       := ARPRxState.RECEIVE
      }
    }

    is(ARPRxState.RECEIVE) {
      when(io.ethRx.fire) {
        when(counter < 42.U) {
          rxBuffer(counter) := io.ethRx.bits.data
        }
        counter := counter + 1.U

        when(io.ethRx.bits.last || counter >= 41.U) {
          // Parse after receiving at least 42 bytes
          // Ethernet header is bytes 0-13
          // ARP starts at byte 14

          val etherType = Cat(rxBuffer(12), rxBuffer(13))
          val hwType    = Cat(rxBuffer(14), rxBuffer(15))
          val protoType = Cat(rxBuffer(16), rxBuffer(17))

          // Check: EtherType = 0x0806 (ARP), HwType = 1 (Ethernet), ProtoType = 0x0800 (IPv4)
          when(etherType === 0x0806.U && hwType === 1.U && protoType === 0x0800.U && counter >= 41.U) {
            // Operation at bytes 20-21
            operation := Cat(rxBuffer(20), rxBuffer(21))

            // Sender MAC at bytes 22-27
            senderMAC := Cat(rxBuffer(22), rxBuffer(23), rxBuffer(24), rxBuffer(25), rxBuffer(26), rxBuffer(27))

            // Sender IP at bytes 28-31
            senderIP := Cat(rxBuffer(28), rxBuffer(29), rxBuffer(30), rxBuffer(31))

            // Target IP at bytes 38-41
            targetIP := Cat(rxBuffer(38), rxBuffer(39), rxBuffer(40), rxBuffer(41))

            validPkt := true.B
          }

          state   := ARPRxState.IDLE
          counter := 0.U
        }
      }
    }
  }
}
