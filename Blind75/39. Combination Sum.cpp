//
// Created by Suhas Reddy on 2/14/25.
//

class Solution{
public:

  void helper(vector<int>&candidates, int target, int index, vector<vector<int>>&result, vector<int>curr)
  {
    if(target==0)
    {
      result.push_back(curr);
      return;
    }

    if(index>=candidates.size() || target<0)
      return;

    //take and stay on same index as infinite supply is provided
    curr.push_back(candidates[index]);
    helper(candidates, target-candidates[index], index, result,curr);
    curr.pop_back();

    //do not take and step to next index
    helper(candidates, target, index+1, result,curr);

  }

  vector<vector<int>> combinationSum(vector<int>&candidates, int target)
  {
    vector<vector<int>>result;

    //pass index
    helper(candidates, target, 0, result, {});

    return result;
  }
};
