package mem.register

case class Register(
  name: String,
  addr: Long,
  initValue: Long = 0L,
  writable: Boolean = true,
  readable: Boolean = true
)
