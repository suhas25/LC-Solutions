//
// Created by Suhas Reddy on 2/17/25.
//

class Solution
{
public:

  vector<int>numbers;
  int result = 0;

  void helper(TreeNode* root, vector<int>path)
  {
    if(root == nullptr)
      return;

    path.push_back(root->val);

    if(root->left == nullptr && root->right == nullptr)
    {
      int number = 0;
      for(int i=0; i<path.size(); i++)
      {
        number= number*10+path[i];
      }
      numbers.push_back(number);
      //path.pop_back();
    }

    helper(root->left, path);
    helper(root->right, path);
    //path.pop_back();
  }
  int sumNumbers(TreeNode* root)
  {
    if(root == nullptr)
      return 0;

    vector<int>path;
    helper(root, path);

    for(auto n:numbers)
      result+=n;

    return result;
  }
};