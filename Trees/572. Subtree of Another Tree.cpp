//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:

  bool isSame(TreeNode* p, TreeNode*q)
  {
    if(p==nullptr && q==nullptr)
      return true;

    if(p==nullptr || q==nullptr)
      return false;

    return (p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right));
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot)
  {
    if(root==nullptr)
      return false;

    if(isSame(root, subRoot))
      return true;

    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));

  }
};
