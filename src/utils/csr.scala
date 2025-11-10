package utils 

case class Register(
  name: String,
  addr: BigInt,
  initValue: BigInt = 0L,
  writable: Boolean = true,
  readable: Boolean = true
)

trait CSRMMap { 
  def baseAddr: BigInt 
  def registers: Seq[Register]
}

