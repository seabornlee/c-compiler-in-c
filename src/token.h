#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include <string>

using namespace std;

enum TokenType {
    END, KEYWORD, ID, ASSIGN, OPERATOR, SYMBOL, NUMBER, STRING
};

class Token {
public:

    Token(TokenType type, string rawText);

    Token(TokenType type, char ch);

    Token(TokenType type);

    string rawText;
    TokenType type;
    int nValue;
    string sValue;
};

#endif  //  SRC_TOKEN_H_
