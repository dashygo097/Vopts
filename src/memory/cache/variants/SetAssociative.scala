package vopts.mem.cache

import vopts.utils._
import chisel3._
import chisel3.util._

class SetAssociativeCache(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  linesPerWay: Int,
  numWays: Int,
  replPolicy: ReplacementPolicy
) extends Module {
  override def desiredName: String = s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${linesPerWay}x$numWays"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth, wordsPerLine)).suggestName("CACHE")
  val io     = Wire(new CacheIO(addrWidth, dataWidth, wordsPerLine))

  dontTouch(ext_io)

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
  val reqData       = RegInit(0.U(dataWidth.W))
  val reqOp         = RegInit(MemoryOp.READ)
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

  // Extract word from cache line (BIG ENDIAN - MSB is word 0)
  def extractWord(lineData: UInt, wordOffset: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).reverse.map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth)))
    words(wordOffset)
  }

  // Update word in cache line (BIG ENDIAN)
  def updateWord(lineData: UInt, wordOffset: UInt, newWord: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      val currentWord    = lineData((i + 1) * dataWidth - 1, i * dataWidth)
      val bigEndianIndex = (wordsPerLine - 1 - i).U
      Mux(wordOffset === bigEndianIndex, newWord, currentWord)
    })
    words.asUInt
  }

  // Helper to compute flat index from set and way
  def getFlatIndex(setIndex: UInt, way: UInt): UInt =
    (setIndex * linesPerWay.U) + way

  // Default outputs
  io.upper.req.ready      := false.B
  io.upper.resp.valid     := false.B
  io.upper.resp.bits.data := 0.U
  io.lower.req.valid      := false.B
  io.lower.req.bits.addr  := 0.U
  io.lower.req.bits.data  := 0.U
  io.lower.req.bits.op    := MemoryOp.READ
  io.lower.resp.ready     := false.B
  io.miss                 := false.B

  // FSM
  switch(state) {
    is(CacheFSMState.IDLE) {
      io.upper.req.ready := true.B
      memReqSent         := false.B

      when(io.upper.req.fire) {
        val parsed = parseAddr(io.upper.req.bits.addr)
        reqAddr       := io.upper.req.bits.addr
        reqData       := io.upper.req.bits.data
        reqOp         := io.upper.req.bits.op
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
        io.miss := false.B
        when(reqOp === MemoryOp.READ) {
          // Read hit - return the specific word
          io.upper.resp.valid     := true.B
          io.upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)

          when(io.upper.resp.ready) {
            state := CacheFSMState.IDLE
            val way        = selectedLine - reqIndex ## 0.U(log2Ceil(linesPerWay).W)
            // Update replacement policy for this set
            val updateWays = Wire(Vec(numWays, Bool()))
            for (s <- 0 until numWays) {
              updateWays(s) := (s.U === reqIndex) && io.upper.resp.ready
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

          io.upper.resp.valid := true.B
          when(io.upper.resp.ready) {
            state := CacheFSMState.IDLE
            val way        = selectedLine - reqIndex ## 0.U(log2Ceil(linesPerWay).W)
            // Update replacement policy for this set
            val updateWays = Wire(Vec(numWays, Bool()))
            for (s <- 0 until numWays) {
              updateWays(s) := (s.U === reqIndex) && io.upper.resp.ready
              when(updateWays(s)) {
                replStates(s).update(way, true.B)
              }
            }
          }
        }
      }.otherwise {
        // Cache miss
        io.miss := true.B
        when(lastWriteValid && (lastWriteIndex === reqIndex)) {
          lastWriteValid := false.B
        }

        when(meta.alloc && meta.dirty) {
          // Need to write back dirty line
          when(lastWriteValid && (lastSelectedLine === selectedLine) && (lastWriteTag === meta.tag)) {
            currentLineData := lastWriteData
          }
          state := CacheFSMState.WRITEBACK
        }.otherwise {
          // No write-back needed
          state := CacheFSMState.ALLOCATE
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

    is(CacheFSMState.WRITEBACK) {
      // Write back dirty line to memory
      io.lower.req.valid     := true.B
      io.lower.req.bits.op   := MemoryOp.WRITE
      io.lower.req.bits.addr := Cat(metaArray(selectedLine).tag, reqIndex, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      io.lower.req.bits.data := currentLineData

      when(io.lower.req.ready) {
        metaArray(selectedLine).dirty := false.B
        state                         := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        io.lower.req.valid     := true.B
        io.lower.req.bits.op   := MemoryOp.READ
        io.lower.req.bits.addr := Cat(currParsed.tag, currParsed.index, 0.U((wordOffsetWidth + byteOffsetWidth).W))
        io.lower.req.bits.data := 0.U

        when(io.lower.req.ready) {
          memReqSent := true.B
        }
      }

      // Always assert ready to accept response
      io.lower.resp.ready := true.B

      when(memReqSent && io.lower.resp.fire) {
        val newLineData = Wire(UInt(lineWidth.W))

        when(reqOp === MemoryOp.WRITE) {
          // Write allocate - update the word being written
          newLineData                   := updateWord(io.lower.resp.bits.data, reqWordOffset, reqData)
          metaArray(selectedLine).dirty := true.B
        }.otherwise {
          newLineData                   := io.lower.resp.bits.data
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
        io.upper.resp.valid     := true.B
        io.upper.resp.bits.data := Mux(
          reqOp === MemoryOp.READ,
          extractWord(newLineData, reqWordOffset),
          reqData
        )

        when(io.upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }

  ext_io.connect(io)
}

object TestSetAssociativeCache extends App {
  VerilogEmitter.parse(
    new SetAssociativeCache(
      addrWidth = 32,
      dataWidth = 32,
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
