
#include "gtest/gtest.h"
#include "../src/token.h"
#include "../src/scanner.h"

class KeywordParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        KeywordParameterizedTestFixture,
        ::testing::Values(
                "int", "auto", "break", "case", "char", "const", "continue", "default", "do",
                "double", "else", "enum", "extern", "float", "for", "goto", "if",
                "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
        )
);

class IdentifierParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        IdentifierParameterizedTestFixture,
        ::testing::Values(
                "i", "name", "nextChar", "p0", "next_char", "_name"
        )
);

class AssignParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        AssignParameterizedTestFixture,
        ::testing::Values(
                "=", "+=", "-=", "*=", "/=", "%="
        )
);

class OperatorParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        OperatorParameterizedTestFixture,
        ::testing::Values(
                "+", "-", "*", "/", "%"
        )
);

class SymbolParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        SymbolParameterizedTestFixture,
        ::testing::Values(
                "(", ")", "[", "]", "{", "}", "<", ">", ",", ";"
        )
);

class NumberParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        NumberParameterizedTestFixture,
        ::testing::Values(
                "0", "123"
        )
);

TEST(ScannerTest, getNextTokenShouldReturnEndWhenEnded) {
    Scanner scanner("");
    Token *token = scanner.getNextToken();
    EXPECT_EQ(END, token->type);
}

TEST_P(KeywordParameterizedTestFixture, getNextTokenShouldReturnKeywordToken) {
    ParamType keyword = GetParam();
    Scanner scanner(keyword);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(KEYWORD, token->type);
    EXPECT_EQ(keyword, token->name);
}

TEST_P(IdentifierParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType identifier = GetParam();
    Scanner scanner(identifier);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(ID, token->type);
    EXPECT_EQ(identifier, token->name);
}

TEST_P(AssignParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType assign = GetParam();
    Scanner scanner(assign);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(ASSIGN, token->type);
    EXPECT_EQ(assign, token->name);
}

TEST_P(OperatorParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType aOperator = GetParam();
    Scanner scanner(aOperator);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(OPERATOR, token->type);
    EXPECT_EQ(aOperator, token->name);
}

TEST_P(SymbolParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType symbol = GetParam();
    Scanner scanner(symbol);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(SYMBOL, token->type);
    EXPECT_EQ(symbol, token->name);
}

TEST_P(NumberParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType number = GetParam();
    Scanner scanner(number);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(NUMBER, token->type);
    EXPECT_EQ(stoi(number), token->nValue);
}