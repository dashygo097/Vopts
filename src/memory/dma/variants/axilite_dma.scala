package mem.dma

import com.amba._
import utils._
import chisel3._
import chisel3.util._

object AXILiteSlaveDMAState extends ChiselEnum {
  val IDLE = Value(0.U(3.W))

  // Write States
  val WRITE_DATA = Value(1.U(3.W))
  val WRITE_ADDR = Value(2.U(3.W))
  val WRITE_RESP = Value(3.U(3.W))

  // Read States
  val READ_DATA = Value(4.U(3.W))
  val READ_ADDR = Value(5.U(3.W))

  val DONE  = Value(6.U(3.W))
  val ERROR = Value(7.U(3.W))
}

class AXILiteSlaveDMA(
  addrWidth: Int,
  dataWidth: Int,
  ctrlAddrWidth: Int,
  idWidth: Int,
  userWidth: Int,
  baseAddr: BigInt
) extends Module {
  override def desiredName: String =
    s"axilite_slave_dma_${addrWidth}x${dataWidth}_ctrl${ctrlAddrWidth}_i${idWidth}_u$userWidth"

  // AXI-Lite Slave (CSR)
  val ext_axi_ctrl = IO(new AXILiteSlaveExternalIO(ctrlAddrWidth, 32)).suggestName("S_AXI_CTRL")
  val axi_ctrl     = Wire(new AXILiteSlaveIO(ctrlAddrWidth, 32))

  // AXI Full Master (to memory)
  val ext_axi_mem = IO(new AXIFullMasterExternalIO(addrWidth, dataWidth, idWidth, userWidth))
    .suggestName("M_AXI_MEM")
  val axi_mem     = Wire(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  // External interrupt
  val interrupt = IO(Output(Bool())).suggestName("INTERRUPT")

  // Submodule: DMA Channel
  val dma = Module(new DMAChannel(addrWidth, dataWidth))

  // Address map
  val CTRL_ADDR       = (baseAddr + 0x00).U(ctrlAddrWidth.W)
  val STATUS_ADDR     = (baseAddr + 0x04).U(ctrlAddrWidth.W)
  val SRC_ADDR        = (baseAddr + 0x08).U(ctrlAddrWidth.W)
  val DST_ADDR        = (baseAddr + 0x0c).U(ctrlAddrWidth.W)
  val LENGTH_ADDR     = (baseAddr + 0x10).U(ctrlAddrWidth.W)
  val BYTES_XFER_ADDR = (baseAddr + 0x14).U(ctrlAddrWidth.W)
  val BURST_SIZE_ADDR = (baseAddr + 0x18).U(ctrlAddrWidth.W)
  val PRIORITY_ADDR   = (baseAddr + 0x1c).U(ctrlAddrWidth.W)

  // Control/Status
  val reg_enable       = RegInit(false.B)
  val reg_int_enable   = RegInit(false.B)
  val ready_pulse      = RegInit(false.B)
  val soft_reset_pulse = RegInit(false.B)

  val reg_src_addr   = RegInit(0.U(addrWidth.W))
  val reg_dst_addr   = RegInit(0.U(addrWidth.W))
  val reg_length     = RegInit(0.U(addrWidth.W))
  val reg_burst_size = RegInit(1.U(8.W))
  val reg_priority   = RegInit(0.U(3.W))

  val bytes_xfer   = RegInit(0.U(32.W))
  val done_sticky  = RegInit(false.B)
  val error_sticky = RegInit(false.B)

  // Latch DMA outputs
  bytes_xfer := dma.io.bytes
  when(dma.io.done) {
    done_sticky := true.B
  }
  when(dma.io.error) {
    error_sticky := true.B
  }

  // Clear one-shots
  when(ready_pulse) {
    ready_pulse := false.B
  }
  when(soft_reset_pulse) {
    soft_reset_pulse := false.B
  }

  // DMA descriptor wiring
  dma.io.descriptor.srcAddr   := reg_src_addr
  dma.io.descriptor.dstAddr   := reg_dst_addr
  dma.io.descriptor.length    := reg_length
  dma.io.descriptor.burstSize := reg_burst_size
  dma.io.descriptor.prity     := reg_priority
  dma.io.descriptor.enable    := reg_enable
  dma.io.descriptor.interrupt := reg_int_enable

  dma.io.ready := ready_pulse || soft_reset_pulse

  // Local soft reset behavior
  when(soft_reset_pulse) {
    done_sticky  := false.B
    error_sticky := false.B
    ready_pulse  := true.B
  }

  // AXI-Lite CSR slave
  val axi_awready = RegInit(false.B)
  val axi_awaddr  = RegInit(0.U(ctrlAddrWidth.W))
  val axi_wready  = RegInit(false.B)
  val axi_bvalid  = RegInit(false.B)
  val axi_bresp   = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(ctrlAddrWidth.W))
  val axi_rdata   = RegInit(0.U(32.W))
  val axi_rvalid  = RegInit(false.B)
  val axi_rresp   = RegInit(0.U(2.W))

  // I/O Connections
  axi_ctrl.aw.ready    := axi_awready
  axi_ctrl.w.ready     := axi_wready
  axi_ctrl.b.bits.resp := axi_bresp
  axi_ctrl.b.valid     := axi_bvalid
  axi_ctrl.ar.ready    := axi_arready
  axi_ctrl.r.bits.data := axi_rdata
  axi_ctrl.r.bits.resp := axi_rresp
  axi_ctrl.r.valid     := axi_rvalid

  // Write Address
  when(!axi_awready && axi_ctrl.aw.valid) {
    axi_awaddr  := axi_ctrl.aw.bits.addr
    axi_awready := true.B
  }.otherwise {
    axi_awready := false.B
  }

  // Write Data
  when(!axi_wready && axi_awready && axi_ctrl.aw.valid) {
    axi_wready := true.B
  }.otherwise {
    when(axi_wready && axi_ctrl.w.valid) {
      axi_wready := false.B
    }
  }

  // Write Response + decode
  when(!axi_bvalid && axi_wready && axi_ctrl.w.valid) {
    axi_bvalid := true.B
    axi_bresp  := 0.U // OKAY

    when(axi_awaddr === CTRL_ADDR) {
      when(axi_ctrl.w.bits.data(0)) {
        ready_pulse := true.B; done_sticky := false.B // start W1P
      }
      when(axi_ctrl.w.bits.data(1)) {
        soft_reset_pulse := true.B // soft reset W1P
      }
      reg_enable     := axi_ctrl.w.bits.data(2)
      reg_int_enable := axi_ctrl.w.bits.data(3)
    }.elsewhen(axi_awaddr === SRC_ADDR) {
      reg_src_addr := axi_ctrl.w.bits.data.asUInt.pad(addrWidth)
    }.elsewhen(axi_awaddr === DST_ADDR) {
      reg_dst_addr := axi_ctrl.w.bits.data.asUInt.pad(addrWidth)
    }.elsewhen(axi_awaddr === LENGTH_ADDR) {
      reg_length := axi_ctrl.w.bits.data.asUInt.pad(addrWidth)
    }.elsewhen(axi_awaddr === BURST_SIZE_ADDR) {
      reg_burst_size := axi_ctrl.w.bits.data(7, 0)
    }.elsewhen(axi_awaddr === PRIORITY_ADDR) {
      reg_priority := axi_ctrl.w.bits.data(2, 0)
    }
  }.otherwise {
    when(axi_ctrl.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }

  // Read Address
  when(!axi_arready && axi_ctrl.ar.valid) {
    axi_araddr  := axi_ctrl.ar.bits.addr
    axi_arready := true.B
  }.otherwise {
    axi_arready := false.B
  }

  // Read Data
  when(!axi_rvalid && axi_arready && axi_ctrl.ar.valid) {
    axi_rvalid := true.B
    axi_rresp  := 0.U // OKAY
    axi_rdata  := 0.U

    when(axi_araddr === CTRL_ADDR) {
      axi_rdata := Cat(0.U(28.W), reg_int_enable, reg_enable, 0.U(1.W), 0.U(1.W)) // RO view; start/reset show 0
    }.elsewhen(axi_araddr === STATUS_ADDR) {
      axi_rdata := Cat(0.U(29.W), error_sticky, done_sticky, dma.io.busy) // [2] error, [1] done, [0] busy
    }.elsewhen(axi_araddr === SRC_ADDR) {
      axi_rdata := reg_src_addr(31, 0)
    }.elsewhen(axi_araddr === DST_ADDR) {
      axi_rdata := reg_dst_addr(31, 0)
    }.elsewhen(axi_araddr === LENGTH_ADDR) {
      axi_rdata := reg_length(31, 0)
    }.elsewhen(axi_araddr === BYTES_XFER_ADDR) {
      axi_rdata := bytes_xfer
    }.elsewhen(axi_araddr === BURST_SIZE_ADDR) {
      axi_rdata := Cat(0.U(24.W), reg_burst_size)
    }.elsewhen(axi_araddr === PRIORITY_ADDR) {
      axi_rdata := Cat(0.U(29.W), reg_priority)
    }
  }.otherwise {
    when(axi_rvalid && axi_ctrl.r.ready)(axi_rvalid := false.B)
  }

  // Connect external ports
  ext_axi_ctrl.connect(axi_ctrl)

  // AXI4-Full Master bridge (single beat transfers)
  val beatBytes = dataWidth / 8
  val sizeBits  = log2Ceil(beatBytes)

  // Default assignments
  axi_mem.ar.bits.id     := 0.U(idWidth.W)
  axi_mem.ar.bits.addr   := 0.U(addrWidth.W)
  axi_mem.ar.bits.len    := 0.U(8.W) // single beat
  axi_mem.ar.bits.size   := sizeBits.U(3.W)
  axi_mem.ar.bits.burst  := 1.U(2.W) // INCR
  axi_mem.ar.bits.lock   := 0.U
  axi_mem.ar.bits.cache  := 0.U
  axi_mem.ar.bits.prot   := 0.U
  axi_mem.ar.bits.qos    := 0.U
  axi_mem.ar.bits.user   := 0.U(userWidth.W)
  axi_mem.ar.bits.region := 0.U(4.W)
  axi_mem.ar.valid       := false.B
  axi_mem.r.ready        := false.B

  axi_mem.aw.bits.id     := 0.U(idWidth.W)
  axi_mem.aw.bits.addr   := 0.U(addrWidth.W)
  axi_mem.aw.bits.len    := 0.U(8.W) // single beat
  axi_mem.aw.bits.size   := sizeBits.U(3.W)
  axi_mem.aw.bits.burst  := 1.U(2.W)
  axi_mem.aw.bits.lock   := 0.U
  axi_mem.aw.bits.cache  := 0.U
  axi_mem.aw.bits.prot   := 0.U
  axi_mem.aw.bits.qos    := 0.U
  axi_mem.aw.bits.user   := 0.U(userWidth.W)
  axi_mem.aw.bits.region := 0.U(4.W)
  axi_mem.aw.valid       := false.B

  axi_mem.w.bits.id   := 0.U(idWidth.W)
  axi_mem.w.bits.data := 0.U(dataWidth.W)
  axi_mem.w.bits.strb := Fill(beatBytes, 1.U(1.W))
  axi_mem.w.bits.last := true.B
  axi_mem.w.bits.user := 0.U(userWidth.W)
  axi_mem.w.valid     := false.B

  axi_mem.b.ready := false.B

  // Read path bridge - FIXED: prevent deadlock
  val rd_ar_valid_q = RegInit(false.B)
  val rd_addr_q     = Reg(UInt(addrWidth.W))
  val rd_inflight   = RegInit(false.B)

  dma.io.readAddr.ready := !rd_ar_valid_q && !rd_inflight
  when(dma.io.readAddr.fire) {
    rd_addr_q     := dma.io.readAddr.bits
    rd_ar_valid_q := true.B
  }

  axi_mem.ar.bits.addr := rd_addr_q
  axi_mem.ar.valid     := rd_ar_valid_q
  when(axi_mem.ar.ready && rd_ar_valid_q) {
    rd_ar_valid_q := false.B
    rd_inflight   := true.B
  }

  dma.io.readData.valid := rd_inflight && axi_mem.r.valid
  dma.io.readData.bits  := axi_mem.r.bits.data
  axi_mem.r.ready       := rd_inflight && dma.io.readData.ready
  when(rd_inflight && axi_mem.r.valid && dma.io.readData.ready && axi_mem.r.bits.last) {
    rd_inflight := false.B
  }

  // Write path bridge - FIXED: prevent deadlock
  val wr_aw_valid_q = RegInit(false.B)
  val wr_addr_q     = Reg(UInt(addrWidth.W))
  val wr_aw_done    = RegInit(false.B) // AW completed
  val wr_w_done     = RegInit(false.B) // W completed
  val wr_inflight   = RegInit(false.B) // waiting for B

  dma.io.writeAddr.ready := !wr_aw_valid_q && !wr_aw_done
  when(dma.io.writeAddr.fire) {
    wr_addr_q     := dma.io.writeAddr.bits
    wr_aw_valid_q := true.B
  }

  axi_mem.aw.bits.addr := wr_addr_q
  axi_mem.aw.valid     := wr_aw_valid_q
  when(axi_mem.aw.ready && wr_aw_valid_q) {
    wr_aw_valid_q := false.B
    wr_aw_done    := true.B
  }

  axi_mem.w.valid        := wr_aw_done && dma.io.writeData.valid && !wr_w_done
  axi_mem.w.bits.data    := dma.io.writeData.bits
  axi_mem.w.bits.last    := true.B
  dma.io.writeData.ready := wr_aw_done && axi_mem.w.ready && !wr_w_done
  when(wr_aw_done && axi_mem.w.ready && dma.io.writeData.valid && !wr_w_done) {
    wr_w_done   := true.B
    wr_inflight := true.B
  }

  dma.io.writeResp.valid := wr_inflight && axi_mem.b.valid
  dma.io.writeResp.bits  := (axi_mem.b.bits.resp === 0.U)
  axi_mem.b.ready        := wr_inflight && dma.io.writeResp.ready
  when(dma.io.writeResp.fire) {
    wr_aw_done  := false.B
    wr_w_done   := false.B
    wr_inflight := false.B
  }

  interrupt := dma.io.interrupt && reg_int_enable
  ext_axi_mem.connect(axi_mem)

  def connect(intf: AXIFullSlaveExternalIO): Unit =
    intf <> ext_axi_mem
}

object TestAXILiteSlaveDMA extends App {
  VerilogEmitter.parse(
    new AXILiteSlaveDMA(
      addrWidth = 32,
      dataWidth = 32,
      ctrlAddrWidth = 32,
      idWidth = 4,
      userWidth = 1,
      baseAddr = 0x40000
    ),
    "axi_lite_slave_dma.sv",
    info = true
  )
}
