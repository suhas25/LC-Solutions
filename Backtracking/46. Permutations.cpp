//
// Created by Suhas Reddy on 2/19/25.
//
/*
 *
 * Logic similar to finding all subsets.
 * Catch here is to add to list when the list size matches (as we need to include every character).
 * Track this by maintaing visited set or array( if it contains duplicates)
 * Update list and visited when traversing back
 * O(n!) combinations generated.
 */
class Solution {
public:
  vector<vector<int>> result;

  void helper(vector<int>& nums, vector<int>& list, vector<int>& vis)
  {
    //base case
    if(list.size()==nums.size())
    {
      result.push_back(list);
      return;
    }

    for(int idx=0; idx<nums.size(); idx++)
    {
      if(vis[idx]==1)
        continue;

      vis[idx]=1;
      list.push_back(nums[idx]);
      helper(nums,list, vis);

      //backtrack by popping them.
      list.pop_back();
      vis[idx]=-1;
    }
  }

  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<int>list;
    vector<int>vis(nums.size(),-1);

    helper(nums,list, vis);
    return result;
  }
};


// Approach using swaps (no need of visited array/set here).

class Solution2
{
  public:
  vector<vector<int>> result;

  void helper(vector<int>& list, int index)
  {
    //base case
    if(index>=list.size())
    {
      result.push_back(list);
      return;
    }

    for(int idx = index; idx<list.size(); idx++)
    {
      swap(list[index], list[idx]);
      helper(list, index+1);
      swap(list[index], list[idx]);
    }
  }

  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<int>list(nums);
    helper(list, 0);
    return result;
  }
};
