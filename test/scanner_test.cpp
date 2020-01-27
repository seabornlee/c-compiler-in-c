
#include "gtest/gtest.h"
#include "../src/token.h"
#include "../src/scanner.h"

TEST(ScannerTest, getNextTokenShouldReturnEndWhenEnded) {
    Scanner scanner("");
    Token token = scanner.getNextToken();
    EXPECT_TRUE(token.isEnd());
}
