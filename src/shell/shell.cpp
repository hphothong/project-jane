#include <iostream>
#include <string>
#include "../compiler/lexer.hpp"

using namespace std;

int main() {
  string input;
  while (true) {
    try {
      cout << "shell>";
      getline(cin, input);
      Lexer lexer = Lexer("shell", input);
      vector<Token> tokens = lexer.getTokens();
      for (auto token : tokens) {
        cout << token.toString() << endl;
      }
    } catch (runtime_error const& e) {
      cout << e.what() << endl;
    }
  }
}