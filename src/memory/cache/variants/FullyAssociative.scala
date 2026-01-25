package vopts.mem.cache

import vopts.utils._
import chisel3._
import chisel3.util._

class FullyAssociativeCache(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
  replPolicy: ReplacementPolicy,
  bigEndian: Boolean = true
) extends Module {
  override def desiredName: String = s"fully_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val upper = IO(Flipped(new UnifiedMemoryIO(addrWidth, dataWidth, 1, wordsPerLine)))
  val lower = IO(new UnifiedMemoryIO(addrWidth, dataWidth, wordsPerLine, wordsPerLine))
  val miss  = IO(Output(Bool()))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)

  val lineWidth = dataWidth * wordsPerLine

  // Cache storage
  val dataArray = Mem(numLines, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numLines)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSM state
  val state     = RegInit(CacheFSMState.IDLE)
  val replState = ReplacementPolicyState(replPolicy, numLines)

  // Registers
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = RegInit(0.U(dataWidth.W))
  val reqOp         = RegInit(MemoryOp.READ)
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine  = RegInit(0.U(log2Ceil(numLines).W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  // Write forwarding
  val lastWriteValid   = RegInit(false.B)
  val lastWriteTag     = Reg(UInt(tagWidth.W))
  val lastWriteData    = Reg(UInt(lineWidth.W))
  val lastSelectedLine = Reg(UInt(log2Ceil(numLines).W))

  val memReqSent = RegInit(false.B)

  // Address parsing helper function
  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val byteOffset = addr(byteOffsetWidth - 1, 0)
  }

  // Extract word from cache line
  def extractWord(lineData: UInt, wordOffset: UInt): UInt =
    if (bigEndian) {
      val words = VecInit((0 until wordsPerLine).reverse.map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth)))
      words(wordOffset)
    } else {
      val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth)))
      words(wordOffset)
    }

  // Update word in cache line
  def updateWord(lineData: UInt, wordOffset: UInt, newWord: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      val currentWord    = lineData((i + 1) * dataWidth - 1, i * dataWidth)
      val bigEndianIndex = (wordsPerLine - 1 - i).U
      Mux(wordOffset === bigEndianIndex, newWord, currentWord)
    })
    words.asUInt
  }

  // Default outputs
  upper.req.ready      := false.B
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U
  lower.req.valid      := false.B
  lower.req.bits.addr  := 0.U
  lower.req.bits.data  := 0.U
  lower.req.bits.op    := MemoryOp.READ
  lower.resp.ready     := false.B
  miss                 := false.B

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
        reqWordOffset := parsed.wordOffset

        // Search for tag match
        val hits        = Wire(Vec(numLines, Bool()))
        for (i <- 0 until numLines) {
          val meta = metaArray(i)
          hits(i) := meta.alloc && (meta.tag === parsed.tag)
        }
        val isHit       = hits.asUInt.orR
        val hitIndex    = PriorityEncoder(hits)
        val victimIndex = replState.getVictim()

        selectedLine := Mux(isHit, hitIndex, victimIndex)

        // Handle write forwarding
        val useForwardedData = lastWriteValid &&
          isHit && (lastWriteTag === parsed.tag)

        // NOTE: Area optimization to reduce number of read ports on data array
        currentLineData := Mux(useForwardedData, lastWriteData, dataArray.read(Mux(isHit, hitIndex, victimIndex)))

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta = metaArray(selectedLine)
      val hit  = meta.alloc && (meta.tag === reqTag)

      when(hit) {
        miss := false.B
        // Cache hit
        when(reqOp === MemoryOp.READ) {
          // Read hit - return the specific word
          upper.resp.valid     := true.B
          upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)

          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
            replState.update(selectedLine, true.B)
          }
        }.otherwise {
          // Write hit - update the specific word
          val updatedLine = updateWord(currentLineData, reqWordOffset, reqData)
          dataArray.write(selectedLine, updatedLine)
          metaArray(selectedLine).dirty := true.B

          // Update write forwarding
          lastWriteValid   := true.B
          lastWriteData    := updatedLine
          lastWriteTag     := reqTag
          lastSelectedLine := selectedLine

          upper.resp.valid := true.B
          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
            replState.update(selectedLine, true.B)
          }
        }
      }.otherwise {
        // Cache miss
        miss := true.B
        when(lastWriteValid && (lastSelectedLine === selectedLine)) {
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
        replState.update(selectedLine, false.B)
      }
    }

    is(CacheFSMState.WRITEBACK) {
      // Write back dirty line to memory
      lower.req.valid     := true.B
      lower.req.bits.op   := MemoryOp.WRITE
      lower.req.bits.addr := Cat(metaArray(selectedLine).tag, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      lower.req.bits.data := currentLineData

      when(lower.req.ready) {
        metaArray(selectedLine).dirty := false.B
        state                         := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        lower.req.valid     := true.B
        lower.req.bits.op   := MemoryOp.READ
        lower.req.bits.addr := Cat(currParsed.tag, 0.U((wordOffsetWidth + byteOffsetWidth).W))
        lower.req.bits.data := 0.U

        when(lower.req.ready) {
          memReqSent := true.B
        }
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        val newLineData = Wire(UInt(lineWidth.W))

        when(reqOp === MemoryOp.WRITE) {
          // Write allocate - update the word being written
          newLineData                   := updateWord(lower.resp.bits.data, reqWordOffset, reqData)
          metaArray(selectedLine).dirty := true.B
        }.otherwise {
          newLineData                   := lower.resp.bits.data
          metaArray(selectedLine).dirty := false.B
        }

        // Update cache
        dataArray.write(selectedLine, newLineData)
        metaArray(selectedLine).alloc := true.B
        metaArray(selectedLine).tag   := reqTag

        currentLineData := newLineData

        // Update write forwarding
        lastWriteValid   := true.B
        lastWriteData    := newLineData
        lastWriteTag     := reqTag
        lastSelectedLine := selectedLine

        // Return data to CPU
        upper.resp.valid     := true.B
        upper.resp.bits.data := Mux(
          reqOp === MemoryOp.READ,
          extractWord(newLineData, reqWordOffset),
          reqData
        )

        when(upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }
}

object TestFullyAssociativeCache extends App {
  VerilogEmitter.parse(
    new FullyAssociativeCache(
      addrWidth = 32,
      dataWidth = 32,
      wordsPerLine = 4,
      numLines = 16,
      replPolicy = FIFO
    ),
    "fully_associative_cache.sv",
    info = true,
    lowering = true
  )
}
