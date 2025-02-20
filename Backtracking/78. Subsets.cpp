//
// Created by Suhas Reddy on 2/19/25.
//

// O(2^n) time complexity and O(n) space complexity.

class Solution1
{
  public:

  void helper(vector<int>&nums, vector<int>&curr_result, int curr_index, vector<vector<int>>& result)
  {
    if(curr_index==nums.size())
    {
      result.push_back(curr_result);
      return;
    }

    //pick and move
    curr_result.push_back(nums[curr_index]);
    helper(nums, curr_result, curr_index+1, result);

    //do not pick and move
    curr_result.pop_back();
    helper(nums, curr_result, curr_index+1, result);
  }
  vector<vector<int>> subsets(vector<int>& nums)
  {
    vector<vector<int>> result;
    helper(nums,vector<int>(), 0, result);

    return result;
  }
};

class Solution2
{
public:

  void helper(vector<int>&nums, vector<int>curr_result, int curr_index, vector<vector<int>>& result)
  {
    //second way
    result.push_back(curr_result);

    for(int idx = curr_index; idx<nums.size(); idx++)
    {
      curr_result.push_back(nums[idx]);
      helper(nums, curr_result, idx+1, result);
      curr_result.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums)
  {
    vector<vector<int>> result;

    helper(nums,vector<int>(), 0, result);
    return result;

  }
};