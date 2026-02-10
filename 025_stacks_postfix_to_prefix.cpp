



#include <iostream>
#include <bits/stdc++.h>
#define DEBUG

using namespace std;


string prefixToPostfix ()
{

}

string postfixToPrefix (string str)
{
  stack<char> st;
  string prefix = "";

  for (int i = 0; i < str.size(); ++i)
  {
    st.push(str[i]);
  }

  while (!st.empty())
  {
    prefix += st.top();
    st.pop();
  }

  return prefix;
}

bool getPrecedence (char optr)
{
  if (optr == '^') return 3;
  else if (optr == '*' || optr == '/') return 2;
  else if (optr == '+' || optr == '-') return 1;
}

bool isRightAssociative (char optr)
{
  if (optr == '^') return 1;
  return 0;
}

string infixToPostfix (string str)
{
  stack<char> st;
  int i = 0;
  string postfix = "";

  while (str[i])
  {
    #ifdef DEBUG
    cout << "while start | str[i]: " << str[i] << " i: " << i << endl;
    #endif
    // if operand, push to postfix
    if ((str[i] > 47 && str[i] < 58) || // digits
        (str[i] > 64 && str[i] < 91) || // alpha upper
        (str[i] > 96 && str[i] < 123)    // alpha lower
    )
    {
      postfix += str[i];
      ++i;
      continue; // process next feed
    }

    // if parenthesis
    if (str[i] == '(')
    {
    #ifdef DEBUG
    cout << "open paren | str[i]: " << str[i] << " i: " << i << endl;
    #endif
      // append
      postfix += str[i];
      ++i;
      continue;
    }
    else if (str[i] == ')')
    {
    #ifdef DEBUG
    cout << "close paren | str[i]: " << str[i] << " i: " << i << endl;
    #endif
      // pop and append all until '(' and discard both parenthesis
      while (st.top() != '(')
      {
        postfix += st.top();
        st.pop();
    #ifdef DEBUG
    cout << "postfix | postfix: " << postfix << endl;
    #endif
      }
      ++i;
      continue;
    }

    // if operator
    if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '^')
    {
    #ifdef DEBUG
    cout << "operator | str[i]: " << str[i] << " i: " << i << endl;
    #endif
      // check if higher precedence exists in stack
      while (!st.empty() && (getPrecedence(st.top()) > getPrecedence(str[i]) || 
              (getPrecedence(st.top()) == getPrecedence(str[i]) && !isRightAssociative(str[i]))))
      {
        // append higher precedence operator and pop
        postfix += st.top();
        st.pop();
    #ifdef DEBUG
    cout << "postfix | postfix: " << postfix << endl;
    #endif
      }
      // else push to stack
      st.push(str[i]);
      ++i;
    #ifdef DEBUG
    cout << "operator stack push" << endl;
    #endif
    }
  }

  // empty the stack
  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

string infixToPrefix ()
{

}

string prefixToInfix ()
{

}

string postfixToInfix ()
{

}


// TC 1
//===================
void TC1 ()
{
  string str = "2+5^5^5-1";
  cout << "==TC1==begin=============" << endl;
  cout << str << endl;
  cout << infixToPostfix(str) << endl;
  cout << "==TC1==end===============" << endl;
}

int main(void)
{
  TC1();

  return 1;
}