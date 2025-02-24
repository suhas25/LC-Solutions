//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * i -> min_value
 * j -> stk.top()
 * k -> curr running value in loop
 * */

class Solution {
public:
  bool find132pattern(vector<int>& nums)
  {
    //pair {num->min value}
    stack<pair<int, int>>stk;
    int min_value=nums[0];

    //try to put j in stack, min for i and compare values for k
    for(int i=1; i<nums.size(); i++)
    {
      while(!stk.empty() && stk.top().first<nums[i])
      {
        stk.pop();
      }

      if(!stk.empty() && stk.top().first>nums[i] && stk.top().second<nums[i])
        return true;

      stk.push({nums[i], min_value});
      //update min value for next iteration
      min_value = min(min_value, nums[i]);
    }

    return false;
  }
};