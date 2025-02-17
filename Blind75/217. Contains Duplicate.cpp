//
// Created by Suhas Reddy on 2/14/25.
//
class Solution {
public:
  bool containsDuplicate(vector<int>& nums)
  {
    unordered_set<int>m;

    for(auto num:nums){
      if(m.find(num)!=m.end())
        return true;
      m.insert(num);
    }

    return false;
  }
};