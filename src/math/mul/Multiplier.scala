package vopts.math

import vopts.utils._
import chisel3._
import chisel3.util._

// Encoding guide:
// MUL    a_signed=x b_signed=x take_high=0 → low dw
// MULH   a_signed=1 b_signed=1 take_high=1 → signed * signed high
// MULHU  a_signed=0 b_signed=0 take_high=1 → unsigned * unsigned high
// MULHSU a_signed=1 b_signed=0 take_high=1 → signed * unsigned high
class Multiplier(dw: Int, pipeline_stages: Int = 1) extends Module {
  require(dw > 0, "dw needs to be > 0")
  require(pipeline_stages >= 1, "pipeline_stages needs to be >= 1 (minimum is 1, i.e. only a_reg stage)")

  override def desiredName: String =
    s"booth_4_wallace_tree_mul_${dw}_s$pipeline_stages"

  // IO
  val multiplicand = IO(Input(UInt(dw.W)))
  val multiplier   = IO(Input(UInt(dw.W)))
  val start        = IO(Input(Bool())) // start a request
  val kill         = IO(Input(Bool())) // cancel in-flight request on flush/mispredict
  val a_signed     = IO(Input(Bool())) // multiplicand signed flag
  val b_signed     = IO(Input(Bool())) // multiplier signed flag
  val take_high    = IO(Input(Bool())) // 1=high dw bits (MULH*), 0=low dw bits (MUL)
  val result       = IO(Output(UInt(dw.W)))
  val busy         = IO(Output(Bool()))
  val done         = IO(Output(Bool()))

  // Handshake: fully pipelined
  val in_fire = start && !kill

  // Stage 0: input latch; counts toward total delay so Wallace tree adds (pipeline_stages - 1) RegNext
  val a_reg         = Reg(UInt(dw.W))
  val b_reg         = Reg(UInt(dw.W))
  val a_signed_reg  = Reg(Bool())
  val b_signed_reg  = Reg(Bool())
  val take_high_reg = Reg(Bool())
  when(in_fire) {
    a_reg         := multiplicand
    b_reg         := multiplier
    a_signed_reg  := a_signed
    b_signed_reg  := b_signed
    take_high_reg := take_high
  }

  // Stage 1: Booth-4 partial product generation
  val ext_dw = dw + 1
  val a_ext  = Cat(Mux(a_signed_reg, a_reg(dw - 1), 0.U), a_reg)
  val b_ext  = Cat(Mux(b_signed_reg, b_reg(dw - 1), 0.U), b_reg)

  val pp_gen = Module(new PartialProductGen(ext_dw))
  pp_gen.multiplicand        := a_ext
  pp_gen.multiplier          := b_ext
  pp_gen.multiplicand_signed := a_signed_reg
  pp_gen.multiplier_signed   := b_signed_reg

  val full_width_pps = pp_gen.partial_products
  val final_width    = 2 * dw

  // Stage 2: Wallace tree reduction
  // RegNext count inside Wallace tree = pipeline_stages - 1 (excluding a_reg stage)
  val wallace_target_stages = pipeline_stages - 1

  val (r1, r2, actual_wallace_stages) =
    if (wallace_target_stages > 0)
      wallace_tree_reduce_pipelined(full_width_pps, wallace_target_stages, final_width)
    else {
      // pipeline_stages == 1: pure combinational Wallace
      val p = wallace_tree_reduce(full_width_pps, final_width)
      (p._1, p._2, 0)
    }

  // Total latency = a_reg (1 stage) + actual Wallace pipeline depth
  val actual_delay = actual_wallace_stages + 1

  // Valid shift chain: vld(0) = in_fire; vld(i) = vld(i-1); done = vld.last
  // Align take_high to done
  val vld = RegInit(VecInit(Seq.fill(actual_delay)(false.B)))
  when(reset.asBool) {
    vld.foreach(_ := false.B)
  }.otherwise {
    vld(0)                               := in_fire
    for (i <- 1 until vld.length) vld(i) := vld(i - 1)
  }

  val take_high_aligned: Bool = if (actual_delay > 1) {
    val p = RegInit(VecInit(Seq.fill(actual_delay - 1)(false.B)))
    when(reset.asBool) {
      p.foreach(_ := false.B)
    }.otherwise {
      p(0)                             := take_high_reg
      for (i <- 1 until p.length) p(i) := p(i - 1)
    }
    p.last
  } else {
    // actual_delay == 1: take_high_reg is aligned with vld(0)
    take_high_reg
  }

  done := vld.last
  busy := vld.asUInt.orR

