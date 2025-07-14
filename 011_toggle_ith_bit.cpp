



#include <bits/stdc++.h>

using namespace std;

int toggleIthBit(int num, int i)
{
  return (num ^ (1 << i));
}

// toggle ith bit in number
int main()
{
  int a, i;

  cin >> a >> i;
  --i;

  cout << toggleIthBit(a, i);

  return 0;
}