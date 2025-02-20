//
// Created by Suhas Reddy on 2/17/25.
//

//Check the max length obtained trying each node as parent.

class Solution {
public:

  int longestpath = 0;
  //diameter = calculate left subtree height and right subtree height passing through //every node. the one with maximum length is diameter.
  int getdiameter(TreeNode* node)
  {
    if(node == nullptr)
      return 0;

    int lh = getdiameter(node->left);
    int rh = getdiameter(node->right);

    longestpath = max(longestpath, lh+rh);//longest path passing through this node as root
    return 1+max(lh, rh);// longest path considering this as in path

  }
  int diameterOfBinaryTree(TreeNode* root)
  {
    if(root == nullptr)
      return longestpath;

    getdiameter(root);
    return longestpath;
  }
};