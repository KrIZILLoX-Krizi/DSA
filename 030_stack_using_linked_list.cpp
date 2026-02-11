



#include "030_stack_using_linked_lists.h"
#define DEBUG

void Stack::push (int data)
{
  #ifdef DEBUG
  cout << "push " << data << endl;
  #endif
  Node* newNode = new Node (data);

  if (!this->pHead)
  { 
    #ifdef DEBUG
    cout << "Empty stack. Adding to head." << endl;
    cout << "pushed " << data << endl;
    #endif
    pHead = newNode;
    this->top++;
    this->size++;
    return;
  }

  Node* pTemp = this->pHead;
  Node* pHolder = nullptr;

  while (pTemp)
  {
    pHolder = pTemp;
    pTemp = pTemp->pNext;
  }

  pHolder->pNext = newNode;
  #ifdef DEBUG
  cout << "pushed " << data << endl;
  #endif
  this->top++;
  this->size++;
}

void Stack::pop (void)
{
  #ifdef DEBUG
  cout << "pop" << endl;
  #endif
  if (!this->pHead) 
  {
    #ifdef DEBUG
    cout << "pop | Stack empty. Operation denied." << endl;
    #endif
    this->top = -1;
    this->size = 0;
    return;
  }

  Node* pTemp = this->pHead;
  Node* pHolder = nullptr;

  // single node
  if (!pTemp->pNext)
  {
    #ifdef DEBUG
    cout << "pop | single node popped " << pTemp->iData << endl;
    #endif
    delete pTemp;
    pTemp = nullptr;
    this->pHead = nullptr;
    this->top = -1;
    this->size = 0;
    return;
  }

  while (pTemp->pNext)
  {
    #ifdef DEBUG
    cout << "pop | traveling data " << pTemp->iData << endl;
    #endif
    pHolder = pTemp;
    pTemp = pTemp->pNext;
  }

  #ifdef DEBUG
  cout << "popped " << pTemp->iData << endl;
  #endif
  delete pTemp;
  pHolder->pNext = nullptr;
  --this->top;
  --this->size;
}

int Stack::sTop (void)
{
  #ifdef DEBUG
  cout << "top" << endl;
  #endif
  if (this->top < 0 || !this->pHead)
  {
    #ifdef DEBUG
    cout << "sTop | Stack empty. Operation denied." << endl;
    #endif
    this->size = 0;
    this->top = -1;
    return -1;
  }

  Node* pTemp = this->pHead;
  Node* pHolder = nullptr;

  while (pTemp)
  {
    pHolder = pTemp;
    pTemp = pTemp->pNext;
  }

  #ifdef DEBUG
  cout << "top " << pHolder->iData << endl;
  #endif
  return pHolder->iData;
}

bool Stack::empty (void)
{
  #ifdef DEBUG
  cout << "empty ";
  #endif

  if (this->top == -1 || !this->pHead)
  {
    #ifdef DEBUG
    cout << "1" << endl;
    #endif
    return true;
  }

  #ifdef DEBUG
  cout << "0" << endl;
  #endif
  return false;
}


int main (void)
{
  Stack st;

  st.pop();
  st.sTop();
  st.empty();
  st.push(1);
  st.sTop();
  st.empty();
  st.pop();
  st.pop();
  st.empty();
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.sTop();
  st.empty();
  st.pop();
  st.sTop();
  st.empty();
  st.pop();
  st.sTop();
  st.empty();
  st.pop();
  st.sTop();
  st.empty();
  st.pop();
  st.sTop();
  st.empty();
  st.pop();
  st.sTop();
  st.empty();

  return 0;
}