//
// Created by Suhas Reddy on 2/19/25.
//

//keep track of min and max nodes in path from root->leaf. Calculate result once we reach null node.

class Solution {
public:

  int helper(TreeNode* root, int max_val, int min_val)
  {
    if(root==nullptr)
      return max_val-min_val;

    max_val = max(max_val, root->val);
    min_val = min(min_val, root->val);

    int left = helper(root->left, max_val, min_val);
    int right = helper(root->right, max_val, min_val);

    return max(right, left);
  }
  int maxAncestorDiff(TreeNode* root)
  {
    if(root==nullptr)
      return 0;

    return helper(root, root->val, root->val);
  }
};
