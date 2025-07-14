



#include<bits/stdc++.h>

using namespace std;

int minCost(vector<int> cost, int i, vector<int>& dp)
{
  for(auto it : dp)
  {
    cout << it << " ";
  }
  cout << endl;
  int right, left;
  right = INT_MAX;
  if(i == 0) return 0;
  if(dp[i] != -1) return dp[i];
  left = minCost(cost, i-1, dp) + abs(cost[i] - cost[i-1]);
  if(i > 1)
    right = minCost(cost, i-2, dp) + abs(cost[i] - cost[i-2]);
  return dp[i] = min(left, right);
}

int findMinCost(vector<int> cost)
{
  vector<int> dp(cost.size()+1, -1);
  return minCost(cost, cost.size()-1, dp);
}

// can jump one step or two steps at a time
// find min cost to reach n from 1
// array contains costs for each step
int main()
{
  vector<int> cost = {10, 20, 30, 10};

  cout << findMinCost(cost);
  
  return 0;
}