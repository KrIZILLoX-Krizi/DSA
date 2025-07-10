



#include <bits/stdc++.h>

using namespace std;


struct Node
{
  Node* alphabets[26] = {nullptr};
  bool flag = false;

  // method to check if the char is already in trie
  bool containsKey(char ch)
  {
    return alphabets[ch - 'a'];
  }
  
  // method to put a new char in node
  void put(char ch, Node* node)
  {
    alphabets[ch - 'a'] = node;
  }

  // method to get reference of char
  Node* get(char ch)
  {
    return alphabets[ch - 'a'];
  }

  // method to set end at last reference
  void setEnd()
  {
    flag = true;
  }

  // method to return if end trie node
  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
  public:
  Trie()
  {
    root = new Node();
  }

  // method to insert a new trie node
  void insert(string word)
  {
    // create reference
    Node* node = root;

    // loop over alphabets in the word
    for(char alpha : word)
    {
      // if alphabet reference does not exist
      if(!(node->containsKey(alpha)))
      {
        node->put(alpha, new Node());
      }
      // move reference
      node = node->get(alpha);
    }

    // set end to this trie path
    node->setEnd();
  }

  // method to search a trie
  bool search(string word)
  {
    Node* node = root;

    // traverse through the word
    for(char alpha : word)
    {
      if(!(node->containsKey(alpha)))
      {
        return false;
      }
      node = node->get(alpha);
    }

    return node->isEnd();
  }

  // method to check if trie path exists
  // which has word as a prefix
  bool startsWith(string word)
  {
    Node* node = root;

    // traverse through word and trie path
    for(char alpha : word)
    {
      // check if alpha exists in trie
      if(!(node->containsKey(alpha)))
      {
        return false;
      }

      // if exists
      node = node->get(alpha);
    }

    // word path is traversed
    // hence atleast word is present
    // return true
    return true;
  }

  private:
  Node* root;
};

int main(void)
{
  Trie* obj = new Trie();
  obj->insert("hello");
  cout << obj->search("hello") << endl;
  cout << obj->startsWith("hel") << endl;
  cout << obj->search("hel") << endl;
  cout << obj->startsWith("leo") << endl;

  return 0;
}