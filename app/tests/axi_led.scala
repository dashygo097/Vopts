package app.test

import app.VerilogEmitter
import com.axi._
import chisel3._

class AXILedSlave(addrWidth: Int, dataWidth: Int) extends Module {
  val io = IO(new Bundle {
    val axi = new AXILiteSlaveIF(addrWidth, dataWidth)
    val led = Output(Bool())
  })

  val ledReg = RegInit(0.U(dataWidth.W))
  io.led := ledReg(0)

  io.axi.writeAddr.ready := true.B
  io.axi.writeData.ready := true.B
  io.axi.writeResp.valid := false.B
  io.axi.writeResp.bits := 0.U

  val write_fire = io.axi.writeAddr.valid && io.axi.writeData.valid
  when(write_fire) {
    when(io.axi.writeAddr.bits.addr === 0.U) {
      ledReg := io.axi.writeData.bits.data
    }
    io.axi.writeResp.valid := true.B
    io.axi.writeResp.bits := 0.U
  }

  io.axi.readAddr.ready := true.B

  io.axi.readData.valid := io.axi.readAddr.valid
  io.axi.readData.bits.resp := 0.U
  io.axi.readData.bits.data := Mux(
    io.axi.readAddr.bits.addr === 0.U,
    ledReg,
    0.U
  )
}

class Top extends Module {
  val led = IO(Output(Bool()))
  val axi = IO(new AXILiteExternalIF(32, 4)).suggestName("S_AXI")

  val slave = Module(new AXILedSlave(32, 4))

  axi.connect(slave.io.axi)
  led := slave.io.led
}

object AXILedTest extends App {
  VerilogEmitter.parse(new Top, "axi_led.sv")
}

