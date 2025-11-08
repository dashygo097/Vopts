package math

import utils._
import chisel3._

class Matrix[T <: Data](gen: T, row: Int, col: Int)(implicit ev: Arithmetic[T]) extends Bundle with MatrixOps[T] {
  var _row = row
  var _col = col

  val value = Vec(row, Vec(col, gen.cloneType))

  def row(): Int               = _row
  def row(idx: Int): Vector[T] = {
    require(idx >= 0 && idx < _row, s"Matrix row index out of bounds: $idx, size=${_row}")
    Vector(value(idx))
  }
  def col(): Int               = _col
  def col(idx: Int): Vector[T] = {
    require(idx >= 0 && idx < _col, s"Matrix column index out of bounds: $idx, size=${_col}")
    Vector(value.map(_(idx)))
  }
  def gen(): T                 = value.head.head.cloneType

  def apply(r: Int, c: Int): T              = {
    require(
      r >= 0 && r < _row && c >= 0 && c < _col,
      s"Matrix index out of bounds: ($r, $c), size=(${_row}, ${_col})"
    )
    value(r)(c)
  }
  def update(r: Int, c: Int, data: T): Unit = {
    require(
      r >= 0 && r < _row && c >= 0 && c < _col,
      s"Matrix index out of bounds: ($r, $c), size=(${_row}, ${_col})"
    )
    value(r)(c) := data
  }

  def fromSeq(seq: Seq[Seq[T]]): Matrix[T] = {
    require(
      seq.length == _row && seq.forall(_.length == _col),
      s"Matrix size mismatch: expected ${_row}x${_col}, got ${seq.length}x${if (seq.nonEmpty) seq.head.length else 0}"
    )
    for (r <- 0 until _row)
      value(r) := seq(r).map(_.asTypeOf(gen)).toVector
    this
  }

  def slice(rowStart: Int, rowEnd: Int, colStart: Int, colEnd: Int): Matrix[T] = {
    require(
      rowStart >= 0 && rowEnd <= _row && rowStart < rowEnd &&
        colStart >= 0 && colEnd <= _col && colStart < colEnd,
      s"Matrix slice indices out of bounds: ($rowStart, $colStart) to ($rowEnd, $colEnd), size=(${_row}, ${_col})"
    )
    val mat = Wire(new Matrix(gen, rowEnd - rowStart, colEnd - colStart))
    for (r <- 0 until (rowEnd - rowStart))
      for (c <- 0 until (colEnd - colStart))
        mat.value(r)(c) := value(rowStart + r)(colStart + c)
    mat
  }

  def sliceRows(rowStart: Int, rowEnd: Int): Matrix[T] = {
    require(
      rowStart >= 0 && rowEnd <= _row && rowStart < rowEnd,
      s"Matrix slice indices out of bounds: $rowStart to $rowEnd, size=${_row}"
    )
    val mat = Wire(new Matrix(gen, rowEnd - rowStart, _col))
    for (r <- 0 until (rowEnd - rowStart))
      mat.value(r) := value(rowStart + r)
    mat
  }

  def sliceCols(colStart: Int, colEnd: Int): Matrix[T] = {
    require(
      colStart >= 0 && colEnd <= _col && colStart < colEnd,
      s"Matrix slice indices out of bounds: $colStart to $colEnd, size=${_col}"
    )
    val mat = Wire(new Matrix(gen, _row, colEnd - colStart))
    for (r <- 0 until _row)
      for (c <- 0 until (colEnd - colStart))
        mat.value(r)(c) := value(r)(colStart + c)
    mat
  }

  def isCompatible(that: Matrix[T]): Boolean =
    this.row() == that.row() && this.col() == that
      .col() && this.gen().getClass == that.gen().getClass

  def requireCompatible(that: Matrix[T]): Unit =
    require(
      isCompatible(that),
      s"Matrix compatibility check failed: " +
        s"this(${this.row()}, ${this.col()}, ${this.gen()}) vs that(${that.row()}, ${that.col()}, ${that.gen()})"
    )
}

