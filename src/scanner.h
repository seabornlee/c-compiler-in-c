#include <string>
#include "token.h"

class Scanner {
    public:
        Scanner(std::string text);
        Token *getNextToken();

        string text;
private:
    char nextChar();
    int index;
    char currentChar = '\0';
};