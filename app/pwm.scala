package app

import pwm.{PWMCore, ModPWMCore}

object PWM extends App {
  VerilogEmitter.parse(new PWMCore(1000000, 0.2), "pwm.sv")
  VerilogEmitter.parse(new ModPWMCore(1000000), "mod_pwm.sv")
}
