package vopts.mem.cache

import chisel3._
import chisel3.util._

class FullyAssociativeCacheReadOnly[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
  replPolicy: ReplacementPolicy,
) extends Module {
  val dataWidth = gen.getWidth

  override def desiredName: String = s"fully_associative_cache_read_only_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val upper = IO(Flipped(new CacheReadOnlyIO(gen, addrWidth)))
  val lower = IO(new CacheReadOnlyIO(Vec(wordsPerLine, gen), addrWidth))

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
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val selectedLine  = RegInit(0.U(log2Ceil(numLines).W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  val memReqSent = RegInit(false.B)

  // Address parsing helper function
  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, wordOffsetWidth + byteOffsetWidth)
    val wordOffset = addr(wordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth)
    val byteOffset = addr(byteOffsetWidth - 1, 0)
  }

  // Extract word from cache line (returns T)
  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))
    words(wordOffset)
  }

  // Convert UInt line data to Vec[T]
  def lineDataToVec(lineData: UInt): Vec[T] =
    VecInit((0 until wordsPerLine).map(i => lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)))

  // Convert Vec[T] to UInt line data
  def vecToLineData(vec: Vec[T]): UInt =
    vec.asUInt

  // Default outputs
  upper.req.ready      := false.B
  upper.resp.valid     := false.B
  upper.resp.bits.data := 0.U.asTypeOf(gen)
  upper.resp.bits.hit  := false.B
  lower.req.valid      := false.B
  lower.req.bits.addr  := 0.U
  lower.resp.ready     := false.B

  // FSM
  switch(state) {
    is(CacheFSMState.IDLE) {
      upper.req.ready := true.B
      memReqSent      := false.B

      when(upper.req.fire) {
        val parsed = parseAddr(upper.req.bits.addr)
        reqAddr       := upper.req.bits.addr
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

        // NOTE: Area optimization to reduce number of read ports on data array
        currentLineData := dataArray.read(Mux(isHit, hitIndex, victimIndex))

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      val meta = metaArray(selectedLine)
      val hit  = meta.alloc && (meta.tag === reqTag)

      when(hit) {
        // Cache hit
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
        upper.resp.bits.hit  := true.B

        when(upper.resp.ready) {
          state := CacheFSMState.IDLE
          replState.update(selectedLine, true.B)
        }
      }.otherwise {
        // Cache miss
        state := CacheFSMState.ALLOCATE
        replState.update(selectedLine, false.B)
      }
    }

    is(CacheFSMState.ALLOCATE) {
      val currParsed = parseAddr(reqAddr)

      when(!memReqSent) {
        lower.req.valid     := true.B
        lower.req.bits.addr := Cat(currParsed.tag, 0.U((wordOffsetWidth + byteOffsetWidth).W))

        when(lower.req.ready) {
          memReqSent := true.B
        }
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        val receivedLineData = vecToLineData(lower.resp.bits.data)
        val newLineData      = Wire(UInt(lineWidth.W))

        newLineData                   := receivedLineData
        metaArray(selectedLine).dirty := false.B

        // Update cache
        dataArray.write(selectedLine, newLineData)
        metaArray(selectedLine).alloc := true.B
        metaArray(selectedLine).tag   := reqTag

        currentLineData := newLineData

        // Return data to CPU
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(newLineData, reqWordOffset)
        upper.resp.bits.hit  := false.B

        when(upper.resp.ready) {
          state      := CacheFSMState.IDLE
          memReqSent := false.B
        }
      }
    }
  }
}
