package vopts.mem.cache

import vopts.utils.CombTree
import chisel3._
import chisel3.util._

class SetAssociativeCache[T <: Data](
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
    s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${numSets}x$numWays"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(gen, addrWidth))

  val tagWidth        = addrWidth - log2Ceil(numSets) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numSets)
  val wordOffsetWidth = log2Ceil(wordsPerLine).max(1)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val lineWidth       = dataWidth * wordsPerLine

  val dataArray = Mem(numWays * numSets, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * numSets)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  val state      = RegInit(CacheFSMState.IDLE)
  val replStates = Seq.fill(numSets)(ReplacementPolicyState(replPolicy, numWays))

  val victimWayReg = RegInit(VecInit(Seq.fill(numSets)(0.U(log2Ceil(numWays).max(1).W))))
  for (s <- 0 until numSets) victimWayReg(s) := replStates(s).getVictim()

  val reqValid        = RegInit(false.B)
  val reqAddr         = RegInit(0.U(addrWidth.W))
  val reqData         = Reg(gen)
  val reqStrb         = RegInit(0.U((dataWidth / 8).W))
  val reqOp           = RegInit(CacheOp.READ)
  val reqTag          = RegInit(0.U(tagWidth.W))
  val reqIndex        = RegInit(0.U(indexWidth.W))
  val reqWordOffset   = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine    = RegInit(0.U(log2Ceil(numWays * numSets).W))
  val currentLineData = Reg(UInt(lineWidth.W))

  val lastWriteValid   = RegInit(false.B)
  val lastWriteTag     = Reg(UInt(tagWidth.W))
  val lastWriteIndex   = Reg(UInt(indexWidth.W))
  val lastWriteData    = Reg(UInt(lineWidth.W))
  val lastSelectedLine = Reg(UInt(log2Ceil(numWays * numSets).W))

  val MSHR_IDLE = 0.U(2.W)
  val MSHR_WB   = 1.U(2.W)
  val MSHR_FILL = 2.U(2.W)

  val mshrState     = RegInit(MSHR_IDLE)
  val mshrReqSent   = RegInit(false.B)
  val mshrTag       = Reg(UInt(tagWidth.W))
  val mshrVictimTag = Reg(UInt(tagWidth.W))
  val mshrIndex     = Reg(UInt(indexWidth.W))
  val mshrWay       = Reg(UInt(log2Ceil(numWays).max(1).W))
  val mshrCw        = Reg(UInt(wordOffsetWidth.W))
  val mshrDirty     = RegInit(false.B)

  val reqOffset     = Reg(UInt(wordOffsetWidth.W))
  val wbData        = Reg(Vec(wordsPerLine, gen))
  val fillValid     = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillData      = Reg(Vec(wordsPerLine, gen))
  val fillDirtyStrb = RegInit(VecInit(Seq.fill(wordsPerLine)(0.U((dataWidth / 8).W))))

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

  def applyStrb(oldWord: UInt, newWord: UInt, strb: UInt): UInt = {
    val bytes = (0 until (dataWidth / 8)).map { i =>
      val oldByte = oldWord(8 * i + 7, 8 * i)
      val newByte = newWord(8 * i + 7, 8 * i)
      Mux(strb(i), newByte, oldByte)
    }
    Cat(bytes.reverse)
  }

  def updateWord(lineData: UInt, wordOffset: UInt, newWord: T, strb: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      val cur     = lineData((i + 1) * dataWidth - 1, i * dataWidth)
      val updated = applyStrb(cur, newWord.asUInt, strb)
      Mux(wordOffset === i.U, updated, cur)
    })
    words.asUInt
  }

  def lineDataToVec(lineData: UInt): Vec[T]                        = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
  def vecToLineData(vec: Vec[T]): UInt                             = vec.asUInt
  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numSets) when(s.U === setIdx)(replStates(s).update(way, isHit))

  val proceedReq  = upper.req.fire || reqValid
  val currentAddr = Mux(reqValid, reqAddr, upper.req.bits.addr)
  val currentData = Mux(reqValid, reqData, upper.req.bits.data)
  val currentStrb = Mux(reqValid, reqStrb, upper.req.bits.strb)
  val currentOp   = Mux(reqValid, reqOp, upper.req.bits.op)

  upper.req.ready      := (state === CacheFSMState.IDLE) && !reqValid
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  upper.resp.bits.last := true.B

  lower.req.valid     := false.B
  lower.req.bits.addr := 0.U
  lower.req.bits.data := 0.U.asTypeOf(gen)
  lower.req.bits.op   := CacheOp.READ
  lower.req.bits.strb := Fill(dataWidth / 8, 1.U)
  lower.resp.ready    := true.B

  val mshrFillArriving  = (mshrState === MSHR_FILL) && lower.resp.valid
  val currentRespOffset = reqOffset

  val cpuWriteToMshrValid  = WireInit(false.B)
  val cpuWriteToMshrOffset = WireInit(0.U(wordOffsetWidth.W))
  val cpuWriteToMshrData   = WireInit(0.U.asTypeOf(gen))
  val cpuWriteToMshrStrb   = WireInit(0.U((dataWidth / 8).W))

  val isFillLast  = (mshrState === MSHR_FILL) && lower.resp.valid && lower.resp.bits.last
  val fillLineIdx = (mshrIndex * numWays.U) + mshrWay
  val finalLine   = Wire(Vec(wordsPerLine, gen))
  for (i <- 0 until wordsPerLine) {
    val isResp = currentRespOffset === i.U
    val isCpu  = cpuWriteToMshrValid && (cpuWriteToMshrOffset === i.U)

    val memData = lower.resp.bits.data.asUInt
    val cpuData = cpuWriteToMshrData.asUInt

    val mergedIfBoth = applyStrb(memData, cpuData, cpuWriteToMshrStrb).asTypeOf(gen)
    val mergedIfCpu  = applyStrb(fillData(i).asUInt, cpuData, cpuWriteToMshrStrb).asTypeOf(gen)
    val memApplyStrb = (~fillDirtyStrb(i)).asUInt
    val mergedIfResp = applyStrb(fillData(i).asUInt, memData, memApplyStrb).asTypeOf(gen)

    finalLine(i) := Mux(isCpu && isResp, mergedIfBoth, Mux(isCpu, mergedIfCpu, Mux(isResp, mergedIfResp, fillData(i))))
  }

  val arrivingMem         = lower.resp.bits.data
  val memApplyStrbForRead = (~fillDirtyStrb(reqWordOffset)).asUInt
  val mergedArrivingWord  = applyStrb(fillData(reqWordOffset).asUInt, arrivingMem.asUInt, memApplyStrbForRead).asTypeOf(gen)

  switch(state) {
    is(CacheFSMState.IDLE) {
      when(proceedReq) {
        val parsed = parseAddr(currentAddr)
        reqAddr       := currentAddr
        reqData       := currentData
        reqStrb       := currentStrb
        reqOp         := currentOp
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

        val rawReadData      = dataArray.read(nextSelectedLine)
        val useForwardedData = CombTree.andTree(Seq(lastWriteValid, lastWriteIndex === parsed.index, lastWriteTag === parsed.tag))
        val useFillData      = isFillLast && (nextSelectedLine === fillLineIdx)

        currentLineData := Mux(useFillData, vecToLineData(finalLine), Mux(useForwardedData, lastWriteData, rawReadData))
        state           := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta      = metaArray(selectedLine)
      val cacheHit  = meta.alloc && (meta.tag === reqTag)
      val isMshrHit = (mshrState =/= MSHR_IDLE) && (mshrTag === reqTag) && (mshrIndex === reqIndex)
      val way       = selectedLine - (reqIndex * numWays.U)

      when(cacheHit) {
        when(reqOp === CacheOp.READ) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
          upper.resp.bits.hit  := true.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, way, true.B)
            state := CacheFSMState.IDLE
          }
        }.otherwise {
          val updatedLine = updateWord(currentLineData, reqWordOffset, reqData, reqStrb)
          dataArray.write(selectedLine, updatedLine)
          metaArray(selectedLine).dirty := true.B

          lastWriteValid   := true.B
          lastWriteTag     := reqTag
          lastWriteIndex   := reqIndex
          lastWriteData    := updatedLine
          lastSelectedLine := selectedLine

          upper.resp.valid    := true.B
          upper.resp.bits.hit := true.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, way, true.B)
            state := CacheFSMState.IDLE
          }
        }
      }.elsewhen(isMshrHit) {
        val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)
        when(cwReady) {
          when(reqOp === CacheOp.READ) {
            upper.resp.valid     := true.B
            upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillData(reqWordOffset), mergedArrivingWord)
            upper.resp.bits.hit  := true.B
            when(upper.resp.ready) {
              updateReplPolicy(reqIndex, mshrWay, true.B)
              state := CacheFSMState.IDLE
            }
          }.otherwise {
            upper.resp.valid    := true.B
            upper.resp.bits.hit := true.B
            when(upper.resp.ready) {
              updateReplPolicy(reqIndex, mshrWay, true.B)
              cpuWriteToMshrValid  := true.B
              cpuWriteToMshrOffset := reqWordOffset
              cpuWriteToMshrData   := reqData
              cpuWriteToMshrStrb   := reqStrb
              state                := CacheFSMState.IDLE
            }
          }
        }.otherwise(state := CacheFSMState.WAIT_WORD)
      }.otherwise {
        when(lastWriteValid && (lastWriteIndex === reqIndex))(lastWriteValid := false.B)

        when(mshrState =/= MSHR_IDLE) {
          reqValid := true.B
          state    := CacheFSMState.IDLE
        }.otherwise {
          updateReplPolicy(reqIndex, way, false.B)

          mshrTag       := reqTag
          mshrIndex     := reqIndex
          mshrWay       := way
          mshrCw        := reqWordOffset
          mshrDirty     := false.B
          mshrVictimTag := meta.tag
          mshrReqSent   := false.B

          val useFwdForWb    = CombTree.andTree(Seq(lastWriteValid, lastSelectedLine === selectedLine, lastWriteTag === meta.tag))
          val victimLineData = Mux(useFwdForWb, lastWriteData, currentLineData)

          when(meta.alloc && meta.dirty) {
            mshrState := MSHR_WB
            wbData    := lineDataToVec(victimLineData)
            reqOffset := 0.U
          }.otherwise {
            mshrState := MSHR_FILL
            reqOffset := reqWordOffset
          }
          fillValid     := VecInit(Seq.fill(wordsPerLine)(false.B))
          fillDirtyStrb := VecInit(Seq.fill(wordsPerLine)(0.U((dataWidth / 8).W)))
          state         := CacheFSMState.WAIT_WORD
        }
      }
    }

    is(CacheFSMState.WAIT_WORD) {
      val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)

      when(cwReady) {
        val wordData = Mux(fillValid(reqWordOffset), fillData(reqWordOffset), mergedArrivingWord)
        when(reqOp === CacheOp.READ) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := wordData
          upper.resp.bits.hit  := false.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, mshrWay, true.B)
            state := CacheFSMState.IDLE
          }
        }.otherwise {
          upper.resp.valid    := true.B
          upper.resp.bits.hit := false.B
          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, mshrWay, true.B)
            cpuWriteToMshrValid  := true.B
            cpuWriteToMshrOffset := reqWordOffset
            cpuWriteToMshrData   := reqData
            cpuWriteToMshrStrb   := reqStrb
            state                := CacheFSMState.IDLE
          }
        }
      }
    }
  }

  when(cpuWriteToMshrValid)(mshrDirty := true.B)

  for (i <- 0 until wordsPerLine) {
    val isRespTarget = mshrFillArriving && (currentRespOffset === i.U)
    val isCpuTarget  = cpuWriteToMshrValid && (cpuWriteToMshrOffset === i.U)

    when(isCpuTarget && isRespTarget) {
      fillData(i)      := applyStrb(lower.resp.bits.data.asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillValid(i)     := true.B
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isCpuTarget) {
      fillData(i)      := applyStrb(fillData(i).asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isRespTarget) {
      val memApplyStrb = (~fillDirtyStrb(i)).asUInt
      fillData(i)  := applyStrb(fillData(i).asUInt, lower.resp.bits.data.asUInt, memApplyStrb).asTypeOf(gen)
      fillValid(i) := true.B
    }
  }

  switch(mshrState) {
    is(MSHR_WB) {
      lower.req.valid     := true.B
      lower.req.bits.op   := CacheOp.WRITE
      lower.req.bits.addr := makeAddr(mshrVictimTag, mshrIndex, 0.U)
      lower.req.bits.data := wbData(reqOffset)

      when(lower.req.fire) {
        reqOffset := reqOffset + 1.U
      }
      when(lower.resp.valid && lower.resp.bits.last) {
        mshrState   := MSHR_FILL
        reqOffset   := mshrCw
        mshrReqSent := false.B
      }
    }

    is(MSHR_FILL) {
      lower.req.valid     := !mshrReqSent
      lower.req.bits.op   := CacheOp.READ
      lower.req.bits.addr := makeAddr(mshrTag, mshrIndex, mshrCw)

      when(lower.req.fire)(mshrReqSent := true.B)

      when(lower.resp.valid) {
        reqOffset := Mux(reqOffset === (wordsPerLine - 1).U, 0.U, reqOffset + 1.U)

        when(lower.resp.bits.last) {
          mshrState := MSHR_IDLE
          dataArray.write(fillLineIdx, vecToLineData(finalLine))

          val newMeta = Wire(new CacheEntry(tagWidth))
          newMeta.alloc          := true.B
          newMeta.tag            := mshrTag
          newMeta.dirty          := mshrDirty || cpuWriteToMshrValid
          metaArray(fillLineIdx) := newMeta
        }
      }
    }
  }
}
