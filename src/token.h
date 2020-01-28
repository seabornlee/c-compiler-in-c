#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include <string>

using namespace std;

enum TokenType {
    END, KEYWORD, ID, ASSIGN, OPERATOR
};

class Token {
public:

    Token(TokenType type, string name);

    Token(TokenType type);

    string name;
    TokenType type;
};

#endif  //  SRC_TOKEN_H_
