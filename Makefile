BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build
TESTBENCH_DIR = $(BASE_DIR)/testbench


.PHONY: pre run build clean test-build update debug tb

pre:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TESTBENCH_DIR)

build: pre update
	@sbt compile

run: pre
	@sbt app/run

test-build: pre
	@sbt tests/run

clean:
	@rm -rf $(TESTBENCH_DIR)/obj_dir
	@sbt clean bloopInstall
	@sbt clean

tb: pre
	@./tb.sh

update:
	@sbt bloopInstall
	@sbt update
	@sbt reload
