package vopts.utils

import chisel3._

object CombTree {
  def treeReduce[T](items: Seq[T])(op: (T, T) => T): T         =
    items.length match {
      case 0 => throw new IllegalArgumentException("treeReduce on empty Seq")
      case 1 => items.head
      case _ =>
        val mid = items.length / 2
        op(treeReduce(items.take(mid))(op), treeReduce(items.drop(mid))(op))
    }
  def oneHotMux(cases: Seq[(Bool, UInt)], default: UInt): UInt = {
    require(cases.nonEmpty, "oneHotMux requires at least one case")
    val w                 = default.getWidth
    val masked: Seq[UInt] = cases.map { case (cond, v) =>
      Mux(cond, v, 0.U(w.W))
    }
    treeReduce(masked)(_ | _) | Mux(
      cases.map(_._1).reduce(_ || _),
      0.U(w.W),
      default
    )
  }

  def oneHotMux(cases: Seq[(Bool, UInt)]): UInt = {
    require(cases.nonEmpty)
    val w      = cases.head._2.getWidth
    val masked = cases.map { case (cond, v) => Mux(cond, v, 0.U(w.W)) }
    treeReduce(masked)(_ | _)
  }

  def orTree(bits: Seq[Bool]): Bool  = treeReduce(bits)(_ || _)
  def andTree(bits: Seq[Bool]): Bool = treeReduce(bits)(_ && _)
  def xorTree(bits: Seq[Bool]): Bool = treeReduce(bits)(_ ^ _)
}
