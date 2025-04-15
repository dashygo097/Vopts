package fmc 

import chisel3._
import chisel3.util._

import chisel3.experimental.Analog

class FSMCSRAMCoreIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr = Output(UInt(addrWidth.W))
  val data = Analog(dataWidth.W)
  val lclk = Output(Bool())
  val ne = Input(Bool())
  val oe = Input(Bool())
  val we = Input(Bool())
  val waitn = Output(Bool())
}

class FSMCSRAMCore(addrWidth: Int , dataWidth: Int) extends Module {
  val io = IO(new FSMCSRAMCoreIO(addrWidth, dataWidth))

  val mem = SyncReadMem(addrWidth, UInt(dataWidth.W))

  val dataDriver = Wire(Bool())
  val dataBuf = Wire(UInt(dataWidth.W))
  
  dataDriver := !io.oe && !io.we && !io.ne

  when(!io.oe && !io.we) {
    dataBuf := io.data.asUInt
    mem.write(io.addr, dataIn)
  } .elsewhen(!io.ne && !io.oe) {
    dataBuf := mem.read(io.addr)
    attach(io.data, dataBuf)
  } .otherwise {
    dataBuf := 0.U
  }

}


