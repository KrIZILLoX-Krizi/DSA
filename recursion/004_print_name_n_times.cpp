#include <iostream>

using namespace std;

void printNameNTimes(string name, int count) {
  if (count == 0) {
    return;
  }
  --count;
  cout << name << "\n";
  printNameNTimes(name, count);
}

int main() {
  printNameNTimes("abc", 10);

  return 1;
}