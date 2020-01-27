#include "token.h"

bool Token::isEnd() {
    return false;
}

bool TokenEOF::isEnd() {
    return true;
}
