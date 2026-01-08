package net.arp

import chisel3._

trait EtherType {
  val ARP  = 0x0806.U(16.W)
  val IPv4 = 0x0800.U(16.W)
}

object ARPOp {
  val REQUEST = 1.U(16.W)
  val REPLY   = 2.U(16.W)
}

class ARPPacket extends Bundle {
  val hwType       = UInt(16.W)
  val protoType    = UInt(16.W)
  val hwAddrLen    = UInt(8.W)
  val protoAddrLen = UInt(8.W)
  val operation    = UInt(16.W)
  val senderMAC    = UInt(48.W)
  val senderIP     = UInt(32.W)
  val targetMAC    = UInt(48.W)
  val targetIP     = UInt(32.W)
}

class ARPTxFrameIO extends Bundle {
  val operation = UInt(16.W)
  val targetIP  = UInt(32.W)
  val targetMAC = UInt(48.W)
}

class ARPRxFrameIO extends Bundle {
  val operation = UInt(16.W)
  val senderMAC = UInt(48.W)
  val senderIP  = UInt(32.W)
  val targetIP  = UInt(32.W)
}
