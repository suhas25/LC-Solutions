//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
public:
  TreeNode* sufficientSubset(TreeNode* root, int limit)
  {
    //leaf node
    if (root->left == nullptr &&  root->right==nullptr)
      return root->val < limit ? NULL : root;

    if (root->left)
      root->left = sufficientSubset(root->left, limit - root->val);

    if (root->right)
      root->right = sufficientSubset(root->right, limit - root->val);

    return root->left == root->right? nullptr : root;
  }
};