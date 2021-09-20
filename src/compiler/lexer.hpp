#ifndef LEXER_H
#define LEXER_H

#include <memory>
#include <string>
#include <vector>
#include "tokens/token.hpp"

class Lexer {
  public:
    Lexer(std::string filename, std::string fileContents);
    std::vector<std::unique_ptr<Token>> getTokens();
  private:
    std::string filename;
    std::string fileContents;
    long unsigned int position;
    char currentCharacter;
    void next();
    void prev();
    std::unique_ptr<Token> getNumberToken();
    bool isDigit();
};

#endif