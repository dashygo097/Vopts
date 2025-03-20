#!/bin/bash

CURRENT_DIR=$(pwd)
SCRIPT_DIR=$(dirname "$0")

run_test() {
	cd "$SCRIPT_DIR/build" || exit
	printf "\e[1;31m[NOTE] Choose the testbench.\n\e[0m"
	tb_file=$(find . -type f -name "*_tb.sv" -o -name "*_tb.v" | fzf)
	module_file=$(basename "$tb_file" | sed 's/_tb\.sv//')
	verilator --cc --exe --build --binary --trace "$tb_file" -o "V$(basename "$module_file" .sv)"
	cd "./obj_dir" || exit
	"./V$(basename "$module_file" .sv)"
	# run if .vcd file exists
	if [ -f "$(basename "$module_file" .sv).vcd" ]; then
		gtkwave "$(basename "$module_file" .sv).vcd"
	fi

	cd "$CURRENT_DIR" || exit
}

run_test
