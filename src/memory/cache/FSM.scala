package vopts.mem.cache

import chisel3._

object CacheState extends ChiselEnum {
  val IDLE        = Value(0.U(2.W))
  val COMPARE_TAG = Value(1.U(2.W))
  val ALLOCATE    = Value(2.U(2.W))
  val WRITEBACK   = Value(3.U(2.W))
}

object CacheNonBlockingState extends ChiselEnum {
  val IDLE        = Value(0.U(2.W))
  val COMPARE_TAG = Value(1.U(2.W))
  val WAIT_WORD   = Value(2.U(2.W))
  val WAIT_MSHR   = Value(3.U(2.W))
}
