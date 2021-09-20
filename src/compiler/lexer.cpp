#include <stdexcept>
#include "lexer.hpp"
#include "tokens/numberToken.hpp"

Lexer::Lexer(std::string filename, std::string fileContents) {
  this->filename = filename;
  this->fileContents = fileContents;
  this->position = 0;
  this->currentCharacter = (char)NULL;
};

std::vector<Token> Lexer::getTokens() {
  std::vector<Token> tokens;

  this->next();
  
  while (this->currentCharacter != (char)NULL) {
    if (this->currentCharacter == ' ' || this->currentCharacter == '\t') {
      this->next();
      continue;
    } else if (this->isDigit()) {
      tokens.push_back(this->getNumberToken());
    } else if (this->currentCharacter == '+') {
      tokens.push_back(Token(TokenType::Addition)); 
    } else if (this->currentCharacter == '-') {
      tokens.push_back(Token(TokenType::Subtraction)); 
    } else if (this->currentCharacter == '*') {
      tokens.push_back(Token(TokenType::Multiplication)); 
    } else if (this->currentCharacter == '/') {
      tokens.push_back(Token(TokenType::Division)); 
    } else if (this->currentCharacter == '(') {
      tokens.push_back(Token(TokenType::LeftParen)); 
    } else if (this->currentCharacter == ')') {
      tokens.push_back(Token(TokenType::RightParen));
    } else {
      throw std::runtime_error("Invalid Character '" + std::to_string(this->currentCharacter) + "' at column: " + std::to_string(this->position - 1));
    }
    this->next();
  };

  return tokens;
}

void Lexer::next() {
  this->currentCharacter = this->position < this->fileContents.length() ? this->fileContents[this->position] : (char)NULL;
  this->position++;
}

void Lexer::prev() {
  this->position--;
  this->currentCharacter = this->position < this->fileContents.length() ? this->fileContents[this->position] : (char)NULL;
}

bool Lexer::isDigit() {
  return this->currentCharacter == '0'
    || this->currentCharacter == '1'
    || this->currentCharacter == '2'
    || this->currentCharacter == '3'
    || this->currentCharacter == '4'
    || this->currentCharacter == '5'
    || this->currentCharacter == '6'
    || this->currentCharacter == '7'
    || this->currentCharacter == '8'
    || this->currentCharacter == '9';
}

Token Lexer::getNumberToken() {
  bool isDouble = false;
  std::string value  = "";

  while (this->currentCharacter != (char)NULL && (this->isDigit() || this->currentCharacter == '.')) {
    if (this->currentCharacter == '.') {
      if (isDouble) {
        break;
      }
      isDouble = true;
    }
    value.push_back(this->currentCharacter);
    this->next();
  }

  this->prev();

  if (isDouble) {
    return NumberToken<double>(TokenType::Double, std::stod(value));
  }

  return NumberToken<int>(TokenType::Integer, std::stoi(value));
}