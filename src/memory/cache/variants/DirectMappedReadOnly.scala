package vopts.mem.cache

import chisel3._
import chisel3.util._

class DirectMappedCacheReadOnly[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
) extends Module {
  val dataWidth = gen.getWidth

  override def desiredName: String = s"direct_mapped_cache_read_only_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val upper = IO(Flipped(new CacheReadOnlyIO(gen, addrWidth)))
  val lower = IO(new CacheReadOnlyIO(Vec(wordsPerLine, gen), addrWidth))

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

  // Current metadata
  val meta = metaArray(reqIndex)
  val hit  = meta.alloc && (meta.tag === reqTag)

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
        reqIndex      := parsed.index
        reqWordOffset := parsed.wordOffset

        currentLineData := dataArray.read(parsed.index)

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      when(hit) {
        // Cache hit
        upper.resp.valid     := true.B
        upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
        upper.resp.bits.hit  := true.B

        when(upper.resp.ready) {
          state := CacheFSMState.IDLE
        }
      }.otherwise {
        // Cache miss
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
        val receivedLineData = vecToLineData(lower.resp.bits.data)
        val newLineData      = Wire(UInt(lineWidth.W))

        newLineData := receivedLineData

        // Update cache
        dataArray.write(reqIndex, newLineData)
        metaArray(reqIndex).alloc := true.B
        metaArray(reqIndex).tag   := reqTag

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
