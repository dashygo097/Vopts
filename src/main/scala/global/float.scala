package global

import scala.math.pow

import chisel3._
import chisel3.util._

class Float extends Bundle with Config {
  val value = SInt(dataWidth.W)

  def +(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := this.value + that.value
    fl
  }

  def -(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := this.value - that.value
    fl
  }

  def *(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := (this.value * that.value) >> bp
    fl
  }

  def >(that: Float): Bool = {
    this.value > that.value
  }

  def <(that: Float): Bool = {
    this.value < that.value
  }

  def >=(that: Float): Bool = {
    this.value >= that.value
  }

  def <=(that: Float): Bool = {
    this.value <= that.value
  }

  def ===(that: Float): Bool = {
    this.value === that.value
  }

  def fromDouble(value: Double): Float = {
    val scale = pow(2, bp).toInt
    val fl = Wire(new Float)
    fl.value := (value * scale).toInt.S
    fl
  }

}

object Float extends Config {
  def apply(value: Double): Float = {
    (new Float).fromDouble(value)
  }
}

class FloatAdd extends Module with Config {
  val io = IO(new Bundle {
    val a = Input(new Float)
    val b = Input(new Float)
    val c = Output(new Float)
  })
  io.c := io.a + io.b
}

class FloatSub extends Module with Config {
  val io = IO(new Bundle {
    val a = Input(new Float)
    val b = Input(new Float)
    val c = Output(new Float)
  })
  io.c := io.a - io.b
}

class FloatMul extends Module with Config {
  val io = IO(new Bundle {

    val a = Input(new Float)
 val b = Input(new Float)
    val c = Output(new Float)
  })
  io.c := io.a * io.b
}


