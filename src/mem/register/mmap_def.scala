package mem.register

case class RegisterFactory(
  name: String,
  addr: Long,
  initValue: Long = 0L
)
