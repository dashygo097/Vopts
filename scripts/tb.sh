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
  echo -e "${DIM}◇ Available testbenches:${NC}" >&2
  
  local tb_files=()
  while IFS= read -r -d $'\0' file; do
    tb_files+=("$file")
  done < <(find "$TB_DIR" -type f \( -name "*.sv" -o -name "*.v" \) -print0)
  
  if [ ${#tb_files[@]} -eq 0 ]; then
    echo -e "${RED}✖ No testbench files found.${NC}" >&2
    exit 1
  fi
  
  for i in "${!tb_files[@]}"; do
    echo -e "  ${GRAY}$((i+1)))${NC} $(basename "${tb_files[$i]}")" >&2
  done
  
  local selected
  while true; do
    echo -ne "${YELLOW}? Select testbench (1-${#tb_files[@]}): ${NC}" >&2
    read -r selected
    
    if [[ "$selected" =~ ^[0-9]+$ ]] && \
       [ "$selected" -ge 1 ] && \
       [ "$selected" -le ${#tb_files[@]} ]; then
      break
    elif [[ "$selected" = "q" || "$selected" = "Q" ]]; then
      echo -e "${RED}✖  Exiting.${NC}" >&2
      exit 0
    else
      echo -e "${RED}Invalid selection. Please enter a number between 1 and ${#tb_files[@]}.${NC}" >&2
    fi
  done
  
  local tb_file="${tb_files[$((selected-1))]}"
  echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$tb_file")${NC} ($tb_file)" >&2
  
  echo "$(basename "$tb_file")"
}

select_vcd() {
  echo -e "${DIM}◇ Available VCD files in ${TB_DIR}/obj_dir:${NC}" >&2
  
  local vcd_files=()
  while IFS= read -r -d $'\0' file; do
    vcd_files+=("$file")
  done < <(find "$TB_DIR/obj_dir" -type f -name "*.vcd" -print0)
  
  if [ ${#vcd_files[@]} -eq 0 ]; then
    echo -e "${RED}✖ No VCD files found in ${TB_DIR}/obj_dir.${NC}" >&2
    exit 1
  fi
  
  for i in "${!vcd_files[@]}"; do
    echo -e "  ${GRAY}$((i+1)))${NC} $(basename "${vcd_files[$i]}")" >&2
  done
  
  local selected
  while true; do
    echo -ne "${YELLOW}? Select VCD file (1-${#vcd_files[@]}): ${NC}" >&2
    read -r selected
    
    if [[ "$selected" =~ ^[0-9]+$ ]] && \
       [ "$selected" -ge 1 ] && \
       [ "$selected" -le ${#vcd_files[@]} ]; then
      break
    else
      echo -e "${RED}Invalid selection. Please enter a number between 1 and ${#vcd_files[@]}.${NC}" >&2
    fi
  done
  
  local vcd_file="${vcd_files[$((selected-1))]}"
  echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$vcd_file")${NC} ($vcd_file)" >&2
  
  echo "$(basename "$vcd_file")"
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
  "./${tb_file%.*}" 2>&1
  "./${tb_file%.*}" > "$LOG_DIR/simulation_run.log" 2>&1 

  show_status "info" "Using waveform viewer: gtkwave"

  gtkwave "$(select_vcd)" > "$LOG_DIR/gtkwave.log" 2>&1
  show_status "success" "Testbench run completed. Logs saved in $LOG_DIR"
}

# Main execution
run_test
