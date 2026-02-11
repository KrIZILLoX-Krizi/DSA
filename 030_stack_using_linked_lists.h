



#include <iostream>

using namespace std;



class Node
{
public:
  int iData = 0;
  Node* pNext = nullptr;

  Node (int data) { this->iData = data; this->pNext = nullptr;}
};




class Stack
{
public:
  void push (int data);
  void pop (void);
  bool empty (void);
  int sTop (void);


private:
  Node* pHead = nullptr;
  int top = -1;
  int size = 0;
};