package app

import app.VerilogEmitter
import math._
import utils._
import chisel3._

class VecAdd extends Module {
  val io = IO(new Bundle {
    val a = Input(vec4(new FP))
    val b = Input(vec4(new FP))
    val c = Output(vec4(new FP))
  })

  io.c := io.a + (io.b, 32) 
}

object VecAdd extends App {
  VerilogEmitter.parse(new VecAdd, "vec_add.sv", info=true)
}
