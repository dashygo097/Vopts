package mem.fifo

import mem.register._
import utils._
import chisel3._
import chisel3.util._

class AsyncFIFOCtrlIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val waddr = Output(UInt(log2Ceil(depth).W))
  val raddr = Output(UInt(log2Ceil(depth).W))
  val wr = Input(Bool())
  val rd = Input(Bool())
  val empty = Output(Bool())
  val full = Output(Bool())

  val wclk = Input(Clock())
  val rclk = Input(Clock())
}


class AsyncFIFOCtrl[T <: Data](gen: T, depth: Int) extends Module {
  override def desiredName = s"a_fifo_ctrl_${gen.toString.toLowerCase()}_x${depth}"
  val io = IO(new AsyncFIFOCtrlIO(gen, depth)).suggestName("A_CTRL")
  
  val ptrWidth = log2Ceil(depth) + 1
  
  val wPtrGray = Wire(UInt(ptrWidth.W))
  val rPtrGray = Wire(UInt(ptrWidth.W))
  
  withClock(io.wclk) {
    val wPtr = RegInit(0.U(ptrWidth.W))
    val wPtrGrayReg = RegInit(0.U(ptrWidth.W))
    val wPtrPlus1Gray = Wire(UInt(ptrWidth.W))
    val rPtrGraySync = withReset(false.B) {
      val sync1 = RegInit(0.U(ptrWidth.W))
      val sync2 = RegInit(0.U(ptrWidth.W))
      sync1 := rPtrGray
      sync2 := sync1
      sync2
    }
    
    val wPtrNext = Wire(UInt(ptrWidth.W))
    val wPtrBinIncr = wPtr + 1.U
    wPtrNext := Mux(io.wr && !io.full, 
                    Mux(wPtrBinIncr(ptrWidth - 2, 0) === depth.U, 
                        Cat(~wPtr(ptrWidth - 1), 0.U(log2Ceil(depth).W)), 
                        wPtrBinIncr),
                    wPtr)

    val wPtrNextGray = (wPtrNext >> 1) ^ wPtrNext
    val wPtrPlus1 = Mux(wPtr(ptrWidth - 2, 0) === (depth - 1).U, 
                         Cat(~wPtr(ptrWidth - 1), 0.U(log2Ceil(depth).W)), 
                        wPtr + 1.U)

    wPtrPlus1Gray := (wPtrPlus1 >> 1) ^ wPtrPlus1
    
    wPtr := wPtrNext
    wPtrGrayReg := wPtrNextGray
    
    io.full := (wPtrPlus1Gray === rPtrGraySync)
    
    io.waddr := wPtr(log2Ceil(depth)-1, 0) % depth.U
    
    wPtrGray := wPtrGrayReg
  }
  
  withClock(io.rclk) {
    val rPtr = RegInit(0.U(ptrWidth.W))
    val rPtrGrayReg = RegInit(0.U(ptrWidth.W))
    val wPtrGraySync = withReset(false.B) {
      val sync1 = RegInit(0.U(ptrWidth.W))
      val sync2 = RegInit(0.U(ptrWidth.W))
      sync1 := wPtrGray
      sync2 := sync1
      sync2
    }
    
    val rPtrNext = Wire(UInt(ptrWidth.W))
    val rPtrBinIncr = rPtr + 1.U
    rPtrNext := Mux(io.rd && !io.empty, 
                    Mux(rPtrBinIncr(ptrWidth - 2, 0) === depth.U, 
                        Cat(~rPtr(ptrWidth - 1), 0.U(log2Ceil(depth).W)), 
                        rPtrBinIncr),
                    rPtr)
    
    val rPtrNextGray = (rPtrNext >> 1) ^ rPtrNext
    
    rPtr := rPtrNext
    rPtrGrayReg := rPtrNextGray
    
    io.empty := (rPtrGrayReg === wPtrGraySync)
    
    io.raddr := rPtr(log2Ceil(depth)-1, 0) % depth.U
    
    rPtrGray := rPtrGrayReg
  }
}

class AsyncFIFOIO[T <: Data](gen: T, depth: Int) extends Bundle {
  val wdata = Input(gen)
  val rdata = Output(gen)
  val wr = Input(Bool())
  val rd = Input(Bool())
  val empty = Output(Bool())
  val full = Output(Bool())

  val wclk = Input(Clock())
  val rclk = Input(Clock())
}

class AsyncFIFO[T <: Data](gen: T, depth: Int)(implicit ev: Arithmetic[T]) extends Module {
  override def desiredName = s"a_fifo_${gen.toString.toLowerCase()}_x${depth}"
  val io = IO(new AsyncFIFOIO(gen, depth)).suggestName("A_FIFO")

  val control = Module(new AsyncFIFOCtrl(gen, depth))
  val register = Module(new RegFile(gen, depth))

  control.io.wr := io.wr
  control.io.rd := io.rd
  control.io.wclk := io.wclk
  control.io.rclk := io.rclk

  register.io.waddr := control.io.waddr
  register.io.raddr := control.io.raddr
  register.io.we := control.io.wr && !control.io.full
  register.io.wdata := io.wdata

  io.empty := control.io.empty
  io.full := control.io.full
  io.rdata := register.io.rdata
}
