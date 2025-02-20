//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  vector<int>result;

  bool isleaf(TreeNode* root)
  {
    if(root->left == nullptr && root->right == nullptr)
      return true;
    return false;
  }

  void leftboundary(TreeNode* root)
  {
    if(root != nullptr && !isleaf(root))
    {
      result.push_back(root->val);
      if(root->left)
        leftboundary(root->left);
      else
        leftboundary(root->right);
    }
  }

  void rightboundary(TreeNode* root)
  {
    if(root!=nullptr && !isleaf(root))
    {
      if(root->right)
        rightboundary(root->right);
      else
        rightboundary(root->left);
      result.push_back(root->val);
    }
  }

  void leafnodes(TreeNode* root)
  {
    if(root==nullptr)
      return;
    if(!isleaf(root))
    {
      leafnodes(root->left);
      leafnodes(root->right);
    }
    else
      result.push_back(root->val);
  }


  vector<int> boundaryOfBinaryTree(TreeNode* root)
  {
    if(root == nullptr)
      return {};

    result.push_back(root->val);

    leftboundary(root->left);
    leafnodes(root->left);
    leafnodes(root->right);
    rightboundary(root->right);

    return result;

  }
};
