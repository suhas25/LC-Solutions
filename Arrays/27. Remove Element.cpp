//
// Created by Suhas Reddy on 3/2/25.
//

class Solution {
public:
  int removeElement(vector<int>& nums, int val)
  {
    int j=0;

    for(int i=0;i<nums.size(); i++)
    {
      if(nums[i]!=val)
        nums[j++]=nums[i];
    }
    return j;
  }
};