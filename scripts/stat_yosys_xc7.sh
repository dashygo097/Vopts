#!/bin/bash

BASE_DIR=$(dirname $(cd "$(dirname "$0")" && pwd))
BUILD_DIR=$BASE_DIR/build
SYNTH_DIR=$BASE_DIR/synth

# Colors
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
    echo " ███████╗████████╗ █████╗ ████████╗"
    echo " ██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝"
    echo " ███████╗   ██║   ███████║   ██║   "
    echo " ╚════██║   ██║   ██╔══██║   ██║   "
    echo " ███████║   ██║   ██║  ██║   ██║   "
    echo " ╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   "
    echo -e "${NC}"
    echo -e "${DIM}Synthesis & Timing Analysis Tool${NC}"
    echo -e "${DIM}──────────────────────────────────────────────────────────${NC}"
    echo
}

show_status() {
    local status=$1
    local message=$2
    case $status in
        "info")    echo -e "${DIM}│ ${message}${NC}" >&2;;
        "success") echo -e "${GREEN}✔ ${message}${NC}" >&2;;
        "warning") echo -e "${YELLOW}│ ${message}${NC}" >&2;;
        "error")   echo -e "${RED}✖ ${message}${NC}" >&2;;
        *)         echo -e "${DIM}│ ${message}${NC}" >&2;;
    esac
}

