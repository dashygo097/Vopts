package vopts.mem.dma

import chisel3._
import chisel3.util._

object DMAState extends ChiselEnum {
  val IDLE = Value(0.U(3.W))

  // Read States
  val READ_ADDR = Value(1.U(3.W))
  val READ_DATA = Value(2.U(3.W))

  // Write States
  val WRITE_ADDR = Value(3.U(3.W))
  val WRITE_DATA = Value(4.U(3.W))
  val WRITE_RESP = Value(5.U(3.W))

  val DONE = Value(6.U(3.W))
}

class DMAChannel(addrWidth: Int, dataWidth: Int) extends Module {
  override def desiredName: String =
    s"dma_channel_${addrWidth}x$dataWidth"

  val io = IO(new Bundle {
    val descriptor = Input(new DMADescriptorIO(addrWidth, dataWidth))
    val ready      = Input(Bool())
    val busy       = Output(Bool())
    val error      = Output(Bool())
    val done       = Output(Bool())
    val bytes      = Output(UInt(dataWidth.W))

    val readAddr = Decoupled(UInt(addrWidth.W))
    val readData = Flipped(Decoupled(UInt(dataWidth.W)))

    val writeAddr = Decoupled(UInt(addrWidth.W))
    val writeData = Decoupled(UInt(dataWidth.W))
    val writeResp = Flipped(Decoupled(Bool()))

    val interrupt = Output(Bool())
  })

  // State machine
  val state = RegInit(DMAState.IDLE)

  // Registers
  val srcAddr          = RegInit(0.U(addrWidth.W))
  val dstAddr          = RegInit(0.U(addrWidth.W))
  val bytesRemaining   = RegInit(0.U(addrWidth.W))
  val bytesTransferred = RegInit(0.U(dataWidth.W))
  val burstSize        = RegInit(1.U(8.W))
  val priority         = RegInit(0.U(3.W))
  val dataBuffer       = Reg(UInt(dataWidth.W))
  val errorReg         = RegInit(false.B)

  // Burst tracking
  val currentBurstBeats = RegInit(0.U(8.W))
  val beatsInBurst      = RegInit(0.U(8.W))
  val bytesPerBeat      = (dataWidth / 8).U

  // Interrupt output
  val interruptReg = RegInit(false.B)

  // Default outputs
  io.readAddr.valid  := false.B
  io.readAddr.bits   := srcAddr
  io.readData.ready  := false.B
  io.writeAddr.valid := false.B
  io.writeAddr.bits  := dstAddr
  io.writeData.valid := false.B
  io.writeData.bits  := dataBuffer
  io.writeResp.ready := false.B

  // Status outputs
  io.busy      := state =/= DMAState.IDLE && state =/= DMAState.DONE
  io.error     := errorReg
  io.done      := state === DMAState.DONE
  io.bytes     := bytesTransferred
  io.interrupt := interruptReg

  // FSM
  switch(state) {
    is(DMAState.IDLE) {
      interruptReg := false.B

      when(io.ready && io.descriptor.enable) {
        srcAddr           := io.descriptor.srcAddr
        dstAddr           := io.descriptor.dstAddr
        bytesRemaining    := io.descriptor.length
        bytesTransferred  := 0.U
        burstSize         := Mux(io.descriptor.burstSize === 0.U, 1.U, io.descriptor.burstSize)
        priority          := io.descriptor.priority
        errorReg          := false.B
        currentBurstBeats := 0.U

        val effectiveBurstSize = Mux(io.descriptor.burstSize === 0.U, 1.U, io.descriptor.burstSize)
        val remainingBeats     = (io.descriptor.length + bytesPerBeat - 1.U) / bytesPerBeat
        beatsInBurst := Mux(remainingBeats < effectiveBurstSize, remainingBeats(7, 0), effectiveBurstSize)

        state := DMAState.READ_ADDR
      }
    }

    is(DMAState.READ_ADDR) {
      io.readAddr.valid := true.B
      when(io.readAddr.ready) {
        state := DMAState.READ_DATA
      }
    }

    is(DMAState.READ_DATA) {
      io.readData.ready := true.B
      when(io.readData.valid) {
        dataBuffer := io.readData.bits
        state      := DMAState.WRITE_ADDR
      }
    }

    is(DMAState.WRITE_ADDR) {
      io.writeAddr.valid := true.B
      when(io.writeAddr.ready) {
        state := DMAState.WRITE_DATA
      }
    }

    is(DMAState.WRITE_DATA) {
      io.writeData.valid := true.B
      when(io.writeData.ready) {
        state := DMAState.WRITE_RESP
      }
    }

    is(DMAState.WRITE_RESP) {
      io.writeResp.ready := true.B
      when(io.writeResp.valid) {
        when(!io.writeResp.bits) {
          errorReg := true.B
        }

        srcAddr           := srcAddr + bytesPerBeat
        dstAddr           := dstAddr + bytesPerBeat
        bytesTransferred  := bytesTransferred + bytesPerBeat
        bytesRemaining    := Mux(bytesRemaining > bytesPerBeat, bytesRemaining - bytesPerBeat, 0.U)
        currentBurstBeats := currentBurstBeats + 1.U

        val transferDone = bytesRemaining <= bytesPerBeat
        val burstDone    = (currentBurstBeats + 1.U) >= beatsInBurst

        when(transferDone || errorReg) {
          state := DMAState.DONE
        }.elsewhen(burstDone && !transferDone) {
          currentBurstBeats := 0.U
          val newRemainingBeats = ((bytesRemaining - bytesPerBeat) + bytesPerBeat - 1.U) / bytesPerBeat
          beatsInBurst := Mux(newRemainingBeats < burstSize, newRemainingBeats(7, 0), burstSize)
          state        := DMAState.READ_ADDR
        }.otherwise {
          state := DMAState.READ_ADDR
        }
      }
    }

    is(DMAState.DONE) {
      when(io.descriptor.interrupt && !interruptReg) {
        interruptReg := true.B
      }

      when(io.ready) {
        state        := DMAState.IDLE
        interruptReg := false.B
      }
    }
  }
}
