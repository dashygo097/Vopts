package net.eth

import chisel3._
import chisel3.util._

trait EthernetFrameParams {
  val PREAMBLE        = 0x55555555555555d5L
  val MIN_FRAME_SIZE  = 64
  val MAX_FRAME_SIZE  = 1518
  val MAC_ADDR_BYTES  = 6
  val ETHERTYPE_BYTES = 2
  val CRC_BYTES       = 4
}

class EthernetFrameIO extends Bundle {
  val tdata  = UInt(8.W)
  val tvalid = Bool()
  val tready = Bool()
  val tlast  = Bool()
  val tuser  = Bool() // Error indicator
}

class EthernetTxFrameIO extends Bundle {
  val frame = Flipped(Decoupled(new EthernetFrameIO))
}

class EthernetRxFrameIO extends Bundle {
  val frame = Decoupled(new EthernetFrameIO)
}
