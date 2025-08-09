package utils

import chisel3._

object Pipeline {
  
  def apply[T <: Data](data: T, stages: Int): T = {
    require(stages > 0, "Number of stages must be greater than 0")
    var currentData = data
    for (_ <- 0 until stages) {
      currentData = RegNext(currentData)
    }
    currentData
  }

  def buildBinaryTree[T <: Data](data: Vec[T])(op : (T, T) => T) : T = {
    val n = data.length
    if (n == 1) {
      data(0)
    } else {
      val half = n / 2
      val left = VecInit(data.take(half))
      val right = VecInit(data.drop(half))
      RegNext(op(buildBinaryTree(left)(op), buildBinaryTree(right)(op)))
    }
  }
}
