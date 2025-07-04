



#include<bits/stdc++.h>

using namespace std;

class Solution
{
  public:
  vector<int> DFS(int i, vector<int> adjList[], int visited[], vector<int>& dfs_res)
  {
    visited[i] = 1;
    dfs_res.push_back(i);
    
    for(auto it : adjList[i])
    {
      if(!visited[it])
      {
        DFS(it, adjList, visited, dfs_res);
      }
    }
  }

  vector<int> depthFirstSearch(int V, vector<vector<int>> edges)
  {
    vector<int> adjList[V];

    // populating adjacency list
    for(int i = 0; i < edges.size(); ++i)
    {
      adjList[edges[i][0]].push_back(edges[i][1]);
      adjList[edges[i][1]].push_back(edges[i][0]);
    }

    int visited[V] = {0};
    vector<int> dfs_res;
    for(int i = 0; i < V; ++i)
    {
      if(!visited[i])
      {
        DFS(i, adjList, visited, dfs_res);
      }
    }

    return dfs_res;
  }
};

int main(void)
{
  Solution sol;
  int V = 7;
  vector<vector<int>> edges = {
    {0, 1},
    {0, 3},
    {1, 2},
    {3, 2},
    {3, 4},
    {4, 5},
    {4, 6}
  };

  vector<vector<int>> edges2 = {
    {0, 2},
    {0, 1},
    {2, 5},
    {2, 3},
    {1, 6},
    {1, 4}
  };

  vector<int> res = sol.depthFirstSearch(V, edges2);
  for(auto it : res)
  {
    cout << it << " ";
  }
}