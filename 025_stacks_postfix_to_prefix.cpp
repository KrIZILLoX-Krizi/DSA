



#include <iostream>
#include <bits/stdc++.h>
#define DEBUG

using namespace std;


string prefixToPostfix ()
{

}

int operateOver(int op2, int op1, char optr)
{
  if (optr == '*') return op1 * op2;
  if (optr == '-') return op1 - op2;
  if (optr == '+') return op1 + op2;
  if (optr == '/') return op1 / op2;
  if (optr == '^') return pow(op1, op2);
}

int resolvePostfix (string postfix)
{
  stack<int> st;

  for (int i = 0; i < postfix.size(); ++i)
  {
    // if operand, push to stack
    if (postfix[i] > 47 && postfix[i] < 58)
    {
    #ifdef DEBUG
    cout << "operand: " << postfix[i] << endl;
    #endif
      st.push(postfix[i] - 48);
      continue;
    }

    // if operator, pop stack 2 times and operate
    if (postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '^')
    {
      int operand1, operand2 = 0;

      operand1 = st.top();
      st.pop();
      operand2 = st.top();
      st.pop();

    #ifdef DEBUG
    cout << "op1: " << operand1 << " op2: " << operand2 << " optr: " << postfix[i] << endl;
    #endif

      // push intermediary res in stack
      st.push(operateOver(operand1, operand2, postfix[i]));
    #ifdef DEBUG
    cout << "top res: " << st.top() << endl;
    #endif
    }
  }

  return st.top();
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
  if (optr == '(') return 0;
  else if (optr == '^') return 3;
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
    #ifdef DEBUG
    cout << "append postfix | postfix: " << postfix << endl;
    #endif
      continue; // process next feed
    }

    // if parenthesis
    if (str[i] == '(')
    {
    #ifdef DEBUG
    cout << "open paren | str[i]: " << str[i] << " i: " << i << endl;
    #endif
      // push onto stack
      st.push(str[i]);
      ++i;
    #ifdef DEBUG
    cout << "stack top: " << st.top() << endl;
    cout << "postfix: " << postfix << endl;
    #endif
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
      // discard open paren
      st.pop();
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

// TC 2
//===================
void TC2 ()
{
  string str = "2+(3-4)";
  cout << "==TC2==begin=============" << endl;
  cout << str << endl;
  cout << infixToPostfix(str) << endl;
  cout << "==TC2==end===============" << endl;
}

// TC 3
//===================
void TC3 ()
{
  string str = "234-+";
  cout << "==TC3==begin=============" << endl;
  cout << str << endl;
  cout << resolvePostfix(str) << endl;
  cout << "==TC3==end===============" << endl;
}

// TC 4
//===================
void TC4 ()
{
  string str = "22^33^+42^-";
  cout << "==TC4==begin=============" << endl;
  cout << str << endl;
  cout << resolvePostfix(str) << endl;
  cout << "==TC4==end===============" << endl;
}

int main(void)
{
  TC3();
  TC4();

  return 1;
}