object Matrix {
  def apply[T <: Data](gen: T, row: Int, col: Int)(implicit ev: Arithmetic[T]): Matrix[T] =
    new Matrix(gen, row, col)
  def apply[T <: Data](seq: Seq[Seq[T]])(implicit ev: Arithmetic[T]): Matrix[T]           = {
    val row = seq.length
    val col = if (row > 0) seq.head.length else 0
    val mat = new Matrix(seq.head.head, row, col)
    for (r <- 0 until row) {
      require(
        seq(r).length == col,
        s"Matrix row size mismatch at row $r: expected $col, got ${seq(r).length}"
      )
      mat.value(r) := seq(r).map(_.asTypeOf(mat.gen())).toVector
    }
    mat
  }
}

object mat2x2 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Matrix[T]                 =
    new Matrix(gen, 2, 2)
  def apply[T <: Data](a: T, b: T, c: T, d: T)(implicit ev: Arithmetic[T]): Matrix[T] = {
    val mat = new Matrix(a, 2, 2)
    mat.value(0)(0) := a
    mat.value(0)(1) := b
    mat.value(1)(0) := c
    mat.value(1)(1) := d
    mat
  }
  def apply[T <: Data](a: Seq[T], b: Seq[T])(implicit ev: Arithmetic[T]): Matrix[T]   = {
    require(
      a.length == 2 && b.length == 2,
      s"mat2x2 requires exactly 2x2 elements, got ${a.length}x${b.length}"
    )
    val mat = new Matrix(a.head, 2, 2)
    mat.value(0)(0) := a(0)
    mat.value(0)(1) := a(1)
    mat.value(1)(0) := b(0)
    mat.value(1)(1) := b(1)
    mat
  }
  def apply[T <: Data](seq: Seq[Seq[T]])(implicit ev: Arithmetic[T]): Matrix[T]       = {
    require(
      seq.length == 2 && seq.forall(_.length == 2),
      s"mat2x2 requires exactly 2x2 elements, got ${seq.length}x${if (seq.nonEmpty) seq.head.length else 0}"
    )
    new Matrix(seq.head.head, 2, 2).fromSeq(seq)
  }
}

object mat3x3 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Matrix[T]                          =
    new Matrix(gen, 3, 3)
  def apply[T <: Data](a: T, b: T, c: T, d: T, e: T, f: T, g: T, h: T, i: T)(implicit
    ev: Arithmetic[T]
  ): Matrix[T] = {
    val mat = new Matrix(a, 3, 3)
    mat.value(0)(0) := a
    mat.value(0)(1) := b
    mat.value(0)(2) := c
    mat.value(1)(0) := d
    mat.value(1)(1) := e
    mat.value(1)(2) := f
    mat.value(2)(0) := g
    mat.value(2)(1) := h
    mat.value(2)(2) := i
    mat
  }
  def apply[T <: Data](a: Seq[T], b: Seq[T], c: Seq[T])(implicit ev: Arithmetic[T]): Matrix[T] = {
    require(
      a.length == 3 && b.length == 3 && c.length == 3,
      s"mat3x3 requires exactly 3x3 elements, got ${a.length}x${b.length}x${c.length}"
    )
    val mat = new Matrix(a.head, 3, 3)
    mat.value(0)(0) := a(0)
    mat.value(0)(1) := a(1)
    mat.value(0)(2) := a(2)
    mat.value(1)(0) := b(0)
    mat.value(1)(1) := b(1)
    mat.value(1)(2) := b(2)
    mat.value(2)(0) := c(0)
    mat.value(2)(1) := c(1)
    mat.value(2)(2) := c(2)
    mat
  }
  def apply[T <: Data](seq: Seq[Seq[T]])(implicit ev: Arithmetic[T]): Matrix[T]                = {
    require(
      seq.length == 3 && seq.forall(_.length == 3),
      s"mat3x3 requires exactly 3x3 elements, got ${seq.length}x${if (seq.nonEmpty) seq.head.length else 0}"
    )
    new Matrix(seq.head.head, 3, 3).fromSeq(seq)
  }
}

