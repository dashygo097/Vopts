package vopts.mem.cache

import vopts.utils.CombTree
import chisel3._
import chisel3.util._

class SetAssociativeCacheReadOnly[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  linesPerWay: Int,
  numWays: Int,
  replPolicy: ReplacementPolicy,
) extends Module {

  val dataWidth                    = gen.getWidth
  override def desiredName: String =
    s"set_associative_cache_read_only_${addrWidth}x${dataWidth}x${wordsPerLine}x${linesPerWay}x$numWays"

  val upper = IO(Flipped(new CacheReadOnlyIO(gen, addrWidth)))
  val lower = IO(new CacheReadOnlyIO(Vec(wordsPerLine, gen), addrWidth))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(numWays) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numWays)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val lineWidth       = dataWidth * wordsPerLine

  // Storage
  val dataArray = Mem(numWays * linesPerWay, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * linesPerWay)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSM
  val state      = RegInit(CacheFSMState.IDLE)
  val replStates = Seq.fill(numWays)(ReplacementPolicyState(replPolicy, linesPerWay))

  // Pre-computed victim register
  val victimWayReg = RegInit(VecInit(Seq.fill(numWays)(0.U(log2Ceil(linesPerWay).W))))
  for (s <- 0 until numWays)
    victimWayReg(s) := replStates(s).getVictim()

  // Request registers
  val reqAddr          = RegInit(0.U(addrWidth.W))
  val reqTag           = RegInit(0.U(tagWidth.W))
  val reqIndex         = RegInit(0.U(indexWidth.W))
  val reqWordOffset    = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine     = RegInit(0.U(log2Ceil(numWays * linesPerWay).W))
  val currentLineData  = Reg(UInt(lineWidth.W))
  val lastSelectedLine = Reg(UInt(log2Ceil(numWays * linesPerWay).W))
  val memReqSent       = RegInit(false.B)

  // Helpers
  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val setBase    = Cat(index, 0.U(log2Ceil(linesPerWay).W))
  }

  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
    words(wordOffset)
  }

  def vecToLineData(vec: Vec[T]): UInt = vec.asUInt

  // Replacement policy update
  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numWays)
      when(s.U === setIdx)(replStates(s).update(way, isHit))

  // Default outputs
  upper.req.ready      := false.B
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  lower.req.valid      := false.B
  lower.req.bits.addr  := 0.U
  lower.resp.ready     := false.B

  // FSM
  switch(state) {

    is(CacheFSMState.IDLE) {
      upper.req.ready := true.B
      memReqSent      := false.B

      when(upper.req.fire) {
        val parsed = parseAddr(upper.req.bits.addr)
        reqAddr       := upper.req.bits.addr
        reqTag        := parsed.tag
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset

        // Tag match
        val hitBits: Seq[Bool] = (0 until linesPerWay).map { way =>
          val m = metaArray(parsed.setBase + way.U)
          m.alloc && (m.tag === parsed.tag)
        }
        val isHit              = CombTree.orTree(hitBits)
        val hitWay             = PriorityEncoder(VecInit(hitBits))

        // Victim selection
        val victimWay = CombTree.oneHotMux(
          (0 until numWays).map(s => (parsed.index === s.U) -> victimWayReg(s))
        )

        val chosenWay   = Mux(isHit, hitWay, victimWay)
        val chosenIndex = parsed.setBase + chosenWay

        selectedLine    := chosenIndex
        currentLineData := dataArray.read(chosenIndex)
        state           := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta = metaArray(selectedLine)
      val hit  = meta.alloc && (meta.tag === reqTag)
      val way  = selectedLine - Cat(reqIndex, 0.U(log2Ceil(linesPerWay).W))

      when(hit) {
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
        upper.resp.bits.hit  := true.B

        when(upper.resp.ready) {
          updateReplPolicy(reqIndex, way, true.B)
          state := CacheFSMState.IDLE
        }
      }.otherwise {
        updateReplPolicy(reqIndex, way, false.B)
        state := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        lower.req.valid     := true.B
        lower.req.bits.addr := Cat(
          currParsed.tag,
          currParsed.index,
          0.U((wordOffsetWidth + byteOffsetWidth).W)
        )
        when(lower.req.ready)(memReqSent := true.B)
      }

      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        val newLineData = vecToLineData(lower.resp.bits.data)

        metaArray(selectedLine).dirty := false.B
        metaArray(selectedLine).alloc := true.B
        metaArray(selectedLine).tag   := reqTag
        dataArray.write(selectedLine, newLineData)
        currentLineData               := newLineData
        lastSelectedLine              := selectedLine

        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(newLineData, reqWordOffset)
        upper.resp.bits.hit  := false.B

        when(upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }
}
