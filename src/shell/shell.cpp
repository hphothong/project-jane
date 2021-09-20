#include <iostream>
#include <memory>
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
      vector<std::unique_ptr<Token>> pTokens = lexer.getTokens();
      for (auto&& p : pTokens) {
        cout << p->toString() << endl;
      }
    } catch (runtime_error const& e) {
      cout << e.what() << endl;
    }
  }
}