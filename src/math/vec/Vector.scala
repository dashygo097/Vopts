package vopts.math

import vopts.utils._
import chisel3._

class Vector[T <: Data](gen: T, val size: Int)(implicit ev: Arithmetic[T]) extends Bundle with VectorOps[T] {
  val value = Vec(size, gen.cloneType)

  def eleType: T = value.head.cloneType

  def apply(idx: Int): T = {
    require(idx >= 0 && idx < size, s"Vector index out of bounds: $idx, size=$size")
    value(idx)
  }

  def update(idx: Int, data: T): Unit = {
    require(idx >= 0 && idx < size, s"Vector index out of bounds: $idx, size=$size")
    value(idx) := data
  }

  def slice(start: Int, end: Int): Vector[T] = {
    require(
      start >= 0 && end <= size && start < end,
      s"Vector slice indices out of bounds: start=$start, end=$end, size=$size"
    )
    val vec = Wire(new Vector(gen, end - start))
    vec.value := value.slice(start, end)
    vec
  }

  def fromSeq(seq: Seq[T]): Vector[T] = {
    require(seq.length == size, s"Vector size mismatch: expected $size, got ${seq.length}")
    val vec = Wire(new Vector(gen, size))
    vec.value := seq.map(_.asTypeOf(gen)).toVector
    vec
  }

  def isCompatible(that: Vector[T]): Boolean =
    this.size == that.size && this.gen.getClass == that.eleType.getClass

  def requireCompatible(that: Vector[T]): Unit =
    require(
      isCompatible(that),
      s"Vector compatibility check failed: " +
        s"this(${this.size}, ${this.eleType}) vs that(${that.size}, ${that.eleType})"
    )
}

object Vector {
  def apply[T <: Data](gen: T, size: Int)(implicit ev: Arithmetic[T]): Vector[T] =
    new Vector(gen, size)
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T]       = {
    val size = seq.length
    val vec  = new Vector(seq.head, size)
    vec.fromSeq(seq)
  }
}

object vec2 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Vector[T]      =
    new Vector(gen, 2)
  def apply[T <: Data](x: T, y: T)(implicit ev: Arithmetic[T]): Vector[T]  = {
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
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Vector[T]           =
    new Vector(gen, 3)
  def apply[T <: Data](x: T, y: T, z: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = new Vector(x, 3)
    vec.value(0) := x
    vec.value(1) := y
    vec.value(2) := z
    vec
  }
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T]      = {
    require(seq.length == 3, s"vec3 requires exactly 3 elements, got ${seq.length}")
    new Vector(seq.head, 3).fromSeq(seq)
  }
}

object vec4 {
  def apply[T <: Data](gen: T)(implicit ev: Arithmetic[T]): Vector[T]                 =
    new Vector(gen, 4)
  def apply[T <: Data](x: T, y: T, z: T, w: T)(implicit ev: Arithmetic[T]): Vector[T] = {
    val vec = new Vector(x, 4)
    vec.value(0) := x
    vec.value(1) := y
    vec.value(2) := z
    vec.value(3) := w
    vec
  }
  def apply[T <: Data](seq: Seq[T])(implicit ev: Arithmetic[T]): Vector[T]            = {
    require(seq.length == 4, s"vec4 requires exactly 4 elements, got ${seq.length}")
    new Vector(seq.head, 4).fromSeq(seq)
  }
}

trait VectorOps[T <: Data] {
  self: Vector[T] =>

  def add(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T] = {
    this.requireCompatible(that)
    val result = Wire(new Vector(self.eleType, self.size))
    result.value := Pipeline.buildChunkTree(self.value, that.value, chunkSize)(_ + _)
    result
  }
  def +(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T]   = this.add(that, chunkSize)

  def sub(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T] = {
    this.requireCompatible(that)
    val result = Wire(new Vector(self.eleType, self.size))
    result.value := Pipeline.buildChunkTree(self.value, that.value, chunkSize)(_ - _)
    result
  }
  def -(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T]   = this.sub(that, chunkSize)

  def mul(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T] = {
    this.requireCompatible(that)
    val result = Wire(new Vector(self.eleType, self.size))
    result.value := Pipeline.buildChunkTree(self.value, that.value, chunkSize)(_ * _)
    result
  }
  def *(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T]   = this.mul(that, chunkSize)

  def div(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T] = {
    this.requireCompatible(that)
    val result = Wire(new Vector(self.eleType, self.size))
    result.value := Pipeline.buildChunkTree(self.value, that.value, 16)(_ / _)
    result
  }
  def /(that: Vector[T], chunkSize: Int = 16)(implicit ev: Arithmetic[T]): Vector[T]   = this.div(that, chunkSize)

  def sum(groupSize: Int = 2)(implicit ev: Arithmetic[T]): T = {
    val sum = Wire(self.eleType)
    sum := Pipeline.buildTree(self.value, groupSize)(_ + _)
    sum
  }

  def dot(that: Vector[T], groupSize: Int = 2)(implicit ev: Arithmetic[T]): T = {
    this.requireCompatible(that)
    val products = VecInit.tabulate(self.size) { i =>
      RegNext(self.value(i) * that.value(i))
    }
    val sum      = Pipeline.buildTree(products, groupSize)(_ + _)
    sum
  }

  def min(groupSize: Int = 2)(implicit ord: PartialOrdered[T]): T = {
    val minimum = Wire(self.eleType)
    minimum := Pipeline.buildTree(self.value, groupSize)(_ min _)
    minimum
  }

  def max(groupSize: Int = 2)(implicit ord: PartialOrdered[T]): T = {
    val maximum = Wire(self.eleType)
    maximum := Pipeline.buildTree(self.value, groupSize)(_ max _)
    maximum
  }
}
