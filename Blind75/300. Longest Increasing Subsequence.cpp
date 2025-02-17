//
// Created by Suhas Reddy on 2/16/25.
//

//DP - O(n^2 solution) and O(n) space complexity.
class Solution
{
public:
  int lengthOfLIS(vector<int>& nums)
  {
    vector<int>dp(nums.size(),1);

    for(int i=1;i<nums.size(); i++)
    {
      for(int j=0;j<i; j++)
      {
        if(nums[i]>nums[j])
          dp[i]=max(dp[i], 1+dp[j]);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

