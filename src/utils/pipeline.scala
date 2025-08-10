package utils

import scala.math.min
import chisel3._
import chisel3.util._

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
      val groups = (0 until groupNum).map { i =>
        val startIdx = i * groupSize
        val endIdx = min(startIdx + groupSize, n)
        VecInit(data.slice(startIdx, endIdx))
      }
      val reducedGroups = RegNext(VecInit(groups.map(_.reduce(op)))) 
      buildTree(reducedGroups, groupSize)(op)
    }
  }

  def buildChunkTree[T <: Data](data1: Vec[T], data2: Vec[T], chunkSize: Int)(op: (T, T) => T) : Vec[T] = {
    val n1 = data1.length
    val n2 = data2.length
    require(n1 == n2, "Both vectors must have the same length")

    val result = Wire(Vec(n1, data1.head.cloneType))
    val chunkNum = n1 / chunkSize + (if (n1 % chunkSize == 0) 0 else 1)

    for (chunkIdx <- 0 until chunkNum) {
      val startIdx = chunkIdx * chunkSize
      val endIdx = min(startIdx + chunkSize, n1)
      val chunk1 = data1.slice(startIdx, endIdx)
      val chunk2 = data2.slice(startIdx, endIdx)

      val stagedResult = Wire(Vec(chunkSize, data1.head.cloneType))
      stagedResult := chunk1.zip(chunk2).map { case (d1, d2) => op(d1, d2) }

      for (i <- 0 until stagedResult.length) {
        if (startIdx + i < n1) {
          result(startIdx + i) := ShiftRegister(stagedResult(i), chunkIdx + 1)
        }
      }
    }

    result
  }
}
