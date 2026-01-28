package vopts.utils

import chisel3._

trait Arithmetic[T <: Data] {
  def apply(idx: Int)(x: T): Bool
  def apply(high: Int, low: Int)(x: T): UInt
  def add(x: T, y: T): T
  def add(x: T, y: UInt): T
  def sub(x: T, y: T): T
  def sub(x: T, y: UInt): T
  def mul(x: T, y: T): T
  def mul(x: T, y: UInt): T
  def div(x: T, y: T): T
  def div(x: T, y: UInt): T
  def zero(x: T): T
  def fromInt(x: T, y: Int): T
  def fromDouble(x: T, y: Double): T
}

object ArithmeticSyntax {
  implicit class ArithmeticOps[T <: Data](val x: T) extends AnyVal {
    def apply(idx: Int)(implicit arith: Arithmetic[T]): Bool            = arith.apply(idx)(x)
    def apply(high: Int, low: Int)(implicit arith: Arithmetic[T]): UInt = arith.apply(high, low)(x)
    def +(y: T)(implicit arith: Arithmetic[T]): T                       = arith.add(x, y)
    def +(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.add(x, y)
    def -(y: T)(implicit arith: Arithmetic[T]): T                       = arith.sub(x, y)
    def -(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.sub(x, y)
    def *(y: T)(implicit arith: Arithmetic[T]): T                       = arith.mul(x, y)
    def *(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.mul(x, y)
    def /(y: T)(implicit arith: Arithmetic[T]): T                       = arith.div(x, y)
    def /(y: UInt)(implicit arith: Arithmetic[T]): T                    = arith.div(x, y)
    def zero(implicit arith: Arithmetic[T]): T                        = arith.zero(x)
    def fromInt(value: Int)(implicit arith: Arithmetic[T]): T           = arith.fromInt(x, value)
    def fromDouble(value: Double)(implicit arith: Arithmetic[T]): T     = arith.fromDouble(x, value)
  }
}
