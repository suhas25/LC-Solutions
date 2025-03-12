//
// Created by Suhas Reddy on 3/5/25.
//

//O(h) time complexity
class Solution {
public:

  int successor(TreeNode* node)
  {
    node = node->right;
    while(node->left!=nullptr)
      node=node->left;
    return node->val;
  }

  int predecessor(TreeNode* node)
  {
    node = node->left;
    while(node->right!=nullptr)
      node=node->right;
    return node->val;
  }

  TreeNode* deleteNode(TreeNode* root, int key)
  {
    if(root==nullptr)
      return root;

    if(key>root->val) //search to right
    {
      root->right = deleteNode(root->right, key);
    }
    else if(key<root->val)
      root->left = deleteNode(root->left, key) ;

    //when key is found.
    else
    {
      if(root->left == nullptr && root->right==nullptr)
        root=nullptr;
      else if(root->right)
      {
        root->val = successor(root);
        root->right = deleteNode(root->right, root->val);
      }
      else
      {
        root->val = predecessor(root);
        root->left = deleteNode(root->left, root->val);
      }
    }

    return root;
  }
};