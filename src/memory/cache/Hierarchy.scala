package vopts.mem.cache

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

class MemoryHierarchyReadReq(addrWidth: Int) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class MemoryHierarchyResp(dataWidth: Int, wordsPerRespond: Int) extends Bundle {
  val data = UInt((dataWidth * wordsPerRespond).W)
}

class UnifiedMemoryIO(addrWidth: Int, dataWidth: Int, wordsPerRequest: Int, wordsPerRespond: Int) extends Bundle {
  val req  = Decoupled(new MemoryHierarchyReq(addrWidth, dataWidth, wordsPerRequest))
  val resp = Flipped(Decoupled(new MemoryHierarchyResp(dataWidth, wordsPerRespond)))
}

class UnifiedMemoryReadIO(addrWidth: Int, dataWidth: Int, wordsPerRespond: Int) extends Bundle {
  val req  = Decoupled(new MemoryHierarchyReadReq(addrWidth))
  val resp = Flipped(Decoupled(new MemoryHierarchyResp(dataWidth, wordsPerRespond)))
}

object MemoryHierarchyReq {
  def apply(addrWidth: Int, dataWidth: Int, wordsPerRequest: Int) = new MemoryHierarchyReq(addrWidth, dataWidth, wordsPerRequest)
}

object MemoryHierarchyReadReq {
  def apply(addrWidth: Int) = new MemoryHierarchyReadReq(addrWidth)
}

object MemoryHierarchyResp {
  def apply(addrWidth: Int, wordsPerRespond: Int) = new MemoryHierarchyResp(addrWidth, wordsPerRespond)
}

object UnifiedMemoryIO {
  def apply(addrWidth: Int, dataWidth: Int, wordsPerRequest: Int, wordsPerRespond: Int) =
    new UnifiedMemoryIO(addrWidth, dataWidth, wordsPerRequest, wordsPerRespond)
}

object UnifiedMemoryReadIO {
  def apply(addrWidth: Int, dataWidth: Int, wordsPerRespond: Int) =
    new UnifiedMemoryReadIO(addrWidth, dataWidth, wordsPerRespond)
}
