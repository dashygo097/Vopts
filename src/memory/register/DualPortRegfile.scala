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

  val isWritable = Seq.tabulate(numRegs) { addr =>
    extraInfo.find(_.addr == addr).forall(_.writable)
  }

  val readableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    extraInfo.find(_.addr == addr).forall(_.readable).B
  })

  val regsSeq = Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    val initVal = regInfo
      .map(r => (r.initValue & ((1L << dataWidth) - 1)).U(dataWidth.W))
      .getOrElse(0.U(dataWidth.W))

    val r    = RegInit(initVal)
    val name = regInfo.map(_.name).getOrElse(s"x$addr")
    r.suggestName(name)
    r
  }

  val regsVec = VecInit(regsSeq)

  for (i <- 0 until numRegs)
    if (isWritable(i)) {
      when(write_en && write_addr === i.U) {
        regsSeq(i) := write_data
      }
    }

  val rs1_raw = regsVec(rs1_addr)
  val rs2_raw = regsVec(rs2_addr)

  if (isBypass) {
    val write_target_is_writable = VecInit(isWritable.map(_.B))(write_addr)

    val rs1_is_write_target = write_en && write_target_is_writable && (rs1_addr === write_addr)
    val rs2_is_write_target = write_en && write_target_is_writable && (rs2_addr === write_addr)

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
        Register("zero", 0x0, 0x0L, writable = false, readable = true),
        Register("ra", 0x1, 0x0L, writable = true, readable = true)
      )
    ),
    "dual_port_regfile.sv",
    info = true
  )
}
