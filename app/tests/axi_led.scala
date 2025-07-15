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

  val writeRespValid = RegInit(false.B)

  when(io.axi.writeAddr.fire && io.axi.writeData.fire && !writeRespValid) {
    when(io.axi.writeAddr.bits.addr === 0.U) {
      ledReg := io.axi.writeData.bits.data
    }
    writeRespValid := true.B
  }

  io.axi.writeResp.valid := writeRespValid
  io.axi.writeResp.bits := 0.U
  when(writeRespValid && io.axi.writeResp.ready) {
    writeRespValid := false.B
  }

  val readAddrReg = Reg(UInt(addrWidth.W))
  val readPending = RegInit(false.B)

  when(io.axi.readAddr.fire && !readPending) {
    readAddrReg := io.axi.readAddr.bits.addr
    readPending := true.B
  }

  io.axi.readAddr.ready := !readPending
  io.axi.readData.valid := readPending
  io.axi.readData.bits.resp := 0.U
  io.axi.readData.bits.data := Mux(readAddrReg === 0.U, ledReg, 0.U)

  when(io.axi.readData.fire) {
    readPending := false.B
  }
}

class Top extends Module {
  val led = IO(Output(Bool()))
  val axi = IO(new AXILiteExternalIF(32, 8)).suggestName("S_AXI")

  val slave = Module(new AXILedSlave(32, 8))

  axi.connect(slave.io.axi)
  led := slave.io.led
}

object AXILedTest extends App {
  VerilogEmitter.parse(new Top, "axi_led.sv")
}

