package fir

import chisel3._
import chisel3.util._

trait Config extends global.Config {
  val sampleFreq :Int = clkFreq
}
