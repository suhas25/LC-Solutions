//
// Created by Suhas Reddy on 2/19/25.
//
class Solution {
public:

  vector<vector<int>> result;

  void helper(vector<int>& candidates, int target, vector<int>list, int index)
  {
    //base case
    if(target==0)
      result.push_back(list);

    if(target<0)
      return;

    for(int idx = index; idx<candidates.size(); idx++)
    {
      // do not pick duplicates starting current index as it leads to recursion calls with same list passed.
      if(idx>index && candidates[idx]==candidates[idx-1])
        continue;

      list.push_back(candidates[idx]);
      helper(candidates, target-candidates[idx], list, idx+1);
      list.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, vector<int>(), 0);
    return result;
  }
};
