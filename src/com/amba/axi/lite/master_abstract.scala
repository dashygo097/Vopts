package com.amba

import chisel3._
import chisel3.util._

abstract class AXILiteMaster(
  val addrWidth: Int,
  val dataWidth: Int
) extends Module {
  protected def getExtAXIName: String = "M_AXI"

  val ext_axi = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth))
    .suggestName(getExtAXIName)
  val axi     = Wire(new AXILiteMasterIO(addrWidth, dataWidth))

  // State Encoding
  protected val IDLE       = 0.U(3.W)
  protected val WRITE_ADDR = 1.U(3.W)
  protected val WRITE_DATA = 2.U(3.W)
  protected val WRITE_RESP = 3.U(3.W)
  protected val READ_ADDR  = 4.U(3.W)
  protected val READ_DATA  = 5.U(3.W)

  // Parameters
  protected val addr_lsb     = log2Ceil(dataWidth / 8)
  protected val opt_mem_size = dataWidth - log2Ceil(dataWidth / 8)

  // Signals
  protected val axi_awaddr  = RegInit(0.U(addrWidth.W))
  protected val axi_awvalid = RegInit(false.B)
  protected val axi_awprot  = RegInit(0.U(3.W))
  protected val axi_wdata   = RegInit(0.U(dataWidth.W))
  protected val axi_wvalid  = RegInit(false.B)
  protected val axi_bready  = RegInit(false.B)
  protected val axi_araddr  = RegInit(0.U(addrWidth.W))
  protected val axi_arvalid = RegInit(false.B)
  protected val axi_arprot  = RegInit(0.U(3.W))
  protected val axi_rready  = RegInit(false.B)

  axi.aw.bits.addr := axi_awaddr
  axi.aw.bits.prot := axi_awprot
  axi.aw.valid     := axi_awvalid
  axi.w.bits.data  := axi_wdata
  axi.w.bits.strb  := Fill(dataWidth / 8, 1.U)
  axi.w.valid      := axi_wvalid
  axi.b.ready      := axi_bready
  axi.ar.bits.addr := axi_araddr
  axi.ar.bits.prot := axi_arprot
  axi.ar.valid     := axi_arvalid
  axi.r.ready      := axi_rready

  protected val state = RegInit(IDLE)

  // Abstract Callback Methods
  protected def onIDLE(): Unit      = {}
  protected def onWriteAddr(): Unit = {}
  protected def onWriteData(): Unit = {}
  protected def onWriteResp(): Unit = {}
  protected def onReadAddr(): Unit  = {}
  protected def onReadData(): Unit  = {}

  // Additional state handlers can be overridden
  protected def handleAdditionalStates(): Unit = {}

  protected def setup(): Unit = {
    switch(state) {
      is(IDLE) {
        axi_awvalid := false.B
        axi_wvalid  := false.B
        axi_bready  := false.B
        axi_arvalid := false.B
        axi_rready  := false.B
        onIDLE()
      }

      is(WRITE_ADDR) {
        when(axi.aw.ready && axi_awvalid) {
          state       := WRITE_DATA
          axi_awvalid := false.B
          axi_wvalid  := true.B
          onWriteAddr()
        }
      }

      is(WRITE_DATA) {
        when(axi.w.ready && axi_wvalid) {
          state      := WRITE_RESP
          axi_wvalid := false.B
          axi_bready := true.B
          onWriteData()
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
          state       := READ_DATA
          axi_arvalid := false.B
          axi_rready  := true.B
          onReadAddr()
        }
      }

      is(READ_DATA) {
        when(axi.r.valid && axi_rready) {
          state      := IDLE
          axi_rready := false.B
          onReadData()
        }
      }
    }

    // Allow subclasses to handle additional states
    handleAdditionalStates()
  }

  ext_axi.connect(axi)
}
