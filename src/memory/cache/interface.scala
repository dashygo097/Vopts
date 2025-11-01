package mem.cache

import chisel3._

class CacheEntry(dataWidth: Int, tagWidth: Int) extends Bundle {
  val tag   = UInt(tagWidth.W)
  val valid = Bool()
  val data  = UInt(dataWidth.W)
}

class CacheIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr       = Input(UInt(addrWidth.W))
  val write_data = Input(UInt(dataWidth.W))
  val write_en   = Input(Bool())
  val read_data  = Output(UInt(dataWidth.W))
  val read_en    = Input(Bool())
  val miss       = Output(Bool())
}

class CacheExternalIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val ADDR       = Input(UInt(addrWidth.W))
  val WRITE_DATA = Input(UInt(dataWidth.W))
  val WRITE_EN   = Input(Bool())
  val READ_DATA  = Output(UInt(dataWidth.W))
  val READ_EN    = Input(Bool())
  val MISS       = Output(Bool())

  def connect(intf: CacheIO): Unit = {
    intf.addr       := ADDR
    intf.write_data := WRITE_DATA
    intf.write_en   := WRITE_EN
    READ_DATA       := intf.read_data
    intf.read_en    := READ_EN
    MISS            := intf.miss
  }
}
