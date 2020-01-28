#include <set>
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
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isUnderline(char ch) {
    return ch == '_';
}

bool isAssign(char ch) {
    return ch == '=';
}

bool isOperator(char ch) {
    std::set<char> operators = {
            '+', '-', '*', '/', '%'
    };
    return operators.find(ch) != operators.end();
}

bool isKeyword(const string &name) {
    std::set<string> keywords = {
            "int", "auto", "break", "case", "char", "const", "continue", "default", "do",
            "double", "else", "enum", "extern", "float", "for", "goto", "if",
            "int", "long", "register", "return", "short", "signed", "sizeof", "static",
            "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    return keywords.find(name) != keywords.end();
}

Token *Scanner::getNextToken() {
    char ch = nextChar();
    if (isLetter(ch) || isUnderline(ch)) {
        string name = "";
        do {
            name.push_back(ch);
            ch = nextChar();
        } while (isLetter(ch) || isDigit(ch) || isUnderline(ch));

        auto *token = new Token();
        token->type = isKeyword(name) ? KEYWORD : ID;
        token->name = name;
        return token;
    }

    if (isAssign(ch)) {
        auto *token = new Token();
        token->type = ASSIGN;
        token->name = ch;
        return token;
    }

    if (isOperator(ch)) {
        auto *token = new Token();
        token->type = OPERATOR;
        token->name = ch;
        return token;
    }

    Token *t = new Token();
    t->type = END;
    return t;
}
