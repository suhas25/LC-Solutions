//
// Created by Suhas Reddy on 2/17/25.
//

//Iterative Solution 1.
class Solution
{
public:
  vector<int>result;
  vector<int> preorderTraversal(TreeNode* root)
  {
    stack<TreeNode*>stk;

    while(root!=nullptr || !stk.empty())
    {
      while(root!=nullptr)
      {
        result.push_back(root->val);
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      root = root->right;
    }
    return result;
  }
};

//Iterative Solution2

class Solution2
{
public:
  vector<int>result;
  vector<int> preorderTraversal(TreeNode* root)
  {
    stack<TreeNode*>stk;

    stk.push(root);
    while(!stk.empty())
    {
      root = stk.top();
      stk.pop();

      result.push_back(root->val);

      if(root->left)
        stk.push(root->left);
      if(root->right)
        stk.push(root->right);
    }

    return result;
    }
  }
};

//Recursive
class Solution3
{
public:
  vector<int>result;

  void helper(TreeNode* root)
  {
    if(root== nullptr)
      return;

    result.push_back(root->val);

    helper(root->left);
    helper(root->right);
  }

  vector<int> preorderTraversal(TreeNode* root)
  {
    helper(root);
  }
    return result;
  }
};