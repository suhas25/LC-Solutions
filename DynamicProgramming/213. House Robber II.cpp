//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int rob(vector<int>& nums)
  {
    if (nums.size() == 0) return 0;
    
    if (nums.size() == 1) return nums[0];

    int max1 = rob_simple(nums, 0, nums.size() - 2);
    int max2 = rob_simple(nums, 1, nums.size() - 1);

    return max(max1, max2);
  }

private:
  int rob_simple(vector<int>& nums, int start, int end)
  {
    int prev2 = 0, prev1 = 0, result=0;
    for (int i = start; i <= end; ++i)
    {
      result = max(prev2+nums[i], prev1);
      prev2=prev1;
      prev1 =result;
    }

    return result;
  }
};