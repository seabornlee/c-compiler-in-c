#include "token.h"

Token::Token(TokenType type, const string& rawText) {
    this->type = type;
    this->rawText = rawText;

    if (type == NUMBER) {
        this->nValue = stoi(rawText);
    } else if (type == STRING) {
        this->sValue = rawText;
    }
}

Token::Token(TokenType type, char ch) {
    this->type = type;
    this->rawText = string(1, ch);
}

Token::Token(TokenType type) {
    this->type = type;
}
