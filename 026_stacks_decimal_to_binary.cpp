



#include <iostream>
#include <bits/stdc++.h>
#define DEBUG

using namespace std;


string formatHex (string bin)
{
  int len = bin.size();
  int padding = 4 - (len % 4);

  while (padding--)
  {
    bin = '0' + bin;
  }

  return bin;
}

string decimalToBinary (int dec)
{
  string bin = "";
  stack<int> st;

  while (dec)
  {
    #ifdef DEBUG
    cout << "dec: " << dec << endl;
    cout << "dec%2: " << dec%2 << endl;
    #endif
    st.push(dec % 2);
    dec /= 2;
  }

  while (!st.empty())
  {
    bin += (char)(st.top() + 48);
    #ifdef DEBUG
    cout << "st.top(): " << st.top() << endl;
    cout << "bin: " << bin << endl;
    #endif
    st.pop();
  }

  return formatHex(bin);
}

string decimalToHex (int dec)
{
  string bin = "";
  stack<char> st;
  char rem = ' ';

  while (dec)
  {
    #ifdef DEBUG
    cout << "dec: " << dec << endl;
    cout << "dec%16: " << dec%16 << endl;
    #endif
    switch (dec % 16)
    {
      case 0: rem = '0';
        break;
      case 1: rem = '1';
        break;
      case 2: rem = '2';
        break;
      case 3: rem = '3';
        break;
      case 4: rem = '4';
        break;
      case 5: rem = '5';
        break;
      case 6: rem = '6';
        break;
      case 7: rem = '7';
        break;
      case 8: rem = '8';
        break;
      case 9: rem = '9';
        break;
      case 10: rem = 'A';
        break;
      case 11: rem = 'B';
        break;
      case 12: rem = 'C';
        break;
      case 13: rem = 'D';
        break;
      case 14: rem = 'E';
        break;
      case 15: rem = 'F';
        break;
      default: break;
    }
    st.push(rem);
    #ifdef DEBUG
    cout << "stack push | st.top(): " << st.top() << endl;
    #endif
    dec /= 16;
  }

  while (!st.empty())
  {
    bin += st.top();
    #ifdef DEBUG
    cout << "stack dump | st.top(): " << st.top() << endl;
    cout << "bin: " << bin << endl;
    #endif
    st.pop();
  }

  return formatHex(bin);
}

// TC1
//======================
void TC1 ()
{
  int dec = 24;
  cout << "==TC1==begin=======" << endl;
  cout << "decimal: " << dec << endl;
  cout << "bin: " << decimalToBinary(dec) << endl;
  cout << "==TC1==end=========" << endl;
}


// TC2
//======================
void TC2 ()
{
  int dec = 333;
  cout << "==TC2==begin=======" << endl;
  cout << "decimal: " << dec << endl;
  cout << "bin: " << decimalToBinary(dec) << endl;
  cout << "==TC2==end=========" << endl;
}


// TC3
//======================
void TC3 ()
{
  int dec = 333;
  cout << "==TC3==begin=======" << endl;
  cout << "decimal: " << dec << endl;
  cout << "bin: " << decimalToHex(dec) << endl;
  cout << "==TC3==end=========" << endl;
}


// TC4
//======================
void TC4 ()
{
  int dec = 4566;
  cout << "==TC4==begin=======" << endl;
  cout << "decimal: " << dec << endl;
  cout << "bin: " << decimalToHex(dec) << endl;
  cout << "==TC4==end=========" << endl;
}

int main(void)
{
  TC3();
  TC4();

  return 1;
}