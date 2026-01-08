package vopts.mem.dma

import vopts.com.amba._
import chisel3._
import chisel3.util._

object DMAStreamState extends ChiselEnum {
  val IDLE     = Value(0.U(2.W))
  val TRANSFER = Value(1.U(2.W))
  val DONE     = Value(2.U(2.W))
}

class DMAStreamChannel(addrWidth: Int, dataWidth: Int, idWidth: Int, destWidth: Int, userWidth: Int) extends Module {
  override def desiredName: String = s"dma_stream_channel_${addrWidth}x$dataWidth"

  val io = IO(new Bundle {
    val descriptor = Input(new DMADescriptorIO(addrWidth, dataWidth))
    val ready      = Input(Bool())
    val busy       = Output(Bool())
    val error      = Output(Bool())
    val done       = Output(Bool())
    val bytes      = Output(UInt(dataWidth.W))
    val interrupt  = Output(Bool())

    // AXI-Stream interfaces
    val s_axis = new AXIStreamSlaveIO(dataWidth, idWidth, destWidth, userWidth)
    val m_axis = new AXIStreamMasterIO(dataWidth, idWidth, destWidth, userWidth)
  })

  // State machine
  val state = RegInit(DMAStreamState.IDLE)

  // Registers
  val bytesRemaining   = RegInit(0.U(addrWidth.W))
  val bytesTransferred = RegInit(0.U(dataWidth.W))
  val errorReg         = RegInit(false.B)
  val interruptReg     = RegInit(false.B)

  val bytesPerBeat = (dataWidth / 8).U

  // Status outputs
  io.busy      := state === DMAStreamState.TRANSFER
  io.error     := errorReg
  io.done      := state === DMAStreamState.DONE
  io.bytes     := bytesTransferred
  io.interrupt := interruptReg

  io.s_axis.t.ready := false.B
  io.m_axis.t.valid := false.B
  io.m_axis.t.bits  := DontCare

  // FSM
  switch(state) {
    is(DMAStreamState.IDLE) {
      interruptReg := false.B

      when(io.ready && io.descriptor.enable) {
        bytesRemaining   := io.descriptor.length
        bytesTransferred := 0.U
        errorReg         := false.B
        state            := DMAStreamState.TRANSFER
      }
    }

    is(DMAStreamState.TRANSFER) {
      io.m_axis.t.valid     := io.s_axis.t.valid
      io.m_axis.t.bits.data := io.s_axis.t.bits.data
      io.m_axis.t.bits.strb := io.s_axis.t.bits.strb
      io.m_axis.t.bits.keep := io.s_axis.t.bits.keep
      io.m_axis.t.bits.last := io.s_axis.t.bits.last
      io.m_axis.t.bits.id   := io.s_axis.t.bits.id
      io.m_axis.t.bits.dest := io.s_axis.t.bits.dest
      io.m_axis.t.bits.user := io.s_axis.t.bits.user
      io.s_axis.t.ready     := io.m_axis.t.ready

      when(io.s_axis.t.fire) {
        val bytesInBeat = PopCount(io.s_axis.t.bits.keep)
        bytesTransferred := bytesTransferred + bytesInBeat
        bytesRemaining   := Mux(bytesRemaining > bytesInBeat, bytesRemaining - bytesInBeat, 0.U)

        val transferDone = bytesRemaining <= bytesInBeat || io.s_axis.t.bits.last

        when(transferDone) {
          state := DMAStreamState.DONE
        }
      }
    }

    is(DMAStreamState.DONE) {
      when(io.descriptor.interrupt && !interruptReg) {
        interruptReg := true.B
      }

      when(io.ready) {
        state        := DMAStreamState.IDLE
        interruptReg := false.B
      }
    }
  }
}
