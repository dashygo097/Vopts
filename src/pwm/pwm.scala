package pwm
import global.Config

import chisel3._
import chisel3.util._

class PWMCoreIO extends Bundle {
  val dutyCycle = Input(UInt(6.W)) 
  val pwmOut = Output(Bool())
}


