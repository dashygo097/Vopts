package com.axi

import utils._
import chisel3._
import chisel3.util._

object MasterRWState extends ChiselEnum {
  val IDLE       = Value(0.U(3.W))
  val WRITE_ADDR = Value(1.U(3.W))
  val WRITE_DATA = Value(2.U(3.W))
  val WRITE_RESP = Value(3.U(3.W))
  val READ_ADDR  = Value(4.U(3.W))
  val READ_DATA  = Value(5.U(3.W))
}

class AXILiteMasterRW(
  addrWidth: Int,
  dataWidth: Int
) extends Module {
  override def desiredName: String =
    s"axilite_master_rw_${addrWidth}x$dataWidth"

  // AXI Full Master Interface
  val ext_axi = IO(new AXILiteMasterExternalIO(addrWidth, dataWidth)).suggestName("M_AXI")
  val axi     = Wire(new AXILiteMasterIO(addrWidth, dataWidth))

  // User interface
  val write_data = IO(Input(UInt(dataWidth.W))).suggestName("W_DATA")
  val write_addr = IO(Input(UInt(addrWidth.W))).suggestName("W_ADDR")
  val write_en   = IO(Input(Bool())).suggestName("W_EN")
  val write_done = IO(Output(Bool())).suggestName("W_DONE")
  val write_resp = IO(Output(UInt(2.W))).suggestName("W_RESP")

  val read_data = IO(Output(UInt(dataWidth.W))).suggestName("R_DATA")
  val read_addr = IO(Input(UInt(addrWidth.W))).suggestName("R_ADDR")
  val read_en   = IO(Input(Bool())).suggestName("R_EN")
  val read_done = IO(Output(Bool())).suggestName("R_DONE")
  val read_resp = IO(Output(UInt(2.W))).suggestName("R_RESP")

  val busy = IO(Output(Bool())).suggestName("BUSY")

  // FSM state definitions
  val state = RegInit(MasterRWState.IDLE)

  // Internal registers for AXI signals
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_awvalid = RegInit(false.B)
  val axi_wdata   = RegInit(0.U(dataWidth.W))
  val axi_wvalid  = RegInit(false.B)
  val axi_bready  = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_arvalid = RegInit(false.B)
  val axi_rready  = RegInit(false.B)

  // Default values for outputs
  axi.aw.bits.addr := axi_awaddr
  axi.aw.bits.prot := 0.U
  axi.aw.valid     := axi_awvalid
  axi.w.bits.data  := axi_wdata
  axi.w.bits.strb  := Fill(dataWidth / 8, 1.U)
  axi.w.valid      := axi_wvalid
  axi.b.ready      := axi_bready
  axi.ar.bits.addr := axi_araddr
  axi.ar.bits.prot := 0.U
  axi.ar.valid     := axi_arvalid
  axi.r.ready      := axi_rready

  // User-facing outputs
  write_done := false.B
  read_done  := false.B
  write_resp := 0.U
  read_resp  := 0.U
  read_data  := axi.r.bits.data
  busy       := (state =/= MasterRWState.IDLE)

  // State Machine Logic
  switch(state) {
    is(MasterRWState.IDLE) {
      axi_awvalid := false.B
      axi_wvalid  := false.B
      axi_bready  := false.B
      axi_arvalid := false.B
      axi_rready  := false.B

      when(write_en) {
        state       := MasterRWState.WRITE_ADDR
        axi_awaddr  := write_addr
        axi_wdata   := write_data
        axi_awvalid := true.B
      }.elsewhen(read_en) {
        state       := MasterRWState.READ_ADDR
        axi_araddr  := read_addr
        axi_arvalid := true.B
      }
    }

    // --- WRITE STATES ---
    is(MasterRWState.WRITE_ADDR) {
      when(axi.aw.ready) {
        state       := MasterRWState.WRITE_DATA
        axi_awvalid := false.B
        axi_wvalid  := true.B
      }
    }

    is(MasterRWState.WRITE_DATA) {
      when(axi.w.ready) {
        state      := MasterRWState.WRITE_RESP
        axi_wvalid := false.B
        axi_bready := true.B
      }
    }

    is(MasterRWState.WRITE_RESP) {
      when(axi.b.valid) {
        state      := MasterRWState.IDLE
        axi_bready := false.B
        write_done := true.B
        write_resp := axi.b.bits.resp
      }
    }

    // --- READ STATES ---
    is(MasterRWState.READ_ADDR) {
      when(axi.ar.ready) {
        state       := MasterRWState.READ_DATA
        axi_arvalid := false.B
        axi_rready  := true.B
      }
    }

    is(MasterRWState.READ_DATA) {
      when(axi.r.valid) {
        state      := MasterRWState.IDLE
        axi_rready := false.B
        read_done  := true.B
        read_resp  := axi.r.bits.resp
      }
    }
  }

  ext_axi.connect(axi)
}

object TestAXILiteMasterRW extends App {
  VerilogEmitter.parse(new AXILiteMasterRW(32, 32), "axi_lite_master_rw.sv", info = true)
}
