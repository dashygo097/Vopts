package math

import utils._
import chisel3._

class Vector[T <: Data](gen: T, size: Int)(implicit ev: Arithmetic[T]) extends Bundle with VectorOps[T] {
  var _size = size

  val value = Vec(size, gen.cloneType)

  def get_size(): Int = {
    _size
  }

  def get_gen(): T = {
    value.head
  }

  def apply(idx: Int): T = {
    require(idx >= 0 && idx < _size, s"Vector index out of bounds: $idx, size=${_size}")
    value(idx)
  }

  def update(idx: Int, data: T): Unit = {
    require(idx >= 0 && idx < _size, s"Vector index out of bounds: $idx, size=${_size}")
    value(idx) := data
  }

  def slice(start: Int, end: Int): Vector[T] = {
    require(start >= 0 && end <= _size && start < end,
      s"Vector slice indices out of bounds: start=$start, end=$end, size=${_size}")
    val vec = Wire(new Vector(gen, end - start))
    vec.value := value.slice(start, end)
    vec
  }

  def fromSeq(seq: Seq[T]): Vector[T] = {
    require(seq.length == _size, s"Vector size mismatch: expected ${_size}, got ${seq.length}")
    val vec = Wire(new Vector(gen, _size))
    vec.value := seq.map(_.asTypeOf(gen)).toVector
    vec
  }

  def _match(that: Vector[T]): Unit = {
    require(this.get_size() == that.get_size(),
      s"Vector match requires same size: ${this.get_size()} vs ${that.get_size()}")
  }
}

object Vector {
  def apply[T <: Data](gen: T, size: Int)(implicit ev: Arithmetic[T]): Vector[T] = {
    new Vector(gen, size)
  }
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    val size = seq.length
    val vec = new Vector(seq.head, size)
    vec.fromSeq(seq)
  }
}

object vec2 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    new Vector(gen, 2)
  }
  def apply[T <: Data](x: T, y: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = new Vector(x, 2)
    vec.value(0) := x
    vec.value(1) := y
    vec
  }
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    require(seq.length == 2, s"vec2 requires exactly 2 elements, got ${seq.length}")
    new Vector(seq.head, 2).fromSeq(seq)
  }
}

object vec3 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    new Vector(gen, 3)
  }
  def apply[T <: Data](x: T, y: T, z: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = new Vector(x, 3)
    vec.value(0) := x
    vec.value(1) := y
    vec.value(2) := z
    vec
  }
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    require(seq.length == 3, s"vec3 requires exactly 3 elements, got ${seq.length}")
    new Vector(seq.head, 3).fromSeq(seq)
  }
}

trait VectorOps[T <: Data] {
  self: Vector[T] =>
  
  def +(that: Vector[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    this._match(that)
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.zip(that.value).map { case (a, b) => a + b }
    vec
  }
  
  def -(that: Vector[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    this._match(that)
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.zip(that.value).map { case (a, b) => a - b }
    vec
  }

  def *(that: Vector[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    this._match(that)
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.zip(that.value).map { case (a, b) => a * b }
    vec
  }
  
  def *(that: UInt)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.map(a => a * that)
    vec
  }

  def /(that: Vector[T])(implicit ev: Arithmetic[T]): Vector[T] = {
    this._match(that)
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.zip(that.value).map { case (a, b) => a / b }
    vec
  }
  
  def /(that: UInt)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = Wire(new Vector(self.get_gen(), self.get_size()))
    vec.value := self.value.map(a => a / that)
    vec
  }

  def sum()(implicit ev: Arithmetic[T]): T = {
    val sum = Wire(self.get_gen())
    sum := self.value.reduce(_ + _)
    sum
  }

  def dot(that: Vector[T])(implicit ev: Arithmetic[T]): T = {
    this._match(that)
    val sum = Wire(self.get_gen())
    sum := self.value.zip(that.value).map { case (a, b) => a * b }.reduce(_ + _)
    sum
  }

  def norm2()(implicit ev: Arithmetic[T]): T = {
    val sum = Wire(self.get_gen())
    sum := self.value.map(a => a * a).reduce(_ + _)
    sum
  }
}


