package vopts.mem.cache

import vopts.utils.CombTree
import chisel3._
import chisel3.util._

class LRUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val ageWidth = log2Ceil(numLines + 1)
  val age      = RegInit(VecInit(Seq.tabulate(numLines)(i => i.U(ageWidth.W))))

  override def getVictim(): UInt = {
    val indexBits         = log2Ceil(numLines)
    val tagged: Seq[UInt] = (0 until numLines).map { i =>
      Cat(age(i), i.U(indexBits.W))
    }
    val maxTagged         = CombTree.treeReduce(tagged) { (a, b) =>
      Mux(
        a(indexBits + ageWidth - 1, indexBits) >
          b(indexBits + ageWidth - 1, indexBits),
        a,
        b
      )
    }
    maxTagged(indexBits - 1, 0)
  }

  override def update(accessedIndex: UInt, isHit: Bool): Unit = {
    val currentAge = age(accessedIndex)
    for (i <- 0 until numLines)
      when(i.U === accessedIndex) {
        age(i) := 0.U
      }.elsewhen(age(i) < currentAge) {
        age(i) := age(i) + 1.U
      }
  }

  override def reset(): Unit =
    age := VecInit(Seq.tabulate(numLines)(i => i.U(ageWidth.W)))
}
