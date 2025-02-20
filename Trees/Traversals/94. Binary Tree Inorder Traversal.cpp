//
// Created by Suhas Reddy on 2/17/25.
//

//Recursive solution
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root)
  {
    vector<int> res;
    helper(root, res);
    return res;
  }
  void helper(TreeNode* root, vector<int>& res)
  {
    if (root != NULL)
    {
      helper(root->left, res);
      res.push_back(root->val);
      helper(root->right, res);
    }
  }
};

//Iterative Solution
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root)
  {
    stack<TreeNode*> stk;
    vector<int> result;

    if (root == nullptr)
      return result;

    while (root != nullptr || !stk.empty())
    {
      while (root != nullptr)
      {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      result.push_back(root->val);
      root = root->right;
    }
    return result;
  }
};