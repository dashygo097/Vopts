package utils

import chisel3._

object AnalogInstances {
  implicit val fpAnalog: Analog[FP] = new Analog[FP] {
    def apply(idx: Int)(x: FP): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: FP): UInt = x(high, low)
    def add(x: FP, y: FP): FP                   = x + y
    def add(x: FP, y: UInt): FP                 = {
      val y_fp = new FP(x.dw(), x.bp())
      y_fp.value := y
      x + y_fp
    }
    def sub(x: FP, y: FP): FP                   = x - y
    def sub(x: FP, y: UInt): FP                 = {
      val y_fp = new FP(x.dw(), x.bp())
      y_fp.value := y
      x - y_fp
    }
    def mul(x: FP, y: FP): FP                   = x * y
    def mul(x: FP, y: UInt): FP                 = {
      val y_fp = new FP(x.dw(), x.bp())
      y_fp.value := y
      x * y_fp
    }
    def div(x: FP, y: FP): FP                   = {
      assert(y =/= new FP(x.dw(), x.bp()).fromDouble(0.0), "Division by zero in FP arithmetic")
      x / y
    }
    def div(x: FP, y: UInt): FP                 = {
      assert(y =/= 0.U, "Division by zero in FP arithmetic")
      val y_fp = new FP(x.dw(), x.bp())
      y_fp.value := y
      x / y_fp
    }
    def zero(x: FP): FP                         = new FP(x.dw(), x.bp()).fromInt(0)
    def fromInt(x: FP, y: Int): FP              = new FP(x.dw(), x.bp()).fromInt(y)
    def fromDouble(x: FP, y: Double): FP        = new FP(x.dw(), x.bp()).fromDouble(y)
  }

  implicit val floatAnalog: Analog[Float] = new Analog[Float] {
    def apply(idx: Int)(x: Float): Bool            = x(idx)
    def apply(high: Int, low: Int)(x: Float): UInt = x.value(high, low)
    def add(x: Float, y: Float): Float             = x + y
    def add(x: Float, y: UInt): Float              = {
      val y_float = new Float(x.expWidth(), x.sigWidth())
      y_float.value := y
      x + y_float
    }
    def sub(x: Float, y: Float): Float             = x - y
    def sub(x: Float, y: UInt): Float              = {
      val y_float = new Float(x.expWidth(), x.sigWidth())
      y_float.value := y
      x - y_float
    }
    def mul(x: Float, y: Float): Float             = x * y
    def mul(x: Float, y: UInt): Float              = {
      val y_float = new Float(x.expWidth(), x.sigWidth())
      y_float.value := y
      x * y_float
    }
    def div(x: Float, y: Float): Float             = {
      assert(y =/= new Float(x.expWidth(), x.sigWidth()).fromInt(0), "Division by zero in Float arithmetic")
      x / y
    }
    def div(x: Float, y: UInt): Float              = {
      val y_float = new Float(x.expWidth(), x.sigWidth())
      y_float.value := y
      x / y_float
    }
    def zero(x: Float): Float                      = new Float(x.expWidth(), x.sigWidth()).fromInt(0)
    def fromInt(x: Float, y: Int): Float           = new Float(x.expWidth(), x.sigWidth()).fromInt(y)
    def fromDouble(x: Float, y: Double): Float     = new Float(x.expWidth(), x.sigWidth()).fromDouble(y)
  }
}
