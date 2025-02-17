//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
  }
};

class Solution2 {
public:

  int helper(TreeNode* node, int depth)
  {
    if(node==nullptr)
      return depth;
    return max(helper(node->left, depth+1), helper(node->right, depth+ 1));
  }
  int maxDepth(TreeNode* root)
  {
    if(root == nullptr)
      return 0;

    return max(helper(root->left, 1), helper(root->right, 1));
  }
};
