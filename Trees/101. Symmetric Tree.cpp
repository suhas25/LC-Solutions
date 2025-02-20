//
// Created by Suhas Reddy on 2/17/25.
//

//Recursive solution

class Solution
{
public:
  bool isSymmetric(TreeNode* root)
  {
    if(root==nullptr)
      return true;

    return isMirror(root->left, root->right);
  }

  bool isMirror(TreeNode* t1, TreeNode* t2)
  {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
           isMirror(t1->left, t2->right);
  }
};



// Iterative

class Solution {
public:
  bool isSymmetric(TreeNode* root)
  {
    bool isValid = true;
    queue<TreeNode*> q;

    if(root == nullptr)
      return true;

    q.push(root->left);
    q.push(root->right);

    while(!q.empty())
    {
      TreeNode* leftele = q.front();
      q.pop();
      TreeNode* rightele = q.front();
      q.pop();


      if(leftele == nullptr && rightele == nullptr)
      {
        continue;
      }

      else if(leftele == nullptr || rightele == nullptr)
      {
        isValid = false;
        return isValid;
      }

      else
      {
        if(leftele->val != rightele->val)
        {
          isValid = false;
          return isValid;
        }
        else
        {
          q.push(leftele->left);
          q.push(rightele->right);

          q.push(leftele->right);
          q.push(rightele->left);
        }
      }
    }
    return isValid;
  }
};
