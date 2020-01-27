#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include <string>

using namespace std;

enum TokenType {
    END, KEYWORD, ID
};

class Token {
public:

    string name;
    TokenType type;
};

#endif  //  SRC_TOKEN_H_
