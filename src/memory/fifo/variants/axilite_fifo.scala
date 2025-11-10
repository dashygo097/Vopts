package mem.fifo

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class FIFOCSR(override val baseAddr: BigInt) extends CSRMMap {
  override def registers: Seq[Register] = Seq(
    Register("FIFO_DATA", baseAddr + 0x00),
    Register("FIFO_STATUS", baseAddr + 0x04)
  )
}

class AXILiteSlaveSyncFIFO(
  addrWidth: Int,
  dataWidth: Int,
  depth: Int,
  baseAddr: BigInt
) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new FIFOCSR(baseAddr)) {
  override def desiredName: String = s"axilite_syncfifo_${addrWidth}x${dataWidth}_d$depth"

  val sync_fifo = Module(new SyncFIFO(UInt(dataWidth.W), depth))

  // FIFO Write Path
  val write_to_fifo = axi_on_awrite && writeAccess("FIFO_DATA")
  sync_fifo.io.enq.valid := write_to_fifo && axi.w.valid && !sync_fifo.io.full
  sync_fifo.io.enq.bits  := axi.w.bits.data

  // FIFO Read Path
  val read_from_fifo = axi_on_aread && readAccess("FIFO_DATA")
  sync_fifo.io.deq.ready := read_from_fifo && axi.r.ready && !sync_fifo.io.empty

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(sync_fifo.io.full && write_to_fifo, 2.U, 0.U) // SLVERR if full
  }

  // AR

  // R
  registerRead("FIFO_DATA", sync_fifo.io.deq.bits)
  registerRead("FIFO_STATUS", Cat(sync_fifo.io.empty, sync_fifo.io.full))
  when(axi_will_read) {
    axi_rresp := Mux(sync_fifo.io.empty && read_from_fifo, 2.U, 0.U) // SLVERR if empty
  }
}

object TestAXILiteSlaveSyncFIFO extends App {
  VerilogEmitter.parse(
    new AXILiteSlaveSyncFIFO(32, 32, 64, 0x80000000L),
    "axilite_slave_fifo.sv",
    info = true
  )
}
