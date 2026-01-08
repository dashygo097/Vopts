package mem.cache

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

class RandomState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val lfsrWidth = math.max(log2Ceil(numLines), 4)
  val lfsr      = LFSR(lfsrWidth)

  override def getVictim(): UInt =
    lfsr(log2Ceil(numLines) - 1, 0)

  override def update(accessedIndex: UInt, isHit: Bool): Unit = {}

  override def reset(): Unit = {}
}
