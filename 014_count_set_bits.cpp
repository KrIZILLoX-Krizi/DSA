



#include <bits/stdc++.h>

using namespace std;

int countSetBits(int num)
{
  int count = 0;
  while(num)
  {
    num = num & (num - 1);
    ++count;
  }

  return count; 
}

// count set bits in number
int main()
{
  int a;

  cin >> a;

  cout << countSetBits(a);

  return 0;
}