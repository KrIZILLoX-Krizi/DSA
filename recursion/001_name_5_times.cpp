#include <iostream>

using namespace std;

void printName5Times(string name) {
  static uint8_t count = 0;
  if (count == 5) {
    return;
  }
  ++count;
  cout << name << "\n";
  printName5Times(name);
}


int main () {
  printName5Times("aashish");

  return 1;
}