package mem.cache

import chisel3._
import chisel3.util._

object MemoryOp extends ChiselEnum {
  val READ  = Value(0.U(1.W))
  val WRITE = Value(1.U(1.W))
}

class MemoryHierarchyReq(addrWidth: Int, dataWidth: Int, wordsPerRequest: Int) extends Bundle {
  val op   = MemoryOp()
  val addr = UInt(addrWidth.W)
  val data = UInt((dataWidth * wordsPerRequest).W)
}

class MemoryHierarchyResp(dataWidth: Int, wordsPerRespond: Int) extends Bundle {
  val data = UInt((dataWidth * wordsPerRespond).W)
}

class UnifiedMemoryIO(addrWidth: Int, dataWidth: Int, wordsPerRequest: Int, wordsPerRespond: Int) extends Bundle {
  val req  = Decoupled(new MemoryHierarchyReq(addrWidth, dataWidth, wordsPerRequest))
  val resp = Flipped(Decoupled(new MemoryHierarchyResp(dataWidth, wordsPerRespond)))
}
