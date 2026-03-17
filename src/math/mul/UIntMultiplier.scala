package vopts.math
import vopts.utils._
import chisel3._
import chisel3.util._

class UIntMultiplier(dw: Int, pipelineStages: Int = 0) extends Module {
  override def desiredName: String = s"booth_4_wallace_tree_mul_${dw}_s$pipelineStages"

  val isSignedA    = IO(Input(Bool()))
  val isSignedB    = IO(Input(Bool()))
  val en           = IO(Input(Bool()))
  val multiplicand = IO(Input(UInt(dw.W)))
  val multiplier   = IO(Input(UInt(dw.W)))
  val result       = IO(Output(UInt((2 * dw).W)))
  val ready        = IO(Output(Bool()))
  val finish       = IO(Output(Bool()))

  // -------------------------------------------------------
  // Stage 1: 部分积生成
  // 直接接输入，不用 Mux(en,...) 清零
  // en 拉低后输入由调用方保持或任意变化均可，
  // 流水线内的数据已经被寄存器锁住
  // -------------------------------------------------------
  val ppGen = Module(new PartialProductGen(dw))
  ppGen.isSignedA    := isSignedA
  ppGen.isSignedB    := isSignedB
  ppGen.multiplicand := multiplicand
  ppGen.multiplier   := multiplier

  val fullWidthPPs = ppGen.partialProducts
  val finalWidth   = 2 * dw

  // -------------------------------------------------------
  // Stage 2: Wallace 树规约
  // -------------------------------------------------------
  val reduced = if (pipelineStages > 0) {

    val (s, c, actualStages) = wallaceTreeReducePipelined(fullWidthPPs, pipelineStages, finalWidth)

    // finish 需要等到 CPA 结果稳定才能拉高
    // actualStages 是 Wallace 树内实际插入的寄存器层数
    // +1 是让 finish 对齐到 CPA 输出稳定的那一拍
    finish := ShiftRegister(en, actualStages + 1)

    // busyCounter 控制 ready：计数从 actualStages+1 倒数到 0
    val totalLatency = actualStages + 1
    val busyCounter  = RegInit(0.U(log2Ceil(totalLatency + 2).W))
    ready := (busyCounter === 0.U)
    when(en && (busyCounter === 0.U)) {
      busyCounter := totalLatency.U
    }.elsewhen(busyCounter > 0.U) {
      busyCounter := busyCounter - 1.U
    }

    (s, c)

  } else {
    // 纯组合逻辑版本
    ready  := true.B
    finish := en
    wallaceTreeReduce(fullWidthPPs, finalWidth)
  }

  // -------------------------------------------------------
  // Stage 3: 最终加法（CPA）
  // -------------------------------------------------------
  val fullResult = reduced._1 + reduced._2
  result := fullResult(2 * dw - 1, 0)

  // -------------------------------------------------------
  // Wallace 树（纯组合逻辑）
  // -------------------------------------------------------
  def wallaceTreeReduce(inputs: Seq[UInt], width: Int): (UInt, UInt) = {
    var currentLayer = inputs
    while (currentLayer.length > 2) {
      val nextLayer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i = 0
      while (i < currentLayer.length) {
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
      }
      currentLayer = nextLayer.toSeq
    }
    if (currentLayer.length == 2)      (currentLayer(0), currentLayer(1))
    else if (currentLayer.nonEmpty)    (currentLayer(0), 0.U(width.W))
    else                               (0.U(width.W), 0.U(width.W))
  }

  // -------------------------------------------------------
  // Wallace 树（流水线版本）
  // 返回 (sum, carry, 实际插入的寄存器层数)
  // -------------------------------------------------------
  def wallaceTreeReducePipelined(
      inputs: Seq[UInt],
      stages: Int,
      width:  Int
  ): (UInt, UInt, Int) = {

    var currentLayer   = inputs
    var stageCounter   = 0
    var actualStages   = 0
    val layersPerStage =
      scala.math.ceil(
        scala.math.log(inputs.length) / scala.math.log(1.5) / stages
      ).toInt.max(1)
    var layersSinceReg = 0

    while (currentLayer.length > 2) {
      val nextLayer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i = 0
      while (i < currentLayer.length) {
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
      }

      layersSinceReg += 1

      // 满足插寄存器条件：已做够 layersPerStage 层、还没用完 stage 预算、
      // 下一层仍有多于 2 个输入（否则直接进 CPA 即可）
      if (layersSinceReg >= layersPerStage && stageCounter < stages && nextLayer.length > 2) {
        currentLayer   = nextLayer.map(x => RegNext(x)).toSeq
        layersSinceReg = 0
        stageCounter   += 1
        actualStages   += 1   // 记录实际插入的寄存器层数
      } else {
        currentLayer = nextLayer.toSeq
      }
    }

    val (s, c) =
      if (currentLayer.length == 2)   (currentLayer(0), currentLayer(1))
      else if (currentLayer.nonEmpty) (currentLayer(0), 0.U(width.W))
      else                            (0.U(width.W), 0.U(width.W))

    (s, c, actualStages)
  }

  // -------------------------------------------------------
  // 全加器（CSA 单元）
  // -------------------------------------------------------
  def fullAdder(a: UInt, b: UInt, c: UInt, width: Int): (UInt, UInt) = {
    val sum   = (a ^ b ^ c)(width - 1, 0)
    val carry = (Cat((a & b) | (a & c) | (b & c), 0.U(1.W)))(width - 1, 0)
    (sum, carry)
  }

  // -------------------------------------------------------
  // 半加器
  // -------------------------------------------------------
  def halfAdder(a: UInt, b: UInt, width: Int): (UInt, UInt) = {
    val sum   = (a ^ b)(width - 1, 0)
    val carry = (Cat(a & b, 0.U(1.W)))(width - 1, 0)
    (sum, carry)
  }
}

object TestUIntMultiplier extends App {
  VerilogEmitter.parse(
    new UIntMultiplier(16, 2),
    "booth_4_wallace_tree_mul.sv"
  )
}