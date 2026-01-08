package vopts.net.eth

import chisel3._

trait EthernetFrameParams {
  val PREAMBLE        = 0x55555555555555d5L
  val MIN_FRAME_SIZE  = 64
  val MAX_FRAME_SIZE  = 1518
  val MAC_ADDR_BYTES  = 6
  val ETHERTYPE_BYTES = 2
  val CRC_BYTES       = 4
}

class EthernetFrameIO extends Bundle {
  val data  = UInt(8.W)
  val last  = Bool()
  val error = Bool()
}
