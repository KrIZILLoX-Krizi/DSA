



#include <iostream>
#include <unordered_set>

using namespace std;

class Node
{
public:
  int data = 0;
  Node* next = nullptr;
  Node (int data) { this->data = data; }
};

int lengthOfLoop (Node* head)
{
  Node* temp = head;
  unordered_set<Node*> st;
  int len = 0;

  while (temp)
  {
    // if node not visited
    if (st.find(temp) != st.end())
    {
      return len;
    }

    st.insert (temp);
    temp = temp->next;
    ++len;
  }

  return 0;

  // TC: O(N)
  // SC: O(N) -> set
}

int countLoopLength (Node* node)
{
  Node* temp = node;
  int len = 0;

  while (temp->next != node)
  {
    temp = temp->next;
    ++len;
  }

  return len + 1;
}

int lengthOfLoopFloyd (Node* head)
{
  Node* slow = head;
  Node* fast = head;
  int len = 0;

  while (slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (fast == slow)
    {
      return countLoopLength (slow);
    }
  }

  return 0;
}

void TC1()
{
  Node* first = new Node (1);
  Node* second = new Node (2);
  Node* third = new Node (3);
  Node* fourth = new Node (4);
  Node* fifth = new Node (5);
  Node* sixth = new Node (6);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  cout << "len: " << lengthOfLoop (first) << endl;
  cout << "len: " << lengthOfLoopFloyd (first) << endl;

  delete first, second, third, fourth, fifth, sixth;
}

void TC2()
{
  Node* first = new Node (1);
  Node* second = new Node (2);
  Node* third = new Node (3);
  Node* fourth = new Node (4);
  Node* fifth = new Node (5);
  Node* sixth = new Node (6);

  first->next = second;
  second->next = first;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  cout << "len: " << lengthOfLoop (first) << endl;
  cout << "len: " << lengthOfLoopFloyd (first) << endl;

  delete first, second, third, fourth, fifth, sixth;
}

void TC3()
{
  Node* first = new Node (1);
  Node* second = new Node (2);
  Node* third = new Node (3);
  Node* fourth = new Node (4);
  Node* fifth = new Node (5);
  Node* sixth = new Node (6);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = first;

  cout << "len: " << lengthOfLoop (first) << endl;
  cout << "len: " << lengthOfLoopFloyd (first) << endl;

  delete first, second, third, fourth, fifth, sixth;
}

void TC4()
{
  Node* first = new Node (1);
  Node* second = new Node (2);
  Node* third = new Node (3);
  Node* fourth = new Node (4);
  Node* fifth = new Node (5);
  Node* sixth = new Node (6);

  first->next = first;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  cout << "len: " << lengthOfLoop (first) << endl;
  cout << "len: " << lengthOfLoopFloyd (first) << endl;

  delete first, second, third, fourth, fifth, sixth;
}

int main (void)
{
  TC1 ();
  TC2 ();
  TC3 ();
  TC4 ();

  return 1;
}