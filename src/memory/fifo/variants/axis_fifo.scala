package mem.fifo

import com.amba._
import chisel3._
import chisel3.util._

class AXIStreamFIFO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int, depth: Int) extends AXIStreamChannel(dataWidth, idWidth, destWidth, userWidth) {
  override def desiredName: String = s"axis_syncfifo_${dataWidth}x$depth"

  val empty = IO(Output(Bool())).suggestName("EMPTY")
  val full  = IO(Output(Bool())).suggestName("FULL")
  val count = IO(Output(UInt(log2Ceil(depth + 1).W))).suggestName("COUNT")

  // Module
  val fifo = Module(new SyncFIFO(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth), depth))

  // I/O Connections
  fifo.io.enq.valid  := axis_slave.t.valid
  fifo.io.enq.bits   := axis_slave.t.bits
  axis_slave.t.ready := !fifo.io.full

  axis_master.t.valid := !fifo.io.empty
  axis_master.t.bits  := fifo.io.deq.bits
  fifo.io.deq.ready   := axis_master.t.ready

  count := fifo.io.count
  full  := fifo.io.full
  empty := fifo.io.empty
}

class AXILiteAXIStreamFIFO(addrWidth: Int, dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int, depth: Int, baseAddr: BigInt) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new FIFOCSR(baseAddr)) {
  override def desiredName: String = s"axilite_axis_fifo_${dataWidth}x$depth"

  // AXI-Stream Interface
  val axis_master_ext = IO(new AXIStreamMasterExtIO(dataWidth, idWidth, destWidth, userWidth)).suggestName("M_AXIS")
  val axis_master     = Wire(new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth))
  val axis_slave_ext  = IO(new AXIStreamSlaveExtIO(dataWidth, idWidth, destWidth, userWidth)).suggestName("S_AXIS")
  val axis_slave      = Wire(new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth))

  // Module
  val fifo = Module(new SyncFIFO(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth), depth))

  // AXI-Lite Write Path to FIFO
  val write_to_fifo        = axi_on_awrite && writeAccess("FIFO_DATA")
  val axilite_write_enable = write_to_fifo && axi.w.valid && !fifo.io.full

  // AXI-Lite Read Path from FIFO
  val read_from_fifo      = axi_on_aread && readAccess("FIFO_DATA")
  val axilite_read_enable = read_from_fifo && axi.r.ready && !fifo.io.empty

  // I/O Connections
  axis_slave.t.ready := !fifo.io.full && !axilite_write_enable

  axis_master.t.valid := !fifo.io.empty && !read_from_fifo
  axis_master.t.bits  := fifo.io.deq.bits

  when(axilite_write_enable) {
    fifo.io.enq.valid     := true.B
    fifo.io.enq.bits.data := axi.w.bits.data
    fifo.io.enq.bits.strb := Fill(dataWidth / 8, 1.U)
    fifo.io.enq.bits.keep := Fill(dataWidth / 8, 1.U)
    fifo.io.enq.bits.last := false.B
    fifo.io.enq.bits.id   := 0.U
    fifo.io.enq.bits.dest := 0.U
    fifo.io.enq.bits.user := 0.U
  }.elsewhen(axis_slave.t.valid && !fifo.io.full) {
    fifo.io.enq.valid := true.B
    fifo.io.enq.bits  := axis_slave.t.bits
  }.otherwise {
    fifo.io.enq.valid := false.B
    fifo.io.enq.bits  := 0.U.asTypeOf(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth))
  }

  when(axilite_read_enable) {
    fifo.io.deq.ready := true.B
  }.elsewhen(axis_master.t.ready && !fifo.io.empty) {
    fifo.io.deq.ready := true.B
  }.otherwise {
    fifo.io.deq.ready := false.B
  }

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(fifo.io.full && write_to_fifo, 2.U, 0.U) // SLVERR if full
  }

  // AR

  // R
  registerRead("FIFO_DATA", fifo.io.deq.bits.data)
  registerRead("FIFO_STATUS", Cat(fifo.io.empty, fifo.io.full))
  registerRead("FIFO_COUNTER", fifo.io.count)

  when(axi_will_read) {
    axi_rresp := Mux(fifo.io.empty && read_from_fifo, 2.U, 0.U) // SLVERR if empty
  }

  axis_master_ext.connect(axis_master)
  axis_slave_ext.connect(axis_slave)
}
