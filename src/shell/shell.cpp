#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  while (true) {
    cout << "shell>";
    getline(cin, input);
    cout << input << endl;
  }
}