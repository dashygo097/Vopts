package vopts.math

import vopts.utils._
import chisel3._
import chisel3.util._

class UIntMultiplier(dw: Int, pipelineStages: Int = 0) extends Module {
  override def desiredName: String = s"booth_4_wallace_tree_mul_${dw}_s$pipelineStages"

  val en           = IO(Input(Bool()))
  val multiplicand = IO(Input(UInt(dw.W)))
  val multiplier   = IO(Input(UInt(dw.W)))
  val result       = IO(Output(UInt((2 * dw).W)))
  val ready        = IO(Output(Bool()))
  val finish       = IO(Output(Bool()))

  val a = Mux(en, multiplicand, 0.U(dw.W))
  val b = Mux(en, multiplier, 0.U(dw.W))

  // 1. Unsigned Fix: Zero-extend inputs by 1 bit for Booth
  val extDW = dw + 1
  val a_ext = Cat(0.U(1.W), a)
  val b_ext = Cat(0.U(1.W), b)

  // Stage 1: Partial product generation
  val ppGen = Module(new PartialProductGen(extDW))
  ppGen.multiplicand := a_ext
  ppGen.multiplier   := b_ext

  val fullWidthPPs = ppGen.partialProducts
  val finalWidth   = 2 * dw

  // Stage 2: Wallace tree reduction
  val reduced = if (pipelineStages > 0) {
    finish := ShiftRegister(en, pipelineStages)
    val busyCounter = RegInit(0.U(log2Ceil(pipelineStages + 1).W))

    ready := (busyCounter === 0.U)

    when(en && ready) {
      busyCounter := pipelineStages.U
    }.elsewhen(busyCounter > 0.U) {
      busyCounter := busyCounter - 1.U
    }
    wallaceTreeReducePipelined(fullWidthPPs, pipelineStages, finalWidth)
  } else {
    ready  := en
    finish := en
    wallaceTreeReduce(fullWidthPPs, finalWidth)
  }

  // Stage 3: Final addition & Result Truncation
  val fullResult = reduced._1 + reduced._2
  result := fullResult((2 * dw) - 1, 0)

  // Wallace Tree Logic
  def wallaceTreeReduce(inputs: Seq[UInt], width: Int): (UInt, UInt) = {
    var currentLayer = inputs
    while (currentLayer.length > 2) {
      val nextLayer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i         = 0
      while (i < currentLayer.length)
        if (i + 2 < currentLayer.length) {
          val (sum, carry) = fullAdder(currentLayer(i), currentLayer(i + 1), currentLayer(i + 2), width)
          nextLayer += sum
          nextLayer += carry
          i += 3
        } else if (i + 1 < currentLayer.length) {
          val (sum, carry) = halfAdder(currentLayer(i), currentLayer(i + 1), width)
          nextLayer += sum
          nextLayer += carry
          i += 2
        } else {
          nextLayer += currentLayer(i)
          i += 1
        }
      currentLayer = nextLayer.toSeq
    }
    if (currentLayer.length == 2) (currentLayer(0), currentLayer(1))
    else if (currentLayer.nonEmpty) (currentLayer(0), 0.U(width.W))
    else (0.U(width.W), 0.U(width.W))
  }

  def wallaceTreeReducePipelined(inputs: Seq[UInt], stages: Int, width: Int): (UInt, UInt) = {
    var currentLayer   = inputs
    var stageCounter   = 0
    val layersPerStage = scala.math.ceil(scala.math.log(inputs.length) / scala.math.log(1.5) / stages).toInt.max(1)
    var layersSinceReg = 0

    while (currentLayer.length > 2) {
      val nextLayer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i         = 0
      while (i < currentLayer.length)
        if (i + 2 < currentLayer.length) {
          val (sum, carry) = fullAdder(currentLayer(i), currentLayer(i + 1), currentLayer(i + 2), width)
          nextLayer += sum
          nextLayer += carry
          i += 3
        } else if (i + 1 < currentLayer.length) {
          val (sum, carry) = halfAdder(currentLayer(i), currentLayer(i + 1), width)
          nextLayer += sum
          nextLayer += carry
          i += 2
        } else {
          nextLayer += currentLayer(i)
          i += 1
        }

      layersSinceReg += 1

      if (layersSinceReg >= layersPerStage && stageCounter < stages && nextLayer.length > 2) {
        currentLayer = nextLayer.map(x => RegNext(x)).toSeq
        layersSinceReg = 0
        stageCounter += 1
      } else {
        currentLayer = nextLayer.toSeq
      }
    }
    if (currentLayer.length == 2) (currentLayer(0), currentLayer(1))
    else if (currentLayer.nonEmpty) (currentLayer(0), 0.U(width.W))
    else (0.U(width.W), 0.U(width.W))
  }

  def fullAdder(a: UInt, b: UInt, c: UInt, width: Int): (UInt, UInt) = {
    val sumRaw = a ^ b ^ c
    val sum    = sumRaw(width - 1, 0)

    val carryRaw = Cat((a & b) | (a & c) | (b & c), 0.U(1.W))
    val carry    = carryRaw(width - 1, 0)

    (sum, carry)
  }

  def halfAdder(a: UInt, b: UInt, width: Int): (UInt, UInt) = {
    val sumRaw = a ^ b
    val sum    = sumRaw(width - 1, 0)

    val carryRaw = Cat(a & b, 0.U(1.W))
    val carry    = carryRaw(width - 1, 0)

    (sum, carry)
  }
}

object TestUIntMultiplier extends App {
  VerilogEmitter.parse(
    new UIntMultiplier(16, 2),
    "booth_4_wallace_tree_mul.sv"
  )
}
