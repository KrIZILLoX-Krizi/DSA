#include <iostream>

using namespace std;

int sumFirstNUsingStatic(int n) {
  static int i = 1;

  if (i > n) {
    return 0;
  }

  return i++ + sumFirstNUsingStatic(n);
}

int sumFirstN(int n) {
  if (n <= 0) {
    return 0;
  }

  return n + sumFirstN(n-1);
}

int main () {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tcCount = 1;

  for (int num : nums) {
    cout << "TC: " << tcCount++ << "\n";
    cout << "N: " << num << "\n";
    cout << sumFirstN(num) <<"\n";
    cout << "----------------------------------\n\n";
  }

  // static int limits usage of this API once per program lifetime
  // else returns wrong answers on subsequent calls
  cout << sumFirstNUsingStatic(nums[10]) <<"\n";
  cout << sumFirstNUsingStatic(nums[9]) <<"\n";

  return 0;
}