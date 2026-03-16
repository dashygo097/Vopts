package vopts.mem.register

import vopts.utils._
import chisel3._
import chisel3.util._

class DualPortRegFile(numRegs: Int, dataWidth: Int, extraInfo: Seq[Register] = Seq(), isBypass: Boolean = false) extends Module {
  override def desiredName: String = s"dual_port_regfile_b${dataWidth}_r$numRegs"

  val rs1_addr   = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("RS1_ADDR")
  val rs2_addr   = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("RS2_ADDR")
  val write_addr = IO(Input(UInt(log2Ceil(numRegs).W))).suggestName("WRITE_ADDR")
  val write_data = IO(Input(UInt(dataWidth.W))).suggestName("WRITE_DATA")
  val write_en   = IO(Input(Bool())).suggestName("WRITE_EN")
  val rs1_data   = IO(Output(UInt(dataWidth.W))).suggestName("RS1_DATA")
  val rs2_data   = IO(Output(UInt(dataWidth.W))).suggestName("RS2_DATA")

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

  val rs1_raw = regs(rs1_addr)
  val rs2_raw = regs(rs2_addr)

  if (isBypass) {
    val rs1_is_write_target = (rs1_addr === write_addr) && write_en && writableVec(write_addr)
    val rs2_is_write_target = (rs2_addr === write_addr) && write_en && writableVec(write_addr)

    val rs1_bypass = Mux(rs1_is_write_target, write_data, rs1_raw)
    val rs2_bypass = Mux(rs2_is_write_target, write_data, rs2_raw)

    rs1_data := Mux(readableVec(rs1_addr), rs1_bypass, 0.U)
    rs2_data := Mux(readableVec(rs2_addr), rs2_bypass, 0.U)
  } else {
    rs1_data := Mux(readableVec(rs1_addr), rs1_raw, 0.U)
    rs2_data := Mux(readableVec(rs2_addr), rs2_raw, 0.U)
  }
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
