//
// Created by Suhas Reddy on 2/17/25.
//

//Iterative Solution

class Solution
{
public:
  vector<int>result;

  void helper(TreeNode* root)
  {
    if(root==nullptr)
      return;

    helper(root->left);
    helper(root->right);
    result.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode* root)
  {
    helper(root);
    return result;
  }
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root)
  {
    TreeNode* prev = nullptr;
    vector<int>result;
    stack<TreeNode*> stk;

    while(root !=nullptr || !stk.empty())
    {
      while(root !=nullptr)
      {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      if(root->right!=nullptr && root->right!=prev)
      {
        root = root->right;
      }
      else
      {
        result.push_back(root->val);
        stk.pop();
        prev = root;
        root = nullptr;
      }
    }
    return result;
  }
};
