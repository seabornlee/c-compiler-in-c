
#include "gtest/gtest.h"
#include "../src/token.h"
#include "../src/scanner.h"

TEST(ScannerTest, getNextTokenShouldReturnEndWhenEnded) {
    Scanner scanner("");
    Token *token = scanner.getNextToken();
    EXPECT_EQ(END, token->type);
}

TEST(ScannerTest, getNextTokenShouldReturnKeywordToken) {
    Scanner scanner("int");
    Token *token = scanner.getNextToken();
    EXPECT_EQ(KEYWORD, token->type);
    EXPECT_EQ("int", token->name);
}
