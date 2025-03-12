//
// Created by Suhas Reddy on 3/5/25.
//

/*
 * Do an inorder traversal. Compare the predecessor with current and mark nodes to swap
 * perform swap operation if found two nodes which are non null
 *
 */

//O(n) time and space complexity
class Solution
{
public:
  void recoverTree(TreeNode* root)
  {
    if(root==nullptr)
      return;

    TreeNode* prev=nullptr;
    TreeNode* x=nullptr;
    TreeNode* y= nullptr;

    stack<TreeNode*>stk;

    while(root!=nullptr || !stk.empty())
    {
      while(root!=nullptr)
      {
        stk.push(root);
        root=root->left;
      }

      root = stk.top();
      stk.pop();

      if(prev!=nullptr && root->val<prev->val)
      {
        y=root;
        if(x==nullptr)
          x=prev;
        else
          break; //break after finding two incorrect nodes.
      }
      prev=root;
      root=root->right;
    }

    if(x&&y)
      swap(x->val, y->val);
  }
};