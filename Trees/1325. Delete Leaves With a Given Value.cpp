//
// Created by Suhas Reddy on 2/20/25.
//

//post order recursion O(n) time and space complexity
class Solution
{
public:
  TreeNode* removeLeafNodes(TreeNode* root, int target)
  {
    if(root==nullptr)
      return nullptr;

    //Bottom up.
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if(root->left==nullptr && root->right==nullptr && root->val==target)
      return nullptr;

    return root;
  }
};
