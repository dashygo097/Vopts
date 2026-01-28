package vopts.mem.cache

import chisel3._
import chisel3.util._

object CacheOp extends ChiselEnum {
  val READ  = Value(0.U(1.W))
  val WRITE = Value(1.U(1.W))
}

// TODO: Multi request support
class CacheReq[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val op   = CacheOp()
  val addr = UInt(addrWidth.W)
  val data = gen
}

// TODO: Multi request support
class CacheReadOnlyReq(addrWidth: Int) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class CacheResp[T <: Data](gen: T) extends Bundle {
  val data = gen
  val hit  = Bool()
}

// TODO: Multi request support
class CacheIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val req  = Decoupled(new CacheReq(gen, addrWidth))
  val resp = Flipped(Decoupled(new CacheResp(gen)))
}

// TODO: Multi request support
class CacheReadOnlyIO[T <: Data](gen: T, addrWidth: Int) extends Bundle {
  val req  = Decoupled(new CacheReadOnlyReq(addrWidth))
  val resp = Flipped(Decoupled(new CacheResp(gen)))
}
