//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int rob(vector<int>& nums)
  {
    int size = nums.size();

    if(size==1)
      return nums[0];

    vector<int> dp(size, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < size; i++)
    {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[size - 1];
  }
};

class Solution2
{
  public:
    int rob(vector<int>& nums)
    {
      int size = nums.size();

      if(size==1)
        return nums[0];

      int prev2=0,prev1=0;

      int result=0;

      for(int num:nums)
      {
        result = max(prev2+num, prev1);
        prev2 = prev1;
        prev1 = result;
      }
      return result;
    }
};