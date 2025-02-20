//
// Created by Suhas Reddy on 2/19/25.
//

//Use inorder traversal and compare elements.

class Solution {
public:
  int getMinimumDifference(TreeNode* root)
  {
    int min_difference = INT_MAX;

    stack<TreeNode*>stk;
    TreeNode*prev = nullptr;

    while(root!=nullptr || !stk.empty())
    {
      while(root)
      {
        stk.push(root);
        root=root->left;
      }
      root = stk.top();
      stk.pop();

      if(prev!=nullptr)
        min_difference=min(min_difference, root->val-prev->val);

      prev = root;
      root=root->right;
    }

    return min_difference;
  }
};