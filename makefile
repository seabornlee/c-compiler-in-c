BUILD_DIR = build

.PHONY: test
test: build
	cd $(BUILD_DIR) && cmake .. && make all && cd test && ctest -V

build:
	mkdir $(BUILD_DIR)

clean:
	rm -r $(BUILD_DIR)