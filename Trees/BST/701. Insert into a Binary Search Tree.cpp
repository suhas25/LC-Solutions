//
// Created by Suhas Reddy on 3/5/25.
//

///Recursive solution
class Solution
{
  public:
  TreeNode* insertIntoBST(TreeNode* root, int val)
  {
    if(root==nullptr)
    {
      TreeNode* newnode = new TreeNode(val);
      return newnode;
    }

    if(root->val==val)
      return root;

    if(root->val<val)
      root->right = insertIntoBST(root->right, val);
    else
      root->left = insertIntoBST(root->left, val);
    return root;
  }
};

//Iterative
class Solution2
{
  public:
  TreeNode* insertIntoBST(TreeNode* root, int val)
  {
    if(root==nullptr)
    {
      TreeNode* newnode = new TreeNode(val);
      return newnode;
    }

    auto curr = root;
    while(curr!=nullptr)
    {
      if(curr->val>val)
      {
        if(curr->left==nullptr)
        {
          curr->left = new TreeNode(val);
          return root;
        }
        else
          curr = curr->left;
      }

      if(curr->val<val)
      {
        if(curr->right==nullptr)
        {
          curr->right = new TreeNode(val);
          return root;
        }
        else
          curr = curr->right;
      }
    }
    return nullptr; //won't reach here
  }
};
