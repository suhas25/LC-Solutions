//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int missingNumber(vector<int>& nums)
  {
    // every number is repeated twice here because of index i except the missing one
    int res = nums.size();
    for(int i=0; i<nums.size(); i++)
    {
      res ^= i^nums[i];
    }
    return res;
  }
};