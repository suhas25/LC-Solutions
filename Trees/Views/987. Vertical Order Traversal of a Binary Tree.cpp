//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root)
  {
    // {vertical order -> {vector of values}}
    map<int, vector<int>> m;

    //node, vertical level
    queue<pair<TreeNode*, int>>q;

    vector<vector<int>>result;

    q.push({root, 0});

    while(!q.empty())
    {
      auto size = q.size();

      unordered_map<int, vector<int>> level_map;
      for(int i=0;i<size; i++)
      {
        auto [ele, col]= q.front();
        q.pop();

        level_map[col].push_back(ele->val);

        if(ele->left)
          q.push({ele->left, col-1});

        if(ele->right)
          q.push({ele->right, col+1});
      }

      //sort the values at each row for every column
      for(auto& [_, val]:level_map)
        sort(val.begin(), val.end());

      //now insert into map
      for(auto [col, val]:level_map)
      {
        for(auto v:val)
          m[col].push_back(v);
      }
    }

    for(auto [col, values]:m)
      result.push_back(values);

    return result;
  }
};
