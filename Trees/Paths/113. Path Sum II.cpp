//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:

  vector<vector<int>>results;
  void calculateSum(TreeNode* root, vector<int> path, int targetSum)
  {
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr && targetSum-root->val==0)
        results.push_back(path);

    if(root->left!=nullptr)
    {
      calculateSum(root->left, path, targetSum-root->val);
    }

    if(root->right!=nullptr)
    {
      calculateSum(root->right,path, targetSum-root->val);
    }
    //path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum)
  {
    if(root == nullptr)
      return results;
    vector<int>p;

    calculateSum(root,p, targetSum);

    return results;

  }
};
