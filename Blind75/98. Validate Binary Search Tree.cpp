//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  bool isValidBST(TreeNode* root)
  {
    if(root == nullptr)
      return true;

    stack<TreeNode*>stk;
    TreeNode* prev = nullptr;

    while(root!=nullptr || !stk.empty())
    {
      while(root!=nullptr)
      {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();

      if(prev !=nullptr && root->val<=prev->val)
      {
        return false;
      }
      prev = root;
      root = root->right;
    }
    return true;
  }
};
