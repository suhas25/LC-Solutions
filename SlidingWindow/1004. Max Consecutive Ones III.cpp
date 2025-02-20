//
// Created by Suhas Reddy on 2/19/25.
//


class Solution
{
  public:

  int longestOnes(vector<int>& nums, int k)
  {

    int left=0, right=0;

    int res=0;

    while(right<nums.size())
    {
      if(nums[right]==0)
        k--;

      if(k<0)
      {
        if(nums[left]==0)
          k++;

        //making sure window size is same here moving both left and right
        left++;
        right++;
        continue;
      }
      else
        res = max(res, right-left+1);

      right++;
    }
    return res;
  }
};