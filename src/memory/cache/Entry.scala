package vopts.mem.cache

import chisel3._

class CacheEntry(tagWidth: Int) extends Bundle {
  val tag   = UInt(tagWidth.W)
  val alloc = Bool()
  val dirty = Bool()
}

class CacheReadOnlyEntry(tagWidth: Int) extends Bundle {
  val tag   = UInt(tagWidth.W)
  val alloc = Bool()
}
