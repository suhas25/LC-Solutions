//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:

  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
  {
    TreeNode* root = new TreeNode();

    if(root1==nullptr and root2 == nullptr)
      return root1;

    if(root1==nullptr)
      return root2;
    if(root2==nullptr)
      return root1;

    root->val = root1->val+root2->val;
    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);

    return root;

  }
};