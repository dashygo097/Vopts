package mem.cache

import chisel3._

class CacheEntry[T <: Data](gen: T, tagWidth: Int) extends Bundle {
  val tag = UInt(tagWidth.W)
  val valid = Bool()
  val data = gen
}

object CacheEntry {
  def apply[T <: Data](gen: T, tagWidth: Int): CacheEntry[T] = {
    val entry = Wire(new CacheEntry(gen, tagWidth))
    entry.valid := false.B
    entry.tag := 0.U
    entry.data := 0.U.asTypeOf(gen)
    entry
  }

  def apply[T <: Data](gen: T, tagWidth: Int, valid: Bool, tag: UInt, data: T): CacheEntry[T] = {
    val entry = Wire(new CacheEntry(gen, tagWidth))
    entry.valid := valid
    entry.tag := tag
    entry.data := data
    entry
  }
}

class CacheIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val addr = Input(UInt(addrWidth.W))
  val write_data = Input(gen)
  val write_en = Input(Bool())
  val read_data = Output(gen)
  val read_en = Input(Bool())
  val miss = Output(Bool())
}

class CacheExternalIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val ADDR = Input(UInt(addrWidth.W))
  val WRITE_DATA = Input(gen)
  val WRITE_EN = Input(Bool())
  val READ_DATA = Output(gen)
  val READ_EN = Input(Bool())
  val MISS = Output(Bool())

  def connect(intf: CacheIO[T]): Unit = {
    intf.addr := ADDR
    intf.write_data := WRITE_DATA
    intf.write_en := WRITE_EN
    READ_DATA := intf.read_data
    intf.read_en := READ_EN
    MISS := intf.miss
  }
}
