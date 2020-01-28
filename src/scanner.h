#include <string>
#include "token.h"

class Scanner {
public:
    Scanner(std::string text);

    Token *getNextToken();

    string text;
private:
    int index;

    char currentChar();

    void moveToNextChar();

    Token *tokenizeIdOrKeyword();

    Token *tokenizeAssign();

    Token *tokenizeOperatorOrAssign();

    Token *tokenizeSymbol();

    Token *tokenizeNumber();

    Token *tokenizeString();

    bool isSpace();

    bool isLetter();

    bool isDigit();

    bool isUnderline();

    bool isAssign();

    bool isOperator();

    bool isSymbol();

    bool isStartOfString();

    bool isNotEndOfString();
};