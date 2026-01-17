package vopts.mem.cache

import chisel3._

sealed trait ReplacementPolicy {
  def desiredName: String
}

case object Random extends ReplacementPolicy {
  override def desiredName: String = "random"
}

case object FIFO extends ReplacementPolicy {
  override def desiredName: String = "fifo"
}

case object LFU extends ReplacementPolicy {
  override def desiredName: String = "lfu"
}

case object LRU extends ReplacementPolicy {
  override def desiredName: String = "lru"
}

case object PseudoLRU extends ReplacementPolicy {
  override def desiredName: String = "plru"
}

object ReplacementPolicy {
  def fromString(name: String): Option[ReplacementPolicy] = name.toLowerCase match {
    case "random" | "rand"    => Some(Random)
    case "fifo"               => Some(FIFO)
    case "lfu"                => Some(LFU)
    case "lru"                => Some(LRU)
    case "pseudolru" | "plru" => Some(PseudoLRU)
    case _                    => None
  }

  def available: Seq[ReplacementPolicy] = Seq(Random, FIFO, LFU, LRU)
}

abstract class ReplacementPolicyState(val numLines: Int) {
  def getVictim(): UInt
  def update(accessedIndex: UInt, isHit: Bool): Unit
  def reset(): Unit
}

object ReplacementPolicyState {
  def apply(policy: ReplacementPolicy, numLines: Int): ReplacementPolicyState = policy match {
    case Random    => new RandomState(numLines)
    case FIFO      => new FIFOState(numLines)
    case LFU       => new LFUState(numLines)
    case LRU       => new LRUState(numLines)
    case PseudoLRU => new PseudoLRUState(numLines)
  }
}
