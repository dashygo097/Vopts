package vopts.mem.cache

import vopts.utils.CombTree
import chisel3._
import chisel3.util._

class SetAssociativeStreamingCache[T <: Data](
  gen: T,
  addrWidth: Int,
  wordsPerLine: Int,
  linesPerWay: Int,
  numWays: Int,
  replPolicy: ReplacementPolicy,
) extends Module {

  val numSets   = linesPerWay
  val dataWidth = gen.getWidth

  override def desiredName: String = s"set_associative_cache_${addrWidth}x${dataWidth}x${wordsPerLine}x${numSets}x$numWays"

  val upper = IO(Flipped(new CacheIO(gen, addrWidth)))
  val lower = IO(new CacheIO(gen, addrWidth))

  private val rawIndexWidth      = log2Ceil(numSets)
  private val rawWordOffsetWidth = log2Ceil(wordsPerLine)
  private val byteOffsetWidth    = log2Ceil(dataWidth / 8)

  val indexWidth      = rawIndexWidth.max(1)
  val wordOffsetWidth = rawWordOffsetWidth.max(1)
  val tagWidth        = addrWidth - rawIndexWidth - rawWordOffsetWidth - byteOffsetWidth
  val lineWidth       = dataWidth * wordsPerLine

  val wayWidth = log2Ceil(numWays).max(1)

  val dataArray = Seq.fill(numWays)(Mem(numSets, UInt(lineWidth.W)))
  val metaArray = RegInit(VecInit(Seq.fill(numWays)(VecInit(Seq.fill(numSets)(0.U.asTypeOf(new CacheEntry(tagWidth)))))))

  val dataWriteValid = WireDefault(false.B)
  val dataWriteWay   = WireDefault(0.U(wayWidth.W))
  val dataWriteIndex = WireDefault(0.U(indexWidth.W))
  val dataWriteData  = WireDefault(0.U(lineWidth.W))

  for (w <- 0 until numWays)
    when(dataWriteValid && dataWriteWay === w.U) {
      dataArray(w).write(dataWriteIndex, dataWriteData)
    }

  val replStates   = Seq.fill(numSets)(ReplacementPolicyState(replPolicy, numWays))
  val victimWayReg = RegInit(VecInit(Seq.fill(numSets)(0.U(wayWidth.W))))
  for (s <- 0 until numSets) victimWayReg(s) := replStates(s).getVictim()

  val reqValid = RegInit(false.B)
  val reqAddr  = RegInit(0.U(addrWidth.W))
  val reqData  = Reg(gen)
  val reqStrb  = RegInit(0.U((dataWidth / 8).W))
  val reqOp    = RegInit(CacheOp.READ)

  val s1Valid      = RegInit(false.B)
  val s1Addr       = RegInit(0.U(addrWidth.W))
  val s1Data       = Reg(gen)
  val s1Strb       = RegInit(0.U((dataWidth / 8).W))
  val s1Op         = RegInit(CacheOp.READ)
  val s1Tag        = RegInit(0.U(tagWidth.W))
  val s1Index      = RegInit(0.U(indexWidth.W))
  val s1WordOffset = RegInit(0.U(wordOffsetWidth.W))
  val s1VictimWay  = RegInit(0.U(wayWidth.W))
  val s1WayData    = Reg(Vec(numWays, UInt(lineWidth.W)))
  val s1WayMeta    = Reg(Vec(numWays, new CacheEntry(tagWidth)))

  val waitValid      = RegInit(false.B)
  val waitHit        = RegInit(false.B)
  val waitData       = Reg(gen)
  val waitStrb       = RegInit(0.U((dataWidth / 8).W))
  val waitOp         = RegInit(CacheOp.READ)
  val waitWordOffset = RegInit(0.U(wordOffsetWidth.W))
  val waitWriteDone  = RegInit(false.B)

  val lastWriteValid = RegInit(false.B)
  val lastWriteIndex = RegInit(0.U(indexWidth.W))
  val lastWriteWay   = RegInit(0.U(wayWidth.W))
  val lastWriteData  = RegInit(0.U(lineWidth.W))

  val MSHR_IDLE = 0.U(2.W)
  val MSHR_WB   = 1.U(2.W)
  val MSHR_FILL = 2.U(2.W)

  val mshrState     = RegInit(MSHR_IDLE)
  val mshrReqSent   = RegInit(false.B)
  val mshrTag       = RegInit(0.U(tagWidth.W))
  val mshrVictimTag = RegInit(0.U(tagWidth.W))
  val mshrIndex     = RegInit(0.U(indexWidth.W))
  val mshrWay       = RegInit(0.U(wayWidth.W))
  val mshrCw        = RegInit(0.U(wordOffsetWidth.W))
  val mshrDirty     = RegInit(false.B)

  val reqOffset = RegInit(0.U(wordOffsetWidth.W))

  val wbData        = Reg(Vec(wordsPerLine, gen))
  val fillValid     = RegInit(VecInit(Seq.fill(wordsPerLine)(false.B)))
  val fillData      = Reg(Vec(wordsPerLine, gen))
  val fillDirtyStrb = RegInit(VecInit(Seq.fill(wordsPerLine)(0.U((dataWidth / 8).W))))

  val fullStrb = Fill(dataWidth / 8, 1.U(1.W))

  def priorityWay(bits: Seq[Bool]): UInt = {
    val raw = if (numWays == 1) 0.U(1.W) else PriorityEncoder(VecInit(bits))
    raw.pad(wayWidth)
  }

  def makeAddr(tag: UInt, index: UInt, offset: UInt): UInt =
    if (rawIndexWidth > 0 && rawWordOffsetWidth > 0) {
      Cat(tag, index(rawIndexWidth - 1, 0), offset(rawWordOffsetWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else if (rawIndexWidth > 0 && rawWordOffsetWidth == 0) {
      Cat(tag, index(rawIndexWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else if (rawIndexWidth == 0 && rawWordOffsetWidth > 0) {
      Cat(tag, offset(rawWordOffsetWidth - 1, 0), 0.U(byteOffsetWidth.W))
    } else {
      Cat(tag, 0.U(byteOffsetWidth.W))
    }

  def parseAddr(addr: UInt) = new {
    val tag        = addr(addrWidth - 1, rawIndexWidth + rawWordOffsetWidth + byteOffsetWidth)
    val index      = if (rawIndexWidth > 0) addr(rawIndexWidth + rawWordOffsetWidth + byteOffsetWidth - 1, rawWordOffsetWidth + byteOffsetWidth) else 0.U(indexWidth.W)
    val wordOffset = if (rawWordOffsetWidth > 0) addr(rawWordOffsetWidth + byteOffsetWidth - 1, byteOffsetWidth) else 0.U(wordOffsetWidth.W)
  }

  def extractWord(lineData: UInt, wordOffset: UInt): T = {
    val words = VecInit((0 until wordsPerLine).map { i =>
      lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)
    })
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

  def lineDataToVec(lineData: UInt): Vec[T] =
    VecInit((0 until wordsPerLine).map { i =>
      lineData((i + 1) * dataWidth - 1, i * dataWidth).asTypeOf(gen)
    })

  def vecToLineData(vec: Vec[T]): UInt = vec.asUInt

  def updateReplPolicy(setIdx: UInt, way: UInt, isHit: Bool): Unit =
    for (s <- 0 until numSets)
      when(s.U === setIdx) {
        replStates(s).update(way, isHit)
      }

  def wrapInc(x: UInt): UInt = Mux(x === (wordsPerLine - 1).U, 0.U, x + 1.U)

  def wordReady(wordOffset: UInt): Bool = fillValid(wordOffset) || fillDirtyStrb(wordOffset) === fullStrb || (mshrState === MSHR_FILL && lower.resp.valid && lower.resp.ready && currentRespOffset === wordOffset)

  def readMshrWord(wordOffset: UInt): T = {
    val arriving = mshrState === MSHR_FILL && lower.resp.valid && lower.resp.ready && currentRespOffset === wordOffset
    val merged   = applyStrb(fillData(wordOffset).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(wordOffset)).asUInt).asTypeOf(gen)
    Mux(arriving, merged, fillData(wordOffset))
  }

  val upperReqPipe = Module(new Queue(chiselTypeOf(upper.req.bits), 4, pipe = true, flow = true))

  upperReqPipe.io.enq.valid := upper.req.valid
  upperReqPipe.io.enq.bits  := upper.req.bits
  upper.req.ready           := upperReqPipe.io.enq.ready
  upperReqPipe.io.deq.ready := false.B

  val lowerRespReady     = mshrState === MSHR_WB || mshrState === MSHR_FILL
  val mshrFillArriving   = mshrState === MSHR_FILL && lower.resp.valid && lowerRespReady
  val mshrFillCommitFire = mshrFillArriving && lower.resp.bits.last
  val currentRespOffset  = reqOffset

  val cpuWriteToMshrValid  = WireInit(false.B)
  val cpuWriteToMshrOffset = WireInit(0.U(wordOffsetWidth.W))
  val cpuWriteToMshrData   = WireInit(0.U.asTypeOf(gen))
  val cpuWriteToMshrStrb   = WireInit(0.U((dataWidth / 8).W))

  val s1HitBits        = VecInit((0 until numWays).map { w =>
    s1WayMeta(w).alloc && s1WayMeta(w).tag === s1Tag
  })
  val s1CacheHit       = CombTree.orTree((0 until numWays).map(w => s1HitBits(w)))
  val s1HitWay         = priorityWay((0 until numWays).map(w => s1HitBits(w)))
  val s1SelectedWay    = Mux(s1CacheHit, s1HitWay, s1VictimWay)
  val s1HitLineData    = s1WayData(s1HitWay)
  val s1VictimLineData = s1WayData(s1VictimWay)
  val s1VictimMeta     = s1WayMeta(s1VictimWay)

  val s1IsMshrHit         = mshrState =/= MSHR_IDLE && mshrTag === s1Tag && mshrIndex === s1Index
  val s1SameSetAsMshr     = mshrState =/= MSHR_IDLE && mshrIndex === s1Index
  val s1VictimWayHazard   = s1SameSetAsMshr && s1SelectedWay === mshrWay && !s1IsMshrHit
  val s1SameSetMissHazard = s1SameSetAsMshr && !s1CacheHit && !s1IsMshrHit
  val s1MshrConflict      = s1VictimWayHazard || s1SameSetMissHazard

  val s1ReqWordReady     = wordReady(s1WordOffset)
  val s1MshrReadWord     = readMshrWord(s1WordOffset)
  val s1WriteUpdatedLine = updateWord(s1HitLineData, s1WordOffset, s1Data, s1Strb)

  val s1CacheReadRespValid  = s1Valid && !s1MshrConflict && s1CacheHit && s1Op === CacheOp.READ
  val s1CacheWriteRespValid = s1Valid && !s1MshrConflict && s1CacheHit && s1Op =/= CacheOp.READ && !mshrFillCommitFire
  val s1MshrReadRespValid   = s1Valid && !s1MshrConflict && !s1CacheHit && s1IsMshrHit && s1ReqWordReady && s1Op === CacheOp.READ
  val s1MshrWriteRespValid  = s1Valid && !s1MshrConflict && !s1CacheHit && s1IsMshrHit && s1ReqWordReady && s1Op =/= CacheOp.READ

  val s1RespValid = s1CacheReadRespValid || s1CacheWriteRespValid || s1MshrReadRespValid || s1MshrWriteRespValid
  val s1RespData  = Mux(s1Op === CacheOp.READ, Mux(s1CacheHit, extractWord(s1HitLineData, s1WordOffset), s1MshrReadWord), 0.U.asTypeOf(gen))
  val s1RespHit   = s1CacheHit || s1IsMshrHit
  val s1RespFire  = s1RespValid && upper.resp.ready

  val s1CacheReadRespFire  = s1CacheReadRespValid && upper.resp.ready
  val s1CacheWriteRespFire = s1CacheWriteRespValid && upper.resp.ready
  val s1MshrReadRespFire   = s1MshrReadRespValid && upper.resp.ready
  val s1MshrWriteRespFire  = s1MshrWriteRespValid && upper.resp.ready

  val s1MissCandidate   = s1Valid && !s1MshrConflict && !s1CacheHit && !s1IsMshrHit
  val s1Replay          = s1Valid && (s1MshrConflict || (s1MissCandidate && mshrState =/= MSHR_IDLE))
  val s1AllocateMiss    = s1MissCandidate && mshrState === MSHR_IDLE
  val s1MshrHitToWait   = s1Valid && !s1MshrConflict && !s1CacheHit && s1IsMshrHit && !s1ReqWordReady
  val s1MshrWriteToWait = s1MshrWriteRespValid && !upper.resp.ready

  val waitReqWordReady   = wordReady(waitWordOffset)
  val waitMshrReadWord   = readMshrWord(waitWordOffset)
  val waitWriteApply     = waitValid && waitOp =/= CacheOp.READ && waitReqWordReady && !waitWriteDone
  val waitReadRespValid  = waitValid && waitOp === CacheOp.READ && waitReqWordReady
  val waitWriteRespValid = waitValid && waitOp =/= CacheOp.READ && waitReqWordReady && (waitWriteDone || waitWriteApply)
  val waitRespValid      = waitReadRespValid || waitWriteRespValid
  val waitRespData       = Mux(waitOp === CacheOp.READ, waitMshrReadWord, 0.U.asTypeOf(gen))
  val waitRespFire       = waitRespValid && upper.resp.ready

  upper.resp.valid     := waitRespValid || (!waitValid && s1RespValid)
  upper.resp.bits.data := Mux(waitRespValid, waitRespData, s1RespData)
  upper.resp.bits.hit  := Mux(waitRespValid, waitHit, s1RespHit)
  upper.resp.bits.last := true.B

  lower.req.valid     := false.B
  lower.req.bits.addr := 0.U
  lower.req.bits.data := 0.U.asTypeOf(gen)
  lower.req.bits.op   := CacheOp.READ
  lower.req.bits.strb := fullStrb
  lower.resp.ready    := lowerRespReady

  val launchCurrentAddr = Mux(reqValid, reqAddr, upperReqPipe.io.deq.bits.addr)
  val launchCurrentData = Mux(reqValid, reqData, upperReqPipe.io.deq.bits.data)
  val launchCurrentStrb = Mux(reqValid, reqStrb, upperReqPipe.io.deq.bits.strb)
  val launchCurrentOp   = Mux(reqValid, reqOp, upperReqPipe.io.deq.bits.op)
  val launchParsed      = parseAddr(launchCurrentAddr)

  val s0WayMeta    = Wire(Vec(numWays, new CacheEntry(tagWidth)))
  val s0RawWayData = Wire(Vec(numWays, UInt(lineWidth.W)))
  val s0WayData    = Wire(Vec(numWays, UInt(lineWidth.W)))

  for (w <- 0 until numWays) {
    val rawMeta                 = metaArray(w)(launchParsed.index)
    val currentWriteMetaForward = s1CacheWriteRespFire && s1Index === launchParsed.index && s1HitWay === w.U
    s0WayMeta(w) := rawMeta
    when(currentWriteMetaForward) {
      s0WayMeta(w).alloc := true.B
      s0WayMeta(w).tag   := s1Tag
      s0WayMeta(w).dirty := true.B
    }
  }

  for (w <- 0 until numWays)
    s0RawWayData(w) := dataArray(w).read(launchParsed.index)

  for (w <- 0 until numWays) {
    val lastWriteForward    = lastWriteValid && lastWriteIndex === launchParsed.index && lastWriteWay === w.U
    val currentWriteForward = s1CacheWriteRespFire && s1Index === launchParsed.index && s1HitWay === w.U
    s0WayData(w) := Mux(currentWriteForward, s1WriteUpdatedLine, Mux(lastWriteForward, lastWriteData, s0RawWayData(w)))
  }

  val s0InvalidBits = VecInit((0 until numWays).map(w => !s0WayMeta(w).alloc))
  val s0HasInvalid  = CombTree.orTree((0 until numWays).map(w => s0InvalidBits(w)))
  val s0InvalidWay  = priorityWay((0 until numWays).map(w => s0InvalidBits(w)))
  val s0VictimWay   = Mux(s0HasInvalid, s0InvalidWay, victimWayReg(launchParsed.index))

  val launchReqValid = reqValid || upperReqPipe.io.deq.valid
  val s1AllowsLaunch = !waitValid && !mshrFillCommitFire && (!s1Valid || s1RespFire)
  val launchFire     = launchReqValid && s1AllowsLaunch

  upperReqPipe.io.deq.ready := launchFire && !reqValid

  when(launchFire && reqValid) {
    reqValid := false.B
  }

  when(s1CacheReadRespFire) {
    updateReplPolicy(s1Index, s1HitWay, true.B)
  }

  when(s1CacheWriteRespFire) {
    dataWriteValid := true.B
    dataWriteWay   := s1HitWay
    dataWriteIndex := s1Index
    dataWriteData  := s1WriteUpdatedLine

    for (w <- 0 until numWays)
      when(s1HitWay === w.U) {
        metaArray(w)(s1Index).alloc := true.B
        metaArray(w)(s1Index).tag   := s1Tag
        metaArray(w)(s1Index).dirty := true.B
      }

    lastWriteValid := true.B
    lastWriteIndex := s1Index
    lastWriteWay   := s1HitWay
    lastWriteData  := s1WriteUpdatedLine

    updateReplPolicy(s1Index, s1HitWay, true.B)
  }

  when(s1MshrReadRespFire) {
    updateReplPolicy(s1Index, mshrWay, true.B)
  }

  when(s1MshrWriteRespValid) {
    cpuWriteToMshrValid  := true.B
    cpuWriteToMshrOffset := s1WordOffset
    cpuWriteToMshrData   := s1Data
    cpuWriteToMshrStrb   := s1Strb
  }

  when(s1MshrWriteRespFire) {
    updateReplPolicy(s1Index, mshrWay, true.B)
  }

  when(waitWriteApply) {
    cpuWriteToMshrValid  := true.B
    cpuWriteToMshrOffset := waitWordOffset
    cpuWriteToMshrData   := waitData
    cpuWriteToMshrStrb   := waitStrb
    waitWriteDone        := true.B
  }

  when(waitRespFire) {
    updateReplPolicy(mshrIndex, mshrWay, true.B)
    waitValid     := false.B
    waitWriteDone := false.B
  }

  when(s1Replay) {
    reqValid := true.B
    reqAddr  := s1Addr
    reqData  := s1Data
    reqStrb  := s1Strb
    reqOp    := s1Op
    s1Valid  := false.B
  }

  when(s1AllocateMiss) {
    updateReplPolicy(s1Index, s1VictimWay, false.B)

    mshrTag       := s1Tag
    mshrIndex     := s1Index
    mshrWay       := s1VictimWay
    mshrCw        := s1WordOffset
    mshrDirty     := false.B
    mshrVictimTag := s1VictimMeta.tag
    mshrReqSent   := false.B

    when(s1VictimMeta.alloc && s1VictimMeta.dirty) {
      mshrState := MSHR_WB
      wbData    := lineDataToVec(s1VictimLineData)
      reqOffset := 0.U
    }.otherwise {
      mshrState := MSHR_FILL
      reqOffset := s1WordOffset
    }

    fillValid     := VecInit(Seq.fill(wordsPerLine)(false.B))
    fillDirtyStrb := VecInit(Seq.fill(wordsPerLine)(0.U((dataWidth / 8).W)))

    waitValid      := true.B
    waitHit        := false.B
    waitData       := s1Data
    waitStrb       := s1Strb
    waitOp         := s1Op
    waitWordOffset := s1WordOffset
    waitWriteDone  := false.B

    when(lastWriteValid && lastWriteIndex === s1Index && lastWriteWay === s1VictimWay) {
      lastWriteValid := false.B
    }

    s1Valid := false.B
  }

  when(s1MshrHitToWait) {
    waitValid      := true.B
    waitHit        := true.B
    waitData       := s1Data
    waitStrb       := s1Strb
    waitOp         := s1Op
    waitWordOffset := s1WordOffset
    waitWriteDone  := false.B
    s1Valid        := false.B
  }

  when(s1MshrWriteToWait) {
    waitValid      := true.B
    waitHit        := true.B
    waitData       := s1Data
    waitStrb       := s1Strb
    waitOp         := s1Op
    waitWordOffset := s1WordOffset
    waitWriteDone  := true.B
    s1Valid        := false.B
  }

  when(s1RespFire && !launchFire) {
    s1Valid := false.B
  }

  when(launchFire) {
    s1Valid      := true.B
    s1Addr       := launchCurrentAddr
    s1Data       := launchCurrentData
    s1Strb       := launchCurrentStrb
    s1Op         := launchCurrentOp
    s1Tag        := launchParsed.tag
    s1Index      := launchParsed.index
    s1WordOffset := launchParsed.wordOffset
    s1VictimWay  := s0VictimWay
    s1WayData    := s0WayData
    s1WayMeta    := s0WayMeta
  }

  when(cpuWriteToMshrValid) {
    mshrDirty := true.B
  }

  val finalLine = Wire(Vec(wordsPerLine, gen))

  for (i <- 0 until wordsPerLine) {
    val isResp   = mshrFillArriving && currentRespOffset === i.U
    val isCpu    = cpuWriteToMshrValid && cpuWriteToMshrOffset === i.U
    val memData  = lower.resp.bits.data.asUInt
    val cpuData  = cpuWriteToMshrData.asUInt
    val oldWord  = fillData(i).asUInt
    val withMem  = applyStrb(oldWord, memData, (~fillDirtyStrb(i)).asUInt)
    val withCpu  = applyStrb(oldWord, cpuData, cpuWriteToMshrStrb)
    val withBoth = applyStrb(withMem, cpuData, cpuWriteToMshrStrb)
    finalLine(i) := Mux(isResp && isCpu, withBoth.asTypeOf(gen), Mux(isResp, withMem.asTypeOf(gen), Mux(isCpu, withCpu.asTypeOf(gen), fillData(i))))
  }

  for (i <- 0 until wordsPerLine) {
    val isRespTarget = mshrFillArriving && currentRespOffset === i.U
    val isCpuTarget  = cpuWriteToMshrValid && cpuWriteToMshrOffset === i.U

    when(isCpuTarget && isRespTarget) {
      fillData(i)      := applyStrb(applyStrb(fillData(i).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(i)).asUInt), cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillValid(i)     := true.B
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isCpuTarget) {
      fillData(i)      := applyStrb(fillData(i).asUInt, cpuWriteToMshrData.asUInt, cpuWriteToMshrStrb).asTypeOf(gen)
      fillDirtyStrb(i) := fillDirtyStrb(i) | cpuWriteToMshrStrb
    }.elsewhen(isRespTarget) {
      fillData(i)  := applyStrb(fillData(i).asUInt, lower.resp.bits.data.asUInt, (~fillDirtyStrb(i)).asUInt).asTypeOf(gen)
      fillValid(i) := true.B
    }
  }

  switch(mshrState) {
    is(MSHR_WB) {
      lower.req.valid     := true.B
      lower.req.bits.op   := CacheOp.WRITE
      lower.req.bits.addr := makeAddr(mshrVictimTag, mshrIndex, reqOffset)
      lower.req.bits.data := wbData(reqOffset)
      lower.req.bits.strb := fullStrb

      when(lower.req.fire) {
        reqOffset := wrapInc(reqOffset)
      }

      when(lower.resp.fire && lower.resp.bits.last) {
        mshrState   := MSHR_FILL
        reqOffset   := mshrCw
        mshrReqSent := false.B
      }
    }

    is(MSHR_FILL) {
      lower.req.valid     := !mshrReqSent
      lower.req.bits.op   := CacheOp.READ
      lower.req.bits.addr := makeAddr(mshrTag, mshrIndex, mshrCw)
      lower.req.bits.data := 0.U.asTypeOf(gen)
      lower.req.bits.strb := fullStrb

      when(lower.req.fire) {
        mshrReqSent := true.B
      }

      when(mshrFillArriving) {
        reqOffset := wrapInc(reqOffset)

        when(lower.resp.bits.last) {
          val committedLine = vecToLineData(finalLine)
          val newMeta       = Wire(new CacheEntry(tagWidth))

          newMeta.alloc := true.B
          newMeta.tag   := mshrTag
          newMeta.dirty := mshrDirty || cpuWriteToMshrValid

          dataWriteValid := true.B
          dataWriteWay   := mshrWay
          dataWriteIndex := mshrIndex
          dataWriteData  := committedLine

          for (w <- 0 until numWays)
            when(mshrWay === w.U) {
              metaArray(w)(mshrIndex) := newMeta
            }

          lastWriteValid := true.B
          lastWriteIndex := mshrIndex
          lastWriteWay   := mshrWay
          lastWriteData  := committedLine

          mshrState   := MSHR_IDLE
          mshrReqSent := false.B
        }
      }
    }
  }
}
