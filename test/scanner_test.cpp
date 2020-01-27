
#include "gtest/gtest.h"
#include "../src/token.h"
#include "../src/scanner.h"

TEST(ScannerTest, getNextTokenShouldReturnEndWhenEnded) {
    Scanner scanner("");
    Token *token = scanner.getNextToken();
    EXPECT_EQ(END, token->type);
}

class KeywordParameterizedTestFixture : public ::testing::TestWithParam<string> {};

TEST_P(KeywordParameterizedTestFixture, getNextTokenShouldReturnKeywordToken) {
    ParamType keyword = GetParam();
    Scanner scanner(keyword);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(KEYWORD, token->type);
    EXPECT_EQ(keyword, token->name);
}

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        KeywordParameterizedTestFixture,
        ::testing::Values(
                "int", "auto", "break", "case",	"char", "const", "continue", "default", "do",
                "double", "else", "enum", "extern", "float", "for", "goto", "if",
                "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
        )
);