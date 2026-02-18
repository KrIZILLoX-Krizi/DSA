



class Node
{
public:
  int data = 0;
  Node* next = nullptr;
  Node (int data) { this->data = data; }
};

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool findLoop (Node* head)
{
  unordered_set<Node*> m_set;

  Node* temp = head;
  bool found = false;

  while (temp)
  {
    if (m_set.find(temp) != m_set.end())
    {
      found = true;
      break;
    }
    else 
    {
      m_set.insert(temp);
    }
    temp = temp->next;
  }

  // TC: O(n)
  // SC: O(n)
  return found;
}

bool findLoopFloyd (Node* head)
{
  Node* temp = head;
  Node* fast = temp;

  while (temp && fast && fast->next)
  {
    temp = temp->next;
    fast = fast->next->next;

    if (temp == fast) return true;
  }

  return false;
}

void TC1 ()
{
  Node* head;
  Node* first = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
  Node* sixth = new Node(6);
  head = first;
  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = third;

  cout << "loop present: " << findLoop(head) << endl;
  cout << "loop present (Floyd): " << findLoopFloyd(head) << endl;
}

int main (void)
{
  TC1();
}

