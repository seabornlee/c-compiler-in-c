#include "token.h"

Token::Token(TokenType type, string name) {
    this->type = type;
    this->name = name;
}

Token::Token(TokenType type) {
    this->type = type;
}
