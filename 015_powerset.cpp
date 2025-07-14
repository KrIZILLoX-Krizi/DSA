



#include<bits/stdc++.h>

using namespace std;


void countPowerSet(vector<int> nums)
{
  int subsets = (1 << nums.size())-1;
  vector<string> subset;
  for(int i = 1; i <= subsets; ++i)
  {
    string subs = "";
    for(int j = 0; j < nums.size(); ++j)
    {
      if(i & (1 << j))
      {
        subs += to_string(nums[j]);
      }
    }

    subset.push_back(subs);
  }

  for(auto it : subset)
  {
    cout << it << endl;
  }
}


int main()
{
  vector<int> nums = {1,2,3,4,5,6,7,8,9};


  countPowerSet(nums);


  return 0;
}