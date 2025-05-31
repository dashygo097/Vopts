package utils

import chisel3._

trait Arithmetic[T <: Data] {
  def add(x: T, y: T): T
  def sub(x: T, y: T): T
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
    def +(y: T)(implicit arith: Arithmetic[T]): T = arith.add(x, y)
    def -(y: T)(implicit arith: Arithmetic[T]): T = arith.sub(x, y)
    def *(y: T)(implicit arith: Arithmetic[T]): T = arith.mul(x, y)
    def *(y: UInt)(implicit arith: Arithmetic[T]): T = arith.mul(x, y)
    def /(y: T)(implicit arith: Arithmetic[T]): T = arith.div(x, y)
    def /(y: UInt)(implicit arith: Arithmetic[T]): T = arith.div(x, y)
    def zero()(implicit arith: Arithmetic[T]): T = arith.zero(x)
    def fromInt(value: Int)(implicit arith: Arithmetic[T]): T = arith.fromInt(x, value)
    def fromDouble(value: Double)(implicit arith: Arithmetic[T]): T = arith.fromDouble(x, value)
  }
}

