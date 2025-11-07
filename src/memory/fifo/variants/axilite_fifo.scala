package mem.fifo

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class AXILiteSlaveSyncFIFO(
  addrWidth: Int,
  dataWidth: Int,
  depth: Int,
  baseAddr: BigInt
) extends AXILiteSlave(addrWidth, dataWidth) {
  override def desiredName: String = s"axilite_syncfifo_${addrWidth}x${dataWidth}_d$depth"

  val sync_fifo = Module(new SyncFIFO(UInt(dataWidth.W), depth))

  // Address decoding
  val FIFO_ADDR        = (baseAddr + 0x00).U(addrWidth.W)
  val FIFO_STATUS_ADDR = (baseAddr + 0x04).U(addrWidth.W)

  // FIFO Write Path
  val write_to_fifo = axi_awready && axi.aw.valid && (axi.aw.bits.addr === FIFO_ADDR)
  sync_fifo.io.enq.valid := write_to_fifo && axi.w.valid
  sync_fifo.io.enq.bits  := axi.w.bits.data

  // FIFO Read Path
  val read_from_fifo = axi_arready && axi.ar.valid && (axi.ar.bits.addr === FIFO_ADDR)
  sync_fifo.io.deq.ready := read_from_fifo && axi.r.ready

  // Multiplexed Read Data
  when(axi.ar.bits.addr === FIFO_ADDR) {
    axi_rdata := sync_fifo.io.deq.bits
  }.elsewhen(axi.ar.bits.addr === FIFO_STATUS_ADDR) {
    axi_rdata := Cat(sync_fifo.io.empty, sync_fifo.io.full) // [1]: empty, [0]: full
  }.otherwise {
    axi_rdata := 0.U
  }

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(sync_fifo.io.full && write_to_fifo, 2.U, 0.U) // SLVERR if full
  }

  // AR

  // R
  when(axi_will_read) {
    axi_rresp := Mux(sync_fifo.io.empty && read_from_fifo, 2.U, 0.U) // SLVERR if empty
  }
}

object TestAXILiteSlaveSyncFIFO extends App {
  VerilogEmitter.parse(
    new AXILiteSlaveSyncFIFO(32, 32, 64, 0x30000),
    "axilite_slave_fifo.sv",
    info = true
  )
}
