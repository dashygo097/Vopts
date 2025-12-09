package mem.register

import utils._
import chisel3._
import chisel3.util._

class DualPortRegFileIO(numRegs: Int, dataWidth: Int) extends Bundle {
  val rs1_addr   = Input(UInt(log2Ceil(numRegs).W))
  val rs2_addr   = Input(UInt(log2Ceil(numRegs).W))
  val write_addr = Input(UInt(log2Ceil(numRegs).W))
  val write_data = Input(UInt(dataWidth.W))
  val write_en   = Input(Bool())

  val rs1_data = Output(UInt(dataWidth.W))
  val rs2_data = Output(UInt(dataWidth.W))

  val rs1_fwd = Output(Bool())
  val rs2_fwd = Output(Bool())
}

class DualPortRegFile(numRegs: Int, dataWidth: Int, extraInfo: Seq[Register] = Seq()) extends Module {
  override def desiredName: String = s"dual_port_regfile_b${dataWidth}_r$numRegs"

  val io = IO(new DualPortRegFileIO(numRegs, dataWidth)).suggestName("REGFILE")

  // Memory
  val regs = RegInit(VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo
      .map(r => (r.initValue & ((1L << dataWidth) - 1)).U(dataWidth.W))
      .getOrElse(0.U(dataWidth.W))
  }))

  // Writable/readable masks
  val writableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo.map(_.writable).getOrElse(true).B
  })

  val readableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo.map(_.readable).getOrElse(true).B
  })

  // Write logic
  when(io.write_en && writableVec(io.write_addr)) {
    regs(io.write_addr) := io.write_data
  }

  // Combinational read with forwarding
  val rs1_raw = regs(io.rs1_addr)
  val rs2_raw = regs(io.rs2_addr)

  // Forwarding detection
  val rs1_fwd_match = io.write_en && writableVec(io.write_addr) && (io.rs1_addr === io.write_addr)
  val rs2_fwd_match = io.write_en && writableVec(io.write_addr) && (io.rs2_addr === io.write_addr)

  io.rs1_fwd := rs1_fwd_match
  io.rs2_fwd := rs2_fwd_match

  // Read data with forwarding and readable check
  io.rs1_data := Mux(
    rs1_fwd_match,
    io.write_data,
    Mux(readableVec(io.rs1_addr), rs1_raw, 0.U)
  )

  io.rs2_data := Mux(
    rs2_fwd_match,
    io.write_data,
    Mux(readableVec(io.rs2_addr), rs2_raw, 0.U)
  )
}

object TestDualPortRegFile extends App {
  VerilogEmitter.parse(
    new DualPortRegFile(
      32,
      32,
      Seq(
        Register("x0", 0x0, 0x0L, writable = false, readable = true),
        Register("x1", 0x1, 0x0L, writable = false, readable = false)
      )
    ),
    "dual_port_regfile.sv",
    info = true
  )
}
