package mem.ram

import com.amba._
import utils._
import chisel3._

class AXIFullSlaveRAM(
  addrWidth: Int,
  dataWidth: Int,
  idWidth: Int,
  userWidth: Int,
  memSize: Int,
  baseAddr: BigInt
) extends AXIFullSlave(addrWidth, dataWidth, idWidth, userWidth, memSize) {
  override def desiredName: String =
    s"axifull_slave_ram_${addrWidth}x${dataWidth}_i${idWidth}_u${userWidth}_s${memSize}_b$baseAddr"

  // User Interface
  val mmap_region = Module(new MMapRegion(addrWidth, dataWidth, memSize, baseAddr, false))

  // User I/O Connections
  mmap_region.io.write_en   := axi_wready && axi.w.valid
  mmap_region.io.write_addr := axi_awaddr
  mmap_region.io.write_data := axi.w.bits.data
  mmap_region.io.write_strb := axi.w.bits.strb
  aw_addr_valid             := mmap_region.io.write_resp

  mmap_region.io.read_en   := axi_arready || axi_rvalid
  mmap_region.io.read_addr := axi_araddr
  ar_addr_valid            := mmap_region.io.read_resp
  axi_rdata                := Mux(axi_rvalid && ar_addr_valid, mmap_region.io.read_data, 0.U(dataWidth.W))

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(aw_addr_valid, 0.U, 2.U)
  }

  // AR

  // R
  when(axi_on_read) {
    axi_rresp := Mux(ar_addr_valid, 0.U, 2.U)
  }

  ext_axi.connect(axi)
}

object TestAXIFullSlaveRAM extends App {
  VerilogEmitter.parse(
    new AXIFullSlaveRAM(32, 32, 4, 1, 8, 0x80000000L),
    "axifull_slave_ram.sv",
    info = true
  )
}
