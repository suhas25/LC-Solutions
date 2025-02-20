//
// Created by Suhas Reddy on 2/17/25.
//

// O(N) space and time complexity.
class Solution {
public:

  TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode*q)
  {
    if(root==nullptr || root==p || root==q)
      return root;

    auto left = LCA(root->left, p, q);
    auto right = LCA(root->right, p, q);

    if(left&&right)
      return root;

    if(left==nullptr)
      return right;
    return left;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    auto ele = LCA(root, p, q);

    if(ele!=p && ele !=q) //if lca returns a different node than p and q, then both exist in tree.
      return ele;

    TreeNode* ele2=nullptr;

    //search for another node. If found return LCA otherwise return nullptr.
    if(ele==p)
      ele2= LCA(root, q,q);
    else
      ele2= LCA(root, p, p);

    if(ele2!=nullptr)
      return ele;
    return nullptr;
  }
};
