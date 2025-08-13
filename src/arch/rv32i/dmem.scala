package arch.rv32i

import chisel3._

class RV32IDMemIO extends Bundle {}

class RV32IDMem extends Module {
  val io = IO(new RV32IDMemIO).suggestName("RV32I_DMEM")
}
