//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
      return true;
    if (p == NULL || q == NULL)
      return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) &&
            p->val == q->val);
  }
};