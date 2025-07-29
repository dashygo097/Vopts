BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build
TESTBENCH_DIR = $(BASE_DIR)/testbench
TB_DIR = $(TESTBENCH_DIR)/tb
COCOTB_DIR = $(TESTBENCH_DIR)/cocotb

.PHONY: pre run build clean update debug tb cocotb

pre:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TESTBENCH_DIR)
	@mkdir -p $(TB_DIR)
	@mkdir -p $(COCOTB_DIR)

build: pre
	@sbt compile

run: pre
	@sbt app/run

clean:
	@rm -rf $(TB_DIR)/obj_dir
	@rm -rf $(COCOTB_DIR)/sim_build
	@rm -rf $(COCOTB_DIR)__pycache__
	@rm -rf $(COCOTB_DIR)results.xml
	@sbt clean bloopInstall
	@sbt clean

tb: pre
	@./tb.sh

cocotb: pre
	@echo "\033[1;32m[INFO] Select DUT (.v or .sv) file from build/...\033[0m"; \
	v_file=$$(find $(BUILD_DIR) -name "*.sv" -o -name "*.v" | fzf); \
	echo "\033[1;32m[INFO] Select testbench (*_tb.py or test_*.py)\033[0m"; \
	tb_file=$$(find $(COCOTB_DIR) -name "*_tb.py" -o -name "test_*.py" | fzf); \
	tb_mod=$$(basename $$tb_file .py); \
	top_mod=$$(basename $$v_file .sv); \
	cd $(COCOTB_DIR) && \
	make -f $(BASE_DIR)/cocotb.make \
		MODULE=$$tb_mod \
		TOPLEVEL=$$top_mod \
		SIM=icarus \
		VERILOG_SOURCES="$$v_file"

update:
	@sbt bloopInstall
	@sbt update
	@sbt reload
