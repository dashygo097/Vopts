package vopts.utils
import hardfloat._
import scala.math._
import chisel3._
import chisel3.util._

class FloatComplex(val expWidth: Int, val sigWidth: Int) extends Bundle with FloatComplexOps {
  val real: UInt = UInt((expWidth + sigWidth + 1).W)
  val imag: UInt = UInt((expWidth + sigWidth + 1).W)

  def totalWidth: Int = expWidth + sigWidth + 1
  def bias: Int       = (1 << (expWidth - 1)) - 1

  def newInstance: FloatComplex = Wire(new FloatComplex(expWidth, sigWidth))

  def fromDouble(realVal: Double, imagVal: Double): FloatComplex = {
    val fpc       = Wire(this.newInstance)
    val realFloat = createFloat(realVal)
    val imagFloat = createFloat(imagVal)
    fpc.real := realFloat.value
    fpc.imag := imagFloat.value
    fpc
  }

  private def createFloat(value: Double): Float = {
    val fl      = Wire(new Float(expWidth, sigWidth) {
      override def newInstance: Float = Wire(this)
    })
    val signBit = (value < 0).B
    if (value == 0.0) {
      fl.value := 0.U
    } else {
      val absValue      = math.abs(value)
      val expValue      = math.floor(math.log(absValue) / math.log(2)).toInt + bias
      val normValue     = absValue / pow(2, expValue - bias)
      val fractionValue = ((normValue - 1.0) * pow(2, sigWidth)).toLong
      fl.value := Cat(signBit, expValue.U(expWidth.W), fractionValue.U(sigWidth.W))
    }
    fl
  }

  def Zero: FloatComplex = {
    val fpc = Wire(this.newInstance)
    fpc.real := 0.U
    fpc.imag := 0.U
    fpc
  }

  def NaN: FloatComplex = {
    val fpc    = Wire(this.newInstance)
    val nanVal = Cat(0.U(1.W), ((1 << expWidth) - 1).U(expWidth.W), 1.U(sigWidth.W))
    fpc.real := nanVal
    fpc.imag := nanVal
    fpc
  }

  def realPart: UInt = this.real
  def imagPart: UInt = this.imag

  def isCompatible(that: FloatComplex): Boolean =
    this.expWidth == that.expWidth && this.sigWidth == that.sigWidth

  def requireCompatible(that: FloatComplex): Unit =
    require(
      isCompatible(that),
      s"FloatComplex operations require matching formats: " +
        s"FloatComplex(${this.expWidth}, ${this.sigWidth}) vs FloatComplex(${that.expWidth}, ${that.sigWidth})"
    )
}

object FloatComplex {
  def apply(expWidth: Int, sigWidth: Int): FloatComplex                             = new FloatComplex(expWidth, sigWidth)
  def apply(expWidth: Int, sigWidth: Int, real: Double, imag: Double): FloatComplex = {
    val fpc = new FloatComplex(expWidth, sigWidth)
    fpc.fromDouble(real, imag)
  }
}

trait FloatComplexOps {
  self: FloatComplex =>

  def isNaN: Bool = {
    val maxExp   = ((1 << expWidth) - 1).U
    val realExp  = real(totalWidth - 2, sigWidth)
    val imagExp  = imag(totalWidth - 2, sigWidth)
    val realFrac = real(sigWidth - 1, 0)
    val imagFrac = imag(sigWidth - 1, 0)
    ((realExp === maxExp) && (realFrac =/= 0.U)) ||
    ((imagExp === maxExp) && (imagFrac =/= 0.U))
  }

  def isZero: Bool = {
    val realExp  = real(totalWidth - 2, sigWidth)
    val imagExp  = imag(totalWidth - 2, sigWidth)
    val realFrac = real(sigWidth - 1, 0)
    val imagFrac = imag(sigWidth - 1, 0)
    (realExp === 0.U) && (realFrac === 0.U) &&
    (imagExp === 0.U) && (imagFrac === 0.U)
  }

  def +(that: FloatComplex): FloatComplex = {
    this.requireCompatible(that)
    val result = Wire(this.newInstance)

    val realAdder = Module(new AddRecFN(expWidth, sigWidth))
    realAdder.io.subOp          := false.B
    realAdder.io.a              := this.real
    realAdder.io.b              := that.real
    realAdder.io.roundingMode   := 0.U
    realAdder.io.detectTininess := false.B
    result.real                 := realAdder.io.out

    val imagAdder = Module(new AddRecFN(expWidth, sigWidth))
    imagAdder.io.subOp          := false.B
    imagAdder.io.a              := this.imag
    imagAdder.io.b              := that.imag
    imagAdder.io.roundingMode   := 0.U
    imagAdder.io.detectTininess := false.B
    result.imag                 := imagAdder.io.out

    result
  }

  def +(real: Double, imag: Double): FloatComplex = {
    val that = this.newInstance.fromDouble(real, imag)
    this + that
  }

