//
// Created by Suhas Reddy on 2/15/25.
//

//Iterative solution
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
      vector<vector<int>>result;

      if(root == nullptr)
        return result;

      queue<TreeNode*>q;
      q.push(root);

      while(!q.empty())
      {
        vector<int>res;
        int sizee= q.size();

        for(int i=0;i<sizee; i++)
        {
          TreeNode* currnode = q.front();
          q.pop();

          res.push_back(currnode->val);

          if (currnode->left != nullptr)
            q.push(currnode->left);
          if (currnode->right != nullptr)
            q.push(currnode->right);
        }
        result.push_back(res);
      }
      return result;
    }
};

//Recursive solution.
class Solution
{
public:
  vector<vector<int>> levels;

  void helper(TreeNode* node, int level)
  {
    if (levels.size() == level)
      levels.push_back(vector<int>());

    levels[level].push_back(node->val);

    if (node->left != nullptr)
      helper(node->left, level + 1);
    if (node->right != nullptr)
      helper(node->right, level + 1);
  }

  vector<vector<int>> levelOrder(TreeNode* root)
  {
    if (root == nullptr)
      return levels;

    helper(root, 0);
    return levels;
  }
};
