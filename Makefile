BASEDIR = $(shell pwd)
BUILD_DIR = $(BASEDIR)/build


.PHONY: run build clean test bloop-install

build:
	@sbt compile
	@mkdir -p $(BUILD_DIR)

run:
	@sbt app/run

clean:
	@sbt clean bloopInstall
	@sbt clean

test:
	@./test.sh

bloop-install:
	@sbt clean bloopInstall
