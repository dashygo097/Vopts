package mem.ram

import chisel3._
import chisel3.util._

class MMapRegionIO(addrWidth: Int, dataWidth: Int) extends Bundle {
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

class MMapRegion(addrWidth: Int, dataWidth: Int, memSize: BigInt, baseAddr: BigInt = 0x0) extends Module {
  override def desiredName: String =
    s"ram_${addrWidth}x${dataWidth}_s${memSize}_b$baseAddr"
  val maxAddrValue                 = BigInt(1) << addrWidth
  require(
    memSize > 0 && baseAddr >= 0 && (baseAddr + (memSize * dataWidth)) <= maxAddrValue,
    s"RAM address out of range for addrWidth $addrWidth"
  )

  // Parameters
  val addr_lsb          = log2Ceil(dataWidth / 8)
  val opt_mem_addr_bits = log2Ceil(memSize.toInt)

  // I/O Interface
  val io = IO(new MMapRegionIO(addrWidth, dataWidth)).suggestName("RAM")

  // Signals
  val mem_addr       = Wire(UInt(opt_mem_addr_bits.W))
  val byte_in        = Wire(Vec(dataWidth / 8, UInt(8.W)))
  val ar_offset_addr = Wire(UInt(addrWidth.W))
  val aw_offset_addr = Wire(UInt(addrWidth.W))
  val aw_valid       = Wire(Bool())
  val ar_valid       = Wire(Bool())
  val ram            = RegInit(VecInit(Seq.fill(memSize.toInt)(0.U(dataWidth.W))))

  io.write_resp := aw_valid
  io.read_resp  := ar_valid

  aw_offset_addr := io.write_addr - baseAddr.U(addrWidth.W)
  ar_offset_addr := io.read_addr - baseAddr.U(addrWidth.W)
  aw_valid       := (io.write_addr >= baseAddr.U) && (aw_offset_addr < ((1 << addr_lsb) * memSize.toInt).U)
  ar_valid       := (io.read_addr >= baseAddr.U) && (ar_offset_addr < ((1 << addr_lsb) * memSize.toInt).U)

  for (i <- 0 until (dataWidth / 8))
    byte_in(i) := io.write_data(8 * (i + 1) - 1, 8 * i)
  mem_addr     := Mux(
    io.read_en,
    ar_offset_addr(opt_mem_addr_bits + addr_lsb, addr_lsb),
    Mux(io.write_en, aw_offset_addr(opt_mem_addr_bits + addr_lsb, addr_lsb), 0.U)
  )

  when(io.write_en && aw_valid) {
    ram(mem_addr) := Cat((0 until (dataWidth / 8)).map { i =>
      Mux(io.write_strb(i), byte_in(i), ram(mem_addr)(8 * (i + 1) - 1, 8 * i))
    }.reverse)
  }

  io.read_data := 0.U
  when(io.read_en && ar_valid) {
    io.read_data := ram(mem_addr)
  }
}
