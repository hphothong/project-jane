#include "position.hpp"

Position::Position(char* pCurrentCharacter) {
  this->pCurrentCharacter = pCurrentCharacter;
  this->index = -1;
  this->column = 0;
  this->line = 1;
}

int Position::getIndex() {
  return this->index;
}

std::string Position::toString() {
  return "line " + std::to_string(this->line) + ":" + std::to_string(this->column);
}

Position& Position::operator++() {
  this->index++;
  if (*this->pCurrentCharacter == '\n') {
    this->column = 0;
    this->line++;
  } else {
    this->column++;
  }
  return *this;
}

Position Position::operator++(int) {
  Position p = *this;
  ++*this;
  return p;
}