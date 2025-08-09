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

  def buildTree[T <: Data](data: Vec[T], groupSize: Int)(op: (T, T) => T) : T = {
    val n = data.length
    if (n <= groupSize) {
      data.reduce(op)
    } else {
      val groupNum = n / groupSize
      val reminder = n % groupNum
      val groups = (0 until groupNum).map { i =>
        val startIdx = i * groupSize
        val endIdx = if (i == groupNum - 1) startIdx + groupSize + reminder else startIdx + groupSize
        VecInit(data.slice(startIdx, endIdx))
      }
      val reducedGroups = RegNext(VecInit(groups.map(_.reduce(op)))) 
      buildTree(reducedGroups, groupSize)(op)
    }
  }
}
