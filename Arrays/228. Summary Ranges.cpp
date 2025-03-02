//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums)
  {
    vector<string>result;

    for(int i=0;i<nums.size(); i++)
    {
      int start = nums[i];

      while(i+1<nums.size() && nums[i+1]==nums[i]+1)
        i++;

      // i points to a different index when it goes into while loop
      if(start!=nums[i])
        result.push_back(to_string(start) + "->"+ to_string(nums[i]));
      else // when there is no next number in sequence
        result.push_back(to_string(start));
    }

    return result;
  }
};
