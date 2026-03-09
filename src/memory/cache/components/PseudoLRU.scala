package vopts.mem.cache

import vopts.utils._
import chisel3._
import chisel3.util._

class PseudoLRUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  private val counterWidth = log2Ceil(numLines + 1) max 8
  private val counter      = RegInit(0.U(counterWidth.W))
  private val lastUsed     = RegInit(VecInit(Seq.fill(numLines)(0.U(counterWidth.W))))

  override def getVictim(): UInt = {
    val minVal = CombTree.treeReduce(lastUsed.toSeq)((a, b) => Mux(a < b, a, b))
    PriorityEncoder(lastUsed.map(_ === minVal))
  }

  override def update(accessedIndex: UInt, isHit: Bool): Unit = {
    lastUsed(accessedIndex) := counter
    counter                 := counter + 1.U
  }

  override def reset(): Unit = {
    counter  := 0.U
    lastUsed := VecInit(Seq.fill(numLines)(0.U(counterWidth.W)))
  }
}
