



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    void printVector(vector<int> nums)
    {   
      for(int num : nums)
      {
        cout << num << " ";
      }
      cout << endl;
    }   
    
    void bad(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
    }

    void better(vector<int>& nums)
    {
        int count_1s = 0;
        int count_2s = 0;
        int count_0s = 0;

        for(int num : nums)
        {
            if(num == 1) ++count_1s;
            else if(num == 2) ++count_2s;
            else if(num == 0) ++count_0s;
        }

        int index = 0;
        for(; index < count_0s; ++index)
        {
            nums[index] = 0;
        }

        for(; index < count_0s + count_1s; ++index)
        {
            nums[index] = 1;
        }

        for(; index < count_0s + count_1s + count_2s; ++index)
        {
            nums[index] = 2;
        }
    }

    void better2(vector<int>& nums)
    {
      int count_1s = 0;
      int count_2s = 0;
      int count_0s = 0;
      for(int num : nums)
      {
        if(num == 1) ++count_1s;
        else if(num == 2) ++count_2s;
        else if(num == 0) ++count_0s;
      }

      nums.clear();
      for(int i = 0; i < count_0s; ++i)
      {
        nums.push_back(0);
      }

      for(int i = 0; i < count_1s; ++i)
      {
        nums.push_back(1);
      }

      for(int i = 0; i < count_2s; ++i)
      {
        nums.push_back(2);
      }
    }

    void m_swap(vector<int>& nums, int i_src, int i_des)
    {
      int temp = nums[i_src];
      nums[i_src] = nums[i_des];
      nums[i_des] = temp;
    }

    // dutch national flag algorithm
    // assume that the array has three sorted parts and one unsorted
    //
    // 0      low-1 low      mid-1 mid        high high+1  n-1
    // |   sorted  |   sorted     |  unsorted     |  sorted  |
    // |00000000000|11111111111111|110202010201222|2222222222|
    //
    // now four conditions to be assumed here
    // 0 - low-1, all are 0s
    // low to mid-1, all are 1s
    // high to n, all are 2s
    // mid to high-1 is the unsorted part to sort
    void best(vector<int>& nums)
    {
      // 0,1,2,2,1,0,0,0,0,1,1,2,2,2,2,2,2
      int low = 0, high = nums.size()-1;

      for(int mid = 0; mid < nums.size();)
      {
        cout << "mid: " << mid << endl;
        if(nums[mid] == 0)
        {
          m_swap(nums, low, mid);
          ++low;
          ++mid;
          printVector(nums);
          cout << "low: " << low << endl;
        }
        else if(nums[mid] == 1)
        {
          ++mid;
          printVector(nums);
          cout << "mid: " << mid << endl;
        }
        else if(nums[mid] == 2)
        {
          m_swap(nums, high, mid);
          --high;
          printVector(nums);
          cout << "hig: " << high << endl;
        }

        if(mid > high) break;
      }
    }

    void sortZeroOneTwo(vector<int>& nums) 
    {
        bad(nums);
        better(nums);
        best(nums);
    }
};

void printVector(vector<int> nums)
{   
  for(int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;
}   

int main()
{
  Solution sol;

  vector<int> nums = {1,0,2};
  // printVector(nums);
  // sol.bad(nums);
  // printVector(nums);

  // printVector(nums);
  // sol.better(nums);
  // printVector(nums);

  // printVector(nums);
  // sol.better2(nums);
  // printVector(nums);

  printVector(nums);
  sol.best(nums);
  printVector(nums);

  return 0;
}