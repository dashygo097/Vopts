package mem.register

case class RegisterFactory(
  name: String,
  addr: BigInt,
  initValue: BigInt = 0L
)
