//
// Created by Suhas Reddy on 2/17/25.
//

// Find sum of left and right subtree recursively and add it to root node similar to height.
class Solution {
public:
  int totalsum = 0;

  int subtree_sum(TreeNode* node)
  {
    if(node == nullptr)
      return 0;

    int lh_sum = subtree_sum(node->left);
    int rh_sum = subtree_sum(node->right);

    totalsum += abs(lh_sum-rh_sum);

    return lh_sum+rh_sum+node->val;
  }

  int findTilt(TreeNode* root)
  {
    int val = subtree_sum(root);
    return totalsum;
  }
};