//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:

  int maxsum = INT_MIN;
  int calculateSum(TreeNode* node)
  {
    //base case
    if(node==nullptr)
      return 0;

    int lsum = max(calculateSum(node->left), 0);
    int rsum = max(calculateSum(node->right), 0);

    //max sum consider this node as root
    maxsum = max(lsum+rsum+node->val, maxsum);

    //return max sum that can be taken considering this subtree exists in path( both right and left child cannot exist)
    return node->val + max(lsum, rsum);

  }
  int maxPathSum(TreeNode* root)
  {
    if(root == nullptr)
      return -1;

    int sum = calculateSum(root);
    return maxsum;

  }
};
