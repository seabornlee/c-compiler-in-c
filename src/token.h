#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

class Token {
 public:
        virtual bool isEnd();
};

class TokenEOF : public Token {
 public:
        bool isEnd();
};

#endif  //  SRC_TOKEN_H_
