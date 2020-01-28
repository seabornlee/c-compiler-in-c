#include <set>
#include "scanner.h"
#include "token.h"

Scanner::Scanner(std::string text) {
    this->text = text;
    index = 0;
}

void Scanner::moveToNextChar() {
    index++;
}

bool Scanner::isLetter() {
    return (currentChar() >= 'a' && currentChar() <= 'z') || (currentChar() >= 'A' && currentChar() <= 'Z');
}

bool Scanner::isDigit() {
    return currentChar() >= '0' && currentChar() <= '9';
}

bool Scanner::isUnderline() {
    return currentChar() == '_';
}

bool Scanner::isAssign() {
    return currentChar() == '=';
}

bool Scanner::isOperator() {
    std::set<char> operators = {
            '+', '-', '*', '/', '%'
    };
    return operators.find(currentChar()) != operators.end();
}

bool Scanner::isSymbol() {
    std::set<char> symbols = {
            '(', ')', '[', ']', '{', '}', '<', '>', ',', ';'
    };
    return symbols.find(currentChar()) != symbols.end();
}

bool Scanner::isStartOfString() {
    return currentChar() == '"';
}

bool Scanner::isNotEndOfString() {
    return currentChar() != '"';
}

bool Scanner::isSpace() {
    return currentChar() == ' ' || currentChar() == '\t';
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
    while (currentChar() != EOF) {
        if (isSpace()) {
            moveToNextChar();
            continue;
        }

        if (isLetter() || isUnderline()) {
            return tokenizeIdOrKeyword();
        }

        if (isAssign()) {
            return tokenizeAssign();
        }

        if (isOperator()) {
            return tokenizeOperatorOrAssign();
        }

        if (isSymbol()) {
            return tokenizeSymbol();
        }

        if (isDigit()) {
            return tokenizeNumber();
        }

        if (isStartOfString()) {
            return tokenizeString();
        }

        moveToNextChar();
    }

    return new Token(END);
}

Token *Scanner::tokenizeString() {
    string value;
    moveToNextChar(); // skip left "
    while (isNotEndOfString()) {
        value.push_back(currentChar());
        moveToNextChar();
    }
    return new Token(STRING, value);
}

Token *Scanner::tokenizeNumber() {
    string value;
    do {
        value.push_back(currentChar());
        moveToNextChar();
    } while (isDigit());

    return new Token(NUMBER, value);
}

Token *Scanner::tokenizeSymbol() {
    char ch = currentChar();
    moveToNextChar();
    return new Token(SYMBOL, ch);
}

Token *Scanner::tokenizeOperatorOrAssign() {
    string name;
    name.push_back(currentChar());

    moveToNextChar();
    if (isAssign()) {
        name.push_back(currentChar());
        return new Token(ASSIGN, name);
    }

    return new Token(OPERATOR, name);
}

Token *Scanner::tokenizeAssign() {
    char ch = currentChar();
    moveToNextChar();
    return new Token(ASSIGN, ch);
}

Token *Scanner::tokenizeIdOrKeyword() {
    string name = "";
    do {
        name.push_back(currentChar());
        moveToNextChar();
    } while (isLetter() || isDigit() || isUnderline());

    TokenType type = isKeyword(name) ? KEYWORD : ID;
    return new Token(type, name);
}

char Scanner::currentChar() {
    if (index < text.length()) {
        return text.at(index);
    }

    return EOF;
}
