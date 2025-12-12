package mem.cache

import chisel3._
import chisel3.util._

class LRUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val age = RegInit(VecInit(Seq.fill(numLines)(0.U(log2Ceil(numLines).W))))

  override def getVictim(): UInt =
    PriorityEncoder(age.map(_ === (numLines - 1).U))

  override def update(accessedIndex: UInt, isHit: Bool): Unit =
    for (i <- 0 until numLines)
      when(i.U === accessedIndex) {
        age(i) := 0.U
      }.elsewhen(age(i) < (numLines - 1).U) {
        age(i) := age(i) + 1.U
      }

  override def reset(): Unit =
    age := VecInit(Seq.fill(numLines)(0.U(log2Ceil(numLines).W)))
}
