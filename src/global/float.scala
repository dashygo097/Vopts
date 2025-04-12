package global

import scala.math.pow

import chisel3._

class Float(s_dataWidth: Int = 0, s_bp: Int = -1) extends Bundle with Config with FloatOps {
  val _dataWidth = if (s_dataWidth == 0) dataWidth else s_dataWidth
  val _bp = if (s_bp == -1) bp else s_bp

  val value = SInt(_dataWidth.W)

  def fromDouble(value: Double): Float = {
    val scale = pow(2, _bp).toInt
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

trait FloatOps {
  self: Float =>
 
  def +(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := this.value + that.value
    fl
  }

  def +(that: Double): Float = {
    val fl = Wire(new Float)
    fl.value := this.value + (that * pow(2, _bp)).toInt.S
    fl
  }

  def +(that: Int): Float = {
    val fl = Wire(new Float)
    fl.value := this.value + (that << _bp).S
    fl
  }

  def -(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := this.value - that.value
    fl
  }

  def -(that: Double): Float = {
    val fl = Wire(new Float)
    fl.value := this.value - (that * pow(2, _bp)).toInt.S
    fl
  }

  def -(that: Int): Float = {
    val fl = Wire(new Float)
    fl.value := this.value - (that << _bp).S
    fl
  }

  def *(that: Float): Float = {
    val fl = Wire(new Float)
    fl.value := (this.value * that.value) >> _bp
    fl
  }

  def *(that: Double): Float = {
    val fl = Wire(new Float)
    fl.value := (this.value * (that * pow(2, _bp)).toInt.S) >> _bp
    fl
  }

  def *(that: Int): Float = {
    val fl = Wire(new Float)
    fl.value := (this.value * (that << _bp).S) >> _bp
    fl
  }

  def >(that: Float): Bool = {
    this.value > that.value
  }

  def >(that: Double): Bool = {
    this.value > (that * pow(2, _bp)).toInt.S
  }

  def >(that: Int): Bool = {
    this.value > (that << _bp).S
  }

  def <(that: Float): Bool = {
    this.value < that.value
  }

  def <(that: Double): Bool = {
    this.value < (that * pow(2, _bp)).toInt.S
  }

  def <(that: Int): Bool = {
   this.value < (that << _bp).S
  }

  def >=(that: Float): Bool = {
    this.value >= that.value
  }

  def >=(that: Double): Bool = {
    this.value >= (that * pow(2, _bp)).toInt.S
  }

  def >=(that: Int): Bool = {
    this.value >= (that << _bp).S
  }

  def <=(that: Float): Bool = {
    this.value <= that.value
  }

  def <=(that: Double): Bool = {
    this.value <= (that * pow(2, _bp)).toInt.S
  }

  def <=(that: Int): Bool = {
    this.value <= (that << _bp).S
  }

  def ===(that: Float): Bool = {
    this.value === that.value
  }
}



