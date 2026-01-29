package vopts.mem.cache

import vopts.utils._
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

  override def desiredName: String = s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${linesPerWay}x$numWays"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(Vec(wordsPerLine, gen), addrWidth))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(numWays) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numWays)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)

  val lineWidth = dataWidth * wordsPerLine

  // Cache storage
  val dataArray = Mem(numWays * linesPerWay, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numWays * linesPerWay)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSM state
  val state      = RegInit(CacheFSMState.IDLE)
  val replStates = Seq.fill(numWays)(ReplacementPolicyState(replPolicy, linesPerWay))

  // Registers
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = Reg(gen)
  val reqOp         = RegInit(CacheOp.READ)
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqIndex      = RegInit(0.U(indexWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine  = RegInit(0.U(log2Ceil(numWays * linesPerWay).W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  // Write forwarding
  val lastWriteValid   = RegInit(false.B)
  val lastWriteTag     = Reg(UInt(tagWidth.W))
  val lastWriteIndex   = Reg(UInt(indexWidth.W))
  val lastWriteData    = Reg(UInt(lineWidth.W))
  val lastSelectedLine = Reg(UInt(log2Ceil(numWays * linesPerWay).W))

  val memReqSent = RegInit(false.B)

  // Address parsing helper function
  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val byteOffset = addr(byteOffsetWidth - 1, 0)

    val setBase = Cat(index, 0.U(log2Ceil(linesPerWay).W))
  }

  // Extract word from cache line (returns T)
  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
    words(wordOffset)
  }

  // Update word in cache line (accepts T)
  def updateWord(lineData: UInt, wordOffset: UInt, newWord: T): UInt = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      val currentWord = lineData((i + 1) * dataWidth - 1, i * dataWidth)
      Mux(wordOffset === i.U, newWord.asUInt, currentWord)
    })
    words.asUInt
  }

  // Convert UInt line data to Vec[T]
  def lineDataToVec(lineData: UInt): Vec[T] =
    VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))

  // Convert Vec[T] to UInt line data
  def vecToLineData(vec: Vec[T]): UInt =
    vec.asUInt

  // Helper to compute flat index from set and way
  def getFlatIndex(setIndex: UInt, way: UInt): UInt =
    Cat(setIndex, 0.U(log2Ceil(linesPerWay).W)) + way

  // Default outputs
  upper.req.ready      := false.B
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  lower.req.valid      := false.B
  lower.req.bits.addr  := 0.U
  lower.req.bits.data  := 0.U.asTypeOf(Vec(wordsPerLine, gen))
  lower.req.bits.op    := CacheOp.READ
  lower.resp.ready     := false.B

  // FSM
  switch(state) {
    is(CacheFSMState.IDLE) {
      upper.req.ready := true.B
      memReqSent      := false.B

      when(upper.req.fire) {
        val parsed = parseAddr(upper.req.bits.addr)
        reqAddr       := upper.req.bits.addr
        reqData       := upper.req.bits.data
        reqOp         := upper.req.bits.op
        reqTag        := parsed.tag
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset

        // Search within the set for tag match
        val hits = Wire(Vec(linesPerWay, Bool()))
        for (way <- 0 until linesPerWay) {
          val lineIdx = parsed.setBase + way.U
          val meta    = metaArray(lineIdx)
          hits(way) := meta.alloc && (meta.tag === parsed.tag)
        }

        val isHit  = hits.asUInt.orR
        val hitWay = PriorityEncoder(hits)

        // Get victim way for this set - need to evaluate dynamically
        val victimWays  = Wire(Vec(numWays, UInt(log2Ceil(linesPerWay).W)))
        for (s <- 0 until numWays)
          victimWays(s) := replStates(s).getVictim()
        val victimWay   = victimWays(parsed.index)
        val chosenWay   = Mux(isHit, hitWay, victimWay)
        val chosenIndex = parsed.setBase + chosenWay

        selectedLine := chosenIndex

        // Handle write forwarding
        val useForwardedData = lastWriteValid &&
          (lastWriteIndex === parsed.index) &&
          (lastWriteTag === parsed.tag)

        currentLineData := Mux(useForwardedData, lastWriteData, dataArray.read(chosenIndex))

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta = metaArray(selectedLine)
      val hit  = meta.alloc && (meta.tag === reqTag)

      when(hit) {
        // Cache hit
        when(reqOp === CacheOp.READ) {
          // Read hit - return the specific word
          upper.resp.valid     := true.B
          upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
          upper.resp.bits.hit  := true.B

          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
            val way        = selectedLine - reqIndex ## 0.U(log2Ceil(linesPerWay).W)
            // Update replacement policy for this set
            val updateWays = Wire(Vec(numWays, Bool()))
            for (s <- 0 until numWays) {
              updateWays(s) := (s.U === reqIndex) && upper.resp.ready
              when(updateWays(s)) {
                replStates(s).update(way, true.B)
              }
            }
          }
        }.otherwise {
          // Write hit - update the specific word
          val updatedLine = updateWord(currentLineData, reqWordOffset, reqData)
          dataArray.write(selectedLine, updatedLine)
          metaArray(selectedLine).dirty := true.B

          // Update write forwarding
          lastWriteValid   := true.B
          lastWriteTag     := reqTag
          lastWriteIndex   := reqIndex
          lastWriteData    := updatedLine
          lastSelectedLine := selectedLine

          upper.resp.valid    := true.B
          upper.resp.bits.hit := true.B
          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
            val way        = selectedLine - reqIndex ## 0.U(log2Ceil(linesPerWay).W)
            // Update replacement policy for this set
            val updateWays = Wire(Vec(numWays, Bool()))
            for (s <- 0 until numWays) {
              updateWays(s) := (s.U === reqIndex) && upper.resp.ready
              when(updateWays(s)) {
                replStates(s).update(way, true.B)
              }
            }
          }
        }
      }.otherwise {
        // Cache miss
        when(lastWriteValid && (lastWriteIndex === reqIndex)) {
          lastWriteValid := false.B
        }

        when(meta.alloc && meta.dirty) {
          // Need to write back dirty line
          when(lastWriteValid && (lastSelectedLine === selectedLine) && (lastWriteTag === meta.tag)) {
            currentLineData := lastWriteData
          }
          memReqSent := false.B
          state      := CacheFSMState.WRITEBACK
        }.otherwise {
          // No write-back needed
          memReqSent := false.B
          state      := CacheFSMState.ALLOCATE
        }

        // Update replacement policy on miss
        val way        = selectedLine - reqIndex ## 0.U(log2Ceil(linesPerWay).W)
        val updateWays = Wire(Vec(numWays, Bool()))
        for (s <- 0 until numWays) {
          updateWays(s) := s.U === reqIndex
          when(updateWays(s)) {
            replStates(s).update(way, false.B)
          }
        }
      }
    }

    // TODO: The current impl is pending writeback state, there can be a more effective way to do this
    is(CacheFSMState.WRITEBACK) {
      // Write back dirty line to memory
      lower.req.valid     := !memReqSent
      lower.req.bits.op   := CacheOp.WRITE
      lower.req.bits.addr := Cat(metaArray(selectedLine).tag, reqIndex, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      lower.req.bits.data := lineDataToVec(currentLineData)

      when(!memReqSent && lower.req.fire) {
        memReqSent := true.B
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        metaArray(selectedLine).dirty := false.B
        memReqSent                    := false.B
        state                         := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        lower.req.valid     := true.B
        lower.req.bits.op   := CacheOp.READ
        lower.req.bits.addr := Cat(currParsed.tag, currParsed.index, 0.U((wordOffsetWidth + byteOffsetWidth).W))
        lower.req.bits.data := 0.U.asTypeOf(Vec(wordsPerLine, gen))

        when(lower.req.ready) {
          memReqSent := true.B
        }
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        val receivedLineData = vecToLineData(lower.resp.bits.data)
        val newLineData      = Wire(UInt(lineWidth.W))

        when(reqOp === CacheOp.WRITE) {
          // Write allocate
          newLineData                   := updateWord(receivedLineData, reqWordOffset, reqData)
          metaArray(selectedLine).dirty := true.B
        }.otherwise {
          newLineData                   := receivedLineData
          metaArray(selectedLine).dirty := false.B
        }

        // Update cache
        dataArray.write(selectedLine, newLineData)
        metaArray(selectedLine).alloc := true.B
        metaArray(selectedLine).tag   := reqTag

        currentLineData := newLineData

        // Update write forwarding
        lastWriteValid   := true.B
        lastWriteTag     := reqTag
        lastWriteIndex   := reqIndex
        lastWriteData    := newLineData
        lastSelectedLine := selectedLine

        // Return data to CPU
        upper.resp.valid     := true.B
        upper.resp.bits.data := Mux(
          reqOp === CacheOp.READ,
          extractWord(newLineData, reqWordOffset),
          reqData
        )
        upper.resp.bits.hit  := false.B

        when(upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }
}

object TestSetAssociativeCache extends App {
  VerilogEmitter.parse(
    new SetAssociativeCache(
      gen = UInt(32.W),
      addrWidth = 32,
      wordsPerLine = 4,
      linesPerWay = 4,
      numWays = 4,
      replPolicy = FIFO
    ),
    "set_associative_cache.sv",
    info = true,
    lowering = true
  )
}
