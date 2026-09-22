#include <iostream>

using namespace std;

int factorial (int n) {
    if (n == 0 || n == 1) return 1;

    return n * factorial(n-1);
}

int main () {
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tcCount = 1;

    for (int num : nums) {
        cout << "TC: " << tcCount++ << "\n";
        cout << "Num: " << num << "\n";
        cout << factorial(num) << "\n";
        cout << "---------------------------------\n\n";
    }

    return 0;
}