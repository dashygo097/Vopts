package mem.dma

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class AXIStreamDMA(
  dataWidth: Int,
  idWidth: Int,
  destWidth: Int,
  userWidth: Int
) extends AXIStreamChannel(dataWidth, idWidth, destWidth, userWidth) {
  override def desiredName: String = s"axis_dma_${dataWidth}_i${idWidth}_d${destWidth}_u${userWidth}"

  val busy      = IO(Output(Bool())).suggestName("BUSY")
  val error     = IO(Output(Bool())).suggestName("ERROR")
  val done      = IO(Output(Bool())).suggestName("DONE")
  val bytes     = IO(Output(UInt(dataWidth.W))).suggestName("BYTES")
  val interrupt = IO(Output(Bool())).suggestName("INTERRUPT")

  val enable    = IO(Input(Bool())).suggestName("ENABLE")
  val ready     = IO(Input(Bool())).suggestName("READY")
  val int_en    = IO(Input(Bool())).suggestName("INT_EN")
  val length    = IO(Input(UInt(32.W))).suggestName("LENGTH")
  val priority  = IO(Input(UInt(3.W))).suggestName("PRIORITY")

  // DMA Stream Channel
  val dma = Module(new DMAStreamChannel(32, dataWidth, idWidth, destWidth, userWidth))

  // Wire descriptor
  dma.io.descriptor.srcAddr   := 0.U
  dma.io.descriptor.dstAddr   := 0.U
  dma.io.descriptor.length    := length
  dma.io.descriptor.burstSize := 0.U
  dma.io.descriptor.priority  := priority
  dma.io.descriptor.enable    := enable
  dma.io.descriptor.interrupt := int_en
  dma.io.ready                := ready

  // Connect to external streams
  dma.io.s_axis <> axis_slave
  dma.io.m_axis <> axis_master

  // Status outputs
  busy      := dma.io.busy
  error     := dma.io.error
  done      := dma.io.done
  bytes     := dma.io.bytes
  interrupt := dma.io.interrupt
}

class AXILiteAXIStreamDMA(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  destWidth: Int,
  userWidth: Int,
  baseAddr: BigInt
) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new DMACSR(baseAddr)) {
  override protected def getExtAXIName: String = "S_AXI_CTRL"
  override def desiredName: String =
    s"axilite_axis_dma_${addrWidth}x${dataWidth}_i${idWidth}_d${destWidth}_u${userWidth}"

  // AXI-Stream Interface
  val ext_axis_master = IO(new AXIStreamMasterExternalIO(dataWidth, idWidth, destWidth, userWidth))
    .suggestName("M_AXIS")
  val axis_master = Wire(new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth))

  val ext_axis_slave = IO(new AXIStreamSlaveExternalIO(dataWidth, idWidth, destWidth, userWidth))
    .suggestName("S_AXIS")
  val axis_slave = Wire(new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth))

  // External interrupt
  val interrupt = IO(Output(Bool())).suggestName("INTERRUPT")

  // Submodule: DMA Stream Channel
  val dma = Module(new DMAStreamChannel(addrWidth, dataWidth, idWidth, destWidth, userWidth))

  // Control/Status Registers
  val reg_enable       = RegInit(false.B)
  val reg_int_enable   = RegInit(false.B)
  val ready_pulse      = RegInit(false.B)
  val soft_reset_pulse = RegInit(false.B)

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
  dma.io.descriptor.srcAddr   := 0.U(addrWidth.W)
  dma.io.descriptor.dstAddr   := 0.U(addrWidth.W)
  dma.io.descriptor.length    := reg_length
  dma.io.descriptor.burstSize := reg_burst_size
  dma.io.descriptor.priority  := reg_priority
  dma.io.descriptor.enable    := reg_enable
  dma.io.descriptor.interrupt := reg_int_enable

  dma.io.ready                := ready_pulse || soft_reset_pulse

  // Local soft reset behavior
  when(soft_reset_pulse) {
    done_sticky  := false.B
    error_sticky := false.B
    ready_pulse  := true.B
  }

  // Connect AXI-Stream interfaces
  dma.io.s_axis <> axis_slave
  dma.io.m_axis <> axis_master

  // Interrupt output
  interrupt := dma.io.interrupt && reg_int_enable

  // AW (handled by parent)

  // W
  when(axi_last_write) {
    when(writeAccess("DMA_CTRL")) {
      ready_pulse := axi.w.bits.data(0)
      when(axi.w.bits.data(0)) {
        done_sticky := false.B
      }
      soft_reset_pulse := axi.w.bits.data(1)
      reg_enable       := axi.w.bits.data(2)
      reg_int_enable   := axi.w.bits.data(3)
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
  registerRead("DMA_CTRL", Cat(reg_int_enable, reg_enable, 0.U(1.W), 0.U(1.W)))
  registerRead("DMA_STATUS", Cat(error_sticky, done_sticky, dma.io.busy))
  registerRead("DMA_LENGTH", reg_length)
  registerRead("DMA_BYTES_XFER", bytes_xfer)
  registerRead("DMA_BURST_SIZE", reg_burst_size)
  registerRead("DMA_PRIORITY", reg_priority)

  when(axi_will_read) {
    axi_rresp := Mux(dma.io.error, 2.U, 0.U) // SLVERR if error
  }

  // External interface connections
  ext_axis_master.connect(axis_master)
  ext_axis_slave.connect(axis_slave)
}

object TestAXILiteAXIStreamDMA extends App {
  VerilogEmitter.parse(
    new AXILiteAXIStreamDMA(32, 32, 8, 8, 0, 0x80000000L),
    "axilite_axis_dma.sv",
    info = true
  )
}
