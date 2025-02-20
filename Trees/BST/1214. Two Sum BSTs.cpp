//
// Created by Suhas Reddy on 2/19/25.
//

/**
 * Traverse tree 1 and stores in set.
 * Now, traverse tree2 and check for compliment node
 */

class Solution
{
  unordered_set<int>s;
public:
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
  {
    dfs(root1);
    return findTarget(root2, target);
  }

  bool findTarget(TreeNode *root, int target)
  {
    if(!root) return false;

    if(s.find(target - root->val) != s.end())
      return true;

    return findTarget(root->left, target) || findTarget(root->right, target);
  }

  void dfs(TreeNode *root)
  {
    if(!root) return;

    s.insert(root->val);
    dfs(root->left);
    dfs(root->right);
  }
};
