package mem.cache

import chisel3._

object CacheFSMState extends ChiselEnum {
  val IDLE = Value(0.U(3.W))
  val COMPARE_TAG = Value(1.U(3.W))
  val ALLOCATE = Value(2.U(3.W))
  val WRITEBACK = Value(3.U(3.W))
  val FLUSH = Value(4.U(3.W))
}

