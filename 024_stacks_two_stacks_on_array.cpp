



#include <iostream>
#include "03_stacks_two_stacks_on_array.h"




// left stack top must be less than stack size and
// also less than stack 2 top
// both tops should neither overlap nor cross over
bool TwoStacks::checkOverflow ()
{
  if (this->i_top1 < this->i_top2 && 
      this->i_top1 < MAX_STACK_SIZE && 
      this->i_top2 > MIN_STACK_SIZE
  ) 
  {
    return false;
  }
  #ifdef TEST_DEBUG
  cout << "stack overflow " << this->i_top1 << endl;
  #endif
  return true;
}

/*
   | 1 2 3 |
t1           t2
*/
bool TwoStacks::checkUnderflow ()
{
  if (this->i_top2 > this->i_top1 && 
      this->i_top2 <= MAX_STACK_SIZE && 
      this->i_top1 >= MIN_STACK_SIZE
  ) 
  {
    return false;
  }
  #ifdef TEST_DEBUG
  cout << "stack underflow " << this->i_top1 << endl;
  #endif
  return true;
}

void TwoStacks::push1 (int a)
{
  // check if top is valid
  this->i_top1++;
  #ifdef TEST_DEBUG
  cout << "i_top1 before" << this->i_top1 << endl;
  #endif
  if (this->checkOverflow())
  {
    this->i_top1--;
    cout << "Error: Push failed. Stack 1 overflow." << endl;
    #ifdef TEST_DEBUG
    cout << "i_top1 after" << this->i_top1 << endl;
    #endif
    return;
  }
  #ifdef TEST_DEBUG
  cout << "i_top1 after" << this->i_top1 << endl;
  #endif
  stack[this->i_top1] = a;
}

void TwoStacks::push2 (int a)
{
  this->i_top2--;
  if (this->checkOverflow())
  {
    this->i_top2++;
    cout << "Error: Push failed. Stack 2 overflow." << endl;
    return;
  }
  stack[this->i_top2] = a;
}

int TwoStacks::pop1 ()
{
  int a = this->stack[this->i_top1];
  #ifdef TEST_DEBUG
  cout << "i_top1 " << this->i_top1 << endl;
  #endif
  this->i_top1--;
  #ifdef TEST_DEBUG
  cout << "this->i_top1 " << this->i_top1 << endl;
  #endif
  if (this->checkUnderflow())
  {
    this->i_top1++;
    cout << "Error: Pop failed. Stack 1 underflow." << endl;
    return -1;
  }
  return a;
}

int TwoStacks::pop2 ()
{
  int a = this->stack[this->i_top2];
  this->i_top2++;
  if (this->checkUnderflow())
  {
    this->i_top2--;
    cout << "Error: Pop failed. Stack 2 underflow." << endl;
    return -1;
  }
  return a;
}

bool TwoStacks::empty1 ()
{
  if (this->i_top1 == MIN_STACK_SIZE) return true;
  return false;
}

bool TwoStacks::empty2 ()
{
  if (this->i_top2 == MAX_STACK_SIZE) return true;
  return false;

}

int TwoStacks::top1 ()
{
  if (!this->empty1())
  {
    return this->stack[this->i_top1];
  }

  cout << "Error: Empty stack accessed." << endl;
  return -1;
}

int TwoStacks::top2 ()
{
  if (!this->empty2())
  {
    return this->stack[this->i_top2];
  }

  cout << "Error: Empty stack accessed." << endl;
  return -1;
}

int main(void)
{
  TC1();
  TC2();
  TC3();

  return 1;
}