#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "tokenType.hpp"

class Token {
  public:
    Token(TokenType type);
    TokenType getType();
    virtual std::string toString();
  protected:
    TokenType type;
};

#endif