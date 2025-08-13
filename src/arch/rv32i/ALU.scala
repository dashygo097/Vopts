package arch.rv32i

import mem.shift._
import chisel3._

class RV32IALUIO extends Bundle {
  val rs1 = Input(UInt(32.W))
  val rs2 = Input(UInt(32.W))
  val aluCtrl = Input(UInt(4.W))
  val less = Output(Bool())
  val carry = Output(Bool())
  val rout = Output(UInt(32.W))
}

class RV32IALU extends Module {
  val io = IO(new RV32IALUIO).suggestName("RV32I_ALU")
  
  val barrelShift = Module(new BarrelShiftCore(32))
}
