#include <stdexcept>
#include "lexer.hpp"
#include "tokens/numberToken.hpp"

Lexer::Lexer(std::string filename, std::string fileContents) {
  this->filename = filename;
  this->fileContents = fileContents;
  this->position = 0;
  this->currentCharacter = (char)NULL;
};

std::vector<std::unique_ptr<Token>> Lexer::getTokens() {
  std::vector<std::unique_ptr<Token>> pTokens;

  this->next();

  while (this->currentCharacter != (char)NULL) {
    if (this->currentCharacter == ' ' || this->currentCharacter == '\t') {
      this->next();
      continue;
    } else if (this->isDigit()) {
      pTokens.push_back(this->getNumberToken());
    } else if (this->currentCharacter == '+') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::Addition))); 
    } else if (this->currentCharacter == '-') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::Subtraction))); 
    } else if (this->currentCharacter == '*') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::Multiplication))); 
    } else if (this->currentCharacter == '/') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::Division))); 
    } else if (this->currentCharacter == '(') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::LeftParen))); 
    } else if (this->currentCharacter == ')') {
      pTokens.push_back(std::unique_ptr<Token>(new Token(TokenType::RightParen)));
    } else {
      std::string message = "Invalid character '";
      message += this->currentCharacter;
      message += "' at column: " + std::to_string(this->position - 1);
      throw std::runtime_error(message);
    }
    this->next();
  };

  return pTokens;
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

std::unique_ptr<Token> Lexer::getNumberToken() {
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
    return std::unique_ptr<Token>(new NumberToken<double>(TokenType::Double, std::stod(value)));
  }

  return std::unique_ptr<Token>(new NumberToken<int>(TokenType::Integer, std::stoi(value)));
}