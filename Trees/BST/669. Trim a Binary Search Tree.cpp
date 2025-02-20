//
// Created by Suhas Reddy on 2/19/25.
//

//O(log n) solution

class Solution {
public:
  TreeNode* trimBST(TreeNode* root, int low, int high)
  {
    if(root==nullptr)
      return root;

    //root lies in range
    if (root->val >= low && root->val <= high)
    {
      root->left = trimBST(root->left,low, high);
      root->right = trimBST(root->right, low, high);
    }
    else if (root->val < low)
      root = trimBST(root->right, low, high);
    else if (root->val > high)
      root = trimBST(root->left,low, high);

    return root;
  }
};