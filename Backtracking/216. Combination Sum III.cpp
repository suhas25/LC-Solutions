//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
  public:
  vector<vector<int>> result;

  void helper(vector<int>& list, int k, int n, int curr_index)
  {
    //base case
    if(list.size()==k && n==0)
      result.push_back(list);

    if(list.size()>k)
      return ;

    for(int i=curr_index; i<10; i++)
    {
      list.push_back(i);
      helper(list, k, n-i, i+1);
      list.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int>list;
    helper(list, k, n, 1);

    return result;
  }
};
