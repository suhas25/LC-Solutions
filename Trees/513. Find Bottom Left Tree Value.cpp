//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  int maxDepth;
  int bottomLeftValue;

  void dfs(TreeNode* current, int depth) {
    if (current == nullptr) {
      return;
    }
    if (depth > maxDepth) { // If true, we discovered a new level
      maxDepth = depth;
      bottomLeftValue = current->val;
    }
    dfs(current->left, depth + 1);
    dfs(current->right, depth + 1);
  }

  int findBottomLeftValue(TreeNode* root) {
    maxDepth = INT_MIN;
    bottomLeftValue = 0;
    dfs(root, 0);
    return bottomLeftValue;
  }
};