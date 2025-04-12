BASEDIR = $(shell pwd)
BUILD_DIR = $(BASEDIR)/build

.PHONY: run build clean test compile bloop-install

compile:
	@sbt compile

build: compile
	@mkdir -p $(BUILD_DIR)

run: build
	@@sbt app/run

clean:
	@sbt clean bloopInstall
	@sbt clean

test:
	@./test.sh

bloop-install:
	@sbt clean bloopInstall
