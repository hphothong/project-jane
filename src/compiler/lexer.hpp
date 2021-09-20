#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "tokens/token.hpp"

class Lexer {
  public:
    Lexer(std::string filename, std::string fileContents);
    std::vector<Token> getTokens();
  private:
    std::string filename;
    std::string fileContents;
    long unsigned int position;
    char currentCharacter;
    void next();
    void prev();
    Token getNumberToken();
    bool isDigit();
};

#endif