package mem.cache

import utils._
import chisel3._
import chisel3.util._

class FullyAssociativeCache(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
  replacementPolicy: ReplacementPolicy = Random
) extends Module {
  override def desiredName: String =
    s"fully_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${numLines}_${replacementPolicy.desiredName}"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth, wordsPerLine)).suggestName("CACHE")
  val io     = Wire(new CacheIO(addrWidth, dataWidth, wordsPerLine))

  // Parameters
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val tagWidth        = addrWidth - wordOffsetWidth - byteOffsetWidth
  val lineWidth       = dataWidth * wordsPerLine

  // Cache storage - fully associative means ALL lines can hold ANY address
  val dataArray = SyncReadMem(numLines, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numLines)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // Replacement policy state
  val replacementState = ReplacementPolicyState(replacementPolicy, numLines)

  // FSM state
  val state = RegInit(CacheFSMState.IDLE)

  // Registers for holding request information
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = RegInit(0.U(dataWidth.W))
  val reqOp         = RegInit(MemoryOp.READ)
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val reqTag        = RegInit(0.U(tagWidth.W))

  // Victim line index for replacement
  val victimIndex = RegInit(0.U(log2Ceil(numLines).W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  // Write forwarding
  val lastWriteValid = RegInit(false.B)
  val lastWriteIndex = Reg(UInt(log2Ceil(numLines).W))
  val lastWriteTag   = Reg(UInt(tagWidth.W))
  val lastWriteData  = Reg(UInt(lineWidth.W))

  // Track memory request
  val memReqSent = RegInit(false.B)

  // Address parsing
  def parseAddr(addr: UInt) = new {
    val byteOffset = addr(byteOffsetWidth - 1, 0)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val tag        = addr(addrWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val lineAddr   = Cat(addr(addrWidth - 1, wordOffsetWidth + byteOffsetWidth), 0.U((wordOffsetWidth + byteOffsetWidth).W))
  }

  // Extract word from cache line (BIG ENDIAN)
  def extractWord(lineData: UInt, wordOffset: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).reverse.map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth)))
    words(wordOffset)
  }

  // Update word in cache line (BIG ENDIAN)
  def updateWord(lineData: UInt, wordOffset: UInt, newWord: UInt): UInt = {
    val words = Wire(Vec(wordsPerLine, UInt(dataWidth.W)))
    for (i <- 0 until wordsPerLine)
      words(i) := lineData((i + 1) * dataWidth - 1, i * dataWidth)
    words(wordsPerLine.U - 1.U - wordOffset) := newWord
    words.asUInt
  }

  // Fully associative tag comparison - check ALL lines
  val tagMatches = VecInit(metaArray.map(meta => meta.valid && (meta.tag === reqTag)))
  val hit        = tagMatches.asUInt.orR       // Hit if ANY line matches
  val hitIndex   = PriorityEncoder(tagMatches) // Index of first matching line

  // Find if there's an invalid (empty) line
  val invalidLines = VecInit(metaArray.map(!_.valid))
  val hasInvalid   = invalidLines.asUInt.orR
  val invalidIndex = PriorityEncoder(invalidLines)

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

  // Track state
  val waitingForRead    = RegInit(false.B)
  val usedForwardedData = RegInit(false.B)

  // FSM
  switch(state) {
    is(CacheFSMState.IDLE) {
      io.upper.req.ready := true.B
      waitingForRead     := false.B
      usedForwardedData  := false.B
      memReqSent         := false.B

      when(io.upper.req.valid && io.upper.req.ready) {
        val parsed = parseAddr(io.upper.req.bits.addr)
        reqAddr       := io.upper.req.bits.addr
        reqData       := io.upper.req.bits.data
        reqOp         := io.upper.req.bits.op
        reqWordOffset := parsed.wordOffset
        reqTag        := parsed.tag

        // Check all lines for tag match using COMBINATIONAL comparison
        val tagMatchesNow = VecInit(metaArray.map(meta => meta.valid && (meta.tag === parsed.tag)))
        val hitNow        = tagMatchesNow.asUInt.orR
        val hitIndexNow   = PriorityEncoder(tagMatchesNow)

        // Check for write forwarding
        val useForwardedData = lastWriteValid && (lastWriteTag === parsed.tag)

        when(useForwardedData) {
          currentLineData   := lastWriteData
          usedForwardedData := true.B
          waitingForRead    := false.B
        }.elsewhen(hitNow) {
          // Read from the matching line
          currentLineData   := dataArray.read(hitIndexNow)
          waitingForRead    := true.B
          usedForwardedData := false.B
        }.otherwise {
          // Miss - will need to read later
          waitingForRead    := false.B
          usedForwardedData := false.B
        }

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      when(waitingForRead) {
        waitingForRead := false.B
      }.otherwise {
        when(hit) {
          // Cache hit
          when(reqOp === MemoryOp.READ) {
            io.upper.resp.valid     := true.B
            io.upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)

            when(io.upper.resp.ready) {
              // Update replacement policy on hit
              replacementState.update(hitIndex, true.B)
              state := CacheFSMState.IDLE
            }
          }.otherwise {
            // Write hit
            val updatedLine = updateWord(currentLineData, reqWordOffset, reqData)
            dataArray.write(hitIndex, updatedLine)
            metaArray(hitIndex).dirty := true.B

            // Update write forwarding
            lastWriteValid := true.B
            lastWriteIndex := hitIndex
            lastWriteTag   := reqTag
            lastWriteData  := updatedLine

            io.upper.resp.valid := true.B
            when(io.upper.resp.ready) {
              replacementState.update(hitIndex, true.B)
              state := CacheFSMState.IDLE
            }
          }
        }.otherwise {
          // Cache miss
          io.miss := true.B

          // Determine victim line
          when(hasInvalid) {
            // Use an invalid line (no eviction needed)
            victimIndex := invalidIndex
            state       := CacheFSMState.ALLOCATE
          }.otherwise {
            // Need to evict - use replacement policy
            victimIndex := replacementState.getVictim()

            // Clear forwarding if evicting that line
            when(lastWriteValid && (lastWriteIndex === victimIndex)) {
              lastWriteValid := false.B
            }

            when(metaArray(victimIndex).valid && metaArray(victimIndex).dirty) {
              // Read the victim line for writeback
              currentLineData := dataArray.read(victimIndex)
              waitingForRead  := true.B
              state           := CacheFSMState.WRITEBACK_READ
            }.otherwise {
              state := CacheFSMState.ALLOCATE
            }
          }
        }
      }
    }

    is(CacheFSMState.WRITEBACK_READ) {
      // Wait for SyncReadMem to provide victim line data
      when(waitingForRead) {
        waitingForRead := false.B
      }.otherwise {
        state := CacheFSMState.WRITEBACK
      }
    }

    is(CacheFSMState.WRITEBACK) {
      // Write back dirty victim line
      io.lower.req.valid     := true.B
      io.lower.req.bits.op   := MemoryOp.WRITE
      io.lower.req.bits.addr := Cat(metaArray(victimIndex).tag, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      io.lower.req.bits.data := currentLineData

      when(io.lower.req.ready) {
        metaArray(victimIndex).dirty := false.B
        state                        := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        io.lower.req.valid     := true.B
        io.lower.req.bits.op   := MemoryOp.READ
        io.lower.req.bits.addr := currParsed.lineAddr
        io.lower.req.bits.data := 0.U

        when(io.lower.req.ready) {
          memReqSent := true.B
        }
      }

      io.lower.resp.ready := true.B

      when(memReqSent && io.lower.resp.valid && io.lower.resp.ready) {
        val newLineData = Wire(UInt(lineWidth.W))

        when(reqOp === MemoryOp.WRITE) {
          newLineData                  := updateWord(io.lower.resp.bits.data, reqWordOffset, reqData)
          metaArray(victimIndex).dirty := true.B
        }.otherwise {
          newLineData                  := io.lower.resp.bits.data
          metaArray(victimIndex).dirty := false.B
        }

        // Update cache with new line
        dataArray.write(victimIndex, newLineData)
        metaArray(victimIndex).valid := true.B
        metaArray(victimIndex).tag   := reqTag

        currentLineData := newLineData

        // Update write forwarding
        lastWriteValid := true.B
        lastWriteIndex := victimIndex
        lastWriteTag   := reqTag
        lastWriteData  := newLineData

        // Update replacement policy on allocation
        replacementState.update(victimIndex, false.B)

        // Return data to CPU
        io.upper.resp.valid := true.B
        when(reqOp === MemoryOp.READ) {
          io.upper.resp.bits.data := extractWord(newLineData, reqWordOffset)
        }.otherwise {
          io.upper.resp.bits.data := reqData
        }

        when(io.upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }

  ext_io.connect(io)
}

object TestFullyAssociativeCache extends App {
  VerilogEmitter.parse(
    new FullyAssociativeCache(
      addrWidth = 32,
      dataWidth = 32,
      wordsPerLine = 4,
      numLines = 16,
      replacementPolicy = Random
    ),
    "fully_associative_cache.sv",
    info = true
  )
}
