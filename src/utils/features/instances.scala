package utils

import chisel3._

object PartialOrderedInstances {
  implicit val uintPartialOrdered: PartialOrdered[UInt] = new PartialOrdered[UInt] {
    def lt(x: UInt, y: UInt): Bool = x < y
    def le(x: UInt, y: UInt): Bool = x <= y
  }

  implicit val sintPartialOrdered: PartialOrdered[SInt] = new PartialOrdered[SInt] {
    def lt(x: SInt, y: SInt): Bool = x < y
    def le(x: SInt, y: SInt): Bool = x <= y
  }

  implicit val fpPartialOrdered: PartialOrdered[FP] = new PartialOrdered[FP] {
    def lt(x: FP, y: FP): Bool = x < y
    def le(x: FP, y: FP): Bool = x <= y
  }
}

object ArithmeticInstances {
  implicit val uintArithmetic: Arithmetic[UInt] = new Arithmetic[UInt] {
    def add(x: UInt, y: UInt): UInt = x + y
    def sub(x: UInt, y: UInt): UInt = x - y
    def mul(x: UInt, y: UInt): UInt = x * y
    def div(x: UInt, y: UInt): UInt = x / y
    def zero(x: UInt): UInt = 0.U(x.getWidth.W)
    def fromInt(x: UInt, y: Int): UInt = {
      require(y >= 0, "Cannot convert negative int to UInt")
      y.U(x.getWidth.W)
    }
    def fromDouble(x: UInt, y: Double): UInt = {
      require(y >= 0, "Cannot convert negative double to UInt")
      require(y.isValidInt, "Double value is not a valid UInt")
      y.toInt.U(x.getWidth.W)
    }
  }

  implicit val sintArithmetic: Arithmetic[SInt] = new Arithmetic[SInt] {
    def add(x: SInt, y: SInt): SInt = x + y
    def sub(x: SInt, y: SInt): SInt = x - y
    def mul(x: SInt, y: SInt): SInt = x * y
    def mul(x: SInt, y: UInt): SInt = x * y.asSInt
    def div(x: SInt, y: SInt): SInt = x / y
    def div(x: SInt, y: UInt): SInt = x / y.asSInt
    def zero(x: SInt): SInt = 0.S(x.getWidth.W)
    def fromInt(x: SInt, y: Int): SInt = y.S(x.getWidth.W)
    def fromDouble(x: SInt, y: Double): SInt = {
      require(y.isValidInt, "Double value is not a valid SInt")
      y.toInt.S(x.getWidth.W)
    }
  }
  implicit val fpArithmetic: Arithmetic[FP] = new Arithmetic[FP] {
    def add(x: FP, y: FP): FP = x + y
    def sub(x: FP, y: FP): FP = x - y
    def mul(x: FP, y: FP): FP = x * y
    def mul(x: FP, y: UInt): FP = x * y
    def div(x: FP, y: FP): FP = x / y
    def div(x: FP, y: UInt): FP = x / y
    def zero(x: FP): FP = new FP(x.get_dw(), x.get_bp()).fromDouble(0.0)
    def fromInt(x: FP, y: Int): FP = new FP(x.get_dw(), x.get_bp()).fromDouble(y.toDouble)
    def fromDouble(x: FP, y: Double): FP = new FP(x.get_dw(), x.get_bp()).fromDouble(y)
  }
}
