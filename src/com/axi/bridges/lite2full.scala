package com.axi

import chisel3._
import chisel3.util._

class AXILite2FullBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0)
    extends Module {
  override def desiredName: String =
    s"axi_lite2full_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"
  require(dataWidth % 8 == 0, "Data width must be a multiple of 8")

  val lite = IO(new AXILiteSlaveIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val full = IO(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("M_AXI")

  // Write Address Channel
  full.aw.bits.addr   := lite.aw.bits.addr
  full.aw.bits.prot   := lite.aw.bits.prot
  full.aw.bits.id     := 0.U
  full.aw.bits.len    := 0.U // Single transfer
  full.aw.bits.size   := log2Ceil(dataWidth / 8).U
  full.aw.bits.burst  := 1.U // INCR burst type
  full.aw.bits.lock   := false.B
  full.aw.bits.cache  := 0.U
  full.aw.bits.qos    := 0.U
  full.aw.bits.region := 0.U
  full.aw.bits.user   := 0.U
  full.aw.valid       := lite.aw.valid
  lite.aw.ready       := full.aw.ready

  // Write Data Channel
  full.w.bits.data := lite.w.bits.data
  full.w.bits.strb := lite.w.bits.strb
  full.w.bits.last := true.B // Always last for single transfer
  full.w.bits.id   := 0.U
  full.w.bits.user := 0.U
  full.w.valid     := lite.w.valid
  lite.w.ready     := full.w.ready

  // Write Response Channel
  lite.b.bits.resp := full.b.bits.resp
  lite.b.valid     := full.b.valid
  full.b.ready     := lite.b.ready

  // Read Address Channel
  full.ar.bits.addr   := lite.ar.bits.addr
  full.ar.bits.prot   := lite.ar.bits.prot
  full.ar.bits.id     := 0.U
  full.ar.bits.len    := 0.U // Single transfer
  full.ar.bits.size   := log2Ceil(dataWidth / 8).U
  full.ar.bits.burst  := 1.U // INCR burst type
  full.ar.bits.lock   := false.B
  full.ar.bits.cache  := 0.U
  full.ar.bits.qos    := 0.U
  full.ar.bits.region := 0.U
  full.ar.bits.user   := 0.U
  full.ar.valid       := lite.ar.valid
  lite.ar.ready       := full.ar.ready

  // Read Data Channel
  lite.r.bits.data := full.r.bits.data
  lite.r.bits.resp := full.r.bits.resp
  lite.r.valid     := full.r.valid
  full.r.ready     := lite.r.ready
}

object AXILite2FullBridge {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXILite2FullBridge =
    new AXILite2FullBridge(addrWidth, dataWidth, idWidth, userWidth)
}
