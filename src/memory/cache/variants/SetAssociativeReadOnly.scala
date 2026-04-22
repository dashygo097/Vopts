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

  val numSets                      = linesPerWay
  val dataWidth                    = gen.getWidth
  override def desiredName: String =
    s"set_associative_cache_read_only_${addrWidth}x${dataWidth}x${wordsPerLine}x${numSets}x$numWays"

  val upper = IO(Flipped(new CacheReadOnlyIO(gen, addrWidth)))
  val lower = IO(new CacheReadOnlyIO(gen, addrWidth))

  val tagWidth        = addrWidth - log2Ceil(numSets) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numSets)
  val wordOffsetWidth = log2Ceil(wordsPerLine).max(1)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val lineWidth       = dataWidth * wordsPerLine

  val dataArray = Mem(numWays * numSets, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * numSets)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  val state      = RegInit(CacheNonBlockingState.IDLE)
  val replStates = Seq.fill(numSets)(ReplacementPolicyState(replPolicy, numWays))

  val victimWayReg = RegInit(VecInit(Seq.fill(numSets)(0.U(log2Ceil(numWays).max(1).W))))
  for (s <- 0 until numSets) victimWayReg(s) := replStates(s).getVictim()

  val reqAddr         = RegInit(0.U(addrWidth.W))
  val reqValid        = RegInit(false.B)
  val reqTag          = RegInit(0.U(tagWidth.W))
  val reqIndex        = RegInit(0.U(indexWidth.W))
  val reqWordOffset   = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine    = RegInit(0.U(log2Ceil(numWays * numSets).W))
  val currentLineData = Reg(UInt(lineWidth.W))

  val filling           = RegInit(false.B)
  val memReqSent        = RegInit(false.B)
  val fillTag           = Reg(UInt(tagWidth.W))
  val fillIndex         = Reg(UInt(indexWidth.W))
  val fillWay           = Reg(UInt(log2Ceil(numWays).max(1).W))
  val fillValid         = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillBuffer        = Reg(Vec(wordsPerLine, gen))
  val currentFillOffset = Reg(UInt(wordOffsetWidth.W))

  def makeAddr(tag: UInt, index: UInt, offset: UInt): UInt =
    if (byteOffsetWidth > 0) Cat(tag, index, offset, 0.U(byteOffsetWidth.W)) else Cat(tag, index, offset)

  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = if (log2Ceil(wordsPerLine) > 0) addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth) else 0.U(1.W)
    val setBase    = index * numWays.U
  }

  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
    words(wordOffset)
  }

  def vecToLineData(vec: Vec[T]): UInt                             = vec.asUInt
  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numSets) when(s.U === setIdx)(replStates(s).update(way, isHit))

  val proceedReq  = upper.req.fire || reqValid
  val currentAddr = Mux(reqValid, reqAddr, upper.req.bits.addr)

  upper.req.ready      := (state === CacheNonBlockingState.IDLE) && !reqValid
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  upper.resp.bits.last := true.B

  lower.req.valid     := filling && !memReqSent
  lower.req.bits.addr := makeAddr(fillTag, fillIndex, reqWordOffset)
  when(lower.req.fire)(memReqSent := true.B)
  lower.resp.ready    := true.B

  val isFillLast    = filling && lower.resp.valid && lower.resp.bits.last
  val fillLineIdx   = (fillIndex * numWays.U) + fillWay
  val assembledLine = VecInit((0 until wordsPerLine).map { i =>
    Mux(i.U === currentFillOffset, lower.resp.bits.data, fillBuffer(i.U))
  })

  switch(state) {
    is(CacheNonBlockingState.IDLE) {
      when(proceedReq) {
        val parsed = parseAddr(currentAddr)
        reqAddr       := currentAddr
        reqTag        := parsed.tag
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset
        reqValid      := false.B

        val hitBits   = (0 until numWays).map { way =>
          val m = metaArray(parsed.setBase + way.U)
          m.alloc && (m.tag === parsed.tag)
        }
        val isHit     = CombTree.orTree(hitBits)
        val hitWay    = PriorityEncoder(VecInit(hitBits))
        val victimWay = victimWayReg(parsed.index)

        val nextSelectedLine = parsed.setBase + Mux(isHit, hitWay, victimWay)
        selectedLine := nextSelectedLine

        val rawReadData = dataArray.read(nextSelectedLine)
        currentLineData := Mux(isFillLast && (nextSelectedLine === fillLineIdx), vecToLineData(assembledLine), rawReadData)

        state := CacheNonBlockingState.COMPARE_TAG
      }
    }

    is(CacheNonBlockingState.COMPARE_TAG) {
      val meta      = metaArray(selectedLine)
      val cacheHit  = meta.alloc && (meta.tag === reqTag)
      val isMshrHit = filling && (fillTag === reqTag) && (fillIndex === reqIndex)
      val way       = selectedLine - (reqIndex * numWays.U)

      when(cacheHit) {
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
        upper.resp.bits.hit  := true.B
        when(upper.resp.ready) {
          updateReplPolicy(reqIndex, way, true.B)
          state := CacheNonBlockingState.IDLE
        }
      }.elsewhen(isMshrHit) {
        val cwReady = fillValid(reqWordOffset) || (lower.resp.valid && currentFillOffset === reqWordOffset)
        when(cwReady) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillBuffer(reqWordOffset), lower.resp.bits.data)
          upper.resp.bits.hit  := true.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, fillWay, true.B)
            state := CacheNonBlockingState.IDLE
          }
        }.otherwise(state := CacheNonBlockingState.WAIT_WORD)
      }.otherwise {
        when(filling) {
          reqValid := true.B
          state    := CacheNonBlockingState.IDLE
        }.otherwise {
          updateReplPolicy(reqIndex, way, false.B)
          filling           := true.B
          memReqSent        := false.B
          fillTag           := reqTag
          fillIndex         := reqIndex
          fillWay           := way
          fillValid         := VecInit(Seq.fill(wordsPerLine)(false.B))
          currentFillOffset := reqWordOffset
          state             := CacheNonBlockingState.WAIT_WORD
        }
      }
    }

    is(CacheNonBlockingState.WAIT_WORD) {
      val cwReady = fillValid(reqWordOffset) || (lower.resp.valid && currentFillOffset === reqWordOffset)
      when(cwReady) {
        upper.resp.valid     := true.B
        upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillBuffer(reqWordOffset), lower.resp.bits.data)
        upper.resp.bits.hit  := false.B
        when(upper.resp.ready) {
          updateReplPolicy(reqIndex, fillWay, true.B)
          state := CacheNonBlockingState.IDLE
        }
      }
    }
  }

  when(filling && lower.resp.valid) {
    fillBuffer(currentFillOffset) := lower.resp.bits.data
    fillValid(currentFillOffset)  := true.B
    currentFillOffset             := Mux(currentFillOffset === (wordsPerLine - 1).U, 0.U, currentFillOffset + 1.U)

    when(lower.resp.bits.last) {
      filling := false.B
      dataArray.write(fillLineIdx, vecToLineData(assembledLine))

      val newMeta = Wire(new CacheEntry(tagWidth))
      newMeta.alloc          := true.B
      newMeta.tag            := fillTag
      newMeta.dirty          := false.B
      metaArray(fillLineIdx) := newMeta
    }
  }
}
