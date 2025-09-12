package mem.shift

import chisel3._
import chisel3.util._

class LogicBarrelShiftIO(width: Int) extends Bundle {
  val in = Input(UInt(width.W))
  val shamt = Input(UInt(log2Ceil(width).W))
  val lr = Input(Bool())
  val out = Output(UInt(width.W))
}

class ArithmeticBarrelShiftIO(width: Int) extends Bundle {
  val in = Input(UInt(width.W))
  val shamt = Input(UInt(log2Ceil(width).W))
  val lr = Input(Bool())
  val out = Output(UInt(width.W))
}

class CircularShiftIO(width: Int) extends Bundle {
  val in = Input(UInt(width.W))
  val shamt = Input(UInt(log2Ceil(width).W))
  val lr = Input(Bool())
  val out = Output(UInt(width.W))
}

class BarrelShiftIO(width: Int) extends Bundle {
  val in = Input(UInt(width.W))
  val shamt = Input(UInt(log2Ceil(width).W))
  val lr = Input(Bool())
  val al = Input(Bool())
  val out = Output(UInt(width.W))
}

class LogicBarrelShiftCore(width: Int) extends Module {
  val io = IO(new LogicBarrelShiftIO(width)).suggestName("SHIFT")
  io.out := MuxLookup(io.lr, 0.U)(Seq(
    0.U -> (io.in << io.shamt),
    1.U -> (io.in >> io.shamt)
    )
  )
}

class ArithmeticBarrelShiftCore(width: Int) extends Module {
  override def desiredName = s"barrelshift_arith_x${width}"
  val io = IO(new ArithmeticBarrelShiftIO(width)).suggestName("SHIFT")
  io.out := MuxLookup(io.lr, 0.U)(Seq(
    0.U -> (io.in << io.shamt),
    1.U -> (io.in.asSInt >> io.shamt).asUInt
    )
  )
}

class CircularShiftCore(width: Int) extends Module {
  override def desiredName = s"barrelshift_circ_x${width}"
  val io = IO(new CircularShiftIO(width)).suggestName("SHIFT")
  io.out := MuxLookup(io.lr, 0.U)(Seq(
    0.U -> ((io.in << io.shamt) | (io.in >> (width.U - io.shamt))),
    1.U -> ((io.in >> io.shamt) | (io.in << (width.U - io.shamt)))
    )
  )
}

class BarrelShiftCore(width: Int) extends Module {
  override def desiredName = s"barrelshift_x${width}"
  val io = IO(new BarrelShiftIO(width)).suggestName("SHIFT")

  io.out := MuxLookup((io.lr << 1) | io.al, 0.U)(Seq(
    0.U -> (io.in << io.shamt),
    1.U -> (io.in >> io.shamt),
    2.U -> (io.in.asSInt << io.shamt).asUInt,
    3.U -> (io.in.asSInt >> io.shamt).asUInt
    )
  )
}
