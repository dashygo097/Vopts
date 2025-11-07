package mem.fifo

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class AXILiteSlavePingPongFIFO(
  addrWidth: Int,
  dataWidth: Int,
  depth: Int,
  baseAddr: BigInt
) extends AXILiteSlave(addrWidth, dataWidth) {
  override def desiredName: String = s"axilite_pingpong_${addrWidth}x${dataWidth}_d$depth"

  val pingpong = Module(new PingPongFIFO(UInt(dataWidth.W), depth))

  // Address decoding
  val PINGPONG_ADDR        = (baseAddr + 0x00).U(addrWidth.W)
  val PINGPONG_STATUS_ADDR = (baseAddr + 0x04).U(addrWidth.W)

  // Write Path
  val write_valid = axi_awready && axi.aw.valid && (axi.aw.bits.addr === PINGPONG_ADDR)
  pingpong.io.write_port.valid := write_valid && axi.w.valid
  pingpong.io.write_port.bits  := axi.w.bits.data

  // Read Path
  val read_valid = axi_arready && axi.ar.valid && (axi.ar.bits.addr === PINGPONG_ADDR)
  pingpong.io.read_port.ready := read_valid && axi.r.ready

  // Multiplex read data
  when(axi.ar.bits.addr === PINGPONG_ADDR) {
    axi_rdata := pingpong.io.read_port.bits
  }.elsewhen(axi.ar.bits.addr === PINGPONG_STATUS_ADDR) {
    // Status: [1]=read_empty, [0]=write_full
    axi_rdata := Cat(pingpong.io.read_buffer_empty, pingpong.io.write_buffer_full)
  }.otherwise {
    axi_rdata := 0.U
  }

  // AW

  // W

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(pingpong.io.write_buffer_full, 2.U, 0.U)
  }

  // AR

  // R
  when(axi_will_read) {
    axi_rresp := Mux(pingpong.io.read_buffer_empty, 2.U, 0.U)
  }
}

object TestAXILiteSlavePingPong extends App {
  VerilogEmitter.parse(
    new AXILiteSlavePingPongFIFO(32, 32, 16, 0x80000000L),
    "axilite_slave_pingpong.sv",
    info = true
  )
}
