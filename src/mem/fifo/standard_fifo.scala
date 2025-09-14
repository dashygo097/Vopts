package mem.fifo

import mem.register._
import utils._
import chisel3._
import chisel3.util._

class SyncFIFOCtrlIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val waddr = Output(UInt(log2Ceil(depth).W))
  val raddr = Output(UInt(log2Ceil(depth).W))
  val wr = Input(Bool())
  val rd = Input(Bool())
  val empty = Output(Bool())
  val full = Output(Bool())
}

class SyncFIFOCtrl[T <: Data](gen: T, depth: Int) extends Module {
  override def desiredName = s"s_fifo_${gen.toString.toLowerCase()}_x${depth}"
  val io = IO(new SyncFIFOCtrlIO(gen, depth)).suggestName("S_CTRL")

  val wr_ptr = RegInit(0.U(log2Ceil(depth).W))
  val rd_ptr = RegInit(0.U(log2Ceil(depth).W))
  val full = RegInit(false.B)
  val empty = RegInit(true.B)

  val wr_ptr_next = Wire(UInt(log2Ceil(depth).W))
  val rd_ptr_next = Wire(UInt(log2Ceil(depth).W))
  val full_next = Wire(Bool())
  val empty_next = Wire(Bool())

  wr_ptr_next := wr_ptr
  rd_ptr_next := rd_ptr
  full_next := full
  empty_next := empty

  when(io.wr && !io.rd) {
    when(!full) {
      wr_ptr_next := Mux(wr_ptr + 1.U === depth.U, 0.U, wr_ptr + 1.U)
      empty_next := false.B
      when(wr_ptr_next === rd_ptr) {
        full_next := true.B
      }
    }
  } .elsewhen(!io.wr && io.rd) {
    when(!empty) {
      rd_ptr_next := Mux(rd_ptr + 1.U === depth.U, 0.U, rd_ptr + 1.U)
      full_next := false.B
      when(rd_ptr_next === wr_ptr) {
        empty_next := true.B
      }
    }
  } .elsewhen(io.wr && io.rd) {
    when(!empty) {
      wr_ptr_next := Mux(wr_ptr + 1.U === depth.U, 0.U, wr_ptr + 1.U)
      rd_ptr_next := Mux(rd_ptr + 1.U === depth.U, 0.U, rd_ptr + 1.U)
    }
  }

  wr_ptr := wr_ptr_next
  rd_ptr := rd_ptr_next
  full := full_next
  empty := empty_next

  io.waddr := wr_ptr
  io.raddr := rd_ptr
  io.full := full
  io.empty := empty
}


class SyncFIFOIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val wdata = Input(gen)
  val rdata = Output(gen)
  val wr = Input(Bool())
  val rd = Input(Bool())
  val empty = Output(Bool())
  val full = Output(Bool())
}

class SyncFIFO[T <: Data](gen: T, depth: Int)(implicit ev: Arithmetic[T]) extends Module {
  val io = IO(new SyncFIFOIO(gen, depth)).suggestName("S_FIFO")
  val control = Module(new SyncFIFOCtrl(gen, depth))
  val register = Module(new RegFile(gen, depth))

  control.io.wr := io.wr
  control.io.rd := io.rd

  register.io.waddr := control.io.waddr
  register.io.raddr := control.io.raddr
  register.io.we := control.io.wr && !control.io.full
  register.io.wdata := io.wdata

  io.empty := control.io.empty
  io.full := control.io.full
  io.rdata := register.io.rdata
}
