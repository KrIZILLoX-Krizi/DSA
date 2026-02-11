



#include <iostream>
#include "029_stack_using_arrays.h"

using namespace std;



void Stack::sPush (int data)
{
  cout << "push " << data << endl;
  if (this->top + 1 == this->capacity) { cout << "Stack overflow. Operation denied." << endl; return; }

  ++this->top;
  ++this->size;
  this->stack[this->top] = data;
  cout << "pushed " << data << endl;
}

void Stack::sPop (void)
{
  cout << "pop" << endl;
  if (this->top - 1 < -1) { cout << "Stack empty. Operation denied." << endl; return; }

  cout << "popping: " << this->stack[this->top] << endl;
  --this->top;
  --this->size;
}

int Stack::sTop (void)
{
  cout << "top" << endl;
  if (this->top < 0) { cout << "Empty stack. Operation denied." << endl; return -1; }
  return this->stack[this->top];
}

bool Stack::sEmpty (void)
{
  cout << "empty" << endl;
  if (this->top == -1) { return true; }
  return false;
}

int main (void)
{
  Stack st;

  st.sPop();
  st.sPush(1);
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPush(2);
  st.sPush(3);
  st.sPush(4);
  st.sPush(5);
  st.sPush(6);
  st.sPush(7);
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;
  st.sPop();
  cout << st.sTop() << endl;
  cout << st.sEmpty() << endl;

  return 1;
}