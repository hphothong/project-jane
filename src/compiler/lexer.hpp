#ifndef LEXER_H
#define LEXER_H

#include <memory>
#include <string>
#include <vector>
#include "position.hpp"
#include "tokens/token.hpp"

class Lexer {
  public:
    Lexer(std::string filename, std::string fileContents);
    std::vector<std::unique_ptr<Token>> getTokens();
  private:
    std::string filename;
    std::string fileContents;
    char currentCharacter;
    Position position = Position(&(this->currentCharacter));
    void next();
    void prev();
    std::unique_ptr<Token> getNumberToken();
    bool isDigit();
};

#endif