BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build


.PHONY: run build clean test bloop-install

build: bloop-install
	@sbt compile
	@mkdir -p $(BUILD_DIR)

run:
	@sbt app/run

clean:
	@rm -r $(BUILD_DIR)/obj_dir
	@sbt clean bloopInstall
	@sbt clean

autotest:
	@./autotest.sh

bloop-install:
	@sbt clean bloopInstall
