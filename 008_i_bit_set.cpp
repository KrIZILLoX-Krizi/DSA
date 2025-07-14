



#include <bits/stdc++.h>

using namespace std;

// check if i bit is set in a number

bool checkIBitSet(int num, int i)
{
  return (num & (1 << i));
}

int main()
{
  int a, i;
  cin >> a >> i;
  --i;

  cout << checkIBitSet(a, i);

  return 0;
}