#include "token.h"

Token::Token(TokenType type, string name) {
    this->type = type;
    this->name = name;

    if (type == NUMBER) {
        this->nValue = stoi(name);
    } else if (type == STRING) {
        this->sValue = name;
    }
}

Token::Token(TokenType type, char ch) {
    this->type = type;
    this->name = string(1, ch);
}

Token::Token(TokenType type) {
    this->type = type;
}
