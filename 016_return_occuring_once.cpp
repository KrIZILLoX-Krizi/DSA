



#include<bits/stdc++.h>

using namespace std;

int occuringOnce(vector<int> nums)
{
  int res = 0;
  for(auto it : nums)
  {
    res ^= it;
  }

  return res;
}

// return singly occuring integer
// others exist twice
int main()
{
  vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};

  cout << occuringOnce(nums);

  return 0;
}