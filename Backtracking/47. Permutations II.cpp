//
// Created by Suhas Reddy on 2/19/25.
//

class Solution {
public:
  vector<vector<int>> result;

  void helper(vector<int>& nums, vector<int>&list, unordered_map<int, int>&m)
  {
    // base case
    if (list.size() == nums.size())
      result.push_back(list);

    for(auto [key, val]:m)
    {
      if(val==0) continue;

      list.push_back(key);
      --m[key];

      helper(nums, list, m);

      //backtracking
      list.pop_back();
      m[key]++;
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    //{mapping of integer ->count}
    unordered_map<int, int> map;
    for(auto num:nums)
      map[num]++;

    vector<int>list;
    helper(nums, list, map);
    return result;
  }
};