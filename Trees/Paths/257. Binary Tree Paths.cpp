//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:

  vector<vector<int>>resultpaths;
  vector<string>result;

  void helper(TreeNode* root, string path)
  {
    if(root==nullptr)
      return;

    path+=to_string(root->val);

    if(root->left == nullptr && root->right == nullptr)
    {
      result.push_back(path);
      return;
    }

    path = path+"->";
    helper(root->left, path);
    helper(root->right, path);
  }

  vector<string> binaryTreePaths(TreeNode* root)
  {
    if(root==nullptr)
      return result;

    helper(root, {});

    return result;
  }
};
