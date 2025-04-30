package dds.trig

import utils._
import datatype.fp.FP

import scala.math._

import chisel3._

object SineROM extends Config {
  VecInit(
    (0 until lutWidth).map { i => 
      val angle = 2 * Pi * i / lutWidth
      val value = sin(angle) 
      FP(value)
    }
  )
}
