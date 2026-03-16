package vopts.utils

import chisel3._

trait Analog[T <: Data] extends Arithmetic[T]

object AnalogSyntax {
  implicit class AnalogOps[T <: Data](val x: T) extends AnyVal {
    def apply(idx: Int)(implicit arith: Analog[T]): Bool                = arith.apply(idx)(x)
    def apply(high: Int, low: Int)(implicit arith: Arithmetic[T]): UInt = arith.apply(high, low)(x)
    def +(y: T)(implicit arith: Arithmetic[T]): T                       = arith.add(x, y)
    def -(y: T)(implicit arith: Arithmetic[T]): T                       = arith.sub(x, y)
    def *(y: T)(implicit arith: Arithmetic[T]): T                       = arith.mul(x, y)
    def *(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.mul(x, y)
    def /(y: T)(implicit arith: Arithmetic[T]): T                       = arith.div(x, y)
    def /(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.div(x, y)
    def zero(implicit arith: Arithmetic[T]): T                          = arith.zero(x)
    def fromInt(value: Int)(implicit arith: Arithmetic[T]): T           = arith.fromInt(x, value)
    def fromDouble(value: Double)(implicit arith: Arithmetic[T]): T     = arith.fromDouble(x, value)
  }
}
