package vopts.mem.cache

import vopts.utils._
import chisel3._
import chisel3.util._

class DirectMappedCache(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  numLines: Int
) extends Module {
  override def desiredName: String = s"direct_mapped_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val ext_io = IO(new CacheExternalIO(addrWidth, dataWidth, wordsPerLine)).suggestName("CACHE")
  val io     = Wire(new CacheIO(addrWidth, dataWidth, wordsPerLine))

  dontTouch(ext_io)

  // Parameters
  val byteOffsetWidth = log2Ceil(dataWidth / 8)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val indexWidth      = log2Ceil(numLines)
  val tagWidth        = addrWidth - indexWidth - wordOffsetWidth - byteOffsetWidth
  val lineWidth       = dataWidth * wordsPerLine

  // Cache storage
  val dataArray = SyncReadMem(numLines, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numLines)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSM state
  val state = RegInit(CacheFSMState.IDLE)

  // Registers
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = RegInit(0.U(dataWidth.W))
  val reqOp         = RegInit(MemoryOp.READ)
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val reqIndex      = RegInit(0.U(indexWidth.W))
  val reqTag        = RegInit(0.U(tagWidth.W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))
  val cacheReadData   = Wire(UInt(lineWidth.W))
  val cacheReadEn     = Wire(Bool())
  val cacheReadAddr   = Wire(UInt(indexWidth.W))
  cacheReadEn   := false.B
  cacheReadAddr := 0.U
  cacheReadData := dataArray.read(cacheReadAddr, cacheReadEn)

  // Write forwarding
  val lastWriteValid = RegInit(false.B)
  val lastWriteIndex = Reg(UInt(indexWidth.W))
  val lastWriteTag   = Reg(UInt(tagWidth.W))
  val lastWriteData  = Reg(UInt(lineWidth.W))

  val memReqSent = RegInit(false.B)

  // Address parsing helper function
  def parseAddr(addr: UInt) = new {
    val byteOffset = addr(byteOffsetWidth - 1, 0)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val lineAddr   = Cat(addr(addrWidth - 1, wordOffsetWidth + byteOffsetWidth), 0.U((wordOffsetWidth + byteOffsetWidth).W))
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

  // Current metadata
  val meta = metaArray(reqIndex)
  val hit  = meta.valid && (meta.tag === reqTag)

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

  // Track if we need to wait for SyncReadMem data
  val waitingForRead = RegInit(false.B)

  // Track if we used forwarded data (no memory read needed)
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
        reqIndex      := parsed.index
        reqTag        := parsed.tag

        val useForwardedData = lastWriteValid &&
          (lastWriteIndex === parsed.index) &&
          (lastWriteTag === parsed.tag)

        when(useForwardedData) {
          // Use forwarded data instead of reading from memory
          currentLineData   := lastWriteData
          usedForwardedData := true.B
          waitingForRead    := false.B
        }.otherwise {
          cacheReadEn       := true.B
          cacheReadAddr     := parsed.index
          waitingForRead    := true.B
          usedForwardedData := false.B
        }

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      when(waitingForRead) {
        currentLineData := cacheReadData
        waitingForRead  := false.B
      }.otherwise {
        when(hit) {
          // Cache hit
          when(reqOp === MemoryOp.READ) {
            // Read hit - return the specific word
            io.upper.resp.valid     := true.B
            io.upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)

            when(io.upper.resp.ready) {
              state := CacheFSMState.IDLE
            }
          }.otherwise {
            // Write hit - update the specific word
            val updatedLine = updateWord(currentLineData, reqWordOffset, reqData)
            dataArray.write(reqIndex, updatedLine)
            metaArray(reqIndex).dirty := true.B

            // Update write forwarding
            lastWriteValid := true.B
            lastWriteIndex := reqIndex
            lastWriteTag   := reqTag
            lastWriteData  := updatedLine

            io.upper.resp.valid := true.B
            when(io.upper.resp.ready) {
              state := CacheFSMState.IDLE
            }
          }
        }.otherwise {
          // Cache miss
          io.miss := true.B

          when(meta.valid && meta.dirty) {
            // Need to write back dirty line
            when(lastWriteValid && (lastWriteIndex === reqIndex) && (lastWriteTag === meta.tag)) {
              // The SyncReadMem data is stale - use forwarded data instead
              currentLineData := lastWriteData
            }
            // Invalidate forwarding for this index since we're evicting it
            when(lastWriteValid && (lastWriteIndex === reqIndex)) {
              lastWriteValid := false.B
            }
            state := CacheFSMState.WRITEBACK
          }.otherwise {
            // No write-back needed
            when(lastWriteValid && (lastWriteIndex === reqIndex)) {
              lastWriteValid := false.B
            }
            state := CacheFSMState.ALLOCATE
          }
        }
      }
    }

    is(CacheFSMState.WRITEBACK) {
      // Write back dirty line to memory
      io.lower.req.valid     := true.B
      io.lower.req.bits.op   := MemoryOp.WRITE
      io.lower.req.bits.addr := Cat(meta.tag, reqIndex, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      io.lower.req.bits.data := currentLineData

      when(io.lower.req.ready) {
        metaArray(reqIndex).dirty := false.B
        state                     := CacheFSMState.ALLOCATE
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

      // Always assert ready to accept response
      io.lower.resp.ready := true.B

      when(memReqSent && io.lower.resp.valid && io.lower.resp.ready) {
        val newLineData = Wire(UInt(lineWidth.W))

        when(reqOp === MemoryOp.WRITE) {
          // Write allocate - update the word being written
          newLineData               := updateWord(io.lower.resp.bits.data, reqWordOffset, reqData)
          metaArray(reqIndex).dirty := true.B
        }.otherwise {
          newLineData               := io.lower.resp.bits.data
          metaArray(reqIndex).dirty := false.B
        }

        // Update cache
        dataArray.write(reqIndex, newLineData)
        metaArray(reqIndex).valid := true.B
        metaArray(reqIndex).tag   := reqTag

        currentLineData := newLineData

        // Update write forwarding
        lastWriteValid := true.B
        lastWriteIndex := reqIndex
        lastWriteTag   := reqTag
        lastWriteData  := newLineData

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

object TestDirectMappedCache extends App {
  VerilogEmitter.parse(
    new DirectMappedCache(
      addrWidth = 32,
      dataWidth = 32,
      wordsPerLine = 4,
      numLines = 16
    ),
    "direct_mapped_cache.sv",
    info = true,
    lowering = true
  )
}
