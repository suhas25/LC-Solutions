//
// Created by Suhas Reddy on 2/17/25.
//


// Use set to insert or delete the values and if we reach a leaf node and if the set size<=1, then its a possible palindrome.

class Solution {
public:
  int count = 0;

  void helper(TreeNode* root, set<int>&s)
  {
    if(root == nullptr)
      return;

    if(s.find(root->val)!=s.end())
      s.erase(root->val);
    else
      s.insert(root->val);

    if(root->left == nullptr && root->right == nullptr)
    {
      if(s.size()<=1)
        count++;

      //update again as we are backtracking here
      if(s.find(root->val)==s.end())
        s.insert(root->val);
      else
        s.erase(root->val);

      return;
    }

    helper(root->left, s);
    helper(root->right, s);

    if(s.find(root->val)==s.end())
      s.insert(root->val);
    else
      s.erase(root->val);
  }

  int pseudoPalindromicPaths (TreeNode* root)
  {
    if(root == nullptr)
      return 0;

    set<int>s;

    helper(root,s);
    return count;
  }
};
