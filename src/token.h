#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include <string>

using namespace std;

enum TokenType {
    END, KEYWORD, ID, ASSIGN, OPERATOR, SYMBOL, NUMBER
};

class Token {
public:

    Token(TokenType type, string name);

    Token(TokenType type, char ch);

    Token(TokenType type);

    string name;
    TokenType type;
    int nValue;
};

#endif  //  SRC_TOKEN_H_
