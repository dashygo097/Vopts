package vopts.utils

import chisel3._

trait PartialOrdered[T <: Data] {
  def lt(x: T, y: T): Bool
  def le(x: T, y: T): Bool
  def gt(x: T, y: T): Bool = lt(y, x)
  def ge(x: T, y: T): Bool = le(y, x)
  def eq(x: T, y: T): Bool = le(x, y) && le(y, x)
  def ne(x: T, y: T): Bool = !eq(x, y)
  def min(x: T, y: T): T
  def max(x: T, y: T): T
}

object PartialOrderedSyntax {
  implicit class PartialOrderedOps[T <: Data](val x: T) extends AnyVal {
    def <(y: T)(implicit cmp: PartialOrdered[T]): Bool   = cmp.lt(x, y)
    def <=(y: T)(implicit cmp: PartialOrdered[T]): Bool  = cmp.le(x, y)
    def >(y: T)(implicit cmp: PartialOrdered[T]): Bool   = cmp.gt(x, y)
    def >=(y: T)(implicit cmp: PartialOrdered[T]): Bool  = cmp.ge(x, y)
    def ===(y: T)(implicit cmp: PartialOrdered[T]): Bool = cmp.eq(x, y)
    def =/=(y: T)(implicit cmp: PartialOrdered[T]): Bool = cmp.ne(x, y)
    def min(y: T)(implicit cmp: PartialOrdered[T]): T    = cmp.min(x, y)
    def max(y: T)(implicit cmp: PartialOrdered[T]): T    = cmp.max(x, y)
  }
}
