//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
  public:
  int dfs(TreeNode* root, bool is_left)
  {
    int sum = 0;
    if(root==nullptr)
      return 0;

    if(root->left)
      sum+=dfs(root->left, true);

    if(root->right)
      sum+=dfs(root->right, false);

    if(root->left==nullptr && root->right==nullptr && is_left)
      sum+=root->val;

    return sum;
  }

  int sumOfLeftLeaves(TreeNode* root)
  {
    return dfs(root, false);
  }
};
