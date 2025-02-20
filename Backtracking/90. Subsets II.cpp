//
// Created by Suhas Reddy on 2/19/25.
//

// Sort and make sure to not recurse through duplicates
// O(2^n) time complexity and O(n) space complexity.

class Solution
{
  public:
  void helper(vector<int>&nums, vector<int>&curr_result, int curr_index, vector<vector<int>>& result)
  {
    //second way
    result.push_back(curr_result);

    for(int idx = curr_index; idx<nums.size(); idx++)
    {
      if(idx>curr_index && nums[idx]==nums[idx-1])
        continue;

      curr_result.push_back(nums[idx]);
      helper(nums, curr_result, idx+1, result);
      curr_result.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());
    vector<int>list;
    helper(nums,list, 0, result);
    return result;

  }
};
