package vopts.com.amba

import chisel3._

abstract class AHBManager(addrWidth: Int, dataWidth: Int) extends Module {
  protected def getExtAHBName: String = "M_AHB"

  val ahb_ext = IO(new AHBManagerExtIO(addrWidth, dataWidth)).suggestName(getExtAHBName)
  val ahb     = Wire(new AHBManagerIO(addrWidth, dataWidth))

  dontTouch(ahb_ext)

  // State Encoding
  protected val IDLE     = 0.U(2.W)
  protected val REQUEST  = 1.U(2.W)
  protected val TRANSFER = 2.U(2.W)

  // Signals
  protected val state = RegInit(IDLE)
}
