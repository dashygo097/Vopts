#!/bin/bash

BASE_DIR=$(pwd)
TB_DIR="$BASE_DIR/testbench/tb"

run_test() {
	cd "$TB_DIR" || exit
	printf "\e[1;31m[INFO] Choose testbench.\n\e[0m"

	tb_file=$(find . -type f -name "*_tb.sv" -o -name "*_tb.v" | fzf)
	module_file=$(basename "$tb_file" | sed 's/_tb\.sv//')
	ext=".${module_file##*.}"

	verilator --cc --exe --build --binary --trace "$tb_file" -o "V$(basename "$module_file" "$ext")"

	cd "./obj_dir" || exit
	"./V$(basename "$module_file" "$ext")"

	# run if .vcd file exists
	if [ -f "$(basename "$module_file" "$ext").vcd" ]; then
		gtkwave "$(basename "$module_file" "$ext").vcd"
	else 
		printf "\e[1;31m[INFO] No corresponding .vcd file found.\n\e[0m"
		printf "\e[1;31m[INFO] Select a .vcd file.\n\e[0m"
		vcd_file=$(find . -type f -name "*.vcd" | fzf)
		gtkwave "$vcd_file"
	fi

	cd "$BASE_DIR" || exit
}

run_test

