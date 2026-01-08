package net.ipv4

import chisel3._

object IPv4Protocol extends ChiselEnum {
  val ICMP = Value(1.U)
  val TCP  = Value(6.U)
  val UDP  = Value(17.U)
}

class IPv4Header extends Bundle {
  val version        = UInt(4.W)  // Always 4
  val ihl            = UInt(4.W)  // Header length in 32-bit words (min 5)
  val dscp           = UInt(6.W)  // Differentiated Services Code Point
  val ecn            = UInt(2.W)  // Explicit Congestion Notification
  val totalLength    = UInt(16.W) // Total packet length including header
  val identification = UInt(16.W) // Fragment identification
  val flags          = UInt(3.W)  // DF, MF flags
  val fragmentOffset = UInt(13.W) // Fragment offset
  val ttl            = UInt(8.W)  // Time to live
  val protocol       = UInt(8.W)  // Upper layer protocol
  val headerChecksum = UInt(16.W) // Header checksum
  val srcIP          = UInt(32.W) // Source IP address
  val dstIP          = UInt(32.W) // Destination IP address
}

class IPv4RxOutput extends Bundle {
  val header        = new IPv4Header
  val payloadLength = UInt(16.W)
  val checksumValid = Bool()
}

class IPv4TxInput extends Bundle {
  val dstIP          = UInt(32.W)
  val protocol       = UInt(8.W)
  val payloadLength  = UInt(16.W)
  val identification = UInt(16.W)
  val ttl            = UInt(8.W)
  val dscp           = UInt(6.W)
}
