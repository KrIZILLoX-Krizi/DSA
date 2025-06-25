



#include <bits/stdc++.h>
using namespace std;


class Solution
{
  public:

    int bad(vector<int>& nums)
    {
      int count = 0;
      for(int i = 0; i < nums.size(); ++i)
      {
        count = 1;
        for(int j = i+1; j < nums.size(); ++j)
        {
          if(nums[j] == nums[i]) ++count;
        }

        if(count > nums.size()/2) return nums[i];
      }
      return -1;
    }

    int better(vector<int>& nums)
    {
      map<int, int> m_map;
      for(int num : nums)
      {
        if(m_map.find(num) != m_map.end())
        {
          ++m_map[num];
        }
        else
        {
          m_map[num] = 1;
        }
      }

      for(pair<int, int> pair : m_map)
      {
        if(pair.second > nums.size()/2) return pair.first;
      }

      return -1;
    }

    int optimal(vector<int>& nums)
    {
      // code here
      int count = 0;
      int element = -1;
      for(int num : nums)
      {
        if(count == 0) element = num;
        count += (num == element) ? 1 : -1;
      }
      count = 0;
      // count occurance
      for(int num : nums)
      {
        if(num == element) ++count;
      }
      // check if majority ( > n/2)
      if(count > nums.size()/2) return element;
      return -1;
    }


    int majorityElement(vector<int>& nums) 
    {
      // bad(nums);
      better(nums);
      // optimal(nums);
    }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 2, 3, 4, 5, 2, 2, 2};
  cout << sol.majorityElement(nums) << endl; // Output: 2
}