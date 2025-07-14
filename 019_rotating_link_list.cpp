



#include<bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node* next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

int createNode(Node* head, int m_data)
{
  int size = 0;
  Node* temp = head;

  Node* new_node = new Node(m_data);
  new_node->data = m_data;
  new_node->next = NULL;

  if(!head)
  {
    head = new_node;
    cout << "adding head" << endl;
    return 1;
  }

  while(temp->next)
  {
    ++size;
    temp = temp->next;
  }
  temp->next = new_node;
  cout << "new data: " << new_node->data << endl;

  return size;
}

void showList(Node* head)
{
  Node* temp = head;
  while(temp)
  {
    cout << head->data << " ";
    temp = temp->next;
  }

  cout << endl;

  return;
}


int main()
{
  Node* head = NULL;
  cout << createNode(head, 1) << endl;
  cout << createNode(head, 2) << endl;
  cout << createNode(head, 3) << endl;
  cout << createNode(head, 4) << endl;
  showList(head);

  return 0;
}