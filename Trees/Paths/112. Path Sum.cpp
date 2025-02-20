//
// Created by Suhas Reddy on 2/17/25.
//
 //O(n) time and space complexity

class Solution {
public:
  bool has_path = false;

  void helper(TreeNode* root, int targetsum) {
    if (root == nullptr)
      return;

    if (targetsum == root->val && root->left == nullptr &&
        root->right == nullptr)
    {
      has_path = true;
      return;
    }

    if (root->left != nullptr) {
      helper(root->left, targetsum - root->val);
    }

    if (root->right != nullptr) {
      helper(root->right, targetsum - root->val);
    }
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    helper(root, targetSum);
    return has_path;
  }
};