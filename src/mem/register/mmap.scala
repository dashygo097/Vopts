package mem.register

case class RegisterConfig(
  addr: Int,
  width: Int = 32,
  initValue: Int = 0,
  readOnly: Boolean = false,
  writeOnly: Boolean = false,
  name: String = ""
)
