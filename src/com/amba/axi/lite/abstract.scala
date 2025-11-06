package com.amba

import chisel3._

abstract class AXILiteSlave(val addrWidth: Int, val dataWidth: Int) extends Module {
  protected def getExtAXIName: String = "S_AXI" 

  val ext_axi = IO(new AXILiteSlaveExternalIO(addrWidth, dataWidth)).suggestName(getExtAXIName)
  val axi = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  // Signals
  val axi_awready = RegInit(false.B)
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_wready  = RegInit(false.B)
  val axi_bvalid  = RegInit(false.B)
  val axi_bresp   = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_rdata   = RegInit(0.U(dataWidth.W))
  val axi_rvalid  = RegInit(false.B)
  val axi_rresp   = RegInit(0.U(2.W))

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid     := axi_bvalid
  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid     := axi_rvalid

  // Handshake conditions
  val axi_will_awrite = !axi_awready && axi.aw.valid
  val axi_will_write = !axi_wready && axi_awready && axi.aw.valid
  val axi_will_bresp = !axi_bvalid && axi_wready && axi.w.valid
  val axi_will_aread = !axi_arready && axi.ar.valid
  val axi_will_read = !axi_rvalid && axi_arready && axi.ar.valid
  
  // AW
  when(axi_will_awrite) {
    axi_awaddr  := axi.aw.bits.addr
    axi_awready := true.B
  }.otherwise {
    axi_awready := false.B
  }

  // W
  when(axi_will_write) {
    axi_wready := true.B
  }.otherwise {
    when(axi_wready && axi.w.valid) {
      axi_wready := false.B
    }
  }

  // B
  when(axi_will_bresp) {
    axi_bvalid := true.B
  }.otherwise {
    when(axi.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }
  
  // AR
  when(axi_will_aread) {
    axi_araddr  := axi.ar.bits.addr
    axi_arready := true.B
  }.otherwise {
    axi_arready := false.B
  }

  // R
  when(axi_will_read) {
    axi_rvalid := true.B
  }.otherwise {
    when(axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  ext_axi.connect(axi)
}
