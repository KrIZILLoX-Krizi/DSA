




#include<bits/stdc++.h>

using namespace std;

class Solution
{
  public:
  void DFS(int i, vector<int> adjList[], int visited[])
  {
    visited[i] = 1;
    for(auto it : adjList[i])
    {
      if(!visited[it])
      {
        DFS(it, adjList, visited);
      }
    }
  }

  int connectedComponents(int V, vector<vector<int>> edges)
  {
    int count = 0;

    // populate adjacency list
    vector<int> adjList[V];
    for(int i = 0; i < edges.size(); ++i)
    {
      adjList[edges[i][0]].push_back(edges[i][1]);
      adjList[edges[i][1]].push_back(edges[i][0]);
    }
    int visited[V] = {0};

    for(int i = 0; i < V; ++i)
    {
      if(!visited[i])
      {
        ++count;
        DFS(i, adjList, visited);
      }
    }

    return count;
  }
};

int main(void)
{
  int V = 10;

  vector<vector<int>> edges = {
    {0, 1},
    {2, 3},
    {3, 4},
    {6, 7},
    {6, 9},
    {7, 9},
    {7, 8}
  };

  Solution sol;
  cout << sol.connectedComponents(V, edges) << endl;
}