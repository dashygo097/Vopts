package utils 

import scala.math.pow

import chisel3._

class Float(s_dataWidth: Int = 0, s_bp: Int = -1) extends Bundle with Config with FloatOps {
  var _dataWidth: Int = if (s_dataWidth == 0) dataWidth else s_dataWidth
  var _bp: Int = if (s_bp == -1) bp else s_bp

  val value: SInt = SInt(_dataWidth.W)

  def get_datawidth(): Int = {
    _dataWidth
  }

  def get_bp(): Int = {
    _bp
  }

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
  // NOTE: Note that +-* etc. for Float and Float only support same (dataWidth, bp)-typed Float.
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

  def +(that: UInt): Float = {
    val fl = Wire(new Float)
    fl.value := this.value + (that << _bp).asSInt
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

  def -(that: UInt): Float = {
    val fl = Wire(new Float)
    fl.value := this.value - (that << _bp).asSInt
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

  def *(that: UInt): Float = {
    val fl = Wire(new Float)
    fl.value := (this.value * (that << _bp).asSInt) >> _bp
    fl
  }

  def shiftleft(that: UInt): Float = {
    val fl = Wire(new Float)
    fl.value := this.value << that
    fl
  }

  def shiftright(that: UInt): Float = {
    val fl = Wire(new Float)
    fl.value := this.value >> that
    fl
  }

  def >(that: Float): Bool = {
    this.value > that.value
  }

  def >(that: Double): Bool = {
    this.value > (that * pow(2, _bp)).toInt.S
  }

  def >(that: UInt): Bool = {
    this.value > (that << _bp).asSInt
  }

  def <(that: Float): Bool = {
    this.value < that.value
  }

  def <(that: Double): Bool = {
    this.value < (that * pow(2, _bp)).toInt.S
  }

  def <(that: UInt): Bool = {
   this.value < (that << _bp).asSInt
  }

  def >=(that: Float): Bool = {
    this.value >= that.value
  }

  def >=(that: Double): Bool = {
    this.value >= (that * pow(2, _bp)).toInt.S
  }

  def >=(that: UInt): Bool = {
    this.value >= (that << _bp).asSInt
  }

  def <=(that: Float): Bool = {
    this.value <= that.value
  }

  def <=(that: Double): Bool = {
    this.value <= (that * pow(2, _bp)).toInt.S
  }

  def <=(that: UInt): Bool = {
    this.value <= (that << _bp).asSInt
  }

  def ===(that: Float): Bool = {
    this.value === that.value
  }
}



