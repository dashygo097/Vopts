package utils

import chisel3._

object AnalogInstances {
  implicit val fpArithmetic: Arithmetic[FP] = new Arithmetic[FP] {
    def apply(idx: Int)(x: FP): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: FP): UInt = x(high, low)
    def add(x: FP, y: FP): FP                   = x + y
    def sub(x: FP, y: FP): FP                   = x - y
    def mul(x: FP, y: FP): FP                   = x * y
    def mul(x: FP, y: UInt): FP                 = x * y
    def div(x: FP, y: FP): FP                   = {
      assert(y =/= new FP(x.dw(), x.bp()).fromDouble(0.0), "Division by zero in FP arithmetic")
      x / y
    }
    def div(x: FP, y: UInt): FP                 = {
      assert(y =/= 0.U, "Division by zero in FP arithmetic")
      x / y
    }
    def zero(x: FP): FP                         = new FP(x.dw(), x.bp()).fromDouble(0.0)
    def fromInt(x: FP, y: Int): FP              = new FP(x.dw(), x.bp()).fromDouble(y.toDouble)
    def fromDouble(x: FP, y: Double): FP        = new FP(x.dw(), x.bp()).fromDouble(y)
    def mapUInt(x: FP, y: UInt): FP             = new FP(x.dw(), x.bp()).mapSInt(y.asSInt)
    def mapSInt(x: FP, y: SInt): FP             = new FP(x.dw(), x.bp()).mapSInt(y)
  }
}
