#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool brute(vector<int>& nums, int target)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(i == j) continue;
                if(nums[i] + nums[j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool better(vector<int>& nums, int target)
    {
        map<int, int> m_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            int m_need = target - nums[i];
            if(m_map.find(m_need) != m_map.end())
            {
                return true;
            }
            m_map[nums[i]] = i;
        }
        return false;
    }
    
    bool optimal2Pointer(vector<int> nums, int target)
    {
        int left_pointer = 0;
        int right_pointer = nums.size()-1;
        
        sort(nums.begin(), nums.end());
        
        while(left_pointer != right_pointer)
        {
            if(nums[left_pointer] + nums[right_pointer] == target) return true;
            else if(nums[left_pointer] + nums[right_pointer] < target) ++left_pointer;
            else if(nums[left_pointer] + nums[right_pointer] > target) --right_pointer;
        }
        
        return false;
    }
    
    bool twoSum(vector<int>& arr, int target) {
        // code here
        // return brute(arr, target);
        // return better(arr, target);
        return optimal2Pointer(arr, target);
    }
};


int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  Solution sol;
  cout << sol.brute(nums, 100);
}