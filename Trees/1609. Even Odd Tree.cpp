//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
public:
  bool isEvenOddTree(TreeNode* root)
  {
    if (root == nullptr)
      return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level=-1;
    bool odd = false;

    while (!q.empty())
    {
      level++;
      int size = q.size();
      int prev_val = 0;

      odd=!odd;
      for (int i=0;i<size; i++)
      {
        auto curr = q.front();
        q.pop();

        if(odd)
        {
          if(curr->val%2!=1)
            return false;
        }

        if(!odd)
        {
          if(curr->val%2!=0)
            return false;
        }

        if(level%2==0)
        {
          if(i>=1)
          {
            if(curr->val<=prev_val)
              return false;
          }
        }

        if(level%2==1)
        {
          if(i>=1)
          {
            if(curr->val>=prev_val)
              return false;
          }
        }

        if(curr->left)
          q.push(curr->left);
        if(curr->right)
          q.push(curr->right);

        prev_val=curr->val;
      }
    }
    return true;
  }
};
