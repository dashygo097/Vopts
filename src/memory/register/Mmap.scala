package vopts.mem.register

import vopts.utils._
import chisel3._
import chisel3.util._

// Memory Mapped I/O Interface
class MMapRegistersIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  // Write Interface
  val write_en   = Input(Bool())
  val write_addr = Input(UInt(addrWidth.W))
  val write_data = Input(UInt(dataWidth.W))
  val write_strb = Input(UInt((dataWidth / 8).W))
  val write_resp = Output(Bool()) // true = OKAY, false = SLVERR

  // Read Interface
  val read_en   = Input(Bool())
  val read_addr = Input(UInt(addrWidth.W))
  val read_data = Output(UInt(dataWidth.W))
  val read_resp = Output(Bool()) // true = OKAY, false = SLVERR
}

// Memory Mapped Registers Module
class MMapRegisters(
  addrWidth: Int,
  dataWidth: Int,
  mmap: Seq[Register],
) extends Module {
  override def desiredName: String =
    s"mmap_regs_${addrWidth}x${dataWidth}_r${mmap.length}"

  // Parameter Checks
  val maxDataValue = BigInt(1) << dataWidth
  val maxAddrValue = BigInt(1) << addrWidth
  for (reg <- mmap) {
    require(
      reg.addr >= 0 && reg.addr < maxAddrValue,
      s"Register ${reg.name} address ${reg.addr} out of range"
    )
    require(
      reg.initValue >= 0 && reg.initValue < maxDataValue,
      s"Register ${reg.name} init value ${reg.initValue} out of range"
    )
  }

  // IO Interface
  val addr_map = mmap.map(_.addr.U(addrWidth.W))
  val io       = IO(new MMapRegistersIO(addrWidth, dataWidth)).suggestName("MMAP")

  val writable_vec = VecInit(mmap.map(_.writable.B))
  val readable_vec = VecInit(mmap.map(_.readable.B))

  // Signals
  val regs = mmap.zipWithIndex.map { case (reg, i) =>
    val regInst = RegInit(reg.initValue.U(dataWidth.W))
    regInst.suggestName(reg.name)
    regInst
  }

  val byte_banks           = Wire(Vec(dataWidth / 8, UInt(8.W)))
  val write_addr_match     = Wire(Bool())
  val read_addr_match      = Wire(Bool())
  val write_access_allowed = Wire(Bool())
  val read_access_allowed  = Wire(Bool())

  // Default Outputs
  io.write_resp := write_addr_match
  io.read_resp  := read_addr_match

  write_addr_match := addr_map.map(_ === io.write_addr).reduce(_ || _)
  read_addr_match  := addr_map.map(_ === io.read_addr).reduce(_ || _)

  write_access_allowed := write_addr_match &&
    MuxCase(
      false.B,
      mmap.zipWithIndex.map { case (reg, i) =>
        (io.write_addr === addr_map(i)) -> writable_vec(i)
      }
    )

  read_access_allowed := read_addr_match &&
    MuxCase(
      false.B,
      mmap.zipWithIndex.map { case (reg, i) =>
        (io.read_addr === addr_map(i)) -> readable_vec(i)
      }
    )

  for (i <- 0 until (dataWidth / 8))
    byte_banks(i) := io.write_data(8 * (i + 1) - 1, 8 * i)

  // Write Logic
  when(io.write_en && write_access_allowed) {
    for (i <- 0 until mmap.length)
      when(io.write_addr === addr_map(i)) {
        when(writable_vec(i)) {
          regs(i) := Cat((0 until (dataWidth / 8)).map { j =>
            Mux(io.write_strb(j), byte_banks(j), regs(i)(8 * (j + 1) - 1, 8 * j))
          }.reverse)
        }
      }
  }

  // Read Logic
  when(io.read_en && read_access_allowed) {
    io.read_data := MuxCase(
      0.U,
      mmap.zipWithIndex.map { case (reg, i) =>
        (io.read_addr === addr_map(i)) -> Mux(readable_vec(i), regs(i), 0.U)
      }
    )
  }.otherwise {
    io.read_data := 0.U
  }
}
