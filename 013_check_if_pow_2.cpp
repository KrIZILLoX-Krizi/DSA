



#include <bits/stdc++.h>

using namespace std;

bool checkPow2(int num)
{
  return (num & (num - 1));
}

// check if num power of two
int main()
{
  int a, i;

  cin >> a;

  cout << checkPow2(a);

  return 0;
}