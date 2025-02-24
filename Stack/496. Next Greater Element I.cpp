//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * Iterate through and keep track of next greater elements for every element
 * */

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
  {
    stack<int>stk;

    //{value ->nextGreaterElement}
    unordered_map<int, int>mapping;

    for(int i=0;i<nums2.size(); i++)
    {
      while(!stk.empty() && stk.top()<nums2[i])
      {
        auto ele = stk.top(); stk.pop();
        mapping[ele]=nums2[i];
      }

      stk.push(nums2[i]);
    }

    //no next greater element exists for this elements
    while(!stk.empty())
    {
      auto ele = stk.top(); stk.pop();
      mapping[ele]=-1;
    }

    vector<int>result;
    for(auto ele:nums1)
    {
      result.push_back(mapping[ele]);
    }

    return result;
  }
};
