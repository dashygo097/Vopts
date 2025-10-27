package mem.fifo

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class AXILiteSlavePingPongFIFO(
  addrWidth: Int,
  dataWidth: Int,
  depth: Int,
  baseAddr: BigInt = 0x0L
) extends Module {
  override def desiredName: String = s"axilite_pingpong_${addrWidth}x${dataWidth}_d$depth"

  val ext_axi = IO(new AXILiteSlaveExternalIO(addrWidth, dataWidth)).suggestName("S_AXI")
  val axi     = Wire(new AXILiteSlaveIO(addrWidth, dataWidth))

  val pingpong = Module(new PingPongFIFO(UInt(dataWidth.W), depth))

  // Address decoding
  val pingpong_addr        = (baseAddr + 0x00).U(addrWidth.W)
  val pingpong_status_addr = (baseAddr + 0x04).U(addrWidth.W)

  // AXI Lite Signals
  val axi_awready = RegInit(false.B)
  val axi_awaddr  = RegInit(0.U(addrWidth.W))
  val axi_wready  = RegInit(false.B)
  val axi_bvalid  = RegInit(false.B)
  val axi_bresp   = RegInit(0.U(2.W))
  val axi_arready = RegInit(false.B)
  val axi_araddr  = RegInit(0.U(addrWidth.W))
  val axi_rdata   = RegInit(0.U(dataWidth.W))
  val axi_rvalid  = RegInit(false.B)
  val axi_rresp   = RegInit(0.U(2.W))

  // I/O Connections
  axi.aw.ready    := axi_awready
  axi.w.ready     := axi_wready
  axi.b.bits.resp := axi_bresp
  axi.b.valid     := axi_bvalid
  axi.ar.ready    := axi_arready
  axi.r.bits.data := axi_rdata
  axi.r.bits.resp := axi_rresp
  axi.r.valid     := axi_rvalid

  // Write Path
  val write_valid = axi_awready && axi.aw.valid && (axi.aw.bits.addr === pingpong_addr)
  pingpong.io.write_port.valid := write_valid && axi.w.valid
  pingpong.io.write_port.bits  := axi.w.bits.data

  // Read Path
  val read_valid = axi_arready && axi.ar.valid && (axi.ar.bits.addr === pingpong_addr)
  pingpong.io.read_port.ready := read_valid && axi.r.ready

  // Multiplex read data
  when(axi.ar.bits.addr === pingpong_addr) {
    axi_rdata := pingpong.io.read_port.bits
  }.elsewhen(axi.ar.bits.addr === pingpong_status_addr) {
    // Status: [1]=read_empty, [0]=write_full
    axi_rdata := Cat(pingpong.io.read_buffer_empty, pingpong.io.write_buffer_full)
  }.otherwise {
    axi_rdata := 0.U
  }

  // Address Write Channel
  when(!axi_awready && axi.aw.valid) {
    axi_awaddr  := axi.aw.bits.addr
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
    axi_bresp  := Mux(pingpong.io.write_buffer_full, 2.U, 0.U)
  }.otherwise {
    when(axi.b.ready && axi_bvalid) {
      axi_bvalid := false.B
    }
  }

  // Address Read Channel
  when(!axi_arready && axi.ar.valid) {
    axi_araddr  := axi.ar.bits.addr
    axi_arready := true.B
  }.otherwise {
    axi_arready := false.B
  }

  // Data Read Channel
  when(!axi_rvalid && axi_arready && axi.ar.valid) {
    axi_rvalid := true.B
    axi_rresp  := Mux(pingpong.io.read_buffer_empty, 2.U, 0.U)
  }.otherwise {
    when(axi_rvalid && axi.r.ready) {
      axi_rvalid := false.B
    }
  }

  ext_axi.connect(axi)
}

object TestAXILiteSlavePingPong extends App {
  VerilogEmitter.parse(
    new AXILiteSlavePingPongFIFO(32, 32, 16, 0x40000L),
    "axi_lite_slave_pingpong.sv",
    info = true
  )
}
