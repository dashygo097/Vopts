package fft

import chisel3._
import chisel3.util._

trait Config extends global.Config {
  val n: Int = 512
}