object mat4x4 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Matrix[T]           =
    new Matrix(gen, 4, 4)
  def apply[T <: Data](
    a: T,
    b: T,
    c: T,
    d: T,
    e: T,
    f: T,
    g: T,
    h: T,
    i: T,
    j: T,
    k: T,
    l: T,
    m: T,
    n: T,
    o: T,
    p: T
  )(implicit ev: Arithmetic[T]): Matrix[T] = {
    val mat = new Matrix(a, 4, 4)
    mat.value(0)(0) := a
    mat.value(0)(1) := b
    mat.value(0)(2) := c
    mat.value(0)(3) := d
    mat.value(1)(0) := e
    mat.value(1)(1) := f
    mat.value(1)(2) := g
    mat.value(1)(3) := h
    mat.value(2)(0) := i
    mat.value(2)(1) := j
    mat.value(2)(2) := k
    mat.value(2)(3) := l
    mat.value(3)(0) := m
    mat.value(3)(1) := n
    mat.value(3)(2) := o
    mat.value(3)(3) := p
    mat
  }
  def apply[T <: Data](a: Seq[T], b: Seq[T], c: Seq[T], d: Seq[T])(implicit
    ev: Arithmetic[T]
  ): Matrix[T] = {
    require(
      a.length == 4 && b.length == 4 && c.length == 4 && d.length == 4,
      s"mat4x4 requires exactly 4x4 elements, got ${a.length}x${b.length}x${c.length}x${d.length}"
    )
    val mat = new Matrix(a.head, 4, 4)
    mat.value(0)(0) := a(0)
    mat.value(0)(1) := a(1)
    mat.value(0)(2) := a(2)
    mat.value(0)(3) := a(3)
    mat.value(1)(0) := b(0)
    mat.value(1)(1) := b(1)
    mat.value(1)(2) := b(2)
    mat.value(1)(3) := b(3)
    mat.value(2)(0) := c(0)
    mat.value(2)(1) := c(1)
    mat.value(2)(2) := c(2)
    mat.value(2)(3) := c(3)
    mat.value(3)(0) := d(0)
    mat.value(3)(1) := d(1)
    mat.value(3)(2) := d(2)
    mat.value(3)(3) := d(3)
    mat
  }
  def apply[T <: Data](seq: Seq[Seq[T]])(implicit ev: Arithmetic[T]): Matrix[T] = {
    require(
      seq.length == 4 && seq.forall(_.length == 4),
      s"mat4x4 requires exactly 4x4 elements, got ${seq.length}x${if (seq.nonEmpty) seq.head.length else 0}"
    )
    new Matrix(seq.head.head, 4, 4).fromSeq(seq)
  }
}

trait MatrixOps[T <: Data] {
  self: Matrix[T] =>

  def add(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T] = {
    this.requireCompatible(that)
    val mat = Wire(new Matrix(self.gen(), self.row(), self.col()))
    for (r <- 0 until self.row())
      for (c <- 0 until self.col())
        mat.value(r)(c) := self.value(r)(c) + that.value(r)(c)
    mat
  }
  def +(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T]   = add(that)

  def sub(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T] = {
    this.requireCompatible(that)
    val mat = Wire(new Matrix(self.gen(), self.row(), self.col()))
    for (r <- 0 until self.row())
      for (c <- 0 until self.col())
        mat.value(r)(c) := self.value(r)(c) - that.value(r)(c)
    mat
  }
  def -(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T]   = sub(that)

  def mul(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T] = {
    this.requireCompatible(that)
    val mat = Wire(new Matrix(self.gen(), self.row(), that.col()))
    for (r <- 0 until self.row())
      for (c <- 0 until that.col())
        mat.value(r)(c) := self.value(r)(c) * that.value(r)(c)
    mat
  }
  def *(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T]   = mul(that)

  def div(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T] = {
    this.requireCompatible(that)
    val mat = Wire(new Matrix(self.gen(), self.row(), self.col()))
    for (r <- 0 until self.row())
      for (c <- 0 until self.col())
        mat.value(r)(c) := self.value(r)(c) / that.value(r)(c)
    mat
  }
  def /(that: Matrix[T])(implicit ev: Arithmetic[T]): Matrix[T]   = div(that)
}