select_module() {
    echo -e "${DIM}◇ Available modules:${NC}" >&2
    local module_files=()
    while IFS= read -r -d $'\0' file; do
        module_files+=("$file")
    done < <(find "$BUILD_DIR" -type f \( -name "*.sv" -o -name "*.v" \) -print0)

    if [ ${#module_files[@]} -eq 0 ]; then
        echo -e "${RED}✖ No module files found.${NC}" >&2
        exit 1
    fi

    for i in "${!module_files[@]}"; do
        echo -e "  ${GRAY}$((i+1)))${NC} $(basename "${module_files[$i]}")" >&2
    done

    local selected
    while true; do
        echo -ne "${YELLOW}? Select a module (1-${#module_files[@]}): ${NC}" >&2
        read -r selected
        if [[ "$selected" =~ ^[0-9]+$ ]] && \
           [ "$selected" -ge 1 ] && \
           [ "$selected" -le ${#module_files[@]} ]; then
            break
        elif [[ "$selected" = "q" || "$selected" = "Q" ]]; then
            echo -e "${RED}✖ Exiting.${NC}" >&2
            exit 0
        else
            echo -e "${RED}Invalid selection. Please enter a number between 1 and ${#module_files[@]}.${NC}" >&2
        fi
    done

    local module_file="${module_files[$((selected-1))]}"
    echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$module_file")${NC}" >&2
    echo "$(basename "$module_file")"
}

fetch_top_module() {
    local flag=0
    echo -ne "${DIM}│ Enter the top module name: ${NC}" >&2
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

fetch_clock_period() {
    local default_period=10
    echo -ne "${DIM}│ Enter clock period in ns (default: ${default_period}ns = 100MHz): ${NC}" >&2
    read -r clock_period
    if [[ -z "$clock_period" ]]; then
        clock_period=$default_period
    fi
    show_status "success" "Clock period set to: ${clock_period}ns"
    echo "$clock_period"
}

run_stat() {
    show_header
    
    module_file="$(select_module)"
    top_module="$(fetch_top_module)"
    clock_period="$(fetch_clock_period)"
    
    mkdir -p "$SYNTH_DIR/${top_module}"
    cd "$SYNTH_DIR/${top_module}" || exit 1
    
    show_status "info" "Generating optimized synthesis script..."
    
    local clock_period_ps=$((clock_period * 1000))
    
    cat > "synth_stat.ys" << EOF
# Read design
read_verilog -sv $BUILD_DIR/${module_file}

# Hierarchy check
hierarchy -check -top ${top_module}

# High-level synthesis optimizations
proc; opt; fsm; opt; memory; opt

# Technology mapping for Xilinx 7-series
synth_xilinx -family xc7 -top ${top_module} -flatten -abc9 -nobram -nodsp

# Apply timing constraints
# Clock period: ${clock_period}ns = ${clock_period_ps}ps
select -module ${top_module}
setattr -set sta_clock_period ${clock_period_ps} w:clock
select -clear

# Static Timing Analysis (single run to avoid "No timing paths" warning)
tee -o timing_report.txt sta

# Generate statistics
stat
stat -tech xilinx
stat -width

# Clean up before writing outputs
clean
opt_clean

# Write output files
write_verilog -noattr synth_${top_module}.v

# Print final stats
stat
EOF

    show_status "info" "Running Yosys synthesis and timing analysis..."
    
    if yosys -s "synth_stat.ys" > "synthesis.log" 2>&1; then
        show_status "success" "Synthesis completed successfully"
    else
        show_status "error" "Synthesis failed - check synthesis.log"
        exit 1
    fi
    
    echo
    echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
    echo -e "${CYAN}         TIMING ANALYSIS RESULTS${NC}"
    echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
    
    if [ -f timing_report.txt ]; then
        local max_delay=$(grep "Latest arrival time in" timing_report.txt | sed -n "s/.*is \([0-9]*\):.*/\1/p" | head -1)
        
        if [ ! -z "$max_delay" ] && [ "$max_delay" -gt "0" ] 2>/dev/null; then
            local fmax_mhz=$(awk "BEGIN {printf \"%.2f\", 1000000 / $max_delay}")
            local target_mhz=$(awk "BEGIN {printf \"%.2f\", 1000 / $clock_period}")
            local period_ns=$(awk "BEGIN {printf \"%.3f\", $max_delay / 1000}")
            
            echo -e "${YELLOW}Critical Path Delay:${NC}   ${max_delay} ps (${period_ns} ns)"
            echo -e "${YELLOW}Achievable Fmax:${NC}      ${fmax_mhz} MHz"
            echo -e "${YELLOW}Target Frequency:${NC}     ${target_mhz} MHz (${clock_period}ns period)"
            echo
            
            if (( $(echo "$fmax_mhz >= $target_mhz" | bc -l) )); then
                local slack=$(awk "BEGIN {printf \"%.1f\", ($fmax_mhz - $target_mhz) / $target_mhz * 100}")
                echo -e "${GREEN}✔ Timing constraints MET (${slack}% margin)${NC}"
            else
                local deficit=$(awk "BEGIN {printf \"%.1f\", ($target_mhz - $fmax_mhz) / $target_mhz * 100}")
                echo -e "${RED}✖ Timing constraints VIOLATED (${deficit}% deficit)${NC}"
            fi
            echo
            
            echo -e "${YELLOW}Critical Path Breakdown:${NC}"
            grep -A 10 "Latest arrival time in" timing_report.txt | tail -10
        else
            echo -e "${RED}Could not parse timing data${NC}"
            echo -e "${YELLOW}Debug: max_delay='$max_delay'${NC}"
            echo -e "${YELLOW}First few lines of timing_report.txt:${NC}"
            head -3 timing_report.txt
        fi
    else
        echo -e "${RED}Timing report not generated${NC}"
    fi
    
    echo
    echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
    echo -e "${CYAN}         RESOURCE UTILIZATION${NC}"
    echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
    
    # Extract resource stats from last stat output
    echo -e "${YELLOW}Flip-Flops:${NC}"
    grep "FDRE" synthesis.log | tail -1 | awk '{printf "  %-20s %d\n", "FDRE (D Flip-Flops):", $2}'
    grep "FDSE" synthesis.log | tail -1 | awk '{if($2>0) printf "  %-20s %d\n", "FDSE (Set FF):", $2}'
    grep "FDCE" synthesis.log | tail -1 | awk '{if($2>0) printf "  %-20s %d\n", "FDCE (Clock Enable):", $2}'
    
    echo
    echo -e "${YELLOW}Logic:${NC}"
    local total_luts=0
    for i in {2..6}; do
        local count=$(grep "LUT$i" synthesis.log | grep -v "LUTRAM" | tail -1 | awk '{print $2}')
        if [ ! -z "$count" ] && [ "$count" != "0" ]; then
            printf "  %-20s %d\n" "LUT$i:" "$count"
            total_luts=$((total_luts + count))
        fi
    done
    echo -e "  ${CYAN}────────────────────────${NC}"
    printf "  %-20s %d\n" "Total LUTs:" "$total_luts"
    
    echo
    echo -e "${YELLOW}Routing:${NC}"
    grep "MUXF7" synthesis.log | tail -1 | awk '{if($2>0) printf "  %-20s %d\n", "MUXF7:", $2}'
    grep "MUXF8" synthesis.log | tail -1 | awk '{if($2>0) printf "  %-20s %d\n", "MUXF8:", $2}'
    grep "BUFG" synthesis.log | tail -1 | awk '{printf "  %-20s %d\n", "BUFG (Clock):", $2}'
    
    local estimated_lc=$(grep "Estimated number of LCs" synthesis.log | tail -1 | awk '{print $6}')
    if [ ! -z "$estimated_lc" ]; then
        echo
        echo -e "${YELLOW}Estimated Logic Cells:${NC} $estimated_lc"
    fi
    
    echo
    echo -e "${GREEN}Files generated:${NC}"
    echo -e "  ${DIM}├─${NC} synthesis.log            (Full synthesis log)"
    echo -e "  ${DIM}├─${NC} timing_report.txt        (Timing analysis)"
    echo -e "  ${DIM}├─${NC} synth_${top_module}.v       (Synthesized netlist)"
    echo -e "  ${DIM}└─${NC} synth_stat.ys            (Yosys script)"
    echo
    
    if [ -f timing_report.txt ]; then
        local max_delay=$(grep "Latest arrival time in" timing_report.txt | sed -n "s/.*is \([0-9]*\):.*/\1/p" | head -1)
        if [ ! -z "$max_delay" ] && [ "$max_delay" -gt "0" ] 2>/dev/null; then
            local fmax_mhz=$(awk "BEGIN {printf \"%.2f\", 1000000 / $max_delay}")
            local target_mhz=$(awk "BEGIN {printf \"%.2f\", 1000 / $clock_period}")
            
            echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
            echo -e "${CYAN}         FREQUENCY TARGETS${NC}"
            echo -e "${CYAN}═══════════════════════════════════════════════════${NC}"
            
            for target in 50 100 125 150 200 250 300 400 500 750 1000; do
                if (( $(echo "$fmax_mhz >= $target" | bc -l) )); then
                    local margin=$(awk "BEGIN {printf \"%.1f\", ($fmax_mhz - $target) / $target * 100}")
                    echo -e "  ${GREEN}✓${NC} ${target} MHz (${margin}% timing margin)"
                else
                    local deficit=$(awk "BEGIN {printf \"%.1f\", ($target - $fmax_mhz) / $target * 100}")
                    echo -e "  ${RED}✗${NC} ${target} MHz (${deficit}% too fast)"
                fi
            done
            echo
        fi
    fi
    
    show_status "success" "All outputs saved in: $SYNTH_DIR/${top_module}/"
}

# Main execution
run_stat
