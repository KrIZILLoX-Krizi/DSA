#include <iostream>

using namespace std;

void print1toN(uint8_t n) {
  static uint8_t count = 1;
  if (count > n) {
    return;
  }
  cout << +count << " ";
  ++count;
  print1toN(n);
}



int main () {
  uint8_t n = 10;
  print1toN(n);
  
  return 1;
}