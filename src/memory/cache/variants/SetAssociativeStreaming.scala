package vopts.mem.cache

import vopts.utils.CombTree
import chisel3._
import chisel3.util._

class SetAssociativeStreamingCache[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  linesPerWay: Int,
  numWays: Int,
  replPolicy: ReplacementPolicy,
) extends Module {

  val numSets   = linesPerWay
  val dataWidth = gen.getWidth

  override def desiredName: String =
    s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${numSets}x$numWays"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(gen, addrWidth))

  private val rawIndexWidth      = log2Ceil(numSets)
  private val rawWordOffsetWidth = log2Ceil(wordsPerLine)
  private val byteOffsetWidth    = log2Ceil(dataWidth / 8)

  val indexWidth      = rawIndexWidth.max(1)
  val wordOffsetWidth = rawWordOffsetWidth.max(1)
  val tagWidth        = addrWidth - rawIndexWidth - rawWordOffsetWidth - byteOffsetWidth
  val lineWidth       = dataWidth * wordsPerLine

  val wayWidth       = log2Ceil(numWays).max(1)
  val lineIndexWidth = log2Ceil(numWays * numSets).max(1)

  val dataArray = Mem(numWays * numSets, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * numSets)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  val state      = RegInit(CacheNonBlockingState.IDLE)
  val replStates = Seq.fill(numSets)(ReplacementPolicyState(replPolicy, numWays))

  val victimWayReg = RegInit(VecInit(Seq.fill(numSets)(0.U(wayWidth.W))))
  for (s <- 0 until numSets) victimWayReg(s) := replStates(s).getVictim()

  val reqValid      = RegInit(false.B)
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = Reg(gen)
  val reqStrb       = RegInit(0.U((dataWidth / 8).W))
  val reqOp         = RegInit(CacheOp.READ)
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqIndex      = RegInit(0.U(indexWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))

  val selectedLine    = RegInit(0.U(lineIndexWidth.W))
  val currentLineData = RegInit(0.U(lineWidth.W))

  val lastWriteValid   = RegInit(false.B)
  val lastWriteTag     = RegInit(0.U(tagWidth.W))
  val lastWriteIndex   = RegInit(0.U(indexWidth.W))
  val lastWriteData    = RegInit(0.U(lineWidth.W))
  val lastSelectedLine = RegInit(0.U(lineIndexWidth.W))

  val MSHR_IDLE = 0.U(2.W)
  val MSHR_WB   = 1.U(2.W)
  val MSHR_FILL = 2.U(2.W)

  val mshrState     = RegInit(MSHR_IDLE)
  val mshrReqSent   = RegInit(false.B)
  val mshrTag       = RegInit(0.U(tagWidth.W))
  val mshrVictimTag = RegInit(0.U(tagWidth.W))
  val mshrIndex     = RegInit(0.U(indexWidth.W))
  val mshrWay       = RegInit(0.U(wayWidth.W))
  val mshrCw        = RegInit(0.U(wordOffsetWidth.W))
  val mshrDirty     = RegInit(false.B)

  val reqOffset = RegInit(0.U(wordOffsetWidth.W))

  val wbData        = Reg(Vec(wordsPerLine, gen))
  val fillValid     = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillData      = Reg(Vec(wordsPerLine, gen))
  val fillDirtyStrb = RegInit(VecInit(Seq.fill(wordsPerLine)(0.U((dataWidth / 8).W))))

  val fullStrb = Fill(dataWidth / 8, 1.U(1.W))

  def setBase(index: UInt): UInt = index * numWays.U

  def makeAddr(tag: UInt, index: UInt, offset: UInt): UInt =
    if (rawIndexWidth > 0 && rawWordOffsetWidth > 0) {
      Cat(tag, index(rawIndexWidth - 1, 0), offset(rawWordOffsetWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else if (rawIndexWidth > 0 && rawWordOffsetWidth == 0) {
      Cat(tag, index(rawIndexWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else if (rawIndexWidth == 0 && rawWordOffsetWidth > 0) {
      Cat(tag, offset(rawWordOffsetWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else {
      Cat(tag, 0.U(byteOffsetWidth.W))
    }

  def parseAddr(addr: UInt) = new {
    val tag = addr(addrWidth - 1, rawIndexWidth + rawWordOffsetWidth + byteOffsetWidth)

    val index =
      if (rawIndexWidth > 0)
        addr(rawIndexWidth + rawWordOffsetWidth + byteOffsetWidth - 1, rawWordOffsetWidth + byteOffsetWidth)
      else
        0.U(indexWidth.W)

    val wordOffset =
      if (rawWordOffsetWidth > 0)
        addr(rawWordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
      else
        0.U(wordOffsetWidth.W)

    val setBase = index * numWays.U
  }

  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)
    })
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

  def lineDataToVec(lineData: UInt): Vec[T] =
    VecInit((0 until wordsPerLine).map { i =>
      lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)
    })

  def vecToLineData(vec: Vec[T]): UInt = vec.asUInt

  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numSets)
      when(s.U === setIdx) {
        replStates(s).update(way, isHit)
      }

  def wrapInc(x: UInt): UInt = Mux(x === (wordsPerLine - 1).U, 0.U, x + 1.U)

  val lowerRespReady     = mshrState === MSHR_WB || mshrState === MSHR_FILL
  val mshrFillArriving   = mshrState === MSHR_FILL && lower.resp.valid && lowerRespReady
  val mshrFillCommitFire = mshrFillArriving && lower.resp.bits.last
  val currentRespOffset  = reqOffset

  upper.req.ready      := state === CacheNonBlockingState.IDLE && !reqValid && !mshrFillCommitFire
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  upper.resp.bits.last := true.B

  lower.req.valid     := false.B
  lower.req.bits.addr := 0.U
  lower.req.bits.data := 0.U.asTypeOf(gen)
  lower.req.bits.op   := CacheOp.READ
  lower.req.bits.strb := fullStrb
  lower.resp.ready    := lowerRespReady

  val proceedReq  = (upper.req.fire || reqValid) && !mshrFillCommitFire
  val currentAddr = Mux(reqValid, reqAddr, upper.req.bits.addr)
  val currentData = Mux(reqValid, reqData, upper.req.bits.data)
  val currentStrb = Mux(reqValid, reqStrb, upper.req.bits.strb)
  val currentOp   = Mux(reqValid, reqOp, upper.req.bits.op)

  val cpuWriteToMshrValid  = WireInit(false.B)
  val cpuWriteToMshrOffset = WireInit(0.U(wordOffsetWidth.W))
  val cpuWriteToMshrData   = WireInit(0.U.asTypeOf(gen))
  val cpuWriteToMshrStrb   = WireInit(0.U((dataWidth / 8).W))

  val fillLineIdx = mshrIndex * numWays.U + mshrWay

  val finalLine = Wire(Vec(wordsPerLine, gen))
  for (i <- 0 until wordsPerLine) {
    val isResp   = mshrFillArriving && currentRespOffset === i.U
    val isCpu    = cpuWriteToMshrValid && cpuWriteToMshrOffset === i.U
    val memData  = lower.resp.bits.data.asUInt
    val cpuData  = cpuWriteToMshrData.asUInt
    val oldWord  = fillData(i).asUInt
    val withMem  = applyStrb(oldWord, memData, (~fillDirtyStrb(i)).asUInt)
    val withCpu  = applyStrb(oldWord, cpuData, cpuWriteToMshrStrb)
    val withBoth = applyStrb(withMem, cpuData, cpuWriteToMshrStrb)

    finalLine(i) := Mux(
      isResp && isCpu,
      withBoth.asTypeOf(gen),
      Mux(isResp, withMem.asTypeOf(gen), Mux(isCpu, withCpu.asTypeOf(gen), fillData(i)))
    )
  }

  val reqWordMemArriving = mshrFillArriving && currentRespOffset === reqWordOffset
  val reqWordFullDirty   = fillDirtyStrb(reqWordOffset) === fullStrb
  val reqWordReady       = fillValid(reqWordOffset) || reqWordFullDirty || reqWordMemArriving
  val mergedArrivingWord = applyStrb(fillData(reqWordOffset).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(reqWordOffset)).asUInt).asTypeOf(gen)
  val mshrReadWord       = Mux(reqWordMemArriving, mergedArrivingWord, fillData(reqWordOffset))

  switch(state) {
    is(CacheNonBlockingState.IDLE) {
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

        val hitBits = (0 until numWays).map { way =>
          val m = metaArray(parsed.setBase + way.U)
          m.alloc && m.tag === parsed.tag
        }

        val invalidBits = (0 until numWays).map { way =>
          !metaArray(parsed.setBase + way.U).alloc
        }

        val isHit      = CombTree.orTree(hitBits)
        val hasInvalid = CombTree.orTree(invalidBits)
        val hitWay     = PriorityEncoder(VecInit(hitBits))
        val invalidWay = PriorityEncoder(VecInit(invalidBits))
        val victimWay  = Mux(hasInvalid, invalidWay, victimWayReg(parsed.index))

        val nextSelectedLine = parsed.setBase + Mux(isHit, hitWay, victimWay)
        val rawReadData      = dataArray.read(nextSelectedLine)
        val useForwardedData = lastWriteValid && lastSelectedLine === nextSelectedLine

        selectedLine    := nextSelectedLine
        currentLineData := Mux(useForwardedData, lastWriteData, rawReadData)
        state           := CacheNonBlockingState.COMPARE_TAG
      }
    }

    is(CacheNonBlockingState.COMPARE_TAG) {
      val meta              = metaArray(selectedLine)
      val cacheHit          = meta.alloc && meta.tag === reqTag
      val isMshrHit         = mshrState =/= MSHR_IDLE && mshrTag === reqTag && mshrIndex === reqIndex
      val way               = (selectedLine - reqIndex * numWays.U)(wayWidth - 1, 0)
      val sameSetAsMshr     = mshrState =/= MSHR_IDLE && mshrIndex === reqIndex
      val victimWayHazard   = sameSetAsMshr && way === mshrWay && !isMshrHit
      val sameSetMissHazard = sameSetAsMshr && !cacheHit && !isMshrHit
      val mshrConflict      = victimWayHazard || sameSetMissHazard

      when(mshrConflict) {
        reqValid := true.B
        state    := CacheNonBlockingState.IDLE
      }.elsewhen(cacheHit) {
        when(reqOp === CacheOp.READ) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
          upper.resp.bits.hit  := true.B
          upper.resp.bits.last := true.B

          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, way, true.B)
            state := CacheNonBlockingState.IDLE
          }
        }.otherwise {
          val updatedLine = updateWord(currentLineData, reqWordOffset, reqData, reqStrb)

          dataArray.write(selectedLine, updatedLine)
          metaArray(selectedLine).alloc := true.B
          metaArray(selectedLine).tag   := reqTag
          metaArray(selectedLine).dirty := true.B

          lastWriteValid   := true.B
          lastWriteTag     := reqTag
          lastWriteIndex   := reqIndex
          lastWriteData    := updatedLine
          lastSelectedLine := selectedLine

          upper.resp.valid     := true.B
          upper.resp.bits.data := 0.U.asTypeOf(gen)
          upper.resp.bits.hit  := true.B
          upper.resp.bits.last := true.B

          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, way, true.B)
            state := CacheNonBlockingState.IDLE
          }
        }
      }.elsewhen(isMshrHit) {
        when(reqWordReady) {
          when(reqOp === CacheOp.READ) {
            upper.resp.valid     := true.B
            upper.resp.bits.data := mshrReadWord
            upper.resp.bits.hit  := true.B
            upper.resp.bits.last := true.B

            when(upper.resp.ready) {
              updateReplPolicy(reqIndex, mshrWay, true.B)
              state := CacheNonBlockingState.IDLE
            }
          }.otherwise {
            upper.resp.valid     := true.B
            upper.resp.bits.data := 0.U.asTypeOf(gen)
            upper.resp.bits.hit  := true.B
            upper.resp.bits.last := true.B

            when(upper.resp.ready) {
              cpuWriteToMshrValid  := true.B
              cpuWriteToMshrOffset := reqWordOffset
              cpuWriteToMshrData   := reqData
              cpuWriteToMshrStrb   := reqStrb
              updateReplPolicy(reqIndex, mshrWay, true.B)
              state                := CacheNonBlockingState.IDLE
            }
          }
        }.otherwise {
          state := CacheNonBlockingState.WAIT_WORD
        }
      }.otherwise {
        when(mshrState =/= MSHR_IDLE) {
          reqValid := true.B
          state    := CacheNonBlockingState.IDLE
        }.otherwise {
          updateReplPolicy(reqIndex, way, false.B)

          mshrTag       := reqTag
          mshrIndex     := reqIndex
          mshrWay       := way
          mshrCw        := reqWordOffset
          mshrDirty     := false.B
          mshrVictimTag := meta.tag
          mshrReqSent   := false.B

          val useFwdForWb    = lastWriteValid && lastSelectedLine === selectedLine && lastWriteTag === meta.tag
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

          when(lastWriteValid && lastWriteIndex === reqIndex) {
            lastWriteValid := false.B
          }

          state := CacheNonBlockingState.WAIT_WORD
        }
      }
    }

    is(CacheNonBlockingState.WAIT_WORD) {
      when(reqWordReady) {
        when(reqOp === CacheOp.READ) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := mshrReadWord
          upper.resp.bits.hit  := false.B
          upper.resp.bits.last := true.B

          when(upper.resp.ready) {
            updateReplPolicy(reqIndex, mshrWay, true.B)
            state := CacheNonBlockingState.IDLE
          }
        }.otherwise {
          upper.resp.valid     := true.B
          upper.resp.bits.data := 0.U.asTypeOf(gen)
          upper.resp.bits.hit  := false.B
          upper.resp.bits.last := true.B

          when(upper.resp.ready) {
            cpuWriteToMshrValid  := true.B
            cpuWriteToMshrOffset := reqWordOffset
            cpuWriteToMshrData   := reqData
            cpuWriteToMshrStrb   := reqStrb
            updateReplPolicy(reqIndex, mshrWay, true.B)
            state                := CacheNonBlockingState.IDLE
          }
        }
      }
    }

    is(CacheNonBlockingState.WAIT_MSHR) {
      state := CacheNonBlockingState.IDLE
    }
  }

  when(cpuWriteToMshrValid) {
    mshrDirty := true.B
  }

  for (i <- 0 until wordsPerLine) {
    val isRespTarget = mshrFillArriving && currentRespOffset === i.U
    val isCpuTarget  = cpuWriteToMshrValid && cpuWriteToMshrOffset === i.U

    when(isCpuTarget && isRespTarget) {
      fillData(i)      := applyStrb(applyStrb(fillData(i).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(i)).asUInt), cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillValid(i)     := true.B
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isCpuTarget) {
      fillData(i)      := applyStrb(fillData(i).asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isRespTarget) {
      fillData(i)  := applyStrb(fillData(i).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(i)).asUInt).asTypeOf(gen)
      fillValid(i) := true.B
    }
  }

  switch(mshrState) {
    is(MSHR_WB) {
      lower.req.valid     := true.B
      lower.req.bits.op   := CacheOp.WRITE
      lower.req.bits.addr := makeAddr(mshrVictimTag, mshrIndex, reqOffset)
      lower.req.bits.data := wbData(reqOffset)
      lower.req.bits.strb := fullStrb

      when(lower.req.fire) {
        reqOffset := wrapInc(reqOffset)
      }

      when(lower.resp.fire && lower.resp.bits.last) {
        mshrState   := MSHR_FILL
        reqOffset   := mshrCw
        mshrReqSent := false.B
      }
    }

    is(MSHR_FILL) {
      lower.req.valid     := !mshrReqSent
      lower.req.bits.op   := CacheOp.READ
      lower.req.bits.addr := makeAddr(mshrTag, mshrIndex, mshrCw)
      lower.req.bits.data := 0.U.asTypeOf(gen)
      lower.req.bits.strb := fullStrb

      when(lower.req.fire) {
        mshrReqSent := true.B
      }

      when(mshrFillArriving) {
        reqOffset := wrapInc(reqOffset)

        when(lower.resp.bits.last) {
          val committedLine = vecToLineData(finalLine)

          dataArray.write(fillLineIdx, committedLine)

          val newMeta = Wire(new CacheEntry(tagWidth))
          newMeta.alloc := true.B
          newMeta.tag   := mshrTag
          newMeta.dirty := mshrDirty || cpuWriteToMshrValid

          metaArray(fillLineIdx) := newMeta

          lastWriteValid   := true.B
          lastWriteTag     := mshrTag
          lastWriteIndex   := mshrIndex
          lastWriteData    := committedLine
          lastSelectedLine := fillLineIdx

          mshrState   := MSHR_IDLE
          mshrReqSent := false.B
        }
      }
    }
  }
}
