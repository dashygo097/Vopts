package utils

import chisel3._

object PartialOrderedInstances {
  implicit val uintPartialOrdered: PartialOrdered[UInt] = new PartialOrdered[UInt] {
    def lt(x: UInt, y: UInt): Bool  = x < y
    def le(x: UInt, y: UInt): Bool  = x <= y
    def min(x: UInt, y: UInt): UInt = Mux(x < y, x, y)
    def max(x: UInt, y: UInt): UInt = Mux(x > y, x, y)
  }

  implicit val sintPartialOrdered: PartialOrdered[SInt] = new PartialOrdered[SInt] {
    def lt(x: SInt, y: SInt): Bool  = x < y
    def le(x: SInt, y: SInt): Bool  = x <= y
    def min(x: SInt, y: SInt): SInt = Mux(x < y, x, y)
    def max(x: SInt, y: SInt): SInt = Mux(x > y, x, y)
  }

  implicit val fpPartialOrdered: PartialOrdered[FP] = new PartialOrdered[FP] {
    def lt(x: FP, y: FP): Bool = x < y
    def le(x: FP, y: FP): Bool = x <= y
    def min(x: FP, y: FP): FP  = Mux(x < y, x, y)
    def max(x: FP, y: FP): FP  = Mux(x > y, x, y)
  }
}

