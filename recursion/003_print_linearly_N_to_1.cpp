#include <iostream>

using namespace std;

void printNto1 (uint8_t n) {
  if (n == 0) {
    return;
  }

  cout << +n << " ";
  --n;
  printNto1(n);
}

int main () {
  uint8_t n = 10;
  printNto1(n);

  return 0;
}