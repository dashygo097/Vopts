package vopts.mem.register

import vopts.utils._
import chisel3._
import chisel3.util._

class MultiPortRegFile(numRegs: Int, dataWidth: Int, numReadPairs: Int, numWritePorts: Int, extraInfo: Seq[Register] = Seq(), isBypass: Boolean = false) extends Module {
  override def desiredName: String = s"multi_port_regfile_b${dataWidth}_r$numRegs"

  val rs1_addr   = IO(Input(Vec(numReadPairs, UInt(log2Ceil(numRegs).W)))).suggestName("RS1_ADDR")
  val rs2_addr   = IO(Input(Vec(numReadPairs, UInt(log2Ceil(numRegs).W)))).suggestName("RS2_ADDR")
  val write_addr = IO(Input(Vec(numWritePorts, UInt(log2Ceil(numRegs).W)))).suggestName("WRITE_ADDR")
  val write_data = IO(Input(Vec(numWritePorts, UInt(dataWidth.W)))).suggestName("WRITE_DATA")
  val write_en   = IO(Input(Vec(numWritePorts, Bool()))).suggestName("WRITE_EN")
  val rs1_data   = IO(Output(Vec(numReadPairs, UInt(dataWidth.W)))).suggestName("RS1_DATA")
  val rs2_data   = IO(Output(Vec(numReadPairs, UInt(dataWidth.W)))).suggestName("RS2_DATA")

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
      for (w <- 0 until numWritePorts)
        when(write_en(w) && write_addr(w) === i.U) {
          regsSeq(i) := write_data(w)
        }
    }

  for (i <- 0 until numReadPairs) {
    val rs1_raw = regsVec(rs1_addr(i))
    val rs2_raw = regsVec(rs2_addr(i))

    if (isBypass) {
      var rs1_bypassed = rs1_raw
      var rs2_bypassed = rs2_raw

      for (w <- 0 until numWritePorts) {
        val is_w      = VecInit(isWritable.map(_.B))(write_addr(w))
        val match_rs1 = write_en(w) && is_w && (rs1_addr(i) === write_addr(w))
        val match_rs2 = write_en(w) && is_w && (rs2_addr(i) === write_addr(w))

        rs1_bypassed = Mux(match_rs1, write_data(w), rs1_bypassed)
        rs2_bypassed = Mux(match_rs2, write_data(w), rs2_bypassed)
      }

      rs1_data(i) := Mux(readableVec(rs1_addr(i)), rs1_bypassed, 0.U)
      rs2_data(i) := Mux(readableVec(rs2_addr(i)), rs2_bypassed, 0.U)
    } else {
      rs1_data(i) := Mux(readableVec(rs1_addr(i)), rs1_raw, 0.U)
      rs2_data(i) := Mux(readableVec(rs2_addr(i)), rs2_raw, 0.U)
    }
  }
}
