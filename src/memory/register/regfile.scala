package mem.register

import utils._
import chisel3._
import chisel3.util._

class DualPortRegFile(numRegs: Int, dataWidth: Int, extraInfo: Seq[Register] = Seq()) extends Module {
  override def desiredName: String = s"dual_port_regfile_b${dataWidth}_r$numRegs"

  val rs1_addr   = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("RS1_ADDR")
  val rs2_addr   = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("RS2_ADDR")
  val write_addr = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("WRITE_ADDR")
  val write_data = IO(Input(UInt(dataWidth.W))).suggestName("WRITE_DATA")
  val write_en   = IO(Input(Bool())).suggestName("WRITE_EN")
  val rs1_data   = IO(Output(UInt(dataWidth.W))).suggestName("RS1_DATA")
  val rs2_data   = IO(Output(UInt(dataWidth.W))).suggestName("RS2_DATA")
  val rs1_fwd    = IO(Output(Bool())).suggestName("RS1_FWD")
  val rs2_fwd    = IO(Output(Bool())).suggestName("RS2_FWD")

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
  when(write_en && writableVec(write_addr)) {
    regs(write_addr) := write_data
  }

  // Combinational read with forwarding
  val rs1_raw = regs(rs1_addr)
  val rs2_raw = regs(rs2_addr)

  // Forwarding detection
  val rs1_fwd_match = write_en && writableVec(write_addr) && (rs1_addr === write_addr)
  val rs2_fwd_match = write_en && writableVec(write_addr) && (rs2_addr === write_addr)

  rs1_fwd := rs1_fwd_match
  rs2_fwd := rs2_fwd_match

  // Read data with forwarding and readable check
  rs1_data := Mux(
    rs1_fwd_match,
    write_data,
    Mux(readableVec(rs1_addr), rs1_raw, 0.U)
  )

  rs2_data := Mux(
    rs2_fwd_match,
    write_data,
    Mux(readableVec(rs2_addr), rs2_raw, 0.U)
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
