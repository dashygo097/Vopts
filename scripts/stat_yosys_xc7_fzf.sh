#!/bin/bash

BASE_DIR=$(dirname $(cd "$(dirname "$0")" && pwd))
BUILD_DIR=$BASE_DIR/build
SYNTH_DIR=$BASE_DIR/synt
show_header() {
  echo -e "${BLUE}"
  echo "            ███████╗████████╗ █████╗ ████████╗"
  echo "            ██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝"
  echo "            ███████╗   ██║   ███████║   ██║   "
  echo "            ╚════██║   ██║   ██╔══██║   ██║   "
  echo "            ███████║   ██║   ██║  ██║   ██║   "
  echo "            ╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   "
  echo -e "${NC}"
  echo -e "${DIM}Stat Automation Tool${NC}"
  echo -e "${DIM}──────────────────────────────────────────────────────────${NC}"
  echo
}

show_status() {
  local status=$1
  local message=$2
  
  case $status in
    "info") echo -e "${DIM}│  ${message}${NC}" >&2;;
    "success") echo -e "${GREEN}✔  ${message}${NC}" >&2;;
    "warning") echo -e "${YELLOW}│  ${message}${NC}" >&2;;
    "error") echo -e "${RED}✖  ${message}${NC}" >&2;;
    *) echo -e "${DIM}│  ${message}${NC}" >&2;;
  esac
}

select_module() {
  echo -e "${DIM}◇ Select a module: ${NC}" >&2
  local module_file=$(find "$BUILD_DIR" -type f \( -name "*.v" -o -name "*.sv" \) | sed "s|^$BUILD_DIR/||" | fzf --height=30% --prompt="Fuzzy Search: " --header="Use arrow keys to navigate, Enter to select")
  
  if [ -z "$module_file" ]; then
    echo -e "${RED}✖  No testbench selected. Skip.${NC}" >&2
    exit 1
  fi
  
  echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$module_file")${NC} ($module_file)" >&2

  echo $(basename $module_file)
}

fetch_top_module() {
  local flag=0 
  echo -ne "${DIM}│  Enter the top module name: ${NC}" >&2

  read -r top_module
  while [[ -z "$top_module" ]]; do
    echo -ne "\033[1A\033[2K" >&2
    show_status "warning" "Top module name cannot be empty!"
    read -r top_module
    flag=1
  done

  if [[ $flag -eq 1 ]]; then
    echo -ne "\033[1A\033[2K" >&2
  fi
  show_status "success" "Top module name set to: $top_module"

  echo "$top_module"
}

run_stat() {
  show_header
  module_file="$(select_module)"
  top_module="$(fetch_top_module)"
  mkdir -p "$SYNTH_DIR/${top_module%.*}"

  cd "$SYNTH_DIR/${top_module%.*}" || exit 1
  show_status "info" "Generating .ys file: $module_file..."
  cat > "synth_stat.ys" << EOF

read_verilog -sv $BUILD_DIR/${module_file}
hierarchy -check -top ${top_module}

synth_xilinx -family xc7 -top ${top_module}
sta

write_verilog $SYNTH_DIR/${top_module%.*}/synth_${top_module}.v

EOF
  show_status "info" "Running Yosys synthesis and stat..."
  yosys -s "synth_stat.ys" > "$SYNTH_DIR/${top_module%.*}/stat.log" 2>&1
  show_status "success" "Stat run completed. Logs saved in $LOG_DIR"
}

# Main execution
run_stat
