//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int maxSubArray(vector<int>& nums)
  {
    int result=nums[0];
    int curr_max=nums[0];

    for(int i=1;i<nums.size(); i++)
    {
      curr_max = max(curr_max+nums[i], nums[i]);
      result = max(result, curr_max);
    }

    return result;
  }
};