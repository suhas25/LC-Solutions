//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  //should return the first found leaf node at lowest level. i.e node for which left and right are null
  int minDepth(TreeNode* root)
  {
    if(root==nullptr)
      return 0;

    if(root->left==nullptr)
      return (1+minDepth(root->right));

    if(root->right==nullptr)
      return (1+minDepth(root->left));

    return (1+min(minDepth(root->left), minDepth(root->right)));
  }
};