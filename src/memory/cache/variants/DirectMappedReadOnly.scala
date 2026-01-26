package vopts.mem.cache

import chisel3._
import chisel3.util._

class DirectMappedCacheReadOnly(
  addrWidth: Int,
  dataWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
) extends Module {
  override def desiredName: String = s"direct_mapped_cache_read_only_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val upper = IO(Flipped(new UnifiedMemoryReadOnlyIO(addrWidth, dataWidth, 1)))
  val lower = IO(new UnifiedMemoryReadOnlyIO(addrWidth, dataWidth, wordsPerLine))
  val miss  = IO(Output(Bool()))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(numLines) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numLines)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)

  val lineWidth = dataWidth * wordsPerLine

  // Cache storage
  val dataArray = Mem(numLines, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numLines)(0.U.asTypeOf(new CacheReadOnlyEntry(tagWidth)))))

  // FSM state
  val state = RegInit(CacheFSMState.IDLE)

  // Registers
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqIndex      = RegInit(0.U(indexWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  val memReqSent = RegInit(false.B)

  // Address parsing helper function
  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, indexWidth + wordOffsetWidth + byteOffsetWidth)
    val index      = addr(indexWidth + wordOffsetWidth + byteOffsetWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val byteOffset = addr(byteOffsetWidth - 1, 0)
  }

  // Extract word from cache line
  def extractWord(lineData: UInt, wordOffset: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth)))
    words(wordOffset)
  }

  // Update word in cache line
  def updateWord(lineData: UInt, wordOffset: UInt, newWord: UInt): UInt = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      val currentWord = lineData((i + 1) * dataWidth - 1, i * dataWidth)
      Mux(wordOffset === i.U, newWord, currentWord)
    })
    words.asUInt
  }

  // Current metadata
  val meta = metaArray(reqIndex)
  val hit  = meta.alloc && (meta.tag === reqTag)

  // Default outputs
  upper.req.ready      := false.B
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U
  lower.req.valid      := false.B
  lower.req.bits.addr  := 0.U
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
        reqTag        := parsed.tag
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset

        currentLineData := dataArray.read(parsed.index)

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      when(hit) {
        // Cache hit
        miss                 := false.B
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)

        when(upper.resp.ready) {
          state := CacheFSMState.IDLE
        }
      }.otherwise {
        // Cache miss
        miss  := true.B
        state := CacheFSMState.ALLOCATE
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        lower.req.valid     := true.B
        lower.req.bits.addr := Cat(currParsed.tag, currParsed.index, 0.U((wordOffsetWidth + byteOffsetWidth).W))

        when(lower.req.ready) {
          memReqSent := true.B
        }
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        val newLineData = Wire(UInt(lineWidth.W))

        newLineData := lower.resp.bits.data

        // Update cache
        dataArray.write(reqIndex, newLineData)
        metaArray(reqIndex).alloc := true.B
        metaArray(reqIndex).tag   := reqTag

        currentLineData := newLineData

        // Return data to CPU
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(newLineData, reqWordOffset)

        when(upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }
}
