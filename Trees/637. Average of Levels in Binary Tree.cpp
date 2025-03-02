//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root)
  {
    vector<double> result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
      long temp=0;
      int s=q.size();
      for(int i=0;i<s;i++)
      {
        auto curr=q.front(); q.pop();

        if(curr->left!=nullptr)
          q.push(curr->left);
        if(curr->right!=nullptr)
          q.push(curr->right);
        temp+=curr->val;
      }
      result.push_back((double)temp/s);
    }
    return result;
  }
};
