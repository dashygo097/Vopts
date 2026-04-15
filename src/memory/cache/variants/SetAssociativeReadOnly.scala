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
  val lower = IO(new CacheReadOnlyIO(gen, addrWidth))

  val tagWidth        = addrWidth - log2Ceil(numWays) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numWays)
  val wordOffsetWidth = log2Ceil(wordsPerLine).max(1)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val lineWidth       = dataWidth * wordsPerLine

  val dataArray = Mem(numWays * linesPerWay, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * linesPerWay)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  val state      = RegInit(CacheFSMState.IDLE)
  val replStates = Seq.fill(numWays)(ReplacementPolicyState(replPolicy, linesPerWay))

  val victimWayReg = RegInit(VecInit(Seq.fill(numWays)(0.U(log2Ceil(linesPerWay).W))))
  for (s <- 0 until numWays)
    victimWayReg(s) := replStates(s).getVictim()

  val reqAddr         = RegInit(0.U(addrWidth.W))
  val reqValid        = RegInit(false.B)
  val reqTag          = RegInit(0.U(tagWidth.W))
  val reqIndex        = RegInit(0.U(indexWidth.W))
  val reqWordOffset   = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine    = RegInit(0.U(log2Ceil(numWays * linesPerWay).W))
  val currentLineData = Reg(UInt(lineWidth.W))

  // MSHR logic correctly issuing individual beat requests
  val filling    = RegInit(false.B)
  val fillTag    = Reg(UInt(tagWidth.W))
  val fillIndex  = Reg(UInt(indexWidth.W))
  val fillWay    = Reg(UInt(log2Ceil(linesPerWay).W))
  val fillValid  = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillBuffer = Reg(Vec(wordsPerLine, gen))

  val currentFillOffset = Reg(UInt(wordOffsetWidth.W))
  val reqOffset         = Reg(UInt(wordOffsetWidth.W))
  val reqCount          = Reg(UInt(log2Ceil(wordsPerLine + 1).W))
  val respCount         = Reg(UInt(log2Ceil(wordsPerLine + 1).W))

  def makeAddr(tag: UInt, index: UInt, offset: UInt): UInt =
    if (byteOffsetWidth > 0) Cat(tag, index, offset, 0.U(byteOffsetWidth.W)) else Cat(tag, index, offset)

  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = if (log2Ceil(wordsPerLine) > 0) addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth) else 0.U(1.W)
    val setBase    = Cat(index, 0.U(log2Ceil(linesPerWay).W))
  }

  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
    words(wordOffset)
  }

  def vecToLineData(vec: Vec[T]): UInt = vec.asUInt

  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numWays)
      when(s.U === setIdx)(replStates(s).update(way, isHit))

  val proceedReq  = upper.req.fire || reqValid
  val currentAddr = Mux(reqValid, reqAddr, upper.req.bits.addr)

  upper.req.ready      := (state === CacheFSMState.IDLE) && !reqValid
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  upper.resp.bits.last := true.B

  val mshrFillArriving  = filling && lower.resp.valid
  val currentRespOffset = currentFillOffset

  switch(state) {
    is(CacheFSMState.IDLE) {
      when(proceedReq) {
        val parsed = parseAddr(currentAddr)
        reqAddr       := currentAddr
        reqTag        := parsed.tag
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset
        reqValid      := false.B

        val hitBits   = (0 until linesPerWay).map { way =>
          val m = metaArray(parsed.setBase + way.U)
          m.alloc && (m.tag === parsed.tag)
        }
        val isHit     = CombTree.orTree(hitBits)
        val hitWay    = PriorityEncoder(VecInit(hitBits))
        val victimWay = CombTree.oneHotMux((0 until numWays).map(s => (parsed.index === s.U) -> victimWayReg(s)))

        val chosenWay   = Mux(isHit, hitWay, victimWay)
        val chosenIndex = parsed.setBase + chosenWay

        selectedLine    := chosenIndex
        currentLineData := dataArray.read(chosenIndex)
        state           := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta      = metaArray(selectedLine)
      val cacheHit  = meta.alloc && (meta.tag === reqTag)
      val isMshrHit = filling && (fillTag === reqTag) && (fillIndex === reqIndex)
      val way       = selectedLine - Cat(reqIndex, 0.U(log2Ceil(linesPerWay).W))

      when(cacheHit) {
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
        upper.resp.bits.hit  := true.B

        when(upper.resp.ready) {
          updateReplPolicy(reqIndex, way, true.B)
          state := CacheFSMState.IDLE
        }
      }.elsewhen(isMshrHit) {
        val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)
        when(cwReady) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillBuffer(reqWordOffset), lower.resp.bits.data)
          upper.resp.bits.hit  := true.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, fillWay, true.B)
            state := CacheFSMState.IDLE
          }
        }.otherwise {
          state := CacheFSMState.WAIT_WORD
        }
      }.otherwise {
        when(filling) {
          reqValid := true.B
          state    := CacheFSMState.IDLE
        }.otherwise {
          updateReplPolicy(reqIndex, way, false.B)
          filling           := true.B
          fillTag           := reqTag
          fillIndex         := reqIndex
          fillWay           := way
          fillValid         := VecInit(Seq.fill(wordsPerLine)(false.B))
          currentFillOffset := reqWordOffset
          reqOffset         := reqWordOffset
          reqCount          := 0.U
          respCount         := 0.U
          state             := CacheFSMState.WAIT_WORD
        }
      }
    }

    is(CacheFSMState.WAIT_WORD) {
      val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)
      when(cwReady) {
        upper.resp.valid     := true.B
        upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillBuffer(reqWordOffset), lower.resp.bits.data)
        upper.resp.bits.hit  := false.B
        when(upper.resp.ready) {
          state := CacheFSMState.IDLE
        }
      }
    }
  }

  lower.req.valid     := filling && (reqCount < wordsPerLine.U)
  lower.req.bits.addr := makeAddr(fillTag, fillIndex, reqOffset)

  when(filling && (reqCount < wordsPerLine.U) && lower.req.fire) {
    reqCount  := reqCount + 1.U
    reqOffset := Mux(reqOffset === (wordsPerLine - 1).U, 0.U, reqOffset + 1.U)
  }

  lower.resp.ready := true.B

  when(filling && lower.resp.valid) {
    fillBuffer(currentFillOffset) := lower.resp.bits.data
    fillValid(currentFillOffset)  := true.B

    val nextFillOffset = Mux(currentFillOffset === (wordsPerLine - 1).U, 0.U, currentFillOffset + 1.U)
    currentFillOffset := nextFillOffset
    respCount         := respCount + 1.U

    when(respCount === (wordsPerLine - 1).U) {
      filling := false.B

      val assembledLine = VecInit((0 until wordsPerLine).map { i =>
        Mux(i.U === currentFillOffset, lower.resp.bits.data, fillBuffer(i.U))
      })

      val fillLineIndex = Cat(fillIndex, fillWay)
      dataArray.write(fillLineIndex, vecToLineData(assembledLine))

      val newMeta = Wire(new CacheEntry(tagWidth))
      newMeta                  := metaArray(fillLineIndex)
      newMeta.alloc            := true.B
      newMeta.tag              := fillTag
      newMeta.dirty            := false.B
      metaArray(fillLineIndex) := newMeta
    }
  }
}
