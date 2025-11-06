package mem.cache

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

sealed trait ReplacementPolicy {
  def desiredName: String
}

case object Random extends ReplacementPolicy {
  override def desiredName: String = "random"
}

object ReplacementPolicy {
  def fromString(name: String): Option[ReplacementPolicy] = name.toLowerCase match {
    case "random" | "rand" => Some(Random)
    case _                 => None
  }

  def available: Seq[ReplacementPolicy] = Seq(Random)
}

abstract class ReplacementPolicyState(val numLines: Int) {
  def getVictim(): UInt
  def update(accessedIndex: UInt, isHit: Bool): Unit
  def reset(): Unit
}

class RandomState(numLines: Int) extends ReplacementPolicyState(numLines) {
  val lfsrWidth = math.max(log2Ceil(numLines), 4)
  val lfsr      = LFSR(lfsrWidth)

  override def getVictim(): UInt =
    lfsr(log2Ceil(numLines) - 1, 0)

  override def update(accessedIndex: UInt, isHit: Bool): Unit = {}

  override def reset(): Unit = {}
}

object ReplacementPolicyState {
  def apply(policy: ReplacementPolicy, numLines: Int): ReplacementPolicyState = policy match {
    case Random => new RandomState(numLines)
  }
}
