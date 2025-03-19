# Vopts
A lib impled in chisel/scala for generating (system)Verilog of some operators and modules for my learning projects. (still under dev) <br>

NOTE: THIS REPO IS ONLY FOR PERSONAL USAGE.

## Prerequisite

- Sbt version in this project: 1.9.7
- See chisel/scala version in build.sbt
- gtkwave(waveform visualization)
- verilator(generating executable files for testbench)

## How to use
To generate systemVerilog, Run
```
sbt run 
```
Or simply run 
```
sbt 
```
to start a sbt server.

## Run Test
Run test using verilator(Verilator 5.034 2025-02-24 rev UNKNOWN.REV) and gtkwave(GTKWave Analyzer v3.4.0 (w)1999-2022 BSI) through ./test.sh and fzf. 
```
./test.sh
```

## References
Some code references 

[chisel-template](https://github.com/chipsalliance/chisel-template.git) <br>
[FFT](https://github.com/IA-C-Lab-Fudan/Chisel-FFT-generator.git)

