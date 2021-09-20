#include "token.hpp"

Token::Token(TokenType type) {
  this->type = type;
}

TokenType Token::getType() {
  return this->type;
}

std::string Token::toString() {
  return std::to_string(this->type);
}