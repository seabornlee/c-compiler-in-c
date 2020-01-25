BUILD_DIR = build
CC = g++

.PHONY: test

test: build
	$(CC) -std=c++11 ./test/scanner_test.cpp -lgtest -lpthread -o ./$(BUILD_DIR)/scanner_test
	./$(BUILD_DIR)/scanner_test

build:
	mkdir $(BUILD_DIR)

clean:
	rm -r $(BUILD_DIR)