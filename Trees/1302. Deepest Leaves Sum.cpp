//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
public:
  int deepestLeavesSum(TreeNode* root)
  {
    if (root == nullptr)
      return 0;

    queue<TreeNode*> q;
    q.push(root);

    int sum=0;

    while (!q.empty())
    {
      sum=0;
      int size = q.size();
      for (int i=0;i<size; i++)
      {
        auto curr = q.front();
        q.pop();

        if(curr->left)
          q.push(curr->left);
        if(curr->right)
          q.push(curr->right);
        if(curr->left==nullptr && curr->right==nullptr)
          sum+=curr->val;
      }
    }
    return sum;
  }
};
