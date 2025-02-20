//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  TreeNode* result = nullptr;

  TreeNode* searchBST(TreeNode* root, int val)
  {
    if(root == nullptr)
      return nullptr;

    if(root->val==val)
    {
      result=root;
      return result;
    }

    if(root->val>val)
      searchBST(root->left, val);
    else
      searchBST(root->right, val);

    return result;
  }
};