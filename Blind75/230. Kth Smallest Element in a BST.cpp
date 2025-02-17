//
// Created by Suhas Reddy on 2/15/25.
//

//use inorder traversal and use counter k to extract kth element.
class Solution {
public:
  int kthSmallest(TreeNode* root, int k)
  {
    if(root==nullptr)
      return 0;

    stack<TreeNode*> stk;

    while(root!=nullptr || !stk.empty())
    {
      while(root!=nullptr)
      {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();

      if(--k==0)
        return root->val;

      root = root->right;
    }
    return 0;
  }
};
