package vopts.math

import vopts.utils._
import chisel3._
import chisel3.util._

class BoothWallaceMultiplier(dw: Int, pStages: Int) extends Module {
  override def desiredName: String = s"booth_wallace_multiplier_${dw}_p$pStages"

  val multiplicand = IO(Input(UInt(dw.W)))
  val multiplier   = IO(Input(UInt(dw.W)))
  val valid_in     = IO(Input(Bool()))
  val ready_out    = IO(Output(Bool()))

  val product   = IO(Output(UInt((2 * dw).W)))
  val valid_out = IO(Output(Bool()))
  val ready_in  = IO(Input(Bool()))

  val pipelineValid = if (pStages > 0) {
    RegInit(VecInit(Seq.fill(pStages + 1)(false.B)))
  } else {
    WireDefault(VecInit(Seq.fill(1)(false.B)))
  }

  val inputReady = !pipelineValid.last || ready_in
  ready_out := inputReady

  val inputHandshake = valid_in && ready_out

  // Stage 0: Partial Product Generation
  val ppGen = Module(new PartialProductGen(dw))
  ppGen.multiplicand := multiplicand
  ppGen.multiplier   := multiplier

  val stage0_valid = inputHandshake
  val stage0_pps   = ppGen.partialProducts

  // Pipeline registers between stages
  def insertPipelineStage[T <: Data](
    stageNum: Int,
    data: T,
    valid: Bool
  ): (T, Bool) =
    if (pStages > 0 && stageNum <= pStages) {
      val enable   = valid && (!pipelineValid.last || ready_in)
      val regData  = RegEnable(data, 0.U.asTypeOf(data), enable)
      val regValid = RegNext(enable, false.B)
      (regData, regValid)
    } else {
      (data, valid)
    }

  // Distribute pipeline stages
  val stage1Num = pStages / 3
  val stage2Num = 2 * pStages / 3

  // After partial product generation
  val (stage1_pps, stage1_valid) = if (stage1Num > 0) {
    insertPipelineStage(1, stage0_pps, stage0_valid)
  } else {
    (stage0_pps, stage0_valid)
  }

  // Stage 1: Wallace Tree Reduction
  val wallace = Module(new WallaceTree(dw))
  wallace.partialProducts := stage1_pps

  val stage1_sum   = wallace.sum
  val stage1_carry = wallace.carry

  // After Wallace tree
  val (stage2_sum, stage2_valid_sum) = if (stage2Num > stage1Num) {
    insertPipelineStage(2, stage1_sum, stage1_valid)
  } else {
    (stage1_sum, stage1_valid)
  }

  val (stage2_carry, stage2_valid_carry) = if (stage2Num > stage1Num) {
    insertPipelineStage(2, stage1_carry, stage1_valid)
  } else {
    (stage1_carry, stage1_valid)
  }

  val stage2_valid = stage2_valid_sum

  // Stage 2: Final Addition
  val finalProduct = stage2_sum + stage2_carry

  // After final addition
  val (stage3_product, stage3_valid) = if (pStages > stage2Num) {
    insertPipelineStage(3, finalProduct, stage2_valid)
  } else {
    (finalProduct, stage2_valid)
  }

  product   := stage3_product
  valid_out := stage3_valid

  // Update pipeline valid tracking
  if (pStages > 0) {
    when(!pipelineValid.last || ready_in) {
      pipelineValid(0)   := inputHandshake
      for (i <- 1 to pStages)
        pipelineValid(i) := pipelineValid(i - 1)
    }
  }
}

object TestBoothWallaceMultiplier extends App {
  VerilogEmitter.parse(new BoothWallaceMultiplier(16, 0), "booth_wallace_multiplier.v")
}
