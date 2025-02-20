//
// Created by Suhas Reddy on 2/17/25.
//

//O(n) space and time complexity

/*
 * Use Set + BFS/DFS
 *
 */

class Solution
{
public:
  unordered_set<int> s;
  bool findTarget(TreeNode* root, int k)
  {
    if (!root) return false;
    if (s.count(k - root->val)) return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};
