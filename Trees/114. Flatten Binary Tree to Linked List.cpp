//
// Created by Suhas Reddy on 3/5/25.
//

/*
 * Iterate through the tree keeping track of left and right tail to join them.
 * Assign nodes correctly when you encounter a left subtree. otherwise, they are
 * already in correct order.
 */
class Solution
{
public:

  TreeNode* dfs(TreeNode* root)
  {
    if(root==nullptr)
      return nullptr;

    if(root->left==nullptr &&root->right==nullptr)
      return root;

    TreeNode* left_tail = dfs(root->left);
    TreeNode* right_tail = dfs(root->right);

    if(left_tail!=nullptr)
    {
      left_tail->right=root->right;
      root->right=root->left;
      root->left=nullptr;
    }

    return (right_tail==nullptr)?left_tail:right_tail;
  }

  void flatten(TreeNode* root)
  {
    if(root==nullptr)
      return;

    dfs(root);
  }
};
