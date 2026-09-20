#include <iostream>

using namespace std;

void printNTo1Backtracking(int i, int n) {
  if (i > n) {
    return;
  }
  printNTo1Backtracking(i+1, n);
  cout << i << " ";
}

int main () {
  printNTo1Backtracking(1, 10);
  return 0;
}