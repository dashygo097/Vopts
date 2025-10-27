package com.amba

import utils._
import chisel3._
import chisel3.util._

object AXIFull2LiteBridgeState extends ChiselEnum {
  val IDLE = Value(0.U(4.W))

  val W_WAIT_AW     = Value(0.U(4.W))
  val W_WAIT_W      = Value(1.U(4.W))
  val W_LITE_AW     = Value(2.U(4.W))
  val W_LITE_B      = Value(3.U(4.W))
  val W_SEND_B      = Value(4.U(4.W))
  val W_DRAIN_UNSUP = Value(5.U(4.W))

  val R_WAIT_AR  = Value(6.U(4.W))
  val R_LITE_AR  = Value(7.U(4.W))
  val R_LITE_R   = Value(8.U(4.W))
  val R_UNSUPPLY = Value(9.U(4.W))
}

class AXIFull2LiteBridge(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0) extends Module {
  override def desiredName: String =
    s"axi_full2lite_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  require(dataWidth % 8 == 0 && (dataWidth & (dataWidth - 1)) == 0, "dataWidth must be power-of-two multiple of 8")

  val slave  = IO(new AXIFullSlaveIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("S_AXI")
  val master = IO(new AXILiteMasterIO(addrWidth, dataWidth)).suggestName("M_AXI")

  private val beatBytes = (dataWidth / 8).U
  private val reqSize   = log2Ceil(dataWidth / 8).U(3.W)

  val state = RegInit(AXIFull2LiteBridgeState.IDLE)

  def isBurstSupported(b: UInt) = (b === 0.U /*FIXED*/ ) || (b === 1.U /*INCR*/ )
  def sizeOk(sz: UInt)          = sz === reqSize

  // Write-path registers
  val wr_addr        = Reg(UInt(addrWidth.W))
  val wr_len         = Reg(UInt(8.W))
  val wr_burst       = Reg(UInt(2.W))
  val wr_prot        = Reg(UInt(3.W))
  val wr_err         = RegInit(false.B)
  val wr_unsupported = RegInit(false.B)

  val wdata_buf   = Reg(UInt(dataWidth.W))
  val wstrb_buf   = Reg(UInt((dataWidth / 8).W))
  val wbeat_valid = RegInit(false.B)

  // Read-path registers
  val rd_addr        = Reg(UInt(addrWidth.W))
  val rd_len         = Reg(UInt(8.W))
  val rd_burst       = Reg(UInt(2.W))
  val rd_prot        = Reg(UInt(3.W))
  val rd_unsupported = RegInit(false.B)

  // AW
  master.aw.bits.addr := wr_addr
  master.aw.bits.prot := wr_prot
  master.aw.valid     := (state === AXIFull2LiteBridgeState.W_LITE_AW)

  // W
  master.w.bits.data := wdata_buf
  master.w.bits.strb := wstrb_buf
  master.w.valid     := (state === AXIFull2LiteBridgeState.W_LITE_AW)

  // B
  master.b.ready := (state === AXIFull2LiteBridgeState.W_LITE_B)

  // AR
  master.ar.bits.addr := rd_addr
  master.ar.bits.prot := rd_prot
  master.ar.valid     := (state === AXIFull2LiteBridgeState.R_LITE_AR)

  // R
  master.r.ready := (state === AXIFull2LiteBridgeState.R_LITE_R) && slave.r.ready

  // Write channels defaults
  slave.aw.ready    := (state === AXIFull2LiteBridgeState.IDLE) || (state === AXIFull2LiteBridgeState.W_WAIT_AW)
  slave.w.ready     := (state === AXIFull2LiteBridgeState.W_WAIT_W) && !wbeat_valid
  slave.b.bits.resp := Mux(wr_err, 2.U, 0.U) // SLVERR else OKAY
  slave.b.bits.id   := 0.U
  slave.b.bits.user := 0.U
  slave.b.valid     := (state === AXIFull2LiteBridgeState.W_SEND_B)

  // Read channels defaults
  slave.ar.ready := (state === AXIFull2LiteBridgeState.IDLE) || (state === AXIFull2LiteBridgeState.R_WAIT_AR)

  slave.r.bits.id   := 0.U
  slave.r.bits.user := 0.U
  slave.r.bits.last := false.B
  slave.r.bits.data := master.r.bits.data
  slave.r.bits.resp := master.r.bits.resp
  slave.r.valid     := false.B

  // For unsupported read, we fabricate beats with DECERR
  val r_unsup_last = rd_len === 1.U

  // Address increment logic (INCR/FIXED)
  def nextAddr(curr: UInt, burst: UInt): UInt =
    Mux(burst === 1.U /*INCR*/, curr + beatBytes, curr) // FIXED => same addr

  // FSM
  switch(state) {
    is(AXIFull2LiteBridgeState.IDLE) {
      wr_err         := false.B
      wr_unsupported := false.B
      rd_unsupported := false.B
      wbeat_valid    := false.B

      when(slave.aw.valid) {
        when(slave.aw.ready) {
          val beats = slave.aw.bits.len + 1.U
          wr_addr  := slave.aw.bits.addr
          wr_len   := Mux(beats === 0.U, 1.U, beats) // treat 0 as 1 beat
          wr_burst := slave.aw.bits.burst
          wr_prot  := slave.aw.bits.prot

          wr_unsupported := !(isBurstSupported(slave.aw.bits.burst) && sizeOk(slave.aw.bits.size)) ||
            (slave.aw.bits.id =/= 0.U) || (slave.aw.bits.user =/= 0.U)
          state          := Mux(wr_unsupported, AXIFull2LiteBridgeState.W_DRAIN_UNSUP, AXIFull2LiteBridgeState.W_WAIT_W)
        }
      }.elsewhen(slave.ar.valid) {
        when(slave.ar.ready) {
          val beats = slave.ar.bits.len + 1.U
          rd_addr  := slave.ar.bits.addr
          rd_len   := Mux(beats === 0.U, 1.U, beats)
          rd_burst := slave.ar.bits.burst
          rd_prot  := slave.ar.bits.prot

          rd_unsupported := !(isBurstSupported(slave.ar.bits.burst) && sizeOk(slave.ar.bits.size)) ||
            (slave.ar.bits.id =/= 0.U) || (slave.ar.bits.user =/= 0.U)
          state          := Mux(rd_unsupported, AXIFull2LiteBridgeState.R_UNSUPPLY, AXIFull2LiteBridgeState.R_LITE_AR)
        }
      }
    }

    is(AXIFull2LiteBridgeState.W_WAIT_W) {
      // Wait to capture one W beat before issuing a Lite write
      when(slave.w.valid && slave.w.ready) {
        wdata_buf   := slave.w.bits.data
        wstrb_buf   := slave.w.bits.strb
        wbeat_valid := true.B
        state       := AXIFull2LiteBridgeState.W_LITE_AW
      }
    }

    is(AXIFull2LiteBridgeState.W_LITE_AW) {
      val aw_fire = master.aw.valid && master.aw.ready
      val w_fire  = master.w.valid && master.w.ready
      when(aw_fire) { /* nothing else to do */ }
      when(w_fire) { /* nothing else to do */ }

      when(aw_fire && w_fire) {
        state := AXIFull2LiteBridgeState.W_LITE_B
      }
    }

    is(AXIFull2LiteBridgeState.W_LITE_B) {
      when(master.b.valid && master.b.ready) {
        // Aggregate error if any beat fails (OKAY=0, EXOKAY=1, SLVERR=2, DECERR=3)
        wr_err      := wr_err || (master.b.bits.resp =/= 0.U)
        wr_len      := wr_len - 1.U
        wr_addr     := nextAddr(wr_addr, wr_burst)
        wbeat_valid := false.B

        when(wr_len === 1.U) {
          state := AXIFull2LiteBridgeState.W_SEND_B
        }.otherwise {
          state := AXIFull2LiteBridgeState.W_WAIT_W
        }
      }
    }

    is(AXIFull2LiteBridgeState.W_SEND_B) {
      when(slave.b.valid && slave.b.ready) {
        state := AXIFull2LiteBridgeState.IDLE
      }
    }

    is(AXIFull2LiteBridgeState.W_DRAIN_UNSUP) {
      slave.w.ready := true.B
      when(slave.w.valid && slave.w.ready) {
        wr_len := wr_len - 1.U
        when(wr_len === 1.U) {
          slave.b.bits.resp := 3.U // DECERR
          slave.b.valid     := true.B
          when(slave.b.ready)(state := AXIFull2LiteBridgeState.IDLE)
            .otherwise(state := AXIFull2LiteBridgeState.W_SEND_B) // reuse RESP state
        }
      }
    }

    is(AXIFull2LiteBridgeState.R_LITE_AR) {
      when(master.ar.valid && master.ar.ready) {
        state := AXIFull2LiteBridgeState.R_LITE_R
      }
    }

    is(AXIFull2LiteBridgeState.R_LITE_R) {
      slave.r.valid     := master.r.valid
      slave.r.bits.data := master.r.bits.data
      slave.r.bits.resp := master.r.bits.resp
      slave.r.bits.last := (rd_len === 1.U)

      when(master.r.valid && slave.r.ready) {
        rd_len  := rd_len - 1.U
        rd_addr := nextAddr(rd_addr, rd_burst)
        when(rd_len === 1.U) {
          state := AXIFull2LiteBridgeState.IDLE
        }.otherwise {
          state := AXIFull2LiteBridgeState.R_LITE_AR
        }
      }
    }

    is(AXIFull2LiteBridgeState.R_UNSUPPLY) {
      slave.r.valid     := true.B
      slave.r.bits.data := 0.U
      slave.r.bits.resp := 3.U // DECERR
      slave.r.bits.last := r_unsup_last

      when(slave.r.valid && slave.r.ready) {
        rd_len := rd_len - 1.U
        when(r_unsup_last)(state := AXIFull2LiteBridgeState.IDLE)
      }
    }
  }

  def connect(intf: AXIFullMasterExternalIO): Unit = {
    slave.aw.bits.addr   := intf.AWADDR
    slave.aw.bits.prot   := intf.AWPROT
    slave.aw.bits.len    := intf.AWLEN
    slave.aw.bits.size   := intf.AWSIZE
    slave.aw.bits.burst  := intf.AWBURST
    slave.aw.bits.lock   := intf.AWLOCK
    slave.aw.bits.cache  := intf.AWCACHE
    slave.aw.bits.qos    := intf.AWQOS
    slave.aw.bits.region := intf.AWREGION
    slave.aw.bits.id     := intf.AWID
    slave.aw.bits.user   := intf.AWUSER
    slave.aw.valid       := intf.AWVALID
    intf.AWREADY         := slave.aw.ready

    slave.w.bits.data := intf.WDATA
    slave.w.bits.strb := intf.WSTRB
    slave.w.bits.last := intf.WLAST
    slave.w.bits.id   := intf.WID
    slave.w.bits.user := intf.WUSER
    slave.w.valid     := intf.WVALID
    intf.WREADY       := slave.w.ready

    intf.BRESP    := slave.b.bits.resp
    intf.BID      := slave.b.bits.id
    intf.BUSER    := slave.b.bits.user
    intf.BVALID   := slave.b.valid
    slave.b.ready := intf.BREADY

    slave.ar.bits.addr   := intf.ARADDR
    slave.ar.bits.prot   := intf.ARPROT
    slave.ar.bits.len    := intf.ARLEN
    slave.ar.bits.size   := intf.ARSIZE
    slave.ar.bits.burst  := intf.ARBURST
    slave.ar.bits.lock   := intf.ARLOCK
    slave.ar.bits.cache  := intf.ARCACHE
    slave.ar.bits.qos    := intf.ARQOS
    slave.ar.bits.region := intf.ARREGION
    slave.ar.bits.id     := intf.ARID
    slave.ar.bits.user   := intf.ARUSER
    slave.ar.valid       := intf.ARVALID
    intf.ARREADY         := slave.ar.ready

    intf.RDATA    := slave.r.bits.data
    intf.RRESP    := slave.r.bits.resp
    intf.RLAST    := slave.r.bits.last
    intf.RID      := slave.r.bits.id
    intf.RUSER    := slave.r.bits.user
    intf.RVALID   := slave.r.valid
    slave.r.ready := intf.RREADY
  }

  def connect(intf: AXIFullMasterIO): Unit =
    slave <> intf

  def connect(intf: AXILiteSlaveExternalIO): Unit = {
    intf.AWADDR     := master.aw.bits.addr
    intf.AWPROT     := master.aw.bits.prot
    intf.AWVALID    := master.aw.valid
    master.aw.ready := intf.AWREADY

    intf.WDATA     := master.w.bits.data
    intf.WSTRB     := master.w.bits.strb
    intf.WVALID    := master.w.valid
    master.w.ready := intf.WREADY

    master.b.bits.resp := intf.BRESP
    intf.BVALID        := master.b.valid
    master.b.ready     := intf.BREADY

    intf.ARADDR     := master.ar.bits.addr
    intf.ARPROT     := master.ar.bits.prot
    intf.ARVALID    := master.ar.valid
    master.ar.ready := intf.ARREADY

    master.r.bits.data := intf.RDATA
    master.r.bits.resp := intf.RRESP
    intf.RVALID        := master.r.valid
    master.r.ready     := intf.RREADY
  }

  def connect(intf: AXILiteMasterIO): Unit =
    master <> intf
}

object AXIFull2LiteBridge {
  def apply(addrWidth: Int, dataWidth: Int, idWidth: Int, userWidth: Int = 0): AXIFull2LiteBridge =
    Module(new AXIFull2LiteBridge(addrWidth, dataWidth, idWidth, userWidth))
}

object TestAXIFull2LiteBridge extends App {
  VerilogEmitter.parse(
    new AXIFull2LiteBridge(32, 32, 4, 1),
    "axi_full_to_lite_bridge.sv",
    info = true
  )
}
