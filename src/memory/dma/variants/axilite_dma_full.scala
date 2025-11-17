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
  idWidth: Int,
  userWidth: Int,
  baseAddr: BigInt
) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new DMACSR(baseAddr)) {
  override protected def getExtAXIName: String = "S_AXI_CTRL"
  override def desiredName: String             =
    s"axilite_slave_dma_${addrWidth}x${dataWidth}_i${idWidth}_u$userWidth"

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

  val bytes_xfer   = RegInit(0.U(dataWidth.W))
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
  dma.io.descriptor.priority  := reg_priority
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
  when(axi_last_write) {
    when(writeAccess("DMA_CTRL")) {
      ready_pulse      := axi.w.bits.data(0)
      done_sticky      := !axi.w.bits.data(0)
      soft_reset_pulse := axi.w.bits.data(1)
      reg_enable       := axi.w.bits.data(2)
      reg_int_enable   := axi.w.bits.data(3)
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

  // Signals
  val axi_mem_awaddr   = RegInit(0.U(addrWidth.W))
  val axi_mem_awid     = RegInit(0.U(idWidth.W))
  val axi_mem_awlen    = RegInit(0.U(8.W))
  val axi_mem_awsize   = RegInit(sizeBits.U(3.W))
  val axi_mem_awburst  = RegInit(1.U(2.W))
  val axi_mem_awlock   = RegInit(0.U(1.W))
  val axi_mem_awcache  = RegInit(0.U(4.W))
  val axi_mem_awprot   = RegInit(0.U(3.W))
  val axi_mem_awqos    = RegInit(0.U(4.W))
  val axi_mem_awregion = RegInit(0.U(4.W))
  val axi_mem_awuser   = RegInit(0.U(userWidth.W))
  val axi_mem_awvalid  = RegInit(false.B)

  val axi_mem_wdata  = RegInit(0.U(dataWidth.W))
  val axi_mem_wstrb  = RegInit(Fill(beatBytes, 1.U(1.W)))
  val axi_mem_wlast  = RegInit(true.B)
  val axi_mem_wuser  = RegInit(0.U(userWidth.W))
  val axi_mem_wvalid = RegInit(false.B)

  val axi_mem_bready = RegInit(false.B)

  val axi_mem_araddr   = RegInit(0.U(addrWidth.W))
  val axi_mem_arid     = RegInit(0.U(idWidth.W))
  val axi_mem_arlen    = RegInit(0.U(8.W))
  val axi_mem_arsize   = RegInit(sizeBits.U(3.W))
  val axi_mem_arburst  = RegInit(1.U(2.W))
  val axi_mem_arlock   = RegInit(0.U(1.W))
  val axi_mem_arcache  = RegInit(0.U(4.W))
  val axi_mem_arprot   = RegInit(0.U(3.W))
  val axi_mem_arqos    = RegInit(0.U(4.W))
  val axi_mem_arregion = RegInit(0.U(4.W))
  val axi_mem_aruser   = RegInit(0.U(userWidth.W))
  val axi_mem_arvalid  = RegInit(false.B)

  val axi_mem_rready = RegInit(false.B)

  val wr_aw_done  = RegInit(false.B) // AW completed
  val wr_w_done   = RegInit(false.B) // W completed
  val wr_inflight = RegInit(false.B) // waiting for B

  val rd_inflight = RegInit(false.B) // waiting for R

  // Default assignments
  axi_mem.aw.bits.addr   := axi_mem_awaddr
  axi_mem.aw.bits.id     := axi_mem_awid
  axi_mem.aw.bits.len    := axi_mem_awlen
  axi_mem.aw.bits.size   := axi_mem_awsize
  axi_mem.aw.bits.burst  := axi_mem_awburst
  axi_mem.aw.bits.lock   := axi_mem_awlock
  axi_mem.aw.bits.cache  := axi_mem_awcache
  axi_mem.aw.bits.prot   := axi_mem_awprot
  axi_mem.aw.bits.qos    := axi_mem_awqos
  axi_mem.aw.bits.user   := axi_mem_awuser
  axi_mem.aw.bits.region := axi_mem_awregion
  axi_mem.aw.valid       := axi_mem_awvalid

  axi_mem.w.bits.data := axi_mem_wdata
  axi_mem.w.bits.id   := axi_mem_awid
  axi_mem.w.bits.strb := axi_mem_wstrb
  axi_mem.w.bits.last := axi_mem_wlast
  axi_mem.w.bits.user := axi_mem_wuser
  axi_mem.w.valid     := axi_mem_wvalid

  axi_mem.b.ready := axi_mem_bready

  axi_mem.ar.bits.addr   := axi_mem_araddr
  axi_mem.ar.bits.id     := axi_mem_arid
  axi_mem.ar.bits.len    := axi_mem_arlen
  axi_mem.ar.bits.size   := axi_mem_arsize
  axi_mem.ar.bits.burst  := axi_mem_arburst
  axi_mem.ar.bits.lock   := axi_mem_arlock
  axi_mem.ar.bits.cache  := axi_mem_arcache
  axi_mem.ar.bits.prot   := axi_mem_arprot
  axi_mem.ar.bits.qos    := axi_mem_arqos
  axi_mem.ar.bits.user   := axi_mem_aruser
  axi_mem.ar.bits.region := axi_mem_arregion
  axi_mem.ar.valid       := axi_mem_arvalid

  axi_mem.r.ready := axi_mem_rready

  dma.io.writeAddr.ready := !axi_mem_awvalid && !wr_aw_done
  axi_mem_wvalid         := wr_aw_done && dma.io.writeData.valid && !wr_w_done
  axi_mem_wdata          := dma.io.writeData.bits
  axi_mem_wlast          := true.B
  dma.io.writeData.ready := wr_aw_done && axi_mem.w.ready && !wr_w_done

  dma.io.writeResp.valid := wr_inflight && axi_mem.b.valid
  dma.io.writeResp.bits  := (axi_mem.b.bits.resp === 0.U)
  axi_mem_bready         := wr_inflight && dma.io.writeResp.ready

  dma.io.readAddr.ready := !axi_mem_arvalid && !rd_inflight

  dma.io.readData.valid := rd_inflight && axi_mem.r.valid
  dma.io.readData.bits  := axi_mem.r.bits.data
  axi_mem_rready        := rd_inflight && dma.io.readData.ready

  interrupt := dma.io.interrupt && reg_int_enable

  // AW
  when(dma.io.writeAddr.fire) {
    axi_mem_awaddr  := dma.io.writeAddr.bits
    axi_mem_awvalid := true.B
  }

  when(axi_mem.aw.ready && axi_mem_awvalid) {
    axi_mem_awvalid := false.B
    wr_aw_done      := true.B
  }

  // W
  when(axi_mem.w.ready && axi_mem_wvalid) {
    wr_w_done   := true.B
    wr_inflight := true.B
  }

  // B
  when(dma.io.writeResp.fire) {
    wr_aw_done  := false.B
    wr_w_done   := false.B
    wr_inflight := false.B
  }

  // AR
  when(dma.io.readAddr.fire) {
    axi_mem_araddr  := dma.io.readAddr.bits
    axi_mem_arvalid := true.B
  }

  when(axi_mem.ar.ready && axi_mem_arvalid) {
    axi_mem_arvalid := false.B
    rd_inflight     := true.B
  }

  // R
  when(axi_mem.r.valid && axi_mem_rready && axi_mem.r.bits.last) {
    rd_inflight := false.B
  }

  ext_axi_mem.connect(axi_mem)

  def connect(intf: AXIFullSlaveExternalIO): Unit =
    intf <> ext_axi_mem
}

object TestAXILiteSlaveDMA extends App {
  VerilogEmitter.parse(
    new AXILiteSlaveDMA(
      addrWidth = 32,
      dataWidth = 32,
      idWidth = 4,
      userWidth = 1,
      baseAddr = 0x80000000L
    ),
    "axilite_slave_dma.sv",
    info = true
  )
}
