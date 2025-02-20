//
// Created by Suhas Reddy on 2/15/25.
//

//O(log N) time Complexity as its BST and we search at max of one node per level
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    TreeNode* curr =root;

    while(curr!=nullptr)
    {
      if(p->val > curr->val && q->val > curr->val)
        curr = curr->right;

      else if(p->val<curr->val && q->val < curr->val)
        curr = curr->left;

      else
        return curr;
    }
    return nullptr;
  }
};