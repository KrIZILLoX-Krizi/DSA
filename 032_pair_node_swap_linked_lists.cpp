



#include <iostream>

using namespace std;



class Node
{
public:
  int data = 0;
  Node* next = nullptr;
  Node (int data) { this->data = data; }
};

void swapNodes (Node* node)
{
  int temp = node->data;
  node->data = node->next->data;
  node->next->data = temp;
}

void swapEveryOther (Node* node)
{
  // termination condition
  if (!node || !node->next)
  {
    cout << "node is NULL" << endl;
    return;
  }

  // process
  cout << "processing node: " << node->data << endl;
  swapNodes(node);

  // further calls
  swapEveryOther (node->next->next);
}

void printList (Node* head)
{
  Node* temp = head;

  cout << "printing list: ";
  while (temp)
  {
    if (temp->next)
      cout << temp->data << "->";
    else
      cout << temp->data << endl;

    temp = temp->next;
  }
}


bool TC1()
{
  Node* head;
  Node* first = new Node (1);
  Node* second = new Node (2);
  Node* third = new Node (3);
  Node* fourth = new Node (4);
  Node* fifth = new Node (5);
  Node* sixth = new Node (6);
  Node* seventh = new Node (7);

  head = first;
  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = seventh;

  swapEveryOther (head);
  printList (head);

  delete first, second, third, fourth, fifth, sixth, seventh;
}

int main (void)
{
  TC1();
}