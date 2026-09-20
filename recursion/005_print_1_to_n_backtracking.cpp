#include <iostream>

using namespace std;

void print1ToNBacktracking(int n) {
    if (n == 0) {
        return;
    }

    print1ToNBacktracking(n-1);
    cout << n << " ";
}

int main () {
    print1ToNBacktracking(10);
    return 0;
}