//
// Created by Suhas Reddy on 2/17/25.
//


class Solution {
public:
  bool isValid = true;
  int get_height(TreeNode* node)
  {
    if(node == nullptr)
      return 0;

    int lh = get_height(node->left);
    int rh = get_height(node->right);

    int diff= abs(lh-rh);
    if(diff>1)
      isValid = false;

    //return the max height passing through this node. i.e max of both subtree + 1 link for root
    return 1+max(lh, rh);
  }

  bool isBalanced(TreeNode* root)
  {
    if(root==nullptr)
      return true;

    get_height(root);

    return isValid;
  }
};