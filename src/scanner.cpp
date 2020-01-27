#include "scanner.h"
#include "token.h"

Scanner::Scanner(std::string text) {
    this->text = text;
    this->index = 0;
}

char Scanner::nextChar() {
    if (index < this->text.length()) {
        return this->text.at(index++);
    }

    return EOF;
}

bool isLetter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

Token *Scanner::getNextToken() {
    char ch = nextChar();
    if (isLetter(ch)) {
        string name = "";
        do {
            name.push_back(ch);
            ch = nextChar();
        } while (isLetter(ch));
        auto *token = new Token();
        token->type = KEYWORD;
        token->name = name;
        return token;
    }

    Token *t = new Token();
    t->type = END;
    return t;
}
