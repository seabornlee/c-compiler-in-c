#include "scanner.h"
#include "token.h"

Scanner::Scanner(std::string text) {
}

Token* Scanner::getNextToken() {
    return new TokenEOF();
}
