#!/bin/bash

BASE_DIR=$(dirname $(cd "$(dirname "$0")" && pwd))
TB_DIR=$BASE_DIR/testbenchs/tb

RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
MAGENTA='\033[1;35m'
CYAN='\033[1;36m'
GRAY='\033[1;37m'
NC='\033[0m' 
BOLD='\033[1m'
DIM='\033[2m'

show_header() {
  echo -e "${BLUE}"
  echo "  ████████╗███████╗███████╗████████╗██████╗ ███████╗███╗   ██╗ ██████╗██╗  ██╗"
  echo "  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝████╗  ██║██╔════╝██║  ██║"
  echo "     ██║   █████╗  ███████╗   ██║   ██████╔╝█████╗  ██╔██╗ ██║██║     ███████║"
  echo "     ██║   ██╔══╝  ╚════██║   ██║   ██╔══██╗██╔══╝  ██║╚██╗██║██║     ██╔══██║"
  echo "     ██║   ███████╗███████║   ██║   ██████╔╝███████╗██║ ╚████║╚██████╗██║  ██║"
  echo "     ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝"
  echo -e "${NC}"
  echo -e "${DIM}Testbench Automation Tool${NC}"
  echo -e "${DIM}──────────────────────────────────────────────────────────${NC}"
  echo
}

show_status() {
  local status=$1
  local message=$2
  
  case $status in
    "info") echo -e "${DIM}│  ${message}${NC}" ;;
    "success") echo -e "${GREEN}✔  ${message}${NC}" ;;
    "warning") echo -e "${YELLOW}⚠  ${message}${NC}" ;;
    "error") echo -e "${RED}✖  ${message}${NC}" ;;
    *) echo -e "${DIM}│  ${message}${NC}" ;;
  esac
}

select_testbench() {
  echo -e "${DIM}◇ Select a testbench: ${NC}" >&2
  local tb_file=$(find "$TB_DIR" -type f \( -name "*.sv" -o -name "*.v" \) | fzf --height=30% --prompt="Fuzzy Search: " --header="Use arrow keys to navigate, Enter to select")
  
  if [ -z "$tb_file" ]; then
    echo -e "${RED}✖  No testbench selected. Skip.${NC}" >&2
    exit 1
  fi
  
  echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$tb_file")${NC} ($tb_file)" >&2

  echo $(basename $tb_file)
}

select_vcd() {
  echo -e "${DIM}◇ Select a VCD file: ${TB_DIR}/obj_dir${NC}" >&2
  local vcd_file=$(find "$TB_DIR/obj_dir" -type f -name "*.vcd" | fzf --height=40% --prompt="Fuzzy Search: " --header="Use arrow keys to navigate, Enter to select")

  if [ -z "$vcd_file" ]; then
    exit 1
  fi

  echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$vcd_file")${NC} ($vcd_file)" >&2

  echo $(basename $vcd_file)
}

run_test() {
  show_header
  tb_file="$(select_testbench)"
  LOG_DIR="$TB_DIR/logs/${tb_file%.*}"
  mkdir -p "$LOG_DIR"

  show_status "info" "Compile with Verilator: $tb_file"
  cd "$TB_DIR" || exit
  verilator --quiet --cc --exe --build --binary --trace "$tb_file" -o "${tb_file%.*}" > "$LOG_DIR/tb.log" 2>&1
  show_status "success" "Compilation completed. Logs saved in $LOG_DIR"
  cd "$TB_DIR/obj_dir" || exit
  "./${tb_file%.*}" > "$LOG_DIR/simulation_run.log" 2>&1 

  show_status "info" "Using waveform viewer: gtkwave"
  vcd_file="$(select_vcd)"
  if [ -z "$vcd_file" ]; then
    show_status "error" "VCD not selected. Exiting."
    exit 1
  fi

  gtkwave "$vcd_file" > "$LOG_DIR/gtkwave.log" 2>&1
  show_status "success" "Testbench run completed. Logs saved in $LOG_DIR"
}

# Main execution
run_test
