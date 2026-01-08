package vopts.net.eth

import chisel3._

object PHYInterfaceType extends Enumeration {
  val MII   = Value(0)
  val RMII  = Value(1)
  val RGMII = Value(2)
}

class PHYInterface(phyType: PHYInterfaceType.Value) extends Bundle {
  val mdio  = new MDIOInterface
  val rst_n = Output(Bool())
  val irq   = Input(Bool())

  val mii   = if (phyType == PHYInterfaceType.MII) Some(new MIIInterface) else None
  val rmii  = if (phyType == PHYInterfaceType.RMII) Some(new RMIIInterface) else None
  val rgmii = if (phyType == PHYInterfaceType.RGMII) Some(new RGMIIInterface) else None
}
