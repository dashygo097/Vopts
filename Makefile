BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build
SCRIPTS_DIR = $(BASE_DIR)/scripts
TESTBENCH_DIR = $(BASE_DIR)/testbench
TB_DIR = $(TESTBENCH_DIR)/tb
COCOTB_DIR = $(TESTBENCH_DIR)/cocotb

.PHONY: pre run build update debug tb tb-fzf cocotb cocotb-fzf clean-tb clean-log clean-build stat stat-fzf

pre:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TESTBENCH_DIR)
	@mkdir -p $(TB_DIR)
	@mkdir -p $(COCOTB_DIR)

build: pre 
	@sbt compile

run: pre
	@sbt app/run

clean-log:
	@rm -rf $(TB_DIR)/obj_dir
	@rm -rf $(TB_DIR)/logs
	@rm -rf $(COCOTB_DIR)/logs
	@sbt clean bloopInstall
	@sbt clean

clean-build:
	@rm -rf $(BUILD_DIR)

tb: pre
	@bash $(SCRIPTS_DIR)/tb.sh

tb-fzf: pre
	@bash $(SCRIPTS_DIR)/tb_fzf.sh

cocotb: pre
	@touch $(COCOTB_DIR)/cocotb.make
	@echo "TOPLEVEL_LANG ?= verilog" > $(COCOTB_DIR)/cocotb.make
	@echo "SIM = icarus" >> $(COCOTB_DIR)/cocotb.make
	@echo "" >> $(COCOTB_DIR)/cocotb.make
	@echo "include $(shell cocotb-config --makefiles)/Makefile.sim" >> $(COCOTB_DIR)/cocotb.make

	@bash $(SCRIPTS_DIR)/cocotb.sh

cocotb-fzf: pre
	@touch $(COCOTB_DIR)/cocotb.make
	@echo "TOPLEVEL = $(TB_DIR)/tb.v" > $(COCOTB_DIR)/cocotb.make
	@echo "MODULE = tb" >> $(COCOTB_DIR)/cocotb.make
	@echo "" >> $(COCOTB_DIR)/cocotb.make
	@echo "include $(shell cocotb-config --makefiles)/Makefile.sim" >> $(COCOTB_DIR)/cocotb.make

	@bash $(SCRIPTS_DIR)/cocotb_fzf.sh

stat: pre
	@bash $(SCRIPTS_DIR)/stat_yosys_simple.sh	

stat-fzf: pre
	@bash $(SCRIPTS_DIR)/stat_yosys_simple_fzf.sh


update:
	@sbt bloopInstall
	@sbt update
	@sbt reload
