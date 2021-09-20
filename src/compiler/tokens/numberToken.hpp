#ifndef NUMBER_TOKEN_H
#define NUMBER_TOKEN_H

#include "token.hpp"

template<typename T> class NumberToken : public Token {
  public:
    NumberToken(TokenType type, T value): Token(type) {
      this->value = value;
    }
    T getValue() {
      return this->value;
    }
    std::string toString() override {
      return std::to_string(this->type) + ":" + std::to_string(this->value);
    }
  private:
    T value;
};

#endif
