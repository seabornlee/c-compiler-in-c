
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
                "i", "rawText", "nextChar", "p0", "next_char", "_name"
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

class StringParameterizedTestFixture : public ::testing::TestWithParam<string> {
};

INSTANTIATE_TEST_SUITE_P
(
        ScannerTest,
        StringParameterizedTestFixture,
        ::testing::Values(
                "\"\"", "\"China\""
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
    EXPECT_EQ(keyword, token->rawText);
}

TEST_P(IdentifierParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType identifier = GetParam();
    Scanner scanner(identifier);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(ID, token->type);
    EXPECT_EQ(identifier, token->rawText);
}

TEST_P(AssignParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType assign = GetParam();
    Scanner scanner(assign);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(ASSIGN, token->type);
    EXPECT_EQ(assign, token->rawText);
}

TEST_P(OperatorParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType aOperator = GetParam();
    Scanner scanner(aOperator);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(OPERATOR, token->type);
    EXPECT_EQ(aOperator, token->rawText);
}

TEST_P(SymbolParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType symbol = GetParam();
    Scanner scanner(symbol);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(SYMBOL, token->type);
    EXPECT_EQ(symbol, token->rawText);
}

TEST_P(NumberParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType number = GetParam();
    Scanner scanner(number);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(NUMBER, token->type);
    EXPECT_EQ(stoi(number), token->nValue);
}

TEST_P(StringParameterizedTestFixture, getNextTokenShouldReturnIdentifierToken) {
    ParamType str = GetParam();
    Scanner scanner(str);
    Token *token = scanner.getNextToken();
    EXPECT_EQ(STRING, token->type);
    EXPECT_EQ(str.substr(1, str.length() - 2), token->sValue);
}

TEST(ScannerTest, shouldParseStatement) {
    Scanner scanner("int i = 0;");
    Token *intToken = scanner.getNextToken();
    EXPECT_EQ(KEYWORD, intToken->type);
}

TEST(ScannerTest, getNextTokenShouldIgnorSpace) {
    Scanner scanner(" \t");
    Token *token = scanner.getNextToken();
    EXPECT_EQ(END, token->type);
}