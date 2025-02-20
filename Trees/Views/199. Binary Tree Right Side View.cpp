//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:

  vector<int>result;
  void helper(TreeNode* node, int currlevel, int& calculatedlevel)
  {
    if(node==nullptr)
      return;

    if(currlevel>calculatedlevel)
    {
      result.push_back(node->val);
      calculatedlevel = currlevel;
    }

    helper(node->right, currlevel+1, calculatedlevel);
    helper(node->left, currlevel+1, calculatedlevel);
  }

  vector<int> rightSideView(TreeNode* root)
  {
    if(root==nullptr)
      return result;

    int calculatedlevel = 0;
    int currlevel=1;

    result.push_back(root->val);

    helper(root->right, currlevel, calculatedlevel);
    helper(root->left, currlevel, calculatedlevel);

    return result;
  }
};