  // Stage 3: final add and slice
  val full_result = r1 + r2
  result := Mux(
    take_high_aligned,
    full_result((2 * dw) - 1, dw), // MULH / MULHSU / MULHU: high dw bits
    full_result(dw - 1, 0)         // MUL: low dw bits
  )
  // Wallace tree implementation
  /* Combinational Wallace tree: reduce to two vectors */
  def wallace_tree_reduce(inputs: Seq[UInt], width: Int): (UInt, UInt) = {
    var current_layer = inputs
    while (current_layer.length > 2) {
      val next_layer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i          = 0
      while (i < current_layer.length)
        if (i + 2 < current_layer.length) {
          val (s, c) = fullAdder(current_layer(i), current_layer(i + 1), current_layer(i + 2), width)
          next_layer += s; next_layer += c; i += 3
        } else if (i + 1 < current_layer.length) {
          val (s, c) = halfAdder(current_layer(i), current_layer(i + 1), width)
          next_layer += s; next_layer += c; i += 2
        } else {
          next_layer += current_layer(i); i += 1
        }
      current_layer = next_layer.toSeq
    }
    if (current_layer.length == 2) (current_layer(0), current_layer(1))
    else if (current_layer.nonEmpty) (current_layer(0), 0.U(width.W))
    else (0.U(width.W), 0.U(width.W))
  }

  /**
   * Pipelined Wallace tree. Step 1: pure Scala simulation to count total layers (no hardware nodes). Step 2: single Chisel traversal, inserting RegNext at evenly spaced cut points.
   */
  def wallace_tree_reduce_pipelined(
    inputs: Seq[UInt],
    stages: Int,
    width: Int
  ): (UInt, UInt, Int) = {

    // Step 1: compile-time layer counting
    var mock_count   = inputs.length
    var total_layers = 0
    while (mock_count > 2) {
      val fa   = mock_count / 3
      val ha   = (mock_count % 3) / 2
      val pass = mock_count  % 3 % 2
      mock_count = fa * 2 + ha * 2 + pass
      total_layers += 1
    }

    // Clamp to total_layers; warn if requested deeper
    val actual_stages = stages.min(total_layers)
    if (stages > total_layers)
      println(
        s"[WARN] Multiplier(dw=$dw): " +
          s"pipeline_stages=$pipeline_stages asks for $stages Wallace pipeline registers, " +
          s"but total layers = $total_layers; actual latency will be ${actual_stages + 1} cycles. " +
          s"Consider reducing pipeline_stages to ${total_layers + 1}."
      )

    // Cut points: insert RegNext after selected layers, evenly distributed
    val cut_points: Set[Int] = (1 to actual_stages)
      .map(i => (i * total_layers) / (actual_stages + 1))
      .filter(_ > 0)
      .toSet

    // Step 2: single traversal with optional registers
    var current_layer = inputs
    var layer_idx     = 0
    while (current_layer.length > 2) {
      val next_layer = scala.collection.mutable.ArrayBuffer[UInt]()
      var i          = 0
      while (i < current_layer.length)
        if (i + 2 < current_layer.length) {
          val (s, c) = fullAdder(current_layer(i), current_layer(i + 1), current_layer(i + 2), width)
          next_layer += s; next_layer += c; i += 3
        } else if (i + 1 < current_layer.length) {
          val (s, c) = halfAdder(current_layer(i), current_layer(i + 1), width)
          next_layer += s; next_layer += c; i += 2
        } else {
          next_layer += current_layer(i); i += 1
        }

      layer_idx += 1
      current_layer =
        if (cut_points.contains(layer_idx)) next_layer.map(x => RegNext(x)).toSeq
        else next_layer.toSeq
    }

    // Add missing registers if cut points were fewer than requested
    val missing = actual_stages - cut_points.size
    if (missing > 0)
      current_layer = (0 until missing).foldLeft(current_layer) { (layer, _) =>
        layer.map(x => RegNext(x))
      }

    val (out1, out2) =
      if (current_layer.length == 2) (current_layer(0), current_layer(1))
      else if (current_layer.nonEmpty) (current_layer(0), 0.U(width.W))
      else (0.U(width.W), 0.U(width.W))

    (out1, out2, actual_stages)
  }

  // Basic cells (carry-save form)

  def fullAdder(a: UInt, b: UInt, c: UInt, width: Int): (UInt, UInt) = {
    val sum   = (a ^ b ^ c)(width - 1, 0)
    val carry = Cat((a & b) | (a & c) | (b & c), 0.U(1.W))(width - 1, 0)
    (sum, carry)
  }

  /** Half adder (carry-save form) */
  def halfAdder(a: UInt, b: UInt, width: Int): (UInt, UInt) = {
    val sum   = (a ^ b)(width - 1, 0)
    val carry = Cat(a & b, 0.U(1.W))(width - 1, 0)
    (sum, carry)
  }
}

// Generation entry point
object TestMultiplier extends App {
  VerilogEmitter.parse(
    new Multiplier(32, 2),
    "booth_4_wallace_tree_mul.sv"
  )
}
