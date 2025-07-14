



#include <bits/stdc++.h>

using namespace std;

int clearIthBit(int num, int i)
{
  return (num & ~(1 << i));
}

int main()
{
  int a, i;

  cin >> a >> i;
  --i;

  cout << clearIthBit(a, i);

  return 0;
}