package vopts.math

import chisel3._
import chisel3.util._
import vopts.utils._

class Radix4DivStep(dw: Int) extends Module {
  private val iter_count = (dw + 1) / 2
  private val ext_dw = iter_count * 2

  val quotient_in = IO(Input(UInt(dw.W)))
  val remainder_in = IO(Input(UInt((dw + 2).W)))
  val dividend_shift_in = IO(Input(UInt(ext_dw.W)))
  val divisor_abs_in = IO(Input(UInt(dw.W)))

  val q_digit_out = IO(Output(UInt(2.W)))
  val next_quotient_out = IO(Output(UInt(dw.W)))
  val next_remainder_out = IO(Output(UInt((dw + 2).W)))
  val next_dividend_shift_out = IO(Output(UInt(ext_dw.W)))
  val remainder_mag_out = IO(Output(UInt(dw.W)))

  val partial_remainder = Wire(UInt((dw + 2).W))
  partial_remainder := Cat(remainder_in(dw - 1, 0), dividend_shift_in(ext_dw - 1, ext_dw - 2))

  val divisor_ext = Wire(UInt((dw + 2).W))
  divisor_ext := Cat(0.U(2.W), divisor_abs_in)

  val divisor_x2 = Wire(UInt((dw + 2).W))
  divisor_x2 := divisor_ext << 1

  val divisor_x3 = Wire(UInt((dw + 2).W))
  divisor_x3 := divisor_x2 + divisor_ext

  val ge_3 = Wire(Bool())
  val ge_2 = Wire(Bool())
  val ge_1 = Wire(Bool())
  ge_3 := partial_remainder >= divisor_x3
  ge_2 := partial_remainder >= divisor_x2
  ge_1 := partial_remainder >= divisor_ext

  val q_digit = Wire(UInt(2.W))
  q_digit := Mux(ge_3, 3.U(2.W), Mux(ge_2, 2.U(2.W), Mux(ge_1, 1.U(2.W), 0.U(2.W))))

  val next_remainder = Wire(UInt((dw + 2).W))
  next_remainder := MuxLookup(q_digit, partial_remainder)(
    Seq(
      1.U -> (partial_remainder - divisor_ext),
      2.U -> (partial_remainder - divisor_x2),
      3.U -> (partial_remainder - divisor_x3)
    )
  )

  val quotient_shifted = Wire(UInt(dw.W))
  quotient_shifted := (quotient_in << 2)(dw - 1, 0)

  val next_quotient = Wire(UInt(dw.W))
  next_quotient := quotient_shifted | q_digit

  val next_dividend_shift = Wire(UInt(ext_dw.W))
  next_dividend_shift := (dividend_shift_in << 2)(ext_dw - 1, 0)

  q_digit_out := q_digit
  next_quotient_out := next_quotient
  next_remainder_out := next_remainder
  next_dividend_shift_out := next_dividend_shift
  remainder_mag_out := next_remainder(dw - 1, 0)
}

// Radix-4 restoring divider.
// Two quotient bits are generated per cycle.
class RestoringDivider(dw: Int) extends Module {
  require(dw > 0, "dw needs to be > 0")

  private val iter_count = (dw + 1) / 2
  private val ext_dw = iter_count * 2

  val dividend = IO(Input(UInt(dw.W)))
  val divisor = IO(Input(UInt(dw.W)))
  val start = IO(Input(Bool()))
  val kill = IO(Input(Bool()))
  val is_signed = IO(Input(Bool()))
  val select_remainder = IO(Input(Bool()))

  val result = IO(Output(UInt(dw.W)))
  val quotient = IO(Output(UInt(dw.W)))
  val remainder = IO(Output(UInt(dw.W)))
  val div_by_zero = IO(Output(Bool()))
  val busy = IO(Output(Bool()))
  val done = IO(Output(Bool()))

  val running_reg = RegInit(false.B)
  val done_reg = RegInit(false.B)
  val div_by_zero_reg = RegInit(false.B)

