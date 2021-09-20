#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {
  public:
    Position(char* pCurrentCharacter);
    Position& operator++();
    Position operator++(int);
    int getIndex();
    std::string toString();
  private:
    int index;
    char* pCurrentCharacter;
    int line;
    int column;
};

#endif
