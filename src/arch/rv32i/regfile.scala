package arch.rv32i

import mem.register._
import chisel3._

// NOTE: Architecture Specific
class RV32IRegFile(dataWidth: Int, numReg: Int) extends Module {
  val io = IO(new DualReadRegFileIO(UInt(32.W), 32)).suggestName("RV32I_REGFILE")
  val regFile = new DualReadRegFileCore(UInt(32.W), 32)

  regFile.io.raddr1 := io.raddr1
  regFile.io.raddr2 := io.raddr2
  regFile.io.waddr := io.waddr
  regFile.io.we := io.we && (io.waddr =/= 0.U) // x0 is always 0
  regFile.io.wdata := io.wdata

  io.rdata1 := Mux(io.raddr1 === 0.U, 0.U, regFile.io.rdata1)
  io.rdata2 := Mux(io.raddr2 === 0.U, 0.U, regFile.io.rdata2)
}
