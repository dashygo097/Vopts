package mem.register

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

class DualPortRegFile(numRegs: Int, dataWidth: Int, extraInfo: Seq[Register] = Seq())
    extends Module {
  override def desiredName: String = s"dual_port_regfile_b${dataWidth}_r$numRegs"

  val io     = IO(new DualPortRegFileIO(numRegs, dataWidth)).suggestName("REGFILE")
  val regMem = SyncReadMem(numRegs, UInt(dataWidth.W))

  val initMemory = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo.map(r => (r.initValue & ((1L << dataWidth) - 1)).U).getOrElse(0.U)
  })

  val writableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo.map(_.writable).getOrElse(true).B
  })

  val readableVec = VecInit(Seq.tabulate(numRegs) { addr =>
    val regInfo = extraInfo.find(_.addr == addr)
    regInfo.map(_.readable).getOrElse(true).B
  })

  def writable(addr: UInt): Bool = writableVec(addr)
  def readable(addr: UInt): Bool = readableVec(addr)

  when(io.write_en && writable(io.write_addr)) {
    regMem.write(io.write_addr, io.write_data)
  }

  val rs1_raw = regMem.read(io.rs1_addr)
  val rs2_raw = regMem.read(io.rs2_addr)

  io.rs1_fwd := io.write_en && (io.rs1_addr === io.write_addr)
  io.rs2_fwd := io.write_en && (io.rs2_addr === io.write_addr)

  io.rs1_data := Mux(
    io.rs1_fwd,
    io.write_data,
    Mux(readable(io.rs1_addr), rs1_raw, initMemory(io.rs1_addr))
  )
  io.rs2_data := Mux(
    io.rs2_fwd,
    io.write_data,
    Mux(readable(io.rs2_addr), rs2_raw, initMemory(io.rs2_addr))
  )
}
