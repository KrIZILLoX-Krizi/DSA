



#include<bits/stdc++.h>

using namespace std;


int setIthBit(int num, int i)
{
  return (num | (1 << i));
}



int main()
{
  int a, i;

  cin >> a >> i;

  cout << setIthBit(a, i);

  return 0;
}