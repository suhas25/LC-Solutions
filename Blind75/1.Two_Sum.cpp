//
// Created by Suhas Reddy on 2/14/25.
//

class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
      int complement = target - nums[i];
      if (hash.find(complement) != hash.end())
      {
        return {hash[complement], i};
      }
      hash[nums[i]] = i;
    }
    // Return an empty vector if no solution is found
    return {};
  }
};