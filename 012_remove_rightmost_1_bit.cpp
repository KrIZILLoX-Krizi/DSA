



#include <bits/stdc++.h>

using namespace std;

int removeRHSSetBit(int num, int i)
{
  return (num & (num-1));
}

// remove rightmost set bit
int main()
{
  int a, i;

  cin >> a >> i;
  --i;

  cout << removeRHSSetBit(a, i);

  return 0;
}