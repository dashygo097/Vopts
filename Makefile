BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build
TESTBENCH_DIR = $(BASE_DIR)/testbench


.PHONY: pre run build clean test bloop-install debug

pre:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TESTBENCH_DIR)

build: pre bloop-install
	@sbt reload
	@sbt compile

run: pre
	@sbt app/run

clean:
	@rm -rf $(TESTBENCH_DIR)/obj_dir
	@sbt clean bloopInstall
	@sbt clean

test: pre
	@./test.sh

bloop-install:
	@sbt bloopInstall
