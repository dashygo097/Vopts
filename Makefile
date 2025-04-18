BASE_DIR = $(shell pwd)
BUILD_DIR = $(BASE_DIR)/build


.PHONY: pre run build clean autotest bloop-install

pre:
	@mkdir -p $(BUILD_DIR)

build: pre bloop-install
	@sbt compile

run:
	@sbt app/run

clean:
	@rm -r $(BUILD_DIR)/obj_dir
	@sbt clean bloopInstall
	@sbt clean

autotest: pre
	@./autotest.sh

bloop-install:
	@sbt clean bloopInstall
