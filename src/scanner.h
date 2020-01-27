#include <string>
#include "token.h"

class Scanner {
    public:
        Scanner(std::string text);
        Token getNextToken();
};