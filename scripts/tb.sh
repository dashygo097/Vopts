#!/bin/bash

BASE_DIR=$(dirname $(cd "$(dirname "$0")" && pwd))
TB_DIR=$BASE_DIR/sims/tb

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
SPACE='                                                             '

show_header() {
  echo -e "${BLUE}"
  echo "  ████████╗███████╗███████╗████████╗██████╗ ███████╗███╗   ██╗ ██████╗██╗  ██╗"
  echo "  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝████╗  ██║██╔════╝██║  ██║"
  echo "     ██║   █████╗  ███████╗   ██║   ██████╔╝█████╗  ██╔██╗ ██║██║     ███████║"
  echo "     ██║   ██╔══╝  ╚════██║   ██║   ██╔══██╗██╔══╝  ██║╚██╗██║██║     ██╔══██║"
  echo "     ██║   ███████╗███████║   ██║   ██████╔╝███████╗██║ ╚████║╚██████╗██║  ██║"
  echo "     ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝"
  echo -e "${NC}"
  echo -e "${DIM}                Testbench Automation Tool${NC}"
  echo -e "${DIM}──────────────────────────────────────────────────────────${NC}"
  echo
}

show_status() {
  local status=$1
  local message=$2
  
  case $status in
    "info") echo -e "${DIM}│  ${message}${NC}${SPACE}" ;;
    "success") echo -e "${DIM}${GREEN}✔  ${message}${NC}${SPACE}" ;;
    "warning") echo -e "${YELLOW}⚠  ${message}${NC}${SPACE}" ;;
    "error") echo -e "${RED}✖  ${message}${NC}${SPACE}" ;;
    *) echo -e "${DIM}│  ${message}${NC}${SPACE}" ;;
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
    echo -e "   ${GRAY}$((i+1)))${NC} $(basename "${tb_files[$i]}")" >&2
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
    echo -e "   ${GRAY}$((i+1)))${NC} $(basename "${vcd_files[$i]}")" >&2
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

select_wave_viewer() {
    local wave_viewer=""
    local options=("Surfer" "GTKWave" "Custom")
    local current_selection=0
    
    echo -e "${DIM}${BLUE}◇ Select WaveViewer ${NC}" >&2
    echo -e "│${DIM} Use arrow keys to navigate, Enter to confirm${NC}" >&2
    
    local menu_lines=0
    
    display_menu() {
        for i in "${!options[@]}"; do
            if [ $i -eq "$current_selection" ]; then
                echo -e "│ ${BOLD}${GREEN}❯ ${options[i]}${NC}${SPACE}" >&2
            else
                echo -e "│ ${DIM}${GRAY}${options[i]}${NC}${SPACE}" >&2
            fi
        done
        menu_lines="${#options[@]}"
    }
    
    display_menu
    
    echo -ne "\033[s" >&2
    
    while true; do
        read -rsn1 key
        
        if [ "$key" = $'\x1b' ]; then
            read -rsn1 -t 1 key2
            if [ "$key2" = '[' ]; then
                read -rsn1 key3
                case "$key3" in
                    'A')
                        if [ "$current_selection" -gt 0 ]; then
                            current_selection="$((current_selection - 1))"
                            echo -ne "\033[u" >&2
                            echo -ne "\033[${menu_lines}A\033[J" >&2
                            display_menu
                        fi
                        ;;
                    'B') 
                        if [ "$current_selection" -lt "$((${#options[@]} - 1))" ]; then
                            current_selection="$((current_selection + 1))"
                            echo -ne "\033[u" >&2
                            echo -ne "\033[${menu_lines}A\033[J" >&2
                            display_menu
                        fi
                        ;;
                esac
            fi
        elif [ "$key" = "" ]; then
            break
        fi
    done
    
    echo -ne "\033[u\033[J" >&2 
    
    case "${options[current_selection]}" in
        "None") 
            wave_viewer=""
            ;;
        "Custom")
            echo -n "Please enter a custom wave viewer command: " >&2
            read custom_bt
            wave_viewer="${custom_bt}"
            echo -ne "\033[A\033[2K" >&2
            ;;
        *)
            wave_viewer="${options[current_selection]}"
            ;;
    esac
    
    echo -e "${DIM}${BLUE}◆ Wave Viewer Selected!${NC}${SPACE}" >&2
    display_menu
    echo -e "\033[3A\033[3K${GREEN}✔ Wave Viewer: ${NC}${BOLD}$wave_viewer${NC}" >&2
    
    echo "$wave_viewer"
}

run_test() {
  show_header
  tb_file="$(select_testbench)"
  LOG_DIR="$BASE_DIR/sims/logs/${tb_file%.*}"
  mkdir -p "$LOG_DIR"

  show_status "info" "Compile with Verilator: $tb_file"
  cd "$TB_DIR" || exit
  verilator --quiet --cc --exe --build --binary --trace "$tb_file" -o "${tb_file%.*}" > "$LOG_DIR/tb.log" 2>&1
  show_status "success" "Compilation completed. Logs saved in $LOG_DIR"
  cd "$TB_DIR/obj_dir" || exit
  "./${tb_file%.*}" > "$LOG_DIR/simulation_run.log" 2>&1 

  show_status "info" "Select VCD file to view:"
  vcd_file="$(select_vcd)"

  wave_viewer="$(select_wave_viewer)"
  eval "$wave_viewer $vcd_file" > "$LOG_DIR/${wave_viewer}.log" 2>&1
  echo -n " "

  show_status "success" "Testbench run completed. Logs saved in $LOG_DIR"
}

# Main execution
run_test
