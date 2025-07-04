



#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
  void BFS(int i, vector<int> adjList[], int visited[], vector<int>& bfs_res)
  {
    queue<int> que;
    que.push(i);

    while(!que.empty())
    {
      int front = que.front();
      que.pop();
      bfs_res.push_back(front);

      for(auto it : adjList[front])
      {
        if(!visited[it])
        {
          visited[it] = 1;
          que.push(it);
        }
      }
    }

    return;
  }

  vector<int> breadthFirstSearch(int V, vector<vector<int>>& edges)
  {
    vector<int> adjList[V];

    // convert to adjacency list
    for(int i = 0; i < edges.size(); ++i)
    {
      adjList[edges[i][0]].push_back(edges[i][1]);
      adjList[edges[i][1]].push_back(edges[i][0]);
    }

    int visited[V] = {0};
    vector<int> bfs_res;

    //traverse nodes
    for(int i = 0; i < V; ++i)
    {
      if(!visited[i])
      {
        visited[i] = 1;
        BFS(i, adjList, visited, bfs_res);
      }
    }

    return bfs_res;
  }
};

int main(void)
{
  int V = 7;
  vector<vector<int>> edges;

  edges.push_back({0, 1});
  edges.push_back({0, 3});
  edges.push_back({3, 2});
  edges.push_back({3, 4});
  edges.push_back({4, 5});
  edges.push_back({4, 6});

  Solution solution;
  vector<int> sol = solution.breadthFirstSearch(V, edges);
  for(auto it : sol)
  {
    cout << it << " ";
  }


  return 0;
}