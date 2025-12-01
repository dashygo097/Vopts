# Vopts

#### A generative hardware library impled in chisel for common (system)verilog modules

###### **NOTE: THIS REPO IS STILL UNDER DEVELOPMENT AND TARGETED FOR MY PERSONAL USAGE**

## Prerequisite

#### For code generation:

- sbt version in this project: 1.10.11 (see **project/build.properties**)
- see chisel/scala version in **build.sbt**
- For FIR/IIR, scipy is used.

#### For autotest:

##### For regular autotest impled in verilog:

- gtkwave / surfer (waveform visualization)
- verilator (generating executable files for testbench)
- fzf (optional)

##### For cocotb autotest impled in python:

- icarus & cocotb (only tested under cocotb 1.9.2)
- fzf (optional)

#### For Synthesis and STA:

- Use the updated yosys(Yosys 0.58+162)

## How to use

To generate systemVerilog, write demos under **app/...** , and run

> ```bash
> make run
> ```

or

> ```bash
> sbt app/run
> ```

## Run Autotest

Run test using **verilator** and **gtkwave / surfer** through **tb.sh**

> ```bash
> make tb # (FZF=true)
> ```

Make sure that the tb file located in **sims/tb** <br>

or using

> ```bash
> make cocotb # (FZF=true)
> ```

for cocotb through **cocotb.sh**

Similarly, make sure that the py scripts are located in **sims/cocotb** and make sure you have cocotb env, activating a venv with uv is recommended.

###### All the related scripts can be found in scripts/

## Run STA

Run sta using **Yosys** or **Vivaod** through **./sta-yosys.sh** with Xilinx toolchain.

> ```bash
> make sta # (FZF=true STA_TOOL=tosys(vivado))
> ```

## References

#### Some code references:

[chisel-template](https://github.com/chipsalliance/chisel-template.git) <br>
[FFT](https://github.com/IA-C-Lab-Fudan/Chisel-FFT-generator.git) <br>
[AXI-IF](https://github.com/maltanar/axi-in-chisel) <br>
[hardfloat](https://github.com/ucb-bar/berkeley-hardfloat)
