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

class DMACSR(override val baseAddr: BigInt) extends CSRMMap {
  override def registers: Seq[Register] = Seq(
    Register("DMA_CTRL", baseAddr + 0x00),
    Register("DMA_STATUS", baseAddr + 0x04),
    Register("DMA_SRC_ADDR", baseAddr + 0x08),
    Register("DMA_DST_ADDR", baseAddr + 0x0c),
    Register("DMA_LENGTH", baseAddr + 0x10),
    Register("DMA_BYTES_XFER", baseAddr + 0x14),
    Register("DMA_BURST_SIZE", baseAddr + 0x18),
    Register("DMA_PRIORITY", baseAddr + 0x1c)
  )
}

class AXILiteSlaveDMA(
  addrWidth: Int,
  dataWidth: Int,
  ctrlAddrWidth: Int,
  idWidth: Int,
  userWidth: Int,
  baseAddr: BigInt
) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new DMACSR(baseAddr)) {
  override protected def getExtAXIName: String = "S_AXI_CTRL"
  override def desiredName: String             =
    s"axilite_slave_dma_${addrWidth}x${dataWidth}_ctrl${ctrlAddrWidth}_i${idWidth}_u$userWidth"

  // AXI Full Master (to memory)
  val ext_axi_mem = IO(new AXIFullMasterExternalIO(addrWidth, dataWidth, idWidth, userWidth))
    .suggestName("M_AXI_MEM")
  val axi_mem     = Wire(new AXIFullMasterIO(addrWidth, dataWidth, idWidth, userWidth))

  // External interrupt
  val interrupt = IO(Output(Bool())).suggestName("INTERRUPT")

  // Submodule: DMA Channel
  val dma = Module(new DMAChannel(addrWidth, dataWidth))

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

  // AW

  // W
  when(axi_will_write) {
    when(writeAccess("DMA_CTRL")) {
      when(axi.w.bits.data(0)) {
        ready_pulse := true.B
        done_sticky := false.B // start W1P
      }
      when(axi.w.bits.data(1)) {
        soft_reset_pulse := true.B // soft reset W1P
      }
      reg_enable     := axi.w.bits.data(2)
      reg_int_enable := axi.w.bits.data(3)
    }.elsewhen(writeAccess("DMA_SRC_ADDR")) {
      reg_src_addr := axi.w.bits.data
    }.elsewhen(writeAccess("DMA_DST_ADDR")) {
      reg_dst_addr := axi.w.bits.data
    }.elsewhen(writeAccess("DMA_LENGTH")) {
      reg_length := axi.w.bits.data
    }.elsewhen(writeAccess("DMA_BURST_SIZE")) {
      reg_burst_size := axi.w.bits.data(7, 0)
    }.elsewhen(writeAccess("DMA_PRIORITY")) {
      reg_priority := axi.w.bits.data(2, 0)
    }
  }

  // B 
  when(axi_will_bresp) {
    axi_bresp := Mux(dma.io.error, 2.U, 0.U) // SLVERR if error
  }

  // AR

  // R
  registerRead("DMA_CTRL", Cat(reg_int_enable, reg_enable, 0.U(1.W), 0.U(1.W))) // RO view; start/reset show 0
  registerRead("DMA_STATUS", Cat(error_sticky, done_sticky, dma.io.busy))       // [2] error, [1] done, [0] busy
  registerRead("DMA_SRC_ADDR", reg_src_addr)
  registerRead("DMA_DST_ADDR", reg_dst_addr)
  registerRead("DMA_LENGTH", reg_length)
  registerRead("DMA_BYTES_XFER", bytes_xfer)
  registerRead("DMA_BURST_SIZE", reg_burst_size)
  registerRead("DMA_PRIORITY", reg_priority)
  when(axi_will_read) {
    axi_rresp := Mux(dma.io.error, 2.U, 0.U) // SLVERR if error
  }

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
      baseAddr = 0x80000000L
    ),
    "axilite_slave_dma.sv",
    info = true
  )
}