  def -(that: FloatComplex): FloatComplex = {
    this.requireCompatible(that)
    val result = Wire(this.newInstance)

    val realAdder = Module(new AddRecFN(expWidth, sigWidth))
    realAdder.io.subOp          := true.B
    realAdder.io.a              := this.real
    realAdder.io.b              := that.real
    realAdder.io.roundingMode   := 0.U
    realAdder.io.detectTininess := false.B
    result.real                 := realAdder.io.out

    val imagAdder = Module(new AddRecFN(expWidth, sigWidth))
    imagAdder.io.subOp          := true.B
    imagAdder.io.a              := this.imag
    imagAdder.io.b              := that.imag
    imagAdder.io.roundingMode   := 0.U
    imagAdder.io.detectTininess := false.B
    result.imag                 := imagAdder.io.out

    result
  }

  def -(real: Double, imag: Double): FloatComplex = {
    val that = this.newInstance.fromDouble(real, imag)
    this - that
  }

  def *(that: FloatComplex): FloatComplex = {
    this.requireCompatible(that)
    val result = Wire(this.newInstance)

    val acMul = Module(new MulRecFN(expWidth, sigWidth))
    acMul.io.a              := this.real
    acMul.io.b              := that.real
    acMul.io.roundingMode   := 0.U
    acMul.io.detectTininess := false.B

    val bdMul = Module(new MulRecFN(expWidth, sigWidth))
    bdMul.io.a              := this.imag
    bdMul.io.b              := that.imag
    bdMul.io.roundingMode   := 0.U
    bdMul.io.detectTininess := false.B

    val adMul = Module(new MulRecFN(expWidth, sigWidth))
    adMul.io.a              := this.real
    adMul.io.b              := that.imag
    adMul.io.roundingMode   := 0.U
    adMul.io.detectTininess := false.B

    val bcMul = Module(new MulRecFN(expWidth, sigWidth))
    bcMul.io.a              := this.imag
    bcMul.io.b              := that.real
    bcMul.io.roundingMode   := 0.U
    bcMul.io.detectTininess := false.B

    val realAdder = Module(new AddRecFN(expWidth, sigWidth))
    realAdder.io.subOp          := true.B
    realAdder.io.a              := acMul.io.out
    realAdder.io.b              := bdMul.io.out
    realAdder.io.roundingMode   := 0.U
    realAdder.io.detectTininess := false.B
    result.real                 := realAdder.io.out

    val imagAdder = Module(new AddRecFN(expWidth, sigWidth))
    imagAdder.io.subOp          := false.B
    imagAdder.io.a              := adMul.io.out
    imagAdder.io.b              := bcMul.io.out
    imagAdder.io.roundingMode   := 0.U
    imagAdder.io.detectTininess := false.B
    result.imag                 := imagAdder.io.out

    result
  }

  def *(real: Double, imag: Double): FloatComplex = {
    val that = this.newInstance.fromDouble(real, imag)
    this * that
  }

  def ===(that: FloatComplex): Bool = {
    this.requireCompatible(that)
    val realComp = Module(new CompareRecFN(expWidth, sigWidth))
    realComp.io.a         := this.real
    realComp.io.b         := that.real
    realComp.io.signaling := false.B

    val imagComp = Module(new CompareRecFN(expWidth, sigWidth))
    imagComp.io.a         := this.imag
    imagComp.io.b         := that.imag
    imagComp.io.signaling := false.B

    realComp.io.eq && imagComp.io.eq
  }

  def ===(real: Double, imag: Double): Bool = {
    val that = this.newInstance.fromDouble(real, imag)
    this === that
  }

  def =/=(that: FloatComplex): Bool = {
    this.requireCompatible(that)
    !(this === that)
  }

  def =/=(real: Double, imag: Double): Bool = {
    val that = this.newInstance.fromDouble(real, imag)
    this =/= that
  }

  def conjugate: FloatComplex = {
    val result = Wire(this.newInstance)
    result.real := this.real
    val signBit = !this.imag(totalWidth - 1)
    result.imag := Cat(signBit, this.imag(totalWidth - 2, 0))
    result
  }

  def magnitude: UInt = {
    val realSq = Module(new MulRecFN(expWidth, sigWidth))
    realSq.io.a              := this.real
    realSq.io.b              := this.real
    realSq.io.roundingMode   := 0.U
    realSq.io.detectTininess := false.B

    val imagSq = Module(new MulRecFN(expWidth, sigWidth))
    imagSq.io.a              := this.imag
    imagSq.io.b              := this.imag
    imagSq.io.roundingMode   := 0.U
    imagSq.io.detectTininess := false.B

    val sumSq = Module(new AddRecFN(expWidth, sigWidth))
    sumSq.io.subOp          := false.B
    sumSq.io.a              := realSq.io.out
    sumSq.io.b              := imagSq.io.out
    sumSq.io.roundingMode   := 0.U
    sumSq.io.detectTininess := false.B

    val sqrt = Module(new DivSqrtRecFN_small(expWidth, sigWidth, 0))
    sqrt.io.inValid        := true.B
    sqrt.io.sqrtOp         := true.B
    sqrt.io.a              := sumSq.io.out
    sqrt.io.b              := 0.U
    sqrt.io.roundingMode   := 0.U
    sqrt.io.detectTininess := false.B

    sqrt.io.out
  }
}
