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

bool isSymbol(char ch) {
    std::set<char> symbols = {
            '(', ')', '[', ']', '{', '}', '<', '>', ',', ';'
    };
    return symbols.find(ch) != symbols.end();
}

bool isStartOfString(char ch) {
    return ch == '"';
}

bool isNotEndOfString(char ch) {
    return ch != '"';
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
    while (currentChar != EOF) {
        if (isLetter(currentChar) || isUnderline(currentChar)) {
            string name = "";
            do {
                name.push_back(currentChar);
                currentChar = nextChar();
            } while (isLetter(currentChar) || isDigit(currentChar) || isUnderline(currentChar));

            TokenType type = isKeyword(name) ? KEYWORD : ID;
            return new Token(type, name);
        }

        if (isAssign(currentChar)) {
            char ch = currentChar;
            currentChar = nextChar();
            return new Token(ASSIGN, ch);
        }

        if (isOperator(currentChar)) {
            char next = nextChar();
            if (isAssign(next)) {
                string name;
                name.push_back(currentChar);
                name.push_back(next);
                return new Token(ASSIGN, name);
            }

            return new Token(OPERATOR, currentChar);
        }

        if (isSymbol(currentChar)) {
            char ch = currentChar;
            currentChar = nextChar();
            return new Token(SYMBOL, ch);
        }

        if (isDigit(currentChar)) {
            string value;
            do {
                value.push_back(currentChar);
                currentChar = nextChar();
            } while (isDigit(currentChar));

            return new Token(NUMBER, value);
        }

        if (isStartOfString(currentChar)) {
            string value;
            currentChar = nextChar();
            while (isNotEndOfString(currentChar)) {
                value.push_back(currentChar);
                currentChar = nextChar();
            }
            return new Token(STRING, value);
        }

        currentChar = nextChar();
    }

    return new Token(END);
}
