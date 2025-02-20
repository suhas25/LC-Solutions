//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
  public:
  vector<vector<int>> result;

  void helper(int n, int k, vector<int>&list, int index)
  {
    //base case
    if(list.size()==k)
    {
      result.push_back(list);
      return;
    }

    if(list.size()>k)
      return;

    for(int idx = index; idx<n; idx++)
    {
      list.push_back(idx);
      helper(n, k,list, idx+1);
      list.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k)
  {
    vector<int>list;
    helper(n+1, k, list, 1);

    return result;
  }
};
