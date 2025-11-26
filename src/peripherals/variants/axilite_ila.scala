package perip

import com.amba._
import utils._
import chisel3._
import chisel3.util._

class ILACSR(override val baseAddr: BigInt) extends CSRMMap {
  override def registers: Seq[Register] = Seq(
    Register("FIFO_DATA", baseAddr + 0x00),
    Register("FIFO_STATUS", baseAddr + 0x04),
    Register("FIFO_COUNTER", baseAddr + 0x08),
    Register("CONTROL", baseAddr + 0x0C),
    Register("CLOCK_DIV", baseAddr + 0x10)
  )
}

class AXILiteSlaveILA(
  addrWidth: Int,
  dataWidth: Int,
  baseAddr: BigInt,
  fifoDepth: Int,
  probeWidth: Int, 
  numProbes: Int
) extends AXILiteSlaveWithCSR(addrWidth, dataWidth, new ILACSR(baseAddr)) {
  override def desiredName: String = s"axilite_ila_${addrWidth}x${dataWidth}_d$fifoDepth"

  val probes = IO(Vec(numProbes, Input(UInt(probeWidth.W))))
  val fifo = Module(new SyncFIFO(UInt((probeWidth * numProbes).W), fifoDepth))

  // Control Registers
  val enableReg = RegInit(false.B)
  val clearReg = RegInit(false.B)
  val clockDivReg = RegInit(1.U(16.W))

  // Signals
  val clockDivCounter = RegInit(0.U(16.W))
  val clockDivPulse = WireInit(false.B)

  when(enableReg) {
    when(clockDivCounter === (clockDivReg - 1.U)) {
      clockDivCounter := 0.U
      clockDivPulse := true.B
    }.otherwise {
      clockDivCounter := clockDivCounter + 1.U
    }
  }.otherwise {
    clockDivCounter := 0.U
  }

  // Concatenate probe signals
  val probeData = Cat(probes.reverse)

  // FIFO Write Path 
  val write_to_fifo = enableReg && clockDivPulse && !fifo.io.full
  fifo.io.enq.valid := write_to_fifo
  fifo.io.enq.bits  := probeData

  // FIFO Read Path
  val read_from_fifo = axi_on_aread && readAccess("FIFO_DATA")
  fifo.io.deq.ready := read_from_fifo && axi.r.ready && !fifo.io.empty

  // AW

  // W
  when(axi_last_write) {
    when(writeAccess("CONTROL")) {
      when(axi.w.bits.strb(0)) {
        enableReg := axi.w.bits.data(0)    // Bit 0: enable
        clearReg := axi.w.bits.data(1)     // Bit 1: clear pulse
      }
    }
    when(writeAccess("CLOCK_DIV")) {
      when(axi.w.bits.strb(0)) {
        clockDivReg := Mux(axi.w.bits.data(15, 0) === 0.U, 1.U, axi.w.bits.data(15, 0))
      }
    }
  }

  // B
  when(axi_will_bresp) {
    axi_bresp := Mux(fifo.io.full && write_to_fifo, 2.U, 0.U) // SLVERR if FIFO full
  }

  // AR

  // R
  registerRead("FIFO_DATA", fifo.io.deq.bits)
  registerRead("FIFO_STATUS", Cat(fifo.io.empty, fifo.io.full, enableReg, clearReg))
  registerRead("FIFO_COUNTER", fifo.io.count)
  registerRead("CONTROL", Cat(clearReg, enableReg))
  registerRead("CLOCK_DIV", clockDivReg)

  when(axi_will_read) {
    axi_rresp := Mux(fifo.io.empty && read_from_fifo, 2.U, 0.U) // SLVERR if FIFO empty
  }
}

// Test object
object TestAXILiteSlaveILA extends App {
  VerilogEmitter.parse(
    new AXILiteSlaveILA(
      addrWidth = 32,
      dataWidth = 32,
      baseAddr = 0x80000000L,
      fifoDepth = 256,
      probeWidth = 8,
      numProbes = 4
    ),
    "axilite_ila.sv",
    info = true
  )
}
