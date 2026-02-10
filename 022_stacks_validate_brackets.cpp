



#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool validate_brackets(string a)
{
  stack<char> st;
  int i = 0;

  // loop over bracket elements
  for (; i < a.length(); ++i)
  {
    // push if opening brackets
    if (a[i] == '{' || a[i] == '[' || a[i] == '(')
    {
      st.push(a[i]);
    }

    // pop if closing brackets
    if (a[i] == '}' || a[i] == ']' || a[i] == ')')
    {
      // if stack empty, return false
      if (st.empty())
      {
        cout << "Fatal error: Lingering closing bracket found " << a[i] << " at " << i << endl;
        return false;
      }

      // remove if stack top is corresponding opening bracking
      if (a[i] == ')' && st.top() == '(' ||
          a[i] == '}' && st.top() == '{' ||
          a[i] == ']' && st.top() == '['
      )
      {
        st.pop();
      }
      // if mismatching closing bracket, return false
      else
      {
        cout << "Fatal error: Closing bracket mismatch " << a[i] << " at " << i << endl;
        return false;
      }
    }
  }

  // if string traversed and stack empty
  // return true
  if (st.empty())
  {
    return true;
  }

  // string traversed but stack not empty
  // return false
  cout << "Fatal error: String traversed but stack not empty"<< endl;
  return false;
}

// TC 1
//================================
bool TC1 ()
{
  cout << "==TC1==begin==" << endl;
  string a = "{";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC1==end====" << endl;
  return retCode;
}
// TC 2
//================================
bool TC2 ()
{
  cout << "==TC2==begin==" << endl;
  string a = "}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC2==end====" << endl;
  return retCode;
}

// TC 3
//================================
bool TC3 ()
{
  cout << "==TC3==begin==" << endl;
  string a = "{}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC3==end====" << endl;
  return retCode;
}


// TC 4
//================================
bool TC4 ()
{
  cout << "==TC4==begin==" << endl;
  string a = "{()}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC3==end====" << endl;
  return retCode;
}

// TC 5
//================================
bool TC5 ()
{
  cout << "==TC5==begin==" << endl;
  string a = "{{}}{}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC5==end====" << endl;
  return retCode;
}

// TC 6
//================================
bool TC6 ()
{
  cout << "==TC6==begin==" << endl;
  string a = "{{}}{)}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC6==end====" << endl;
  return retCode;
}

// TC 7
//================================
bool TC7 ()
{
  cout << "==TC7==begin==" << endl;
  string a = "{{}}{}{";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC7==end====" << endl;
  return retCode;
}

// TC 8
//================================
bool TC8 ()
{
  cout << "==TC8==begin==" << endl;
  string a = "";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC8==end====" << endl;
  return retCode;
}

// TC 9
//================================
bool TC9 ()
{
  cout << "==TC9==begin==" << endl;
  string a = "{([{([])}])({[]})}";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC9==end====" << endl;
  return retCode;
}

// TC 10
//================================
bool TC10 ()
{
  cout << "==TC10==begin==" << endl;
  string a = "((((({{{{{[[[[[";
  cout << a << endl;
  bool retCode = validate_brackets(a);
  cout << "==TC10==end====" << endl;
  return retCode;
}

int main(void)
{
  if (TC1()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC2()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC3()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC4()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC5()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC6()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC7()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC8()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC9()) cout << "pass" << endl;
  else cout << "fail" << endl;
  if (TC10()) cout << "pass" << endl;
  else cout << "fail" << endl;
}