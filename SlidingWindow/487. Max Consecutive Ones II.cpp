//
// Created by Suhas Reddy on 2/25/25.
//

//O(n) time and O(1) space complexity
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums)
  {
    int result = 0;

    int left=0, right=0;
    int num_zeroes=0;

    while(right<nums.size())
    {
      if(nums[right]==0)
        num_zeroes++;

      while(num_zeroes>1)
      {
        if(nums[left]==0)
          num_zeroes--;
        left++;
      }

      result = max(result, right-left+1);
      right++;
    }
    return result;
  }
};
