package vopts.mem.cache

import chisel3._

class CacheEntry(tagWidth: Int) extends Bundle {
  val tag   = UInt(tagWidth.W)
  val alloc = Bool()
  val dirty = Bool()
}

class CacheIO(addrWidth: Int, dataWidth: Int, wordsPerLine: Int) extends Bundle {
  val upper = Flipped(new UnifiedMemoryIO(addrWidth, dataWidth, 1, wordsPerLine))
  val lower = new UnifiedMemoryIO(addrWidth, dataWidth, wordsPerLine, wordsPerLine)
  val miss  = Output(Bool())
}

class CacheExternalIO(addrWidth: Int, dataWidth: Int, wordsPerLine: Int) extends Bundle {
  // Upper (CPU) side request
  val UADDR  = Input(UInt(addrWidth.W))
  val UDATA  = Input(UInt(dataWidth.W))
  val UOP    = Input(MemoryOp())
  val UVALID = Input(Bool())
  val UREADY = Output(Bool())

  // Upper (CPU) side response
  val URDATA  = Output(UInt(dataWidth.W))
  val URVALID = Output(Bool())
  val URREADY = Input(Bool())

  // Lower (Memory) side request
  val LADDR  = Output(UInt(addrWidth.W))
  val LDATA  = Output(UInt((dataWidth * wordsPerLine).W))
  val LOP    = Output(MemoryOp())
  val LVALID = Output(Bool())
  val LREADY = Input(Bool())

  // Lower (Memory) side response
  val LRDATA  = Input(UInt((dataWidth * wordsPerLine).W))
  val LRVALID = Input(Bool())
  val LRREADY = Output(Bool())

  // CSRs
  val MISS = Output(Bool())

  def connect(intf: CacheIO): Unit = {
    // Upper side request
    intf.upper.req.bits.addr := this.UADDR
    intf.upper.req.bits.data := this.UDATA
    intf.upper.req.bits.op   := this.UOP
    intf.upper.req.valid     := this.UVALID
    this.UREADY              := intf.upper.req.ready

    // Upper side response
    this.URDATA           := intf.upper.resp.bits.data
    this.URVALID          := intf.upper.resp.valid
    intf.upper.resp.ready := this.URREADY

    // Lower side request
    this.LADDR           := intf.lower.req.bits.addr
    this.LDATA           := intf.lower.req.bits.data
    this.LOP             := intf.lower.req.bits.op
    this.LVALID          := intf.lower.req.valid
    intf.lower.req.ready := this.LREADY

    // Lower side response
    intf.lower.resp.bits.data := this.LRDATA
    intf.lower.resp.valid     := this.LRVALID
    this.LRREADY              := intf.lower.resp.ready

    // Control signals
    this.MISS := intf.miss
  }
}
