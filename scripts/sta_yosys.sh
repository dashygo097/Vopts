#!/bin/bash

BASE_DIR=$(dirname $(cd "$(dirname "$0")" && pwd))
BUILD_DIR=$BASE_DIR/build
SYNTH_DIR=$BASE_DIR/synth

# Colors
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
GRAY='\033[1;37m'
NC='\033[0m'
BOLD='\033[1m'
DIM='\033[2m'

show_header() {
    echo -e "${BLUE}"
    echo " ██╗   ██╗██╗██╗   ██╗ █████╗ ██████╗  ██████╗ "
    echo " ██║   ██║██║██║   ██║██╔══██╗██╔══██╗██╔═══██╗"
    echo " ██║   ██║██║██║   ██║███████║██║  ██║██║   ██║"
    echo " ╚██╗ ██╔╝██║╚██╗ ██╔╝██╔══██║██║  ██║██║   ██║"
    echo "  ╚████╔╝ ██║ ╚████╔╝ ██║  ██║██████╔╝╚██████╔╝"
    echo "   ╚═══╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚═════╝  ╚═════╝ "
    echo -e "${NC}"
    echo -e "${DIM}Vivado Static Timing Analysis Tool${NC}"
    echo -e "${DIM}────────────────────────────────────────────────${NC}"
    echo
}

show_status() {
    local status=$1
    local message=$2
    case $status in
        "info")    echo -e "${DIM}│ ${message}${NC}" >&2;;
        "success") echo -e "${GREEN}✔ ${message}${NC}" >&2;;
        "warning") echo -e "${YELLOW}⚠ ${message}${NC}" >&2;;
        "error")   echo -e "${RED}✖ ${message}${NC}" >&2;;
        *)         echo -e "${DIM}│ ${message}${NC}" >&2;;
    esac
}

