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
  val dataWidth = gen.getWidth

  override def desiredName: String =
    s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${linesPerWay}x$numWays"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(gen, addrWidth))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(numWays) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numWays)
  val wordOffsetWidth = log2Ceil(wordsPerLine) max 1
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val lineWidth       = dataWidth * wordsPerLine

  // Storage
  val dataArray = Mem(numWays * linesPerWay, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * linesPerWay)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSMs & Replacements
  val state      = RegInit(CacheFSMState.IDLE)
  val replStates = Seq.fill(numWays)(ReplacementPolicyState(replPolicy, linesPerWay))

  val victimWayReg = RegInit(VecInit(Seq.fill(numWays)(0.U(log2Ceil(linesPerWay).W))))
  for (s <- 0 until numWays) victimWayReg(s) := replStates(s).getVictim()

  // CPU Request Registers
  val reqValid        = RegInit(false.B)
  val reqAddr         = RegInit(0.U(addrWidth.W))
  val reqData         = Reg(gen)
  val reqStrb         = RegInit(0.U((dataWidth / 8).W))
  val reqOp           = RegInit(CacheOp.READ)
  val reqTag          = RegInit(0.U(tagWidth.W))
  val reqIndex        = RegInit(0.U(indexWidth.W))
  val reqWordOffset   = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine    = RegInit(0.U(log2Ceil(numWays * linesPerWay).W))
  val currentLineData = Reg(UInt(lineWidth.W))

  // Write Forwarding Memory
  val lastWriteValid   = RegInit(false.B)
  val lastWriteTag     = Reg(UInt(tagWidth.W))
  val lastWriteIndex   = Reg(UInt(indexWidth.W))
  val lastWriteData    = Reg(UInt(lineWidth.W))
  val lastSelectedLine = Reg(UInt(log2Ceil(numWays * linesPerWay).W))

  // MSHR and Background Process Definitions
  val MSHR_IDLE = 0.U(2.W)
  val MSHR_WB   = 1.U(2.W)
  val MSHR_FILL = 2.U(2.W)

  val mshrState     = RegInit(MSHR_IDLE)
  val mshrValid     = RegInit(false.B)
  val mshrTag       = Reg(UInt(tagWidth.W))
  val mshrVictimTag = Reg(UInt(tagWidth.W))
  val mshrIndex     = Reg(UInt(indexWidth.W))
  val mshrWay       = Reg(UInt(log2Ceil(linesPerWay).W))
  val mshrCw        = Reg(UInt(wordOffsetWidth.W)) // Critical Word Offset
  val mshrDirty     = RegInit(false.B)

  val reqOffset = Reg(UInt(wordOffsetWidth.W))
  val reqCount  = Reg(UInt(log2Ceil(wordsPerLine + 1).W))
  val respCount = Reg(UInt(log2Ceil(wordsPerLine + 1).W))

  val wbData    = Reg(Vec(wordsPerLine, gen))
  val fillValid = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillData  = Reg(Vec(wordsPerLine, gen))

  // Helpers
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

  def lineDataToVec(lineData: UInt): Vec[T] = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
  def vecToLineData(vec: Vec[T]): UInt      = vec.asUInt

  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numWays) when(s.U === setIdx)(replStates(s).update(way, isHit))

  // Default outputs
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
  lower.resp.ready    := false.B

  // Track real-time fill states dynamically
  val mshrFillArriving  = lower.resp.valid && (mshrState === MSHR_FILL)
  val currentRespOffset = WireInit(0.U(wordOffsetWidth.W))
  val targetSum         = mshrCw + respCount
  if (isPow2(wordsPerLine)) {
    currentRespOffset := targetSum(wordOffsetWidth - 1, 0)
  } else {
    currentRespOffset := Mux(targetSum >= wordsPerLine.U, targetSum - wordsPerLine.U, targetSum)(wordOffsetWidth - 1, 0)
  }

  val cpuWriteToMshrValid  = WireInit(false.B)
  val cpuWriteToMshrOffset = WireInit(0.U(wordOffsetWidth.W))
  val cpuWriteToMshrData   = WireInit(0.U.asTypeOf(gen))
  val cpuWriteToMshrStrb   = WireInit(0.U((dataWidth / 8).W))

  // FSM
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

        val hitBits: Seq[Bool] = (0 until linesPerWay).map { way =>
          val m = metaArray(parsed.setBase + way.U)
          m.alloc && (m.tag === parsed.tag)
        }
        val isHit              = CombTree.orTree(hitBits)
        val hitWay             = PriorityEncoder(VecInit(hitBits))
        val victimWay          = CombTree.oneHotMux((0 until numWays).map(s => (parsed.index === s.U) -> victimWayReg(s)))

        val chosenWay   = Mux(isHit, hitWay, victimWay)
        val chosenIndex = parsed.setBase + chosenWay
        selectedLine := chosenIndex

        val useForwardedData = CombTree.andTree(Seq(lastWriteValid, lastWriteIndex === parsed.index, lastWriteTag === parsed.tag))
        currentLineData := Mux(useForwardedData, lastWriteData, dataArray.read(chosenIndex))
        state           := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta      = metaArray(selectedLine)
      val cacheHit  = meta.alloc && (meta.tag === reqTag)
      val isMshrHit = mshrValid && (mshrTag === reqTag) && (mshrIndex === reqIndex)
      val way       = selectedLine - Cat(reqIndex, 0.U(log2Ceil(linesPerWay).W))

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
      }.elsewhen(isMshrHit) { // Hit Under Miss Processing
        val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)

        when(cwReady) {
          when(reqOp === CacheOp.READ) {
            upper.resp.valid     := true.B
            upper.resp.bits.data := Mux(fillValid(reqWordOffset), fillData(reqWordOffset), lower.resp.bits.data)
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
        }.otherwise {
          state := CacheFSMState.WAIT_WORD
        }
      }.otherwise { // Cache Miss Processing
        when(lastWriteValid && (lastWriteIndex === reqIndex))(lastWriteValid := false.B)

        when(mshrValid) {
          // Block CPU execution safely in presence of a structural MSHR stall
          reqValid := true.B
          state    := CacheFSMState.IDLE
        }.otherwise {
          // Allocate Background Miss Tracking
          updateReplPolicy(reqIndex, way, false.B)

          mshrValid     := true.B
          mshrTag       := reqTag
          mshrIndex     := reqIndex
          mshrWay       := way
          mshrCw        := reqWordOffset
          mshrDirty     := false.B
          mshrVictimTag := meta.tag

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
          reqCount  := 0.U
          respCount := 0.U
          fillValid := VecInit(Seq.fill(wordsPerLine)(false.B))
          state     := CacheFSMState.WAIT_WORD
        }
      }
    }

    is(CacheFSMState.WAIT_WORD) {
      val cwReady = fillValid(reqWordOffset) || (mshrFillArriving && currentRespOffset === reqWordOffset)

      when(cwReady) { // Early Restart implementation
        val wordData = Mux(fillValid(reqWordOffset), fillData(reqWordOffset), lower.resp.bits.data)

        when(reqOp === CacheOp.READ) {
          upper.resp.valid     := true.B
          upper.resp.bits.data := wordData
          upper.resp.bits.hit  := false.B

          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
          }
        }.otherwise {
          upper.resp.valid    := true.B
          upper.resp.bits.hit := false.B

          when(upper.resp.ready) {
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

  // Memory Background Pipeline FSM
  when(cpuWriteToMshrValid)(mshrDirty := true.B)

  for (i <- 0 until wordsPerLine) {
    val isRespTarget = mshrFillArriving && (currentRespOffset === i.U)
    val isCpuTarget  = cpuWriteToMshrValid && (cpuWriteToMshrOffset === i.U)

    when(isCpuTarget && isRespTarget) {
      fillData(i)  := applyStrb(lower.resp.bits.data.asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillValid(i) := true.B
    }.elsewhen(isCpuTarget) {
      fillData(i) := applyStrb(fillData(i).asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
    }.elsewhen(isRespTarget) {
      fillData(i)  := lower.resp.bits.data
      fillValid(i) := true.B
    }
  }

  switch(mshrState) {
    is(MSHR_WB) {
      when(reqCount < wordsPerLine.U) {
        lower.req.valid     := true.B
        lower.req.bits.op   := CacheOp.WRITE
        lower.req.bits.addr := makeAddr(mshrVictimTag, mshrIndex, reqOffset)
        lower.req.bits.data := wbData(reqOffset)

        when(lower.req.fire) {
          reqCount  := reqCount + 1.U
          reqOffset := reqOffset + 1.U
        }
      }

      lower.resp.ready := true.B
      when(lower.resp.fire) {
        respCount := respCount + 1.U
        when(respCount === (wordsPerLine - 1).U) {
          mshrState := MSHR_FILL
          reqCount  := 0.U
          respCount := 0.U
          reqOffset := mshrCw
        }
      }
    }

    is(MSHR_FILL) {
      when(reqCount < wordsPerLine.U) {
        lower.req.valid     := true.B
        lower.req.bits.op   := CacheOp.READ
        lower.req.bits.addr := makeAddr(mshrTag, mshrIndex, reqOffset)

        when(lower.req.fire) {
          reqCount  := reqCount + 1.U
          reqOffset := Mux(reqOffset === (wordsPerLine - 1).U, 0.U, reqOffset + 1.U) // Wrap around for Critical Burst Format
        }
      }

      lower.resp.ready := true.B
      when(lower.resp.fire) {
        respCount := respCount + 1.U
        when(respCount === (wordsPerLine - 1).U) {
          mshrState := MSHR_IDLE
          mshrValid := false.B

          // Close Array Entry and Sync States
          val finalLine = Wire(Vec(wordsPerLine, gen))
          for (i <- 0 until wordsPerLine) {
            val isResp           = currentRespOffset === i.U
            val isCpu            = cpuWriteToMshrValid && (cpuWriteToMshrOffset === i.U)
            val cpuAppliedToResp = applyStrb(lower.resp.bits.data.asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
            val cpuAppliedToFill = applyStrb(fillData(i).asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)

            finalLine(i) := Mux(isCpu && isResp, cpuAppliedToResp, Mux(isCpu, cpuAppliedToFill, Mux(isResp, lower.resp.bits.data, fillData(i))))
          }
          val lineIdx   = Cat(mshrIndex, mshrWay)
          dataArray.write(lineIdx, vecToLineData(finalLine))

          val newMeta = Wire(new CacheEntry(tagWidth))
          newMeta.alloc      := true.B
          newMeta.tag        := mshrTag
          newMeta.dirty      := mshrDirty || cpuWriteToMshrValid
          metaArray(lineIdx) := newMeta
        }
      }
    }
  }
}
