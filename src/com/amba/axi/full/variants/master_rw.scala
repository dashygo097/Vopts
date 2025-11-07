package com.amba

import utils._
import chisel3._
import chisel3.util._

object AXIBurstType {
  val FIXED = 0.U(2.W)
  val INCR  = 1.U(2.W)
  val WRAP  = 2.U(2.W)
}

object MasterFullRWState extends ChiselEnum {
  val IDLE       = Value(0.U(3.W))
  val WRITE_ADDR = Value(1.U(3.W))
  val WRITE_DATA = Value(2.U(3.W))
  val WRITE_RESP = Value(3.U(3.W))
  val READ_ADDR  = Value(4.U(3.W))
  val READ_DATA  = Value(5.U(3.W))
}

class AXIFullMasterRW(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int = 0
) extends Module {
  override def desiredName: String =
    s"axifull_master_rw_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

  // External AXI pins and internal AXI record
  val ext_axi = IO(new AXIFullMasterExternalIO(addrWidth, dataWidth, idWidth, userWidth)).suggestName("M_AXI")
  val axi     = Wire(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  // User control interface
  val write_addr  = IO(Input(UInt(addrWidth.W))).suggestName("W_ADDR")
  val write_len   = IO(Input(UInt(8.W))).suggestName("W_LEN") // beats: 1..256
  val write_burst = IO(Input(UInt(2.W))).suggestName("W_BURST")
  val write_en    = IO(Input(Bool())).suggestName("W_EN")
  val write_done  = IO(Output(Bool())).suggestName("W_DONE")
  val write_resp  = IO(Output(UInt(2.W))).suggestName("W_RESP")

  val read_addr  = IO(Input(UInt(addrWidth.W))).suggestName("R_ADDR")
  val read_len   = IO(Input(UInt(8.W))).suggestName("R_LEN") // beats: 1..256
  val read_burst = IO(Input(UInt(2.W))).suggestName("R_BURST")
  val read_en    = IO(Input(Bool())).suggestName("R_EN")
  val read_done  = IO(Output(Bool())).suggestName("R_DONE")
  val read_resp  = IO(Output(UInt(2.W))).suggestName("R_RESP")

  // Streaming data
  val w_in  = IO(Flipped(Decoupled(UInt(dataWidth.W)))).suggestName("W_IN")
  val r_out = IO(Decoupled(UInt(dataWidth.W))).suggestName("R_OUT")

  val busy = IO(Output(Bool())).suggestName("BUSY")

  // Internal constants
  val beatBytes = dataWidth / 8
  require(beatBytes > 0 && ((beatBytes & (beatBytes - 1)) == 0), "dataWidth must be a power-of-two multiple of 8")
  val sizeBits  = log2Ceil(beatBytes).U(3.W)

  val fullStrb = Fill(beatBytes, 1.U(1.W))
  val zeroId   = 0.U(idWidth.W)
  val zeroUser = 0.U(userWidth.W)

  // State / regs
  val state = RegInit(MasterFullRWState.IDLE)

  // Address/control regs for AW/AR
  val aw_addr_r  = RegInit(0.U(addrWidth.W))
  val aw_len_r   = RegInit(0.U(8.W))
  val aw_burst_r = RegInit(AXIBurstType.INCR)
  val aw_valid_r = RegInit(false.B)

  val ar_addr_r  = RegInit(0.U(addrWidth.W))
  val ar_len_r   = RegInit(0.U(8.W))
  val ar_burst_r = RegInit(AXIBurstType.INCR)
  val ar_valid_r = RegInit(false.B)

  // W/B channel regs
  val w_active  = RegInit(false.B)
  val w_count   = RegInit(0.U(8.W))
  val b_ready_r = RegInit(false.B)

  // R channel regs
  val r_active  = RegInit(false.B)
  val r_count   = RegInit(0.U(8.W))
  val r_ready_r = RegInit(false.B)

  // Responses and outputs
  write_done := false.B
  read_done  := false.B
  write_resp := 0.U
  read_resp  := 0.U
  busy       := (state =/= MasterFullRWState.IDLE)

  // Small queues for decoupling user and AXI
  val wq = Module(new Queue(UInt(dataWidth.W), entries = 8)) // adjust depth as needed
  wq.io.enq <> w_in

  val rq = Module(new Queue(UInt(dataWidth.W), entries = 8))
  r_out <> rq.io.deq

  // AW
  axi.aw.bits.addr   := aw_addr_r
  axi.aw.bits.prot   := 0.U
  axi.aw.bits.id     := zeroId
  axi.aw.bits.len    := aw_len_r
  axi.aw.bits.size   := sizeBits
  axi.aw.bits.burst  := aw_burst_r
  axi.aw.bits.lock   := false.B
  axi.aw.bits.cache  := 0.U
  axi.aw.bits.qos    := 0.U
  axi.aw.bits.region := 0.U
  axi.aw.bits.user   := zeroUser
  axi.aw.valid       := aw_valid_r

  // W: drive from wq during active write
  val w_last = w_count === aw_len_r
  axi.w.bits.data := wq.io.deq.bits
  axi.w.bits.strb := fullStrb
  axi.w.bits.last := w_last
  axi.w.bits.id   := zeroId
  axi.w.bits.user := zeroUser
  axi.w.valid     := w_active && wq.io.deq.valid
  wq.io.deq.ready := w_active && axi.w.ready

  // B
  axi.b.ready := b_ready_r

  // AR
  axi.ar.bits.addr   := ar_addr_r
  axi.ar.bits.prot   := 0.U
  axi.ar.bits.id     := zeroId
  axi.ar.bits.len    := ar_len_r
  axi.ar.bits.size   := sizeBits
  axi.ar.bits.burst  := ar_burst_r
  axi.ar.bits.lock   := false.B
  axi.ar.bits.cache  := 0.U
  axi.ar.bits.qos    := 0.U
  axi.ar.bits.region := 0.U
  axi.ar.bits.user   := zeroUser
  axi.ar.valid       := ar_valid_r

  // R -> rq
  rq.io.enq.valid := r_active && axi.r.valid
  rq.io.enq.bits  := axi.r.bits.data
  axi.r.ready     := r_active && rq.io.enq.ready

  // FSM
  switch(state) {
    is(MasterFullRWState.IDLE) {
      // defaults
      aw_valid_r := false.B
      ar_valid_r := false.B
      b_ready_r  := false.B
      r_ready_r  := false.B
      w_active   := false.B
      r_active   := false.B
      w_count    := 0.U
      r_count    := 0.U

      when(write_en) {
        val wLen0 = Mux(write_len === 0.U, 1.U, write_len)
        aw_addr_r  := write_addr
        aw_len_r   := (wLen0 - 1.U)(7, 0)
        aw_burst_r := write_burst
        aw_valid_r := true.B
        state      := MasterFullRWState.WRITE_ADDR

      }.elsewhen(read_en) {
        val rLen0 = Mux(read_len === 0.U, 1.U, read_len)
        ar_addr_r  := read_addr
        ar_len_r   := (rLen0 - 1.U)(7, 0)
        ar_burst_r := read_burst
        ar_valid_r := true.B
        state      := MasterFullRWState.READ_ADDR
      }
    }

    // WRITE
    is(MasterFullRWState.WRITE_ADDR) {
      when(axi.aw.ready && aw_valid_r) {
        aw_valid_r := false.B
        w_active   := true.B
        w_count    := 0.U
        state      := MasterFullRWState.WRITE_DATA
      }
    }

    is(MasterFullRWState.WRITE_DATA) {
      when(axi.w.valid && axi.w.ready) {
        when(w_last) {
          w_active  := false.B
          b_ready_r := true.B
          state     := MasterFullRWState.WRITE_RESP
        }.otherwise {
          w_count := w_count + 1.U
        }
      }
    }

    is(MasterFullRWState.WRITE_RESP) {
      when(axi.b.valid && b_ready_r) {
        b_ready_r  := false.B
        write_done := true.B
        write_resp := axi.b.bits.resp
        state      := MasterFullRWState.IDLE
      }
    }

    // READ
    is(MasterFullRWState.READ_ADDR) {
      when(axi.ar.ready && ar_valid_r) {
        ar_valid_r := false.B
        r_active   := true.B
        r_count    := 0.U
        state      := MasterFullRWState.READ_DATA
      }
    }

    is(MasterFullRWState.READ_DATA) {
      when(axi.r.valid && axi.r.ready) {
        when(axi.r.bits.last) {
          r_active  := false.B
          read_done := true.B
          read_resp := axi.r.bits.resp
          state     := MasterFullRWState.IDLE
        }.otherwise {
          r_count := r_count + 1.U
        }
      }
    }
  }

  // Bind external pins
  ext_axi.connect(axi)
}

object TestAXIFullMasterRW extends App {
  VerilogEmitter.parse(
    new AXIFullMasterRW(32, 64, idWidth = 4, userWidth = 1),
    "axifull_master_rw.sv",
    info = true
  )
}
