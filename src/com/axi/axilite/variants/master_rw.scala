package com.axi

import chisel3._
import chisel3.util._

class AXILiteMasterRW(
  addrWidth: Int,
  dataWidth: Int
) extends Module {
  override def desiredName: String =
    s"axilite_master_${addrWidth}x${dataWidth}"

  // AXI Full Master Interface
  val ext_axi = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi = Wire(new AXILiteMasterIO(addrWidth, dataWidth))

  val write_data = IO(Input(UInt(dataWidth.W))).suggestName("W_DATA")
  val write_addr = IO(Input(UInt(addrWidth.W))).suggestName("W_ADDR")
  val write_en  = IO(Input(Bool())).suggestName("W_EN")
  val write_ready = IO(Output(Bool())).suggestName("W_READY")
  val write_resp = IO(Output(UInt(2.W))).suggestName("W_RESP")
  val read_data  = IO(Output(UInt(dataWidth.W))).suggestName("R_DATA")
  val read_addr  = IO(Input(UInt(addrWidth.W))).suggestName("R_ADDR")
  val read_en   = IO(Input(Bool())).suggestName("R_EN")
  val read_ready = IO(Output(Bool())).suggestName("R_READY")
  val read_resp  = IO(Output(UInt(2.W))).suggestName("R_RESP")

  // Parameters
  val addr_lsb = log2Ceil(dataWidth / 8)

  // Signals
  val axi_awaddr      = RegInit(0.U(addrWidth.W))
  val axi_awvalid     = RegInit(false.B)
  val axi_wdata      = RegInit(0.U(dataWidth.W))
  val axi_wvalid     = RegInit(false.B)
  val axi_bready     = RegInit(false.B)
  val axi_araddr     = RegInit(0.U(addrWidth.W))
  val axi_arvalid    = RegInit(false.B)
  val axi_rready     = RegInit(false.B)

  // I/O Connections
  axi.aw.bits.addr := axi_awaddr
  axi.aw.bits.prot := 0.U
  axi.aw.valid     := axi_awvalid
  axi.w.bits.data  := axi_wdata
  axi.w.bits.strb  := Fill(dataWidth / 8, 1.U)
  axi.w.valid      := axi_wvalid
  axi.b.ready     := axi_bready
  axi.ar.bits.addr := axi_araddr
  axi.ar.bits.prot := 0.U
  axi.ar.valid     := axi_arvalid
  axi.r.ready     := axi_rready

  write_ready := axi.w.ready && axi_wvalid
  write_resp  := axi.b.bits.resp
  read_ready  := axi.r.valid && axi_rready
  read_resp   := axi.r.bits.resp
  

  // Write Addr Channel
  when(write_en && !axi_awvalid) {
    axi_awaddr := write_addr
    axi_awvalid := true.B
  } .elsewhen(axi.aw.ready && axi_awvalid) {
    axi_awvalid := false.B
  }

  // Write Data Channel
  when(write_en && !axi_wvalid) {
    axi_wdata := write_data
    axi_wvalid := true.B
  } .elsewhen(axi.w.ready && axi_wvalid) {
    axi_wvalid := false.B
  }

  // Write Response Channel
  when(axi.b.valid && !axi_bready) {
    axi_bready := true.B
  } .elsewhen(axi_bready) {
    axi_bready := false.B
  }

  // Read Addr Channel
  when(read_en && !axi_arvalid) {
    axi_araddr := read_addr
    axi_arvalid := true.B
  } .elsewhen(axi.ar.ready && axi_arvalid) {
    axi_arvalid := false.B
  }

  // Read Data Channel
  when(axi.r.valid && !axi_rready) {
    read_data   := axi.r.bits.data
    axi_rready := true.B
  } .elsewhen(axi_rready) {
    read_data := RegNext(read_data)
    axi_rready := false.B
  } .otherwise {
    read_data := 0.U
  }


  ext_axi.connect(axi)
}                                     
