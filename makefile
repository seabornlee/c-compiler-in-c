BUILD_DIR = build

.PHONY: test
test: build
	cd $(BUILD_DIR) && cmake .. && make all && cd test && ctest -V

build: checkout
	mkdir $(BUILD_DIR)

checkout:
	git submodule init && git submodule update

clean:
	rm -r $(BUILD_DIR)
