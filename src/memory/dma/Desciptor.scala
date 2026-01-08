package mem.dma

import chisel3._

class DMADescriptorIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val srcAddr   = UInt(addrWidth.W)
  val dstAddr   = UInt(addrWidth.W)
  val length    = UInt(addrWidth.W)
  val burstSize = UInt(8.W)
  val priority  = UInt(3.W)
  val enable    = Bool()
  val interrupt = Bool()
}
