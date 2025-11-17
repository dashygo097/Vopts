package mem.fifo

import com.amba._
import chisel3._
import chisel3.util._

class AXIStreamFIFO(dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int, depth: Int) extends Module {
  override def desiredName: String = s"axistream_syncfifo_${dataWidth}x${depth}"

  // AXI-Stream Interface
  val ext_axis_master = IO(new AXIStreamMasterExternalIO(dataWidth, idWidth, destWidth, userWidth)).suggestName("M_AXI")
  val axis_master = Wire(new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth))
  val ext_axis_slave  = IO(new AXIStreamSlaveExternalIO(dataWidth, idWidth, destWidth, userWidth)).suggestName("S_AXI")
  val axis_slave = Wire(new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth))

  val empty = IO(Output(Bool())).suggestName("EMPTY")
  val full = IO(Output(Bool())).suggestName("FULL")
  val count = IO(Output(UInt(log2Ceil(depth + 1).W))).suggestName("COUNT")

  // Module
  val fifo = Module(new SyncFIFO(new AXIStreamIO(dataWidth, idWidth, destWidth, userWidth), depth))

  // I/O Connections
  fifo.io.enq.valid := axis_slave.t.valid
  fifo.io.enq.bits := axis_slave.t.bits
  axis_slave.t.ready := !fifo.io.full
  
  axis_master.t.valid := !fifo.io.empty
  axis_master.t.bits := fifo.io.deq.bits
  fifo.io.deq.ready := axis_master.t.ready
  
  count := fifo.io.count
  full := fifo.io.full
  empty := fifo.io.empty
}
