//
// Created by Suhas Reddy on 2/17/25.
//

// O(n) solution

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if(root == nullptr || root ==p || root ==q)
      return root;

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    //if one node is found in left and one in right subtree. then this node is the LCA.
    if(left && right)
      return root;

    //Definitely not left, so return right.
    if(left==nullptr)
      return right;

    return left;
  }
};