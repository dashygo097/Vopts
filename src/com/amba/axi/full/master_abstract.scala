package com.amba

import chisel3._
import chisel3.util._

abstract class AXIFullMaster(
  val addrWidth: Int,
  val dataWidth: Int,
  val idWidth: Int,
  val userWidth: Int = 0
) extends Module {
  protected def getExtAXIName: String = "M_AXI"

  val ext_axi = IO(new AXIFullMasterExternalIO(addrWidth, dataWidth, idWidth, userWidth))
    .suggestName(getExtAXIName)
  val axi     = Wire(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  // State Encoding
  protected val IDLE       = 0.U(3.W)
  protected val WRITE_ADDR = 1.U(3.W)
  protected val WRITE_DATA = 2.U(3.W)
  protected val WRITE_RESP = 3.U(3.W)
  protected val READ_ADDR  = 4.U(3.W)
  protected val READ_DATA  = 5.U(3.W)

  // Parameters
  protected val addr_lsb   = log2Ceil(dataWidth / 8)
  protected val strb_width = dataWidth / 8

  // Signals
  protected val axi_awaddr   = RegInit(0.U(addrWidth.W))
  protected val axi_awvalid  = RegInit(false.B)
  protected val axi_awid     = RegInit(0.U(idWidth.W))
  protected val axi_awlen    = RegInit(0.U(8.W))
  protected val axi_awsize   = RegInit(log2Ceil(dataWidth / 8).U(3.W))
  protected val axi_awburst  = RegInit(1.U(2.W)) // INCR
  protected val axi_awlock   = RegInit(false.B)
  protected val axi_awcache  = RegInit(0.U(4.W))
  protected val axi_awprot   = RegInit(0.U(3.W))
  protected val axi_awqos    = RegInit(0.U(4.W))
  protected val axi_awregion = RegInit(0.U(4.W))
  protected val axi_awuser   = RegInit(0.U(userWidth.W))

  protected val axi_wdata  = RegInit(0.U(dataWidth.W))
  protected val axi_wstrb  = RegInit(Fill(strb_width, 1.U))
  protected val axi_wvalid = RegInit(false.B)
  protected val axi_wlast  = RegInit(false.B)
  protected val axi_wid    = RegInit(0.U(idWidth.W))
  protected val axi_wuser  = RegInit(0.U(userWidth.W))

  protected val axi_bready = RegInit(false.B)

  protected val axi_araddr   = RegInit(0.U(addrWidth.W))
  protected val axi_arvalid  = RegInit(false.B)
  protected val axi_arid     = RegInit(0.U(idWidth.W))
  protected val axi_arlen    = RegInit(0.U(8.W))
  protected val axi_arsize   = RegInit(log2Ceil(dataWidth / 8).U(3.W))
  protected val axi_arburst  = RegInit(1.U(2.W)) // INCR
  protected val axi_arlock   = RegInit(false.B)
  protected val axi_arcache  = RegInit(0.U(4.W))
  protected val axi_arprot   = RegInit(0.U(3.W))
  protected val axi_arqos    = RegInit(0.U(4.W))
  protected val axi_arregion = RegInit(0.U(4.W))
  protected val axi_aruser   = RegInit(0.U(userWidth.W))

  protected val axi_rready = RegInit(false.B)

  // Burst counters
  protected val write_beat_count = RegInit(0.U(8.W))
  protected val read_beat_count  = RegInit(0.U(8.W))

  // I/O Connections
  axi.aw.bits.addr   := axi_awaddr
  axi.aw.bits.prot   := axi_awprot
  axi.aw.bits.id     := axi_awid
  axi.aw.bits.len    := axi_awlen
  axi.aw.bits.size   := axi_awsize
  axi.aw.bits.burst  := axi_awburst
  axi.aw.bits.lock   := axi_awlock
  axi.aw.bits.cache  := axi_awcache
  axi.aw.bits.qos    := axi_awqos
  axi.aw.bits.region := axi_awregion
  axi.aw.bits.user   := axi_awuser
  axi.aw.valid       := axi_awvalid

  axi.w.bits.data := axi_wdata
  axi.w.bits.strb := axi_wstrb
  axi.w.bits.last := axi_wlast
  axi.w.bits.id   := axi_wid
  axi.w.bits.user := axi_wuser
  axi.w.valid     := axi_wvalid

  axi.b.ready := axi_bready

  axi.ar.bits.addr   := axi_araddr
  axi.ar.bits.prot   := axi_arprot
  axi.ar.bits.id     := axi_arid
  axi.ar.bits.len    := axi_arlen
  axi.ar.bits.size   := axi_arsize
  axi.ar.bits.burst  := axi_arburst
  axi.ar.bits.lock   := axi_arlock
  axi.ar.bits.cache  := axi_arcache
  axi.ar.bits.qos    := axi_arqos
  axi.ar.bits.region := axi_arregion
  axi.ar.bits.user   := axi_aruser
  axi.ar.valid       := axi_arvalid

  axi.r.ready := axi_rready

  protected val state = RegInit(IDLE)

  // Abstract Callback Methods
  protected def onIDLE(): Unit                 = {}
  protected def onWriteAddr(): Unit            = {}
  protected def onWriteData(): Unit            = {}
  protected def onWriteResp(): Unit            = {}
  protected def onReadAddr(): Unit             = {}
  protected def onReadData(): Unit             = {}
  protected def handleAdditionalStates(): Unit = {}

  protected def setup(): Unit = {
    switch(state) {
      is(IDLE) {
        axi_awvalid      := false.B
        axi_wvalid       := false.B
        axi_bready       := false.B
        axi_arvalid      := false.B
        axi_rready       := false.B
        write_beat_count := 0.U
        read_beat_count  := 0.U
        onIDLE()
      }

      is(WRITE_ADDR) {
        when(axi.aw.ready && axi_awvalid) {
          state            := WRITE_DATA
          axi_awvalid      := false.B
          axi_wvalid       := true.B
          write_beat_count := 0.U
          onWriteAddr()
        }
      }

      is(WRITE_DATA) {
        when(axi.w.ready && axi_wvalid) {
          write_beat_count := write_beat_count + 1.U

          when(write_beat_count === axi_awlen) {
            state      := WRITE_RESP
            axi_wvalid := false.B
            axi_wlast  := false.B
            axi_bready := true.B
          }.otherwise {
            axi_wlast := (write_beat_count + 1.U) === axi_awlen
            onWriteData()
          }
        }
      }

      is(WRITE_RESP) {
        when(axi.b.valid && axi_bready) {
          state      := IDLE
          axi_bready := false.B
          onWriteResp()
        }
      }

      is(READ_ADDR) {
        when(axi.ar.ready && axi_arvalid) {
          state           := READ_DATA
          axi_arvalid     := false.B
          axi_rready      := true.B
          read_beat_count := 0.U
          onReadAddr()
        }
      }

      is(READ_DATA) {
        when(axi.r.valid && axi_rready) {
          read_beat_count := read_beat_count + 1.U

          when(axi.r.bits.last) {
            state      := IDLE
            axi_rready := false.B
          }

          onReadData()
        }
      }
    }

    handleAdditionalStates()
  }

  ext_axi.connect(axi)
}
