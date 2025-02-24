//
// Created by Suhas Reddy on 2/22/25.
//

class Solution {
public:
  int triangularSum(vector<int>& nums)
  {
    int result=0;
    int size = nums.size();

    while(size>1)
    {
      for(int i=0;i<size-1;i++)
        nums[i]= (nums[i]+nums[i+1])%10;

      size--;
    }
    return nums[0];
  }
};