select_module() {
    if [[ "$FZF" == "true" ]]; then
        echo -e "${DIM}◇ Select a module:${NC}" >&2
        
        local module_file=$(find "$BUILD_DIR" -type f \( -name "*.v" -o -name "*.sv" \) | sed "s|^$BUILD_DIR/||" | fzf --height=40% --prompt="Fuzzy Search: " --header="Use arrow keys to navigate, Enter to select")
        
        if [ -z "$module_file" ]; then
            echo -e "${RED}✖ No module selected. Exiting.${NC}" >&2
            exit 1
        fi
        
        echo -e "\033[1A\033[2K${GREEN}◆ Selected: $(basename "$module_file")${NC}" >&2
        echo "$module_file"
    else
        echo -e "${DIM}◇ Available modules:${NC}" >&2
        local module_files=()
        while IFS= read -r -d $'\0' file; do
            local rel_path="${file#$BUILD_DIR/}"
            module_files+=("$rel_path")
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
        echo "$module_file"
    fi
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

fetch_clock_port() {
    local default_port="clk"
    echo -ne "${DIM}│ Enter clock port name (default: ${default_port}): ${NC}" >&2
    read -r clock_port
    if [[ -z "$clock_port" ]]; then
        clock_port=$default_port
    fi
    show_status "success" "Clock port set to: ${clock_port}"
    echo "$clock_port"
}

fetch_fpga_part() {
    local default_part="xc7a100tcsg324-1"
    echo -ne "${DIM}│ Enter FPGA part (default: ${default_part}): ${NC}" >&2
    read -r fpga_part
    if [[ -z "$fpga_part" ]]; then
        fpga_part=$default_part
    fi
    show_status "success" "FPGA part set to: ${fpga_part}"
    echo "$fpga_part"
}

run_sta() {
    show_header
    
    module_file="$(select_module)"
    top_module="$(fetch_top_module)"
    clock_period="$(fetch_clock_period)"
    clock_port="$(fetch_clock_port)"
    fpga_part="$(fetch_fpga_part)"
    
    target_freq=$(awk "BEGIN {printf \"%.2f\", 1000.0 / $clock_period}")
    
    mkdir -p "$SYNTH_DIR/vivado_${top_module}"
    cd "$SYNTH_DIR/vivado_${top_module}" || exit 1
    
    relative_design_file="../../build/${module_file}"
    
    show_status "info" "Generating Vivado TCL script..."
    show_status "info" "Design file (relative): $relative_design_file"
    
    cat > "sta_vivado.tcl" << 'EOF'
# Vivado Static Timing Analysis Script (Auto-generated)
# Configuration
set design_file "DESIGN_FILE_PLACEHOLDER"
set top_module "TOP_MODULE_PLACEHOLDER"
set fpga_part "FPGA_PART_PLACEHOLDER"
set clock_period_ns CLOCK_PERIOD_PLACEHOLDER
set clock_port "CLOCK_PORT_PLACEHOLDER"

# Directories
set output_dir "./reports"
set project_dir "./project"

# Helper Procedures
proc log_info {msg} {
    puts "\[INFO\] $msg"
}

proc log_success {msg} {
    puts "\[SUCCESS\] $msg"
}

proc log_error {msg} {
    puts "\[ERROR\] $msg"
}

proc log_section {title} {
    puts ""
    puts "========================================="
    puts "  $title"
    puts "========================================="
}

# Main Flow
log_section "Vivado Synthesis + Timing Analysis"

# Create output directory
file mkdir $output_dir
log_success "Created output directory: $output_dir"

set target_freq_mhz [expr {1000.0 / $clock_period_ns}]
log_info "Design File: $design_file"
log_info "Top Module: $top_module"
log_info "FPGA Part: $fpga_part"
log_info "Target Clock: ${clock_period_ns}ns ([format "%.2f" $target_freq_mhz] MHz)"
log_info "Clock Port: $clock_port"

# Step 1: Create Project
log_section "Step 1: Project Setup"

if {[file exists $project_dir]} {
    file delete -force $project_dir
}

create_project -force sta_project $project_dir -part $fpga_part
log_success "Created project"

# Add design files
if {[file exists $design_file]} {
    add_files $design_file
    set_property top $top_module [current_fileset]
    log_success "Added design file and set top module"
} else {
    log_error "Design file not found: $design_file"
    log_error "Current working directory: [pwd]"
    exit 1
}

# Step 2: Read RTL (without constraints yet)
log_section "Step 2: Read Design"

# Read the RTL to prepare for constraint creation
read_verilog $design_file
log_success "Read design files"

# Step 3: Create Timing Constraints
log_section "Step 3: Timing Constraints"

# Create XDC file with proper escaping for TCL
set xdc_file "$project_dir/timing_constraints.xdc"
set fp [open $xdc_file w]
puts $fp "# Auto-generated timing constraints"
puts $fp "# Clock constraint"
puts $fp "create_clock -period $clock_period_ns -name sys_clk \[get_ports $clock_port\]"
puts $fp ""
puts $fp "# Relax I/O timing for internal path analysis"
puts $fp "set_input_delay -clock sys_clk 0 \[all_inputs\]"
puts $fp "set_output_delay -clock sys_clk 0 \[all_outputs\]"
close $fp

read_xdc $xdc_file
log_success "Created and loaded timing constraints"

# Step 4: Run Synthesis
log_section "Step 4: Synthesis"

log_info "Running synthesis (this may take a few minutes)..."

synth_design \
    -top $top_module \
    -part $fpga_part \
    -mode out_of_context \
    -flatten_hierarchy rebuilt \
    -keep_equivalent_registers \
    -resource_sharing off \
    -no_lc \
    -shreg_min_size 5

log_success "Synthesis completed"

# Step 5: Generate Timing Reports
log_section "Step 5: Post-Synthesis Timing Analysis"

# Report clock networks
log_info "Analyzing clock networks..."
report_clocks -file "$output_dir/clocks.rpt"

# Check timing constraints
log_info "Checking timing constraints..."
check_timing -verbose -file "$output_dir/check_timing.rpt"

# Timing summary report
log_info "Generating timing summary..."
report_timing_summary \
    -delay_type max \
    -report_unconstrained \
    -check_timing_verbose \
    -max_paths 10 \
    -input_pins \
    -routable_nets \
    -file "$output_dir/timing_summary.rpt"

# Detailed timing report
log_info "Analyzing critical paths..."
report_timing \
    -delay_type max \
    -max_paths 20 \
    -sort_by slack \
    -input_pins \
    -routable_nets \
    -name timing_1 \
    -file "$output_dir/timing_detail.rpt"

# Design analysis
log_info "Generating design analysis..."
report_design_analysis \
    -timing \
    -max_paths 10 \
    -file "$output_dir/design_analysis.rpt"

# Utilization report
log_info "Generating utilization report..."
report_utilization \
    -hierarchical \
    -file "$output_dir/utilization.rpt"

# Step 6: Parse and Display Results
log_section "Step 6: Timing Results Summary"

set timing_file "$output_dir/timing_summary.rpt"
if {[file exists $timing_file]} {
    set fp [open $timing_file r]
    set content [read $fp]
    close $fp
    
    # Extract key metrics
    set wns "N/A"
    set tns "N/A"
    set whs "N/A"
    set failing_endpoints 0
    set total_endpoints 0
    
    # Parse WNS (Worst Negative Slack)
    if {[regexp {WNS\(ns\)\s+WHS\(ns\)\s+TNS\(ns\)\s+THS\(ns\)\s+WPWS\(ns\)\s+TPWS\(ns\)\s+[-]+\s+([-\d.]+)\s+([-\d.]+)\s+([-\d.]+)} $content match wns_val whs_val tns_val]} {
        set wns $wns_val
        set whs $whs_val
        set tns $tns_val
    }
    
    # Parse endpoint counts
    if {[regexp {(\d+)\s+Failing Endpoints} $content match count]} {
        set failing_endpoints $count
    }
    if {[regexp {(\d+)\s+Total Endpoints} $content match count]} {
        set total_endpoints $count
    }
    
    # Display results
    puts ""
    puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    puts "  TIMING ANALYSIS RESULTS"
    puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    puts "  Target Clock Period:  ${clock_period_ns} ns"
    puts "  Target Frequency:     [format "%.2f" $target_freq_mhz] MHz"
    puts ""
    puts "  Setup Timing (Max Delay):"
    puts "    WNS (Worst Slack):  $wns ns"
    puts "    TNS (Total Slack):  $tns ns"
    puts ""
    puts "  Hold Timing (Min Delay):"
    puts "    WHS (Worst Slack):  $whs ns"
    puts ""
    puts "  Endpoints:"
    puts "    Total:              $total_endpoints"
    puts "    Failing:            $failing_endpoints"
    puts ""
    
    # Calculate achievable frequency
    if {$wns != "N/A" && [string is double $wns]} {
        set actual_period [expr {$clock_period_ns - $wns}]
        set achievable_freq [expr {1000.0 / $actual_period}]
        
        puts "  Achievable Frequency: [format "%.2f" $achievable_freq] MHz"
        puts "  Critical Path Delay:  [format "%.3f" $actual_period] ns"
        puts ""
        
        # Timing status
        if {$wns >= 0} {
            set margin_pct [expr {100.0 * $wns / $clock_period_ns}]
            log_success "TIMING MET with [format "%.1f" $margin_pct]% slack"
        } else {
            set violation_pct [expr {100.0 * abs($wns) / $clock_period_ns}]
            log_error "TIMING VIOLATED by [format "%.1f" $violation_pct]%"
            puts ""
            puts "  Recommendations:"
            puts "    • Review critical paths in timing_detail.rpt"
            puts "    • Consider pipeline insertion"
            puts "    • Reduce target frequency"
            puts "    • Apply synthesis optimizations"
        }
        
        # Frequency targets check
        puts ""
        puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        puts "  FREQUENCY TARGET ANALYSIS"
        puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        
        foreach freq {50 100 125 150 200 250 300} {
            if {$achievable_freq >= $freq} {
                set margin [expr {100.0 * ($achievable_freq - $freq) / $freq}]
                puts "  ✓ ${freq} MHz - PASS ([format "%.1f" $margin]% margin)"
            } else {
                set deficit [expr {100.0 * ($freq - $achievable_freq) / $freq}]
                puts "  ✗ ${freq} MHz - FAIL ([format "%.1f" $deficit]% deficit)"
            }
        }
    }
    puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
} else {
    log_error "Could not find timing summary report"
}

# Step 7: Critical Path Details
log_section "Step 7: Critical Path Analysis"

set worst_path [get_timing_paths -max_paths 1 -setup]
if {[llength $worst_path] > 0} {
    log_info "Critical path details:"
    
    report_timing \
        -of_objects $worst_path \
        -input_pins \
        -routable_nets \
        -significant_digits 3 \
        -file "$output_dir/critical_path_detailed.rpt"
    
    set startpoint [get_property STARTPOINT_PIN $worst_path]
    set endpoint [get_property ENDPOINT_PIN $worst_path]
    set slack [get_property SLACK $worst_path]
    
    puts "  Start Point: $startpoint"
    puts "  End Point:   $endpoint"
    puts "  Slack:       [format "%.3f" $slack] ns"
    
    log_success "Detailed critical path analysis saved"
} else {
    log_info "No timing paths found"
}

# Step 8: Resource Utilization Summary
log_section "Step 8: Resource Utilization"

puts ""
puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
puts "  RESOURCE UTILIZATION"
puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# Parse utilization from report
set util_file "$output_dir/utilization.rpt"
if {[file exists $util_file]} {
    set fp [open $util_file r]
    set content [read $fp]
    close $fp
    
    # Extract key resources
    if {[regexp {Slice LUTs\s+\|\s+(\d+)} $content match luts]} {
        puts "  LUTs:                 $luts"
    }
    if {[regexp {Slice Registers\s+\|\s+(\d+)} $content match regs]} {
        puts "  Registers:            $regs"
    }
    if {[regexp {Block RAM Tile\s+\|\s+(\d+)} $content match bram]} {
        puts "  BRAM Tiles:           $bram"
    }
    if {[regexp {DSPs\s+\|\s+(\d+)} $content match dsp]} {
        puts "  DSP Blocks:           $dsp"
    }
}
puts "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# Summary
log_section "Analysis Complete"

puts ""
puts "Reports generated in: $output_dir/"
puts ""
puts "Key Files:"
puts "  • timing_summary.rpt         - Overall timing summary"
puts "  • timing_detail.rpt          - Top 20 critical paths"
puts "  • critical_path_detailed.rpt - Detailed critical path"
puts "  • design_analysis.rpt        - Design analysis"
puts "  • utilization.rpt            - Resource utilization"
puts "  • check_timing.rpt           - Constraint validation"
puts "  • clocks.rpt                 - Clock network analysis"
puts ""

log_success "Vivado STA analysis complete!"

exit 0
EOF

    sed -i "s|DESIGN_FILE_PLACEHOLDER|$relative_design_file|g" sta_vivado.tcl
    sed -i "s|TOP_MODULE_PLACEHOLDER|$top_module|g" sta_vivado.tcl
    sed -i "s|FPGA_PART_PLACEHOLDER|$fpga_part|g" sta_vivado.tcl
    sed -i "s|CLOCK_PERIOD_PLACEHOLDER|$clock_period|g" sta_vivado.tcl
    sed -i "s|CLOCK_PORT_PLACEHOLDER|$clock_port|g" sta_vivado.tcl

    show_status "success" "TCL script generated: sta_vivado.tcl"
    echo
    show_status "info" "Running Vivado in batch mode..."
    echo
    
    echo
    echo -e "${GREEN}◆ Files Generated${NC}"
    echo -e "${DIM}├─${NC} sta_vivado.tcl           (TCL script)"
    echo -e "${DIM}├─${NC} vivado_run.log           (Vivado output log)"
    echo -e "${DIM}└─${NC} reports/                 (All analysis reports)"
    echo
    
    show_status "success" "All outputs saved in: $SYNTH_DIR/vivado_${top_module}/"
    
    echo ""
    echo "╔════════════════════════════════════════════════════════════════════╗"
    echo "║ NOTE: Vivado Post-Synthesis Timing Results                         ║"
    echo "║                                                                    ║"
    echo "║ For final timing closure, run full Place & Route in Vivado!        ║"
    echo "╚════════════════════════════════════════════════════════════════════╝"
    echo ""

    echo "Run the following command to start Vivado manually:"
    echo -e "${CYAN}vivado -mode batch -source sta_vivado.tcl${NC}"
}

# Main execution
run_sta
