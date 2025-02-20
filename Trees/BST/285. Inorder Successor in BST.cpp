//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
  {
    TreeNode* successor=nullptr;
    while(root)
    {
      if(p->val>=root->val)
        root=root->right;
      else{
        successor = root;
        root = root->left;
      }
    }

    return successor;

  }
};
