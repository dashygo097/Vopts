package vopts.mem.cache

import chisel3._
import chisel3.util._

class LRUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val ageWidth = log2Ceil(numLines + 1)
  val age      = RegInit(VecInit(Seq.tabulate(numLines)(i => i.U(ageWidth.W))))

  override def getVictim(): UInt =
    PriorityEncoder(age.map(_ === age.reduce((a, b) => Mux(a > b, a, b))))

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