  val step_count_reg = RegInit(0.U(log2Ceil(iter_count + 1).W))
  val quotient_reg = RegInit(0.U(dw.W))
  val remainder_reg = RegInit(0.U((dw + 2).W))
  val dividend_shift_reg = RegInit(0.U(ext_dw.W))
  val divisor_abs_reg = RegInit(0.U(dw.W))

  val quotient_neg_reg = RegInit(false.B)
  val remainder_neg_reg = RegInit(false.B)

  val quotient_out_reg = RegInit(0.U(dw.W))
  val remainder_out_reg = RegInit(0.U(dw.W))

  def negate_u(value: UInt): UInt = (~value).asUInt + 1.U
  def abs_u(value: UInt, neg_flag: Bool): UInt = Mux(neg_flag, negate_u(value), value)

  val step_unit = Module(new Radix4DivStep(dw))
  step_unit.quotient_in := quotient_reg
  step_unit.remainder_in := remainder_reg
  step_unit.dividend_shift_in := dividend_shift_reg
  step_unit.divisor_abs_in := divisor_abs_reg

  val dividend_neg = Wire(Bool())
  val start_fire = Wire(Bool())
  val divisor_is_zero = Wire(Bool())
  val signed_overflow = Wire(Bool())
  val last_step = Wire(Bool())

  dividend_neg := is_signed && dividend(dw - 1)
  start_fire := start && !kill && !running_reg
  divisor_is_zero := divisor === 0.U
  signed_overflow := is_signed && (dividend === (1.U << (dw - 1)).asUInt) && (divisor === Fill(dw, 1.U(1.W)))
  last_step := step_count_reg === (iter_count - 1).U

  val dividend_abs = abs_u(dividend, dividend_neg)

  done_reg := false.B

  when(kill) {
      running_reg := false.B
    step_count_reg := 0.U
  }.elsewhen(start_fire) {
    when(divisor_is_zero) {
      // RISC-V compatible behavior.
      quotient_out_reg := Fill(dw, 1.U(1.W))
      remainder_out_reg := dividend
      div_by_zero_reg := true.B
      running_reg := false.B
      done_reg := true.B
      step_count_reg := 0.U
    }.elsewhen(signed_overflow) {
      // MIN_INT / -1 => quotient = MIN_INT, remainder = 0.
      quotient_out_reg := (1.U << (dw - 1)).asUInt
      remainder_out_reg := 0.U
      div_by_zero_reg := false.B
      running_reg := false.B
      done_reg := true.B
      step_count_reg := 0.U
    }.otherwise {
      running_reg := true.B
      div_by_zero_reg := false.B
      step_count_reg := 0.U

    quotient_reg := 0.U
    remainder_reg := 0.U
    dividend_shift_reg := (if (ext_dw == dw) dividend_abs else Cat(0.U((ext_dw - dw).W), dividend_abs))
  divisor_abs_reg := Mux(is_signed && divisor(dw - 1), negate_u(divisor), divisor)

  quotient_neg_reg := dividend_neg ^ (is_signed && divisor(dw - 1))
      remainder_neg_reg := dividend_neg
    }
  }.elsewhen(running_reg) {
    quotient_reg := step_unit.next_quotient_out
    remainder_reg := step_unit.next_remainder_out
    dividend_shift_reg := step_unit.next_dividend_shift_out

    when(last_step) {
      quotient_out_reg := Mux(quotient_neg_reg, negate_u(step_unit.next_quotient_out), step_unit.next_quotient_out)
      remainder_out_reg := Mux(remainder_neg_reg, negate_u(step_unit.remainder_mag_out), step_unit.remainder_mag_out)

      running_reg := false.B
      done_reg := true.B
      step_count_reg := 0.U
    }.otherwise {
      step_count_reg := step_count_reg + 1.U
    }
  }

  quotient := quotient_out_reg
  remainder := remainder_out_reg
  result := Mux(select_remainder, remainder_out_reg, quotient_out_reg)

  div_by_zero := div_by_zero_reg
  busy := running_reg
  done := done_reg
}

object TestRestoringDivider extends App {
  VerilogEmitter.parse(
    new RestoringDivider(32),
    "restoring_divider_32.sv"
  )
}
