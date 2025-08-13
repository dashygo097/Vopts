package arch.rv32i

import mem.shift._
import chisel3._
import chisel3.util._

class RV32IAdderIO extends Bundle {
  val rs1 = Input(UInt(32.W))
  val rs2 = Input(UInt(32.W))
  val cin = Input(Bool())
  val carry = Output(Bool())
  val zero = Output(Bool())
  val overflow = Output(Bool())
  val result = Output(UInt(32.W))
}

class RV32IALUIO extends Bundle {
  val rs1 = Input(UInt(32.W))
  val rs2 = Input(UInt(32.W))
  val aluCtrl = Input(UInt(4.W))
  val less = Output(Bool())
  val zero = Output(Bool())
  val dout = Output(UInt(32.W))
}

class RV32IAdder extends Module {
  val io = IO(new RV32IAdderIO).suggestName("RV32I_ADDER")
  val sum = Wire(UInt(33.W))
  sum := io.rs1 + Mux(io.cin, ~io.rs2, io.rs2) + Mux(io.cin, 1.U, 0.U)
  io.result := sum(31, 0)
  io.carry := sum(32)
  io.zero := (sum(31, 0) === 0.U)
  io.overflow := (io.rs1(31) === io.rs2(31)) && (io.rs1(31) =/= sum(31))
}

class RV32IALU extends Module {
  val io = IO(new RV32IALUIO).suggestName("RV32I_ALU")
  val barrelShift = Module(new BarrelShiftCore(32))
  val adder = Module(new RV32IAdder)

  val al = Wire(Bool())
  val lr = Wire(Bool())
  val us = Wire(Bool())
  val sub = Wire(Bool())

  lr := ~io.aluCtrl(2)
  al := io.aluCtrl(3)

  barrelShift.io.in := io.rs1
  barrelShift.io.shamt := io.rs2(4, 0)
  barrelShift.io.lr := lr
  barrelShift.io.al := al

  adder.io.rs1 := io.rs1
  adder.io.rs2 := io.rs2
  adder.io.cin := sub

  io.zero := adder.io.zero
  io.less := Mux(us, sub ^ adder.io.carry, adder.io.overflow ^ adder.io.result(31))
  io.dout := MuxLookup(io.aluCtrl(2, 0), 0.U)(Seq(
    0.U -> adder.io.result,
    1.U -> barrelShift.io.out,
    2.U -> 0.U,  // Not impl yet
    3.U -> io.rs2,
    4.U -> (io.rs1 ^ io.rs2),
    5.U -> barrelShift.io.out,
    6.U -> (io.rs1 | io.rs2),
    7.U -> (io.rs1 & io.rs2)
    )
  )
}
