package utils

import chisel3._

trait Arithmetic[T <: Data] {
  def apply(idx: Int)(x: T): Bool
  def apply(high: Int, low: Int)(x: T): UInt
  def add(x: T, y: T): T
  def sub(x: T, y: T): T
  def mul(x: T, y: T): T
  def mul(x: T, y: UInt): T
  def div(x: T, y: T): T
  def div(x: T, y: UInt): T
  def zero(x: T): T
  // NOTE: `from*` method converts the TYPE
  def fromInt(x: T, y: Int): T
  def fromDouble(x: T, y: Double): T
  // NOTE: `map*` method converts the VALUE as well as the TYPE
  def mapUInt(x: T, y: UInt): T
  def mapSInt(x: T, y: SInt): T
}

object ArithmeticSyntax {
  implicit class ArithmeticOps[T <: Data](val x: T) extends AnyVal {
    def apply(idx: Int)(implicit arith: Arithmetic[T]): Bool            = arith.apply(idx)(x)
    def apply(high: Int, low: Int)(implicit arith: Arithmetic[T]): UInt = arith.apply(high, low)(x)
    def +(y: T)(implicit arith: Arithmetic[T]): T                       = arith.add(x, y)
    def -(y: T)(implicit arith: Arithmetic[T]): T                       = arith.sub(x, y)
    def *(y: T)(implicit arith: Arithmetic[T]): T                       = arith.mul(x, y)
    def *(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.mul(x, y)
    def /(y: T)(implicit arith: Arithmetic[T]): T                       = arith.div(x, y)
    def /(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.div(x, y)
    def zero()(implicit arith: Arithmetic[T]): T                        = arith.zero(x)
    def fromInt(value: Int)(implicit arith: Arithmetic[T]): T           = arith.fromInt(x, value)
    def fromDouble(value: Double)(implicit arith: Arithmetic[T]): T     = arith.fromDouble(x, value)
    def mapUInt(value: UInt)(implicit arith: Arithmetic[T]): T          = arith.mapUInt(x, value)
    def mapSInt(value: SInt)(implicit arith: Arithmetic[T]): T          = arith.mapSInt(x, value)
  }
}
