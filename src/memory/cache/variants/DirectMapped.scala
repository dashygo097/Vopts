package vopts.mem.cache

import vopts.utils._
import chisel3._
import chisel3.util._

class DirectMappedCache[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  numLines: Int,
) extends Module {
  val dataWidth = gen.getWidth
  
  override def desiredName: String = s"direct_mapped_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x$numLines"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(Vec(wordsPerLine, gen), addrWidth))

  // Parameters
  val tagWidth        = addrWidth - log2Ceil(numLines) - log2Ceil(wordsPerLine) - log2Ceil(dataWidth / 8)
  val indexWidth      = log2Ceil(numLines)
  val wordOffsetWidth = log2Ceil(wordsPerLine)
  val byteOffsetWidth = log2Ceil(dataWidth / 8)

  val lineWidth = dataWidth * wordsPerLine

  // Cache storage
  val dataArray = Mem(numLines, UInt(lineWidth.W))
  val metaArray = RegInit(VecInit(Seq.fill(numLines)(0.U.asTypeOf(new CacheEntry(tagWidth)))))

  // FSM state
  val state = RegInit(CacheFSMState.IDLE)

  // Registers
  val reqAddr       = RegInit(0.U(addrWidth.W))
  val reqData       = Reg(gen)
  val reqOp         = RegInit(CacheOp.READ)
  val reqTag        = RegInit(0.U(tagWidth.W))
  val reqIndex      = RegInit(0.U(indexWidth.W))
  val reqWordOffset = RegInit(0.U(wordOffsetWidth.W))

  // Current line data
  val currentLineData = Reg(UInt(lineWidth.W))

  // Write forwarding
  val lastWriteValid = RegInit(false.B)
  val lastWriteTag   = Reg(UInt(tagWidth.W))
  val lastWriteIndex = Reg(UInt(indexWidth.W))
  val lastWriteData  = Reg(UInt(lineWidth.W))

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

        val useForwardedData = lastWriteValid &&
          (lastWriteIndex === parsed.index) &&
          (lastWriteTag === parsed.tag)

        currentLineData := Mux(useForwardedData, lastWriteData, dataArray.read(parsed.index))

        state := CacheFSMState.COMPARE_TAG
      }
    }

    is(CacheFSMState.COMPARE_TAG) {
      when(hit) {
        // Cache hit
        when(reqOp === CacheOp.READ) {
          // Read hit - return the specific word
          upper.resp.valid     := true.B
          upper.resp.bits.data := extractWord(currentLineData, reqWordOffset)
          upper.resp.bits.hit  := true.B

          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
          }
        }.otherwise {
          // Write hit - update the specific word
          val updatedLine = updateWord(currentLineData, reqWordOffset, reqData)
          dataArray.write(reqIndex, updatedLine)
          metaArray(reqIndex).dirty := true.B

          // Update write forwarding
          lastWriteValid := true.B
          lastWriteTag   := reqTag
          lastWriteIndex := reqIndex
          lastWriteData  := updatedLine

          upper.resp.valid    := true.B
          upper.resp.bits.hit := true.B
          when(upper.resp.ready) {
            state := CacheFSMState.IDLE
          }
        }
      }.otherwise {
        // Cache miss
        when(lastWriteValid && (lastWriteIndex === reqIndex)) {
          lastWriteValid := false.B
        }

        when(meta.alloc && meta.dirty) {
          // Need to write back dirty line
          when(lastWriteValid && (lastWriteIndex === reqIndex) && (lastWriteTag === meta.tag)) {
            currentLineData := lastWriteData
          }
          memReqSent := false.B
          state      := CacheFSMState.WRITEBACK
        }.otherwise {
          // No write-back needed
          memReqSent := false.B
          state      := CacheFSMState.ALLOCATE
        }
      }
    }

    // TODO: The current impl is pending writeback state, there can be a more effective way to do this
    is(CacheFSMState.WRITEBACK) {
      // Write back dirty line to memory
      lower.req.valid     := !memReqSent
      lower.req.bits.op   := CacheOp.WRITE
      lower.req.bits.addr := Cat(meta.tag, reqIndex, 0.U((wordOffsetWidth + byteOffsetWidth).W))
      lower.req.bits.data := lineDataToVec(currentLineData)

      when(!memReqSent && lower.req.fire) {
        memReqSent := true.B
      }

      // Always assert ready to accept response
      lower.resp.ready := true.B

      when(memReqSent && lower.resp.fire) {
        metaArray(reqIndex).dirty := false.B
        memReqSent                := false.B
        state                     := CacheFSMState.ALLOCATE
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
          // Write allocate - update the word being written
          newLineData               := updateWord(receivedLineData, reqWordOffset, reqData)
          metaArray(reqIndex).dirty := true.B
        }.otherwise {
          newLineData               := receivedLineData
          metaArray(reqIndex).dirty := false.B
        }

        // Update cache
        dataArray.write(reqIndex, newLineData)
        metaArray(reqIndex).alloc := true.B
        metaArray(reqIndex).tag   := reqTag

        currentLineData := newLineData

        // Update write forwarding
        lastWriteValid := true.B
        lastWriteTag   := reqTag
        lastWriteIndex := reqIndex
        lastWriteData  := newLineData

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

object TestDirectMappedCache extends App {
  VerilogEmitter.parse(
    new DirectMappedCache(
      gen = UInt(32.W),
      addrWidth = 32,
      wordsPerLine = 4,
      numLines = 16
    ),
    "direct_mapped_cache.sv",
    info = true,
    lowering = true
  )
}
