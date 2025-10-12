package utils

import chisel3._

object ArithmeticInstances {
  implicit val uintArithmetic: Arithmetic[UInt] = new Arithmetic[UInt] {
    def apply(idx: Int)(x: UInt): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: UInt): UInt = x(high, low)
    def add(x: UInt, y: UInt): UInt               = x + y
    def sub(x: UInt, y: UInt): UInt               = x - y
    def mul(x: UInt, y: UInt): UInt               = x * y
    def div(x: UInt, y: UInt): UInt               = {
      assert(y =/= 0.U, "Division by zero in UInt arithmetic")
      x / y
    }
    def zero(x: UInt): UInt                       = 0.U(x.getWidth.W)
    def fromInt(x: UInt, y: Int): UInt            = {
      require(y >= 0, "Cannot convert negative int to UInt")
      y.U(x.getWidth.W)
    }
    def fromDouble(x: UInt, y: Double): UInt      = {
      require(y >= 0, "Cannot convert negative double to UInt")
      require(y.isValidInt, "Double value is not a valid UInt")
      y.toInt.U(x.getWidth.W)
    }
    def mapUInt(x: UInt, y: UInt): UInt           = y
    def mapSInt(x: UInt, y: SInt): UInt           = y.asUInt
  }

  implicit val sintArithmetic: Arithmetic[SInt] = new Arithmetic[SInt] {
    def apply(idx: Int)(x: SInt): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: SInt): UInt = x(high, low)
    def add(x: SInt, y: SInt): SInt               = x + y
    def sub(x: SInt, y: SInt): SInt               = x - y
    def mul(x: SInt, y: SInt): SInt               = x * y
    def mul(x: SInt, y: UInt): SInt               = x * y.asSInt
    def div(x: SInt, y: SInt): SInt               = {
      assert(y =/= 0.S, "Division by zero in SInt arithmetic")
      x / y
    }
    def div(x: SInt, y: UInt): SInt               = {
      assert(y =/= 0.U, "Division by zero in SInt arithmetic")
      x / y.asSInt
    }
    def zero(x: SInt): SInt                       = 0.S(x.getWidth.W)
    def fromInt(x: SInt, y: Int): SInt            = y.S(x.getWidth.W)
    def fromDouble(x: SInt, y: Double): SInt      = {
      require(y.isValidInt, "Double value is not a valid SInt")
      y.toInt.S(x.getWidth.W)
    }
    def mapUInt(x: SInt, y: UInt): SInt           = y.asSInt
    def mapSInt(x: SInt, y: SInt): SInt           = y
  }
  implicit val fpArithmetic: Arithmetic[FP]     = new Arithmetic[FP] {
    def apply(idx: Int)(x: FP): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: FP): UInt = x.value(high, low)
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
