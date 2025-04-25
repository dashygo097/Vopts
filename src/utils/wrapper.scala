package utils

import chisel3._

object DataWrapper {
  def apply[T <: Data](data: T): T = RegNext(data)
}

