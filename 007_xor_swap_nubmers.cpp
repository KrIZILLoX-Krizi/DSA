




#include<bits/stdc++.h>

using namespace std;

// swapping two numbers using XOR
int main()
{
  int a, b;
  
  cin >> a >> b;

  a = a^b;
  b = a^b;
  a = a^b;
  
  cout << a << endl << b << endl;
}