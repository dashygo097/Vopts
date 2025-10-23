package mem.fifo

import com.axi._
import utils._
import chisel3._
import chisel3.util._

class AXILiteSlaveSyncFIFO(
  addrWidth: Int,
  dataWidth: Int,
  depth: Int,
  baseAddr: BigInt = 0x0L
) extends Module {
  override def desiredName: String = s"axilite_syncfifo_${dataWidth}x${depth}"

  val ext_axi = IO(new AXILiteSlaveExternalIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val axi = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  val sync_fifo = Module(new SyncFIFO(UInt(dataWidth.W), depth))

  // Address decoding
  val fifo_write_addr = (baseAddr + 0x00).U(addrWidth.W)
  val fifo_read_addr = (baseAddr + 0x04).U(addrWidth.W)
  val fifo_status_addr = (baseAddr + 0x08).U(addrWidth.W)

  // AXI Lite Signals
  val axi_awready = RegInit(false.B)
  val axi_awaddr = RegInit(0.U(addrWidth.W))
  val axi_wready = RegInit(false.B)
  val axi_bvalid = RegInit(false.B)
  val axi_bresp = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr = RegInit(0.U(addrWidth.W))
  val axi_rdata = RegInit(0.U(dataWidth.W))
  val axi_rvalid = RegInit(false.B)
  val axi_rresp = RegInit(0.U(2.W))

  // I/O Connections
  axi.aw.ready := axi_awready
  axi.w.ready := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid := axi_bvalid
  axi.ar.ready := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid := axi_rvalid

  // FIFO Write Path (Write Address Channel)
  val write_to_fifo = axi_awready && axi.aw.valid && (axi.aw.bits.addr === fifo_write_addr)
  sync_fifo.io.enq.valid := write_to_fifo && axi.w.valid
  sync_fifo.io.enq.bits := axi.w.bits.data

  // FIFO Read Path (Read Address Channel)
  val read_from_fifo = axi_arready && axi.ar.valid && (axi.ar.bits.addr === fifo_read_addr)
  sync_fifo.io.deq.ready := read_from_fifo && axi.r.ready

  // Multiplexed Read Data
  when(axi.ar.bits.addr === fifo_read_addr) {
    axi_rdata := sync_fifo.io.deq.bits
  }.elsewhen(axi.ar.bits.addr === fifo_status_addr) {
    axi_rdata := Cat(sync_fifo.io.empty, sync_fifo.io.full)
  }.otherwise {
    axi_rdata := 0.U
  }

  // Address Write Channel
  when(!axi_awready && axi.aw.valid) {
    axi_awaddr := axi.aw.bits.addr
    axi_awready := true.B
  }.otherwise {
    axi_awready := false.B
  }

  // Data Write Channel
  when(!axi_wready && axi_awready && axi.aw.valid) {
    axi_wready := true.B
  }.otherwise {
    when(axi_wready && axi.w.valid) {
      axi_wready := false.B
    }
  }

  // Write Response Channel
  when(!axi_bvalid && axi_wready && axi.w.valid) {
    axi_bvalid := true.B
    axi_bresp := Mux(sync_fifo.io.full && write_to_fifo, 2.U, 0.U) // SLVERR if full
  }.otherwise {
    when(axi.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }

  // Address Read Channel
  when(!axi_arready && axi.ar.valid) {
    axi_araddr := axi.ar.bits.addr
    axi_arready := true.B
  }.otherwise {
    axi_arready := false.B
  }

  // Data Read Channel
  when(!axi_rvalid && axi_arready && axi.ar.valid) {
    axi_rvalid := true.B
    axi_rresp := Mux(sync_fifo.io.empty && read_from_fifo, 2.U, 0.U) // SLVERR if empty
  }.otherwise {
    when(axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  ext_axi.connect(axi)
}

object TestAXILiteSlaveSyncFIFO extends App {
  VerilogEmitter.parse(new AXILiteSlaveSyncFIFO(32, 32, 64, 0x30000), "axi_lite_slave_fifo.sv", info=true)
}
