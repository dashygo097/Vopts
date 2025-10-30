package mem.fifo

import utils._
import chisel3._
import chisel3.util._

class PingPongFIFOIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val write_port        = Flipped(Decoupled(gen))
  val read_port         = Decoupled(gen)
  val write_buffer_full = Output(Bool())
  val read_buffer_empty = Output(Bool())
  val buffer_switch     = Output(Bool())
}

class PingPongFIFO[T <: Data](gen: T, depth: Int) extends Module {
  override def desiredName: String =
    s"pingpong_${depth}x${gen.getWidth}"
  val io                           = IO(new PingPongFIFOIO(gen, depth)).suggestName("PINGPONG")

  // Two memory banks
  val mem_ping = SyncReadMem(depth, gen)
  val mem_pong = SyncReadMem(depth, gen)

  // Signals
  val write_idx       = RegInit(0.U(log2Ceil(depth).W))
  val write_full_ping = RegInit(false.B)
  val write_full_pong = RegInit(false.B)

  val read_idx        = RegInit(0.U(log2Ceil(depth).W))
  val read_empty_ping = RegInit(true.B)
  val read_empty_pong = RegInit(true.B)

  // FIFO selection
  val write_buffer_sel = RegInit(false.B) // false=ping, true=pong
  val read_buffer_sel  = RegInit(false.B)

  val write_ping = !write_buffer_sel
  val write_pong = write_buffer_sel
  val read_ping  = !read_buffer_sel
  val read_pong  = read_buffer_sel

  // Write Port
  io.write_port.ready := Mux(write_ping, !write_full_ping, !write_full_pong)

  when(io.write_port.valid && io.write_port.ready) {
    when(write_ping) {
      mem_ping.write(write_idx, io.write_port.bits)
    }.otherwise {
      mem_pong.write(write_idx, io.write_port.bits)
    }

    when(write_idx === (depth - 1).U) {
      write_idx        := 0.U
      // FIFO full after writing last element
      when(write_ping) {
        write_full_ping := true.B
      }.otherwise {
        write_full_pong := true.B
      }
      // Switch write buffer
      write_buffer_sel := !write_buffer_sel
    }.otherwise {
      write_idx := write_idx + 1.U
    }
  }

  // Read Port
  val read_data_ping = mem_ping.read(read_idx, io.read_port.ready && read_ping)
  val read_data_pong = mem_pong.read(read_idx, io.read_port.ready && read_pong)

  io.read_port.bits  := Mux(read_ping, read_data_ping, read_data_pong)
  io.read_port.valid := Mux(read_ping, !read_empty_ping, !read_empty_pong)

  when(io.read_port.valid && io.read_port.ready) {
    when(read_idx === (depth - 1).U) {
      read_idx        := 0.U
      when(read_ping) {
        read_empty_ping := true.B
      }.otherwise {
        read_empty_pong := true.B
      }
      read_buffer_sel := !read_buffer_sel
    }.otherwise {
      read_idx := read_idx + 1.U
    }
  }

  when(write_ping && write_full_ping && !write_buffer_sel) {
    write_full_ping := false.B
    read_empty_pong := false.B
  }

  when(write_pong && write_full_pong && write_buffer_sel) {
    write_full_pong := false.B
    read_empty_ping := false.B
  }

  io.write_buffer_full := Mux(write_ping, write_full_ping, write_full_pong)
  io.read_buffer_empty := Mux(read_ping, read_empty_ping, read_empty_pong)
  io.buffer_switch     := write_buffer_sel
}
