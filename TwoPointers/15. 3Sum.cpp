//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end()); // nlogn

    vector<vector<int>> result;

    for(int i=0;i<nums.size();i++)
    {
      if(i>=1 && nums[i]==nums[i-1]) // to eliminate duplicates in result
        continue;

      int curr = nums[i];

      int low = i+1;
      int high = nums.size()-1;

      while(low<high)
      {
        auto sum = curr+nums[low]+nums[high];

        if(sum==0)
        {
          result.push_back({curr, nums[low], nums[high]});

          low++;
          while(low<high && nums[low]==nums[low-1])
            low++;
        }

        else if(sum>0)
          high--;
        else
          low++;
      }

    }
    return result;
  }
};