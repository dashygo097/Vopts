package vopts.mem.cache

import chisel3._

class SetAssociativeCache(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  linesPerSet: Int,
  numSets: Int,
  replPolicy: ReplacementPolicy
) extends Module {
  override def desiredName: String = s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${linesPerSet}x$numSets"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth, wordsPerLine)).suggestName("CACHE")
  val io     = Wire(new CacheIO(addrWidth, dataWidth, wordsPerLine))

  dontTouch(ext_io)

}
