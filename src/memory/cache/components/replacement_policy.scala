package mem.cache

import chisel3._

sealed trait ReplacementPolicy {
  def desiredName: String
}

case object Random extends ReplacementPolicy {
  override def desiredName: String = "random"
}

case object LRU extends ReplacementPolicy {
  override def desiredName: String = "lru"
}

object ReplacementPolicy {
  def fromString(name: String): Option[ReplacementPolicy] = name.toLowerCase match {
    case "random" | "rand" => Some(Random)
    case "lru"             => Some(LRU)
    case _                 => None
  }

  def available: Seq[ReplacementPolicy] = Seq(Random)
}

abstract class ReplacementPolicyState(val numLines: Int) {
  def getVictim(): UInt
  def update(accessedIndex: UInt, isHit: Bool): Unit
  def reset(): Unit
}

object ReplacementPolicyState {
  def apply(policy: ReplacementPolicy, numLines: Int): ReplacementPolicyState = policy match {
    case Random => new RandomState(numLines)
    case LRU    => new LRUState(numLines)
  }
}
