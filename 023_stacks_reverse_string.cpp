



#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reverseString(string str)
{
  string rev_string = "";
  int i = 0;
  stack<char> st;

  // populate stack
  for (; i < str.size(); ++i)
  {
    st.push(str[i]);
  }

  // pop stack into rev_string
  while (!st.empty())
  {
    rev_string.push_back(st.top());
    st.pop();
  }

  return rev_string;
}

// TC1
//=====================
void TC1 ()
{
  cout << "==TC1=begin==" << endl;
  string a = "abc";
  cout << a << endl;
  cout << reverseString(a) << endl;
  cout << "==TC1=end====" << endl;
}

// TC2
//=====================
void TC2 ()
{
  cout << "==TC2=begin==" << endl;
  string a = "a";
  cout << a << endl;
  cout << reverseString(a) << endl;
  cout << "==TC2=end====" << endl;
}

// TC3
//=====================
void TC3 ()
{
  cout << "==TC3=begin==" << endl;
  string a = "";
  cout << a << endl;
  cout << reverseString(a) << endl;
  cout << "==TC3=end====" << endl;
}

// TC4
//=====================
void TC4 ()
{
  cout << "==TC4=begin==" << endl;
  string a = "aashish kumar";
  cout << a << endl;
  cout << reverseString(a) << endl;
  cout << "==TC4=end====" << endl;
}

// TC5
//=====================
void TC5 ()
{
  cout << "==TC5=begin==" << endl;
  string a = "racecar";
  cout << a << endl;
  cout << reverseString(a) << endl;
  cout << "==TC5=end====" << endl;
}

int main(void)
{
  TC1();
  TC2();
  TC3();
  TC4();
  TC5();
  
  return 1;
}