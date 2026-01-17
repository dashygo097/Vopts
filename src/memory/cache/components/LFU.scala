package vopts.mem.cache

import chisel3._
import chisel3.util._

class LFUState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val usageCount = RegInit(VecInit(Seq.fill(numLines)(0.U(8.W))))

  override def getVictim(): UInt =
    PriorityEncoder(usageCount.map(_ === usageCount.map(_.asUInt).reduce((a, b) => Mux(a < b, a, b))))

  override def update(accessedIndex: UInt, isHit: Bool): Unit =
    when(isHit) {
      usageCount(accessedIndex) := usageCount(accessedIndex) + 1.U
    }.otherwise {
      usageCount(accessedIndex) := 1.U
    }
  override def reset(): Unit                                  =
    usageCount := VecInit(Seq.fill(numLines)(0.U(8.W)))
}
