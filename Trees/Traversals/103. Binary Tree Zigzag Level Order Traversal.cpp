//
// Created by Suhas Reddy on 2/17/25.
//


class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
  {
    vector<vector<int>>result;
    int r2l = 0;

    if(root == nullptr)
      return result;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
      vector<int>res;
      int sizee= q.size();
      std::cout<<q.size()<<std::endl;
      for(int i=0;i<sizee; i++)
      {
        TreeNode* currnode = q.front();
        q.pop();
        res.push_back(currnode->val);

        if (currnode->left != nullptr)
          q.push(currnode->left);
        if (currnode->right != nullptr)
          q.push(currnode->right);
      }
      if(r2l)
      {
        reverse(res.begin(), res.end());
      }
      result.push_back(res);
      //res.clear();
      r2l = 1-r2l;
    }
    return result;
  }
};