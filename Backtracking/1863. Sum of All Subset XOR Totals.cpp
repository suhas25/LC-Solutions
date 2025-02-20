//
// Created by Suhas Reddy on 2/19/25.
//

// Generating all subsets using pick/no pick and calculate xor.
// O(2^n) time complexity and O(n) space complexity.

class Solution
{
public:
  int helper(vector<int>&nums, int index, int current_xor)
  {
    if(index==nums.size())
      return current_xor;

    int pick_val=helper(nums, index+1, current_xor^nums[index]);
    int non_pick_val = helper(nums, index+1, current_xor);

    return pick_val+non_pick_val;
  }

  int subsetXORSum(vector<int>& nums)
  {
    return helper(nums, 0, 0);
  }
};

class Solution2 {
public:
  int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for(int i = 1; i < (1 << n); i++) {
      int curr_total = 0;
      for(int j = 0; j < n; j++) {
        if(i & (1 << j)) curr_total ^= nums[j];
      }
      total += curr_total;
    }
    return total;
  }
};